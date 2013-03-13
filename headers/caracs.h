#ifndef CARACS_H
#define CARACS_H

#include <QtGui>
#include <vector>

#include "databaseManager.h"

extern DatabaseManager dataManager;

class Caracs: public QWidget
{

	Q_OBJECT

private:
	QGridLayout* layoutPrincipal;
	QGridLayout* layoutInfos;
	QHBoxLayout* layoutClasses;
	QGridLayout* layoutStats;
	QGridLayout* layoutSauvegardes;
	QGridLayout* layoutDivers;
	QGridLayout* layoutPVCA;
	
	//Informations
	int nbClasses;
	int lvlMax;
	
	QLineEdit* c_nom;
	QLineEdit* c_joueur;
	std::vector<QComboBox*> c_classe;
	std::vector<QSpinBox*> c_niveau;
	QComboBox* c_race;
	QComboBox* c_alignement;
	QComboBox* c_divinite;
	QComboBox* c_categorieTaille;
	
	QLabel* l_nom;
	QLabel* l_joueur;
	QLabel* l_classe;
	QLabel* l_race;
	QLabel* l_alignement;
	QLabel* l_divinite;
	QLabel* l_categorieTaille;
	
	QPushButton* boutonAjoutClasse;
	QPushButton* boutonRetraitClasse;
	
	//Stats
	QSpinBox* c_for_score;
	QLineEdit* c_for_mod;
	QLineEdit* c_for_score_tmp;
	QLineEdit* c_for_mod_tmp;
	QSpinBox* c_dex_score;
	QLineEdit* c_dex_mod;
	QLineEdit* c_dex_score_tmp;
	QLineEdit* c_dex_mod_tmp;
	QSpinBox* c_con_score;
	QLineEdit* c_con_mod;
	QLineEdit* c_con_score_tmp;
	QLineEdit* c_con_mod_tmp;
	QSpinBox* c_int_score;
	QLineEdit* c_int_mod;
	QLineEdit* c_int_score_tmp;
	QLineEdit* c_int_mod_tmp;
	QSpinBox* c_sag_score;
	QLineEdit* c_sag_mod;
	QLineEdit* c_sag_score_tmp;
	QLineEdit* c_sag_mod_tmp;
	QSpinBox* c_cha_score;
	QLineEdit* c_cha_mod;
	QLineEdit* c_cha_score_tmp;
	QLineEdit* c_cha_mod_tmp;
	
	QLabel* l_carac;
	QLabel* l_score;
	QLabel* l_mod;
	QLabel* l_score_tmp;
	QLabel* l_mod_tmp;
	QLabel* l_for;
	QLabel* l_dex;
	QLabel* l_con;
	QLabel* l_int;
	QLabel* l_sag;
	QLabel* l_cha;
	
	//Divers
	QLineEdit* c_bba;
	QLineEdit* c_initiative;
	QLineEdit* c_vitesse;
	QLineEdit* c_res_mag;
	QLineEdit* c_reduc_deg;
	QLineEdit* c_lutte;
	
	QLabel* l_bba;
	QLabel* l_initiative;
	QLabel* l_vitesse;
	QLabel* l_res_mag;
	QLabel* l_reduc_deg;
	QLabel* l_lutte;
	
	//PV/CA
	QLineEdit* c_tot_pv;
	QLineEdit* c_rest_pv;
	QLineEdit* c_non_letal;
	QLineEdit* c_tot_ca;
	QLineEdit* c_armure_ca;
	QLineEdit* c_bouclier_ca;
	QLineEdit* c_mod_dex_ca;
	QLineEdit* c_mod_taille_ca;
	QLineEdit* c_arm_naturelle_ca;
	QLineEdit* c_mod_parade_ca;
	QLineEdit* c_mod_divers_ca;
	QLineEdit* c_attaque_contact_ca;
	QLineEdit* c_depourvu_ca;
	
	QLabel* l_pv;
	QLabel* l_ca;
	QLabel* l_tot_pv;
	QLabel* l_rest_pv;
	QLabel* l_non_letal;
	QLabel* l_attaque_contact_ca;
	QLabel* l_depourvu_ca;
	QLabel* l_tot_ca;
	QLabel* l_armure_ca;
	QLabel* l_bouclier_ca;
	QLabel* l_mod_dex_ca;
	QLabel* l_mod_taille_ca;
	QLabel* l_arm_naturelle_ca;
	QLabel* l_mod_parade_ca;
	QLabel* l_mod_divers_ca;
	
	//Sauvegardes
	QLineEdit* c_tot_ref;
	QLineEdit* c_base_ref;
	QLineEdit* c_carac_ref;
	QLineEdit* c_magie_ref;
	QLineEdit* c_divers_ref;
	QLineEdit* c_tmp_ref;
	QLineEdit* c_tot_vig;
	QLineEdit* c_base_vig;
	QLineEdit* c_carac_vig;
	QLineEdit* c_magie_vig;
	QLineEdit* c_divers_vig;
	QLineEdit* c_tmp_vig;
	QLineEdit* c_tot_vol;
	QLineEdit* c_base_vol;
	QLineEdit* c_carac_vol;
	QLineEdit* c_magie_vol;
	QLineEdit* c_divers_vol;
	QLineEdit* c_tmp_vol;
	
	QLabel* l_sauvegarde;
	QLabel* l_total;
	QLabel* l_base;
	QLabel* l_mod_carac;
	QLabel* l_magie;
	QLabel* l_divers;
	QLabel* l_tmp;
	QLabel* l_ref;
	QLabel* l_vig;
	QLabel* l_vol;
	
	//Séparateurs
	QFrame* f_separation1;
	QFrame* f_separation2;
	QFrame* f_separation3;
	QFrame* f_separation4;
	
public:
	Caracs();
	void setClassList(QComboBox*);
	void setRaceList();
	void setDivinityList();
	void setAlignmentList();
	void setSizeCategory();

signals:
	void modForChanged(int newValue);
	void modDexChanged(int newValue);
	void modConChanged(int newValue);
	void modIntChanged(int newValue);
	void modSagChanged(int newValue);
	void modChaChanged(int newValue);

private slots:
	void ajoutClasse();
	void retraitClasse();
	void calculModFor(int);
	void calculModDex(int);
	void calculModCon(int);
	void calculModInt(int);
	void calculModSag(int);
	void calculModCha(int);
};

#endif // CARACS_H
