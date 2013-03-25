#ifndef CARACS_H
#define CARACS_H

#include <QtGui>
#include <vector>

#include "databaseManager.h"
#include "lineEdit.h"
#include "xmlManager.h"

extern DatabaseManager dataManager;
extern XmlManager xmlManager;

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
	
	LineEdit* c_nom;
	LineEdit* c_joueur;
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
	LineEdit* c_for_mod;
	LineEdit* c_for_score_tmp;
	LineEdit* c_for_mod_tmp;
	QSpinBox* c_dex_score;
	LineEdit* c_dex_mod;
	LineEdit* c_dex_score_tmp;
	LineEdit* c_dex_mod_tmp;
	QSpinBox* c_con_score;
	LineEdit* c_con_mod;
	LineEdit* c_con_score_tmp;
	LineEdit* c_con_mod_tmp;
	QSpinBox* c_int_score;
	LineEdit* c_int_mod;
	LineEdit* c_int_score_tmp;
	LineEdit* c_int_mod_tmp;
	QSpinBox* c_sag_score;
	LineEdit* c_sag_mod;
	LineEdit* c_sag_score_tmp;
	LineEdit* c_sag_mod_tmp;
	QSpinBox* c_cha_score;
	LineEdit* c_cha_mod;
	LineEdit* c_cha_score_tmp;
	LineEdit* c_cha_mod_tmp;
	
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
	LineEdit* c_bba;
	LineEdit* c_initiative;
	LineEdit* c_vitesse;
	LineEdit* c_res_mag;
	LineEdit* c_reduc_deg;
	LineEdit* c_lutte;
	
	QLabel* l_bba;
	QLabel* l_initiative;
	QLabel* l_vitesse;
	QLabel* l_res_mag;
	QLabel* l_reduc_deg;
	QLabel* l_lutte;
	
	//PV/CA
	LineEdit* c_tot_pv;
	LineEdit* c_rest_pv;
	LineEdit* c_non_letal;
	LineEdit* c_tot_ca;
	LineEdit* c_armure_ca;
	LineEdit* c_bouclier_ca;
	LineEdit* c_mod_dex_ca;
	LineEdit* c_mod_taille_ca;
	LineEdit* c_arm_naturelle_ca;
	LineEdit* c_mod_parade_ca;
	LineEdit* c_mod_divers_ca;
	LineEdit* c_attaque_contact_ca;
	LineEdit* c_depourvu_ca;
	
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
	LineEdit* c_tot_ref;
	LineEdit* c_base_ref;
	LineEdit* c_carac_ref;
	LineEdit* c_magie_ref;
	LineEdit* c_divers_ref;
	LineEdit* c_tmp_ref;
	LineEdit* c_tot_vig;
	LineEdit* c_base_vig;
	LineEdit* c_carac_vig;
	LineEdit* c_magie_vig;
	LineEdit* c_divers_vig;
	LineEdit* c_tmp_vig;
	LineEdit* c_tot_vol;
	LineEdit* c_base_vol;
	LineEdit* c_carac_vol;
	LineEdit* c_magie_vol;
	LineEdit* c_divers_vol;
	LineEdit* c_tmp_vol;
	
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
	
	void infosToDisplay(std::vector<QString> champs, std::vector<int> vals);
	void finAffichageInfos();

	void saveDone();

private slots:
	void ajoutClasse();
	void retraitClasse();
	
	void calculModFor(int);
	void calculModDex(int);
	void calculModCon(int);
	void calculModInt(int);
	void calculModSag(int);
	void calculModCha(int);
	
	void transmissionAffichageInfos(QString cible);
	void transmissionFinAffichageInfos();
	
	void receiveSaveRequest();
};

#endif // CARACS_H
