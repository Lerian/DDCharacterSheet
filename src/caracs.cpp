#include "caracs.h"

Caracs::Caracs()
{
	//Création des layout
	layoutPrincipal = new QGridLayout();
	layoutInfos = new QGridLayout();
	layoutClasses = new QHBoxLayout();
	layoutStats = new QGridLayout();
	layoutSauvegardes = new QGridLayout();
	layoutDivers = new QGridLayout();
	layoutPVCA = new QGridLayout();
	
// Partie Informations
	
	nbClasses = 0;
	lvlMax = 30;
	
	//Création des champs
	c_nom = new LineEdit("personnage", TEXTE);
	c_joueur = new LineEdit("joueur", TEXTE);
	c_race = new QComboBox();
	c_alignement = new QComboBox();
	c_divinite = new QComboBox();
	c_categorieTaille = new QComboBox();
	
	//Création des labels
	l_nom = new QLabel("Personnage:");
	l_joueur = new QLabel("Joueur:");
	l_classe = new QLabel("Classe(s):");
	l_race = new QLabel("Race:");
	l_alignement = new QLabel("Alignement:");
	l_divinite = new QLabel("Divinité:");
	l_categorieTaille = new QLabel("Catégorie de taille:");
	
	//Création des boutons
	boutonAjoutClasse = new QPushButton("+");
	boutonAjoutClasse->setFixedWidth(25);
	boutonRetraitClasse = new QPushButton("-");
	boutonRetraitClasse->setFixedWidth(25);
	
	//Alignement des textes
	l_nom->setAlignment(Qt::AlignRight);
	l_joueur->setAlignment(Qt::AlignRight);
	l_classe->setAlignment(Qt::AlignRight);
	l_race->setAlignment(Qt::AlignRight);
	l_alignement->setAlignment(Qt::AlignRight);
	l_divinite->setAlignment(Qt::AlignRight);
	l_categorieTaille->setAlignment(Qt::AlignRight);
	
	//Placement des champs dans le layout
	layoutInfos->addWidget(c_nom,0,1,1,3);
	layoutInfos->addWidget(c_joueur,0,5);
	layoutInfos->addWidget(c_race,2,1);
	layoutInfos->addWidget(c_alignement,2,3);
	layoutInfos->addWidget(c_divinite,2,5);
	layoutInfos->addWidget(c_categorieTaille,3,1);
	
	//Construction des comboBox
	setRaceList();
	setDivinityList();
	setAlignmentList();
	setSizeCategory();
	
	//Placement des labels dans le layout
	layoutInfos->addWidget(l_nom,0,0);
	layoutInfos->addWidget(l_joueur,0,4);
	layoutInfos->addWidget(l_race,2,0);
	layoutInfos->addWidget(l_alignement,2,2);
	layoutInfos->addWidget(l_divinite,2,4);
	layoutInfos->addWidget(l_categorieTaille,3,0);
	
	//Création et placement de la section pour la(les) classe(s)
	layoutInfos->addLayout(layoutClasses,1,0,1,-1);
	layoutClasses->addWidget(boutonAjoutClasse);
	layoutClasses->addWidget(boutonRetraitClasse);
	layoutClasses->addWidget(l_classe);
	
	ajoutClasse();
	
// Partie stats

	//Création des champs
	c_for_score = new QSpinBox();
		c_for_score->setRange(0,50);
	c_for_mod = new LineEdit("Mod. de force");
		c_for_mod->setReadOnly(true);
		c_for_mod->setFixedWidth(50);
		c_for_mod->setAlignment(Qt::AlignCenter);
	c_for_score_tmp = new LineEdit("Score de force temp.");
	c_for_mod_tmp = new LineEdit("Mod. temp. de force");
	c_dex_score = new QSpinBox();
		c_dex_score->setRange(0,50);
	c_dex_mod = new LineEdit("Mod. de dex");
		c_dex_mod->setReadOnly(true);
		c_dex_mod->setFixedWidth(50);
		c_dex_mod->setAlignment(Qt::AlignCenter);
	c_dex_score_tmp = new LineEdit("Score de dex temp.");
	c_dex_mod_tmp = new LineEdit("Mod. temp. de dex");
	c_con_score = new QSpinBox();
		c_con_score->setRange(0,50);
	c_con_mod = new LineEdit("Mod. de con");
		c_con_mod->setReadOnly(true);
		c_con_mod->setFixedWidth(50);
		c_con_mod->setAlignment(Qt::AlignCenter);
	c_con_score_tmp = new LineEdit("Score temp. de con");
	c_con_mod_tmp = new LineEdit("Mod. temp. de con");
	c_int_score = new QSpinBox();
		c_int_score->setRange(0,50);
	c_int_mod = new LineEdit("Mod. d'int");
		c_int_mod->setReadOnly(true);
		c_int_mod->setFixedWidth(50);
		c_int_mod->setAlignment(Qt::AlignCenter);
	c_int_score_tmp = new LineEdit("Score temp. d'int");
	c_int_mod_tmp = new LineEdit("Mod. temp. d'int");
	c_sag_score = new QSpinBox();
		c_sag_score->setRange(0,50);
	c_sag_mod = new LineEdit("Mod. de sag");
		c_sag_mod->setReadOnly(true);
		c_sag_mod->setFixedWidth(50);
		c_sag_mod->setAlignment(Qt::AlignCenter);
	c_sag_score_tmp = new LineEdit("Score temp. de sag");
	c_sag_mod_tmp = new LineEdit("Mod. temp. de sag");
	c_cha_score = new QSpinBox();
		c_cha_score->setRange(0,50);
	c_cha_mod = new LineEdit("Mod. de cha");
		c_cha_mod->setReadOnly(true);
		c_cha_mod->setFixedWidth(50);
		c_cha_mod->setAlignment(Qt::AlignCenter);
	c_cha_score_tmp = new LineEdit("Score temp. de cha");
	c_cha_mod_tmp = new LineEdit("Mod. temp. de cha");
	//Placement des champs dans le layout
	layoutStats->addWidget(c_for_score,8,1);
	layoutStats->addWidget(c_for_mod,8,2);
	layoutStats->addWidget(c_for_score_tmp,8,3);
	layoutStats->addWidget(c_for_mod_tmp,8,4);
	layoutStats->addWidget(c_dex_score,9,1);
	layoutStats->addWidget(c_dex_mod,9,2);
	layoutStats->addWidget(c_dex_score_tmp,9,3);
	layoutStats->addWidget(c_dex_mod_tmp,9,4);
	layoutStats->addWidget(c_con_score,10,1);
	layoutStats->addWidget(c_con_mod,10,2);
	layoutStats->addWidget(c_con_score_tmp,10,3);
	layoutStats->addWidget(c_con_mod_tmp,10,4);
	layoutStats->addWidget(c_int_score,11,1);
	layoutStats->addWidget(c_int_mod,11,2);
	layoutStats->addWidget(c_int_score_tmp,11,3);
	layoutStats->addWidget(c_int_mod_tmp,11,4);
	layoutStats->addWidget(c_sag_score,12,1);
	layoutStats->addWidget(c_sag_mod,12,2);
	layoutStats->addWidget(c_sag_score_tmp,12,3);
	layoutStats->addWidget(c_sag_mod_tmp,12,4);
	layoutStats->addWidget(c_cha_score,13,1);
	layoutStats->addWidget(c_cha_mod,13,2);
	layoutStats->addWidget(c_cha_score_tmp,13,3);
	layoutStats->addWidget(c_cha_mod_tmp,13,4);
	
	//Connexion des signaux/slots
	connect(c_for_score,SIGNAL(valueChanged(int)),this,SLOT(calculModFor(int)));
	connect(c_dex_score,SIGNAL(valueChanged(int)),this,SLOT(calculModDex(int)));
	connect(c_con_score,SIGNAL(valueChanged(int)),this,SLOT(calculModCon(int)));
	connect(c_int_score,SIGNAL(valueChanged(int)),this,SLOT(calculModInt(int)));
	connect(c_sag_score,SIGNAL(valueChanged(int)),this,SLOT(calculModSag(int)));
	connect(c_cha_score,SIGNAL(valueChanged(int)),this,SLOT(calculModCha(int)));

	//Calcul des valeurs initiales
	c_for_score->setValue(10);
	calculModFor(c_for_score->value());
	c_dex_score->setValue(10);
	calculModDex(c_dex_score->value());
	c_con_score->setValue(10);
	calculModCon(c_con_score->value());
	c_int_score->setValue(10);
	calculModInt(c_int_score->value());
	c_sag_score->setValue(10);
	calculModSag(c_sag_score->value());
	c_cha_score->setValue(10);
	calculModCha(c_cha_score->value());

	//Création des labels
	l_carac = new QLabel("Caracs");
	l_score = new QLabel("Score");
	l_mod = new QLabel("Mod");
	l_score_tmp = new QLabel("Score temp.");
	l_mod_tmp = new QLabel("Mod temp.");
	l_for = new QLabel("FOR");
	l_dex = new QLabel("DEX");
	l_con = new QLabel("CON");
	l_int = new QLabel("INT");
	l_sag = new QLabel("SAG");
	l_cha = new QLabel("CHA");
	//Alignement des textes
	l_carac->setAlignment(Qt::AlignCenter);
	l_score->setAlignment(Qt::AlignCenter);
	l_mod->setAlignment(Qt::AlignCenter);
	l_score_tmp->setAlignment(Qt::AlignCenter);
	l_mod_tmp->setAlignment(Qt::AlignCenter);
	l_for->setAlignment(Qt::AlignCenter);
	l_dex->setAlignment(Qt::AlignCenter);
	l_con->setAlignment(Qt::AlignCenter);
	l_int->setAlignment(Qt::AlignCenter);
	l_sag->setAlignment(Qt::AlignCenter);
	l_cha->setAlignment(Qt::AlignCenter);
	
	//Placement des labels dans le layout
	layoutStats->addWidget(l_carac,7,0);
	layoutStats->addWidget(l_score,7,1);
	layoutStats->addWidget(l_mod,7,2);
	layoutStats->addWidget(l_score_tmp,7,3);
	layoutStats->addWidget(l_mod_tmp,7,4);
	layoutStats->addWidget(l_for,8,0);
	layoutStats->addWidget(l_dex,9,0);
	layoutStats->addWidget(l_con,10,0);
	layoutStats->addWidget(l_int,11,0);
	layoutStats->addWidget(l_sag,12,0);
	layoutStats->addWidget(l_cha,13,0);
	
//Partie divers

	//Création des champs
	c_bba = new LineEdit("BBA");
	c_initiative = new LineEdit("Initiative");
	c_vitesse = new LineEdit("Vitesse");
	c_res_mag = new LineEdit("Résist. magie");
	c_reduc_deg = new LineEdit("Réduc. dégats");
	c_lutte = new LineEdit("Lutte");
	
	//Placement des champs dans le layout
	layoutDivers->addWidget(c_bba,0,1);
	layoutDivers->addWidget(c_initiative,1,1);
	layoutDivers->addWidget(c_vitesse,2,1);
	layoutDivers->addWidget(c_res_mag,3,1);
	layoutDivers->addWidget(c_reduc_deg,4,1);
	layoutDivers->addWidget(c_lutte,5,1);
	
	//Création des labels
	l_bba = new QLabel("BBA:");
	l_initiative = new QLabel("Initiative:");
	l_vitesse = new QLabel("VD:");
	l_res_mag = new QLabel("Résist. magie:");
	l_reduc_deg = new QLabel("Réduc. dégâts:");
	l_lutte = new QLabel("Lutte:");
		//Positionnement
	l_bba->setAlignment(Qt::AlignRight);
	l_initiative->setAlignment(Qt::AlignRight);
	l_vitesse->setAlignment(Qt::AlignRight);
	l_res_mag->setAlignment(Qt::AlignRight);
	l_reduc_deg->setAlignment(Qt::AlignLeft);
	l_lutte->setAlignment(Qt::AlignRight);
	
	//Placement des labels dans le layout
	layoutDivers->addWidget(l_bba,0,0);
	layoutDivers->addWidget(l_initiative,1,0);
	layoutDivers->addWidget(l_vitesse,2,0);
	layoutDivers->addWidget(l_res_mag,3,0);
	layoutDivers->addWidget(l_reduc_deg,4,0);
	layoutDivers->addWidget(l_lutte,5,0);
	
//Partie PV/CA

	//Création des champs
	c_tot_pv = new LineEdit("PV");
	c_rest_pv = new LineEdit("PV restants");
	c_non_letal = new LineEdit("Dégats non létaux");
	c_attaque_contact_ca = new LineEdit("CA contact");
	c_depourvu_ca = new LineEdit("CA dépourvu");
	c_tot_ca = new LineEdit("CA");
	c_armure_ca = new LineEdit("Armure");
	c_bouclier_ca = new LineEdit("Bouclier");
	c_mod_dex_ca = new LineEdit("Mod. de dex");
		c_mod_dex_ca->setReadOnly(true);
		c_mod_dex_ca->setText("0");
	c_mod_taille_ca = new LineEdit("Mod. de taille");
	c_arm_naturelle_ca = new LineEdit("Armure naturelle");
	c_mod_parade_ca = new LineEdit("Mod. parade");
	c_mod_divers_ca = new LineEdit("Mod. divers CA");
	
	//Placement des champs dans le layout
	layoutPVCA->addWidget(c_tot_pv,1,1);
	layoutPVCA->addWidget(c_rest_pv,1,3);
	layoutPVCA->addWidget(c_non_letal,1,5,1,3);
	layoutPVCA->addWidget(c_attaque_contact_ca,1,10,1,3);
	layoutPVCA->addWidget(c_depourvu_ca,1,13,1,3);
	layoutPVCA->addWidget(c_tot_ca,2,1);
	layoutPVCA->addWidget(c_armure_ca,2,3);
	layoutPVCA->addWidget(c_bouclier_ca,2,5);
	layoutPVCA->addWidget(c_mod_dex_ca,2,7);
	layoutPVCA->addWidget(c_mod_taille_ca,2,9);
	layoutPVCA->addWidget(c_arm_naturelle_ca,2,11);
	layoutPVCA->addWidget(c_mod_parade_ca,2,13);
	layoutPVCA->addWidget(c_mod_divers_ca,2,15);
	
	//Création des labels
	l_pv = new QLabel("PV");
	l_ca = new QLabel("CA");
	l_tot_pv = new QLabel("TOTAL");
	l_rest_pv = new QLabel("Restants");
	l_non_letal = new QLabel("Dégâts non-létaux");
	l_attaque_contact_ca = new QLabel("CA attaques de contact");
	l_depourvu_ca = new QLabel("CA pris au dépourvu");
	l_tot_ca = new QLabel("TOTAL");
	l_armure_ca = new QLabel("Armure");
	l_bouclier_ca = new QLabel("Bouclier");
	l_mod_dex_ca = new QLabel("Dex");
	l_mod_taille_ca = new QLabel("Taille");
	l_arm_naturelle_ca = new QLabel("Armure naturelle");
	l_mod_parade_ca = new QLabel("Parade");
	l_mod_divers_ca = new QLabel("Divers");
	
	//Placement des labels dans le layout
	layoutPVCA->addWidget(l_pv,1,0);
	layoutPVCA->addWidget(l_ca,2,0);
	layoutPVCA->addWidget(l_tot_pv,0,1);
	layoutPVCA->addWidget(l_rest_pv,0,3);
	layoutPVCA->addWidget(l_non_letal,0,5,1,3);
	layoutPVCA->addWidget(l_attaque_contact_ca,0,10,1,3);
	layoutPVCA->addWidget(l_depourvu_ca,0,13,1,3);
	layoutPVCA->addWidget(l_tot_ca,3,1);
	layoutPVCA->addWidget(l_armure_ca,3,3);
	layoutPVCA->addWidget(l_bouclier_ca,3,5);
	layoutPVCA->addWidget(l_mod_dex_ca,3,7);
	layoutPVCA->addWidget(l_mod_taille_ca,3,9);
	layoutPVCA->addWidget(l_arm_naturelle_ca,3,11);
	layoutPVCA->addWidget(l_mod_parade_ca,3,13);
	layoutPVCA->addWidget(l_mod_divers_ca,3,15);
	
	//Placement des + et des = entre les champs
	layoutPVCA->addWidget(new QLabel(" = 10 + "),2,2);
	layoutPVCA->addWidget(new QLabel("+"),2,4);
	layoutPVCA->addWidget(new QLabel("+"),2,6);
	layoutPVCA->addWidget(new QLabel("+"),2,8);
	layoutPVCA->addWidget(new QLabel("+"),2,10);
	layoutPVCA->addWidget(new QLabel("+"),2,12);
	layoutPVCA->addWidget(new QLabel("+"),2,14);
	
	//Connexion des signaux/slots
	connect(c_dex_mod,SIGNAL(textChanged(const QString &)),c_mod_dex_ca,SLOT(setText(const QString &)));

//Partie sauvegardes

	//Création des champs
	c_tot_ref = new LineEdit();
	c_base_ref = new LineEdit();
	c_carac_ref = new LineEdit();
		c_carac_ref->setReadOnly(true);
		c_carac_ref->setText("0");
	c_magie_ref = new LineEdit();
	c_divers_ref = new LineEdit();
	c_tmp_ref = new LineEdit();
	c_tot_vig = new LineEdit();
	c_base_vig = new LineEdit();
	c_carac_vig = new LineEdit();
		c_carac_vig->setReadOnly(true);
		c_carac_vig->setText("0");
	c_magie_vig = new LineEdit();
	c_divers_vig = new LineEdit();
	c_tmp_vig = new LineEdit();
	c_tot_vol = new LineEdit();
	c_base_vol = new LineEdit();
	c_carac_vol = new LineEdit();
		c_carac_vol->setReadOnly(true);
		c_carac_vol->setText("0");
	c_magie_vol = new LineEdit();
	c_divers_vol = new LineEdit();
	c_tmp_vol = new LineEdit();
	
	//Placement des champs dans le layout
	layoutSauvegardes->addWidget(c_tot_ref,1,1);
	layoutSauvegardes->addWidget(c_base_ref,1,3);
	layoutSauvegardes->addWidget(c_carac_ref,1,5);
	layoutSauvegardes->addWidget(c_magie_ref,1,7);
	layoutSauvegardes->addWidget(c_divers_ref,1,9);
	layoutSauvegardes->addWidget(c_tmp_ref,1,11);
	layoutSauvegardes->addWidget(c_tot_vig,2,1);
	layoutSauvegardes->addWidget(c_base_vig,2,3);
	layoutSauvegardes->addWidget(c_carac_vig,2,5);
	layoutSauvegardes->addWidget(c_magie_vig,2,7);
	layoutSauvegardes->addWidget(c_divers_vig,2,9);
	layoutSauvegardes->addWidget(c_tmp_vig,2,11);
	layoutSauvegardes->addWidget(c_tot_vol,3,1);
	layoutSauvegardes->addWidget(c_base_vol,3,3);
	layoutSauvegardes->addWidget(c_carac_vol,3,5);
	layoutSauvegardes->addWidget(c_magie_vol,3,7);
	layoutSauvegardes->addWidget(c_divers_vol,3,9);
	layoutSauvegardes->addWidget(c_tmp_vol,3,11);
	
	//Création des labels
	l_sauvegarde = new QLabel("Sauvegardes");
	l_total = new QLabel("TOTAL");
	l_base = new QLabel("Bonus de base");
	l_mod_carac = new QLabel("Mod. de carac.");
	l_magie = new QLabel("Mod. magique");
	l_divers = new QLabel("Mod. divers");
	l_tmp = new QLabel("Mod. temporaires");
	l_ref = new QLabel("REFLEXES (dex)");
	l_vig = new QLabel("VIGEUR (con)");
	l_vol = new QLabel("VOLONTE (sag)");

	//Placement des labels dans le layout
	layoutSauvegardes->addWidget(l_sauvegarde,0,0);
	layoutSauvegardes->addWidget(l_total,0,1);
	layoutSauvegardes->addWidget(l_base,0,3);
	layoutSauvegardes->addWidget(l_mod_carac,0,5);
	layoutSauvegardes->addWidget(l_magie,0,7);
	layoutSauvegardes->addWidget(l_divers,0,9);
	layoutSauvegardes->addWidget(l_tmp,0,11);
	layoutSauvegardes->addWidget(l_ref,1,0);
	layoutSauvegardes->addWidget(l_vig,2,0);
	layoutSauvegardes->addWidget(l_vol,3,0);
	
	//Placement des + et = entre les champs
	layoutSauvegardes->addWidget(new QLabel("+"),1,4);
	layoutSauvegardes->addWidget(new QLabel("+"),1,6);
	layoutSauvegardes->addWidget(new QLabel("+"),1,8);
	layoutSauvegardes->addWidget(new QLabel("+"),1,10);
	layoutSauvegardes->addWidget(new QLabel("+"),2,4);
	layoutSauvegardes->addWidget(new QLabel("+"),2,6);
	layoutSauvegardes->addWidget(new QLabel("+"),2,8);
	layoutSauvegardes->addWidget(new QLabel("+"),2,10);
	layoutSauvegardes->addWidget(new QLabel("+"),3,4);
	layoutSauvegardes->addWidget(new QLabel("+"),3,6);
	layoutSauvegardes->addWidget(new QLabel("+"),3,8);
	layoutSauvegardes->addWidget(new QLabel("+"),3,10);
	layoutSauvegardes->addWidget(new QLabel("="),1,2);
	layoutSauvegardes->addWidget(new QLabel("="),2,2);
	layoutSauvegardes->addWidget(new QLabel("="),3,2);
	
	//Connexion des signaux/slots
	connect(c_dex_mod,SIGNAL(textChanged(const QString &)),c_carac_ref,SLOT(setText(const QString &)));
	connect(c_con_mod,SIGNAL(textChanged(const QString &)),c_carac_vig,SLOT(setText(const QString &)));
	connect(c_sag_mod,SIGNAL(textChanged(const QString &)),c_carac_vol,SLOT(setText(const QString &)));
	
//Mise en page

	//Création des QFrame(traits de séparation)
	f_separation1 = new QFrame();
		f_separation1->setFrameStyle(QFrame::HLine | QFrame::Plain);
	f_separation2 = new QFrame();
		f_separation2->setFrameStyle(QFrame::HLine | QFrame::Plain);
	f_separation3 = new QFrame();
		f_separation3->setFrameStyle(QFrame::VLine | QFrame::Plain);
	f_separation4 = new QFrame();
		f_separation4->setFrameStyle(QFrame::HLine | QFrame::Plain);
	//Placement des QFrame dans le layout
	layoutPrincipal->addWidget(f_separation1,1,0,1,-1);
	layoutPrincipal->addWidget(f_separation2,3,0,1,-1);
	layoutPrincipal->addWidget(f_separation3,1,1,3,1);
	layoutPrincipal->addWidget(f_separation4,5,0,1,-1);
	
	//Application des layout
	layoutPrincipal->addLayout(layoutInfos,0,0,1,-1);
	layoutPrincipal->addLayout(layoutStats,2,0,1,1);
	layoutPrincipal->addLayout(layoutDivers,2,2,1,1);
	layoutPrincipal->addLayout(layoutPVCA,4,0,1,-1);
	layoutPrincipal->addLayout(layoutSauvegardes,6,0,1,-1);
	this->setLayout(layoutPrincipal);
	
	//Connection des slots
	connect(boutonAjoutClasse,SIGNAL(clicked()),this,SLOT(ajoutClasse()));
	connect(boutonRetraitClasse,SIGNAL(clicked()),this,SLOT(retraitClasse()));
	
	connect(&xmlManager,SIGNAL(requestCaracsSave()),this,SLOT(receiveSaveRequest()));
	connect(this,SIGNAL(saveDone()),&xmlManager,SLOT(caracsSaved()));
	
	/* Modèle de connexion pour afficher des infos sur un LineEdit
	connect(c_nom,SIGNAL(infosToDisplay(QString)),this,SLOT(transmissionAffichageInfos(QString)));
	connect(c_nom,SIGNAL(finAffichageInfos()),this,SLOT(transmissionFinAffichageInfos()));*/
}

void Caracs::setClassList(QComboBox* comboBox)
{
	 if(dataManager.connexion())
     {
     	if(dataManager.requete->exec("select nom from classes"))
		{
			while(dataManager.requete->next())
				comboBox->addItem(dataManager.requete->value(0).toString());
		}
     	dataManager.deconnexion();
     }
}

void Caracs::setRaceList()
{
	 if(dataManager.connexion())
     {
     	if(dataManager.requete->exec("select nom from races"))
		{
			while(dataManager.requete->next())
				c_race->addItem(dataManager.requete->value(0).toString());
		}
     	dataManager.deconnexion();
     }
}

void Caracs::setDivinityList()
{
	 if(dataManager.connexion())
     {
     	if(dataManager.requete->exec("select nom from divinites"))
		{
			while(dataManager.requete->next())
				c_divinite->addItem(dataManager.requete->value(0).toString());
		}
     	dataManager.deconnexion();
     }
}

void Caracs::setAlignmentList()
{
	 if(dataManager.connexion())
     {
     	if(dataManager.requete->exec("select nom from alignements"))
		{
			while(dataManager.requete->next())
				c_alignement->addItem(dataManager.requete->value(0).toString());
		}
     	dataManager.deconnexion();
     }
}

void Caracs::setSizeCategory()
{
	if(dataManager.connexion())
     {
     	if(dataManager.requete->exec("select nom from categoriesTailles"))
		{
			while(dataManager.requete->next())
				c_categorieTaille->addItem(dataManager.requete->value(0).toString());
		}
     	dataManager.deconnexion();
     }
}

void Caracs::ajoutClasse()
{
	nbClasses++;

	QComboBox* classe = new QComboBox(this);
	setClassList(classe);
	c_classe.push_back(classe);
	
	QSpinBox* niveau = new QSpinBox(this);
	niveau->setMinimum(1);
	niveau->setMaximum(lvlMax);
	c_niveau.push_back(niveau);
	
	layoutClasses->addWidget(classe);
	layoutClasses->addWidget(niveau);
}

void Caracs::retraitClasse()
{
	if(nbClasses > 1)
	{
		layoutClasses->removeWidget(c_classe[nbClasses-1]);
		layoutClasses->removeWidget(c_niveau[nbClasses-1]);
		
		
		c_classe[nbClasses-1]->deleteLater();
		c_niveau[nbClasses-1]->deleteLater();
		
		nbClasses--;
	
		c_classe.pop_back();
		c_niveau.pop_back();		
	}
}

void Caracs::calculModFor(int val)
{
	int newVal = (val-10)/2;
	if(val < 10 && val%2 != 0)
		newVal--;
	c_for_mod->setText(QString::number(newVal));
	
	emit modForChanged(newVal);
}

void Caracs::calculModDex(int val)
{
	int newVal = (val-10)/2;
	if(val < 10 && val%2 != 0)
		newVal--;
	c_dex_mod->setText(QString::number(newVal));
	
	emit modDexChanged(newVal);
}

void Caracs::calculModCon(int val)
{
	int newVal = (val-10)/2;
	if(val < 10 && val%2 != 0)
		newVal--;
	c_con_mod->setText(QString::number(newVal));
	
	emit modConChanged(newVal);
}

void Caracs::calculModInt(int val)
{
	int newVal = (val-10)/2;
	if(val < 10 && val%2 != 0)
		newVal--;
	c_int_mod->setText(QString::number(newVal));
	
	emit modIntChanged(newVal);
}

void Caracs::calculModSag(int val)
{
	int newVal = (val-10)/2;
	if(val < 10 && val%2 != 0)
		newVal--;
	c_sag_mod->setText(QString::number(newVal));
	
	emit modSagChanged(newVal);
}

void Caracs::calculModCha(int val)
{
	int newVal = (val-10)/2;
	if(val < 10 && val%2 != 0)
		newVal--;
	c_cha_mod->setText(QString::number(newVal));
	
	emit modChaChanged(newVal);
}

void Caracs::transmissionAffichageInfos(QString cible)
{
	std::vector<QString> champs;
	std::vector<int> vals;
	
	champs.push_back(cible);
	
	/*switch(cible)
	{
		récupération des valeurs à envoyer
	}*/
	
	champs.push_back("ch1");
	champs.push_back("ch2");
	champs.push_back("ch3");
	
	vals.push_back(9);
	vals.push_back(2);
	vals.push_back(3);
	vals.push_back(4);
	
	

	emit infosToDisplay(champs, vals);
}

void Caracs::transmissionFinAffichageInfos()
{
	emit finAffichageInfos();
}

void Caracs::receiveSaveRequest()
{
	QDomElement elem;
	QDomAttr a;
	
	elem = xmlManager.getCaracteristiques().firstChildElement("nomPersonnage");
	a = elem.attributeNode("value");
	a.setValue(c_nom->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("nomJoueur");
	a = elem.attributeNode("value");
	a.setValue(c_joueur->text());
		// liste des classes et combo boxes
	

	elem = xmlManager.getCaracteristiques().firstChildElement("for");
	a = elem.attributeNode("value");
	a.setValue(QString::number(c_for_score->value()));
	
	elem = xmlManager.getCaracteristiques().firstChildElement("dex");
	a = elem.attributeNode("value");
	a.setValue(QString::number(c_dex_score->value()));
	
	elem = xmlManager.getCaracteristiques().firstChildElement("con");
	a = elem.attributeNode("value");
	a.setValue(QString::number(c_con_score->value()));
	
	elem = xmlManager.getCaracteristiques().firstChildElement("int");
	a = elem.attributeNode("value");
	a.setValue(QString::number(c_int_score->value()));
	
	elem = xmlManager.getCaracteristiques().firstChildElement("sag");
	a = elem.attributeNode("value");
	a.setValue(QString::number(c_sag_score->value()));
	
	elem = xmlManager.getCaracteristiques().firstChildElement("cha");
	a = elem.attributeNode("value");
	a.setValue(QString::number(c_cha_score->value()));
	
	elem = xmlManager.getCaracteristiques().firstChildElement("forTmp");
	a = elem.attributeNode("value");
	a.setValue(c_for_score_tmp->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("dexTmp");
	a = elem.attributeNode("value");
	a.setValue(c_dex_score_tmp->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("conTmp");
	a = elem.attributeNode("value");
	a.setValue(c_con_score_tmp->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("intTmp");
	a = elem.attributeNode("value");
	a.setValue(c_int_score_tmp->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("sagTmp");
	a = elem.attributeNode("value");
	a.setValue(c_sag_score_tmp->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("chaTmp");
	a = elem.attributeNode("value");
	a.setValue(c_cha_score_tmp->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("bba");
	a = elem.attributeNode("value");
	a.setValue(c_bba->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("initiative");
	a = elem.attributeNode("value");
	a.setValue(c_initiative->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("vd");
	a = elem.attributeNode("value");
	a.setValue(c_vitesse->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("resistanceMagie");
	a = elem.attributeNode("value");
	a.setValue(c_res_mag->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("reductionDegats");
	a = elem.attributeNode("value");
	a.setValue(c_reduc_deg->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("lutte");
	a = elem.attributeNode("value");
	a.setValue(c_lutte->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("pvTotal");
	a = elem.attributeNode("value");
	a.setValue(c_tot_pv->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("pvRestants");
	a = elem.attributeNode("value");
	a.setValue(c_rest_pv->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("degatsNonLetaux");
	a = elem.attributeNode("value");
	a.setValue(c_non_letal->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("caContact");
	a = elem.attributeNode("value");
	a.setValue(c_attaque_contact_ca->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("caDepourvu");
	a = elem.attributeNode("value");
	a.setValue(c_depourvu_ca->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("armure");
	a = elem.attributeNode("value");
	a.setValue(c_armure_ca->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("bouclier");
	a = elem.attributeNode("value");
	a.setValue(c_bouclier_ca->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("taille");
	a = elem.attributeNode("value");
	a.setValue(c_mod_taille_ca->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("armureNaturelle");
	a = elem.attributeNode("value");
	a.setValue(c_arm_naturelle_ca->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("parade");
	a = elem.attributeNode("value");
	a.setValue(c_mod_parade_ca->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("divers");
	a = elem.attributeNode("value");
	a.setValue(c_mod_divers_ca->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("baseReflexes");
	a = elem.attributeNode("value");
	a.setValue(c_base_ref->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("modMagiqueReflexes");
	a = elem.attributeNode("value");
	a.setValue(c_magie_ref->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("modDiversReflexes");
	a = elem.attributeNode("value");
	a.setValue(c_divers_ref->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("modTmpReflexes");
	a = elem.attributeNode("value");
	a.setValue(c_tmp_ref->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("baseVigueur");
	a = elem.attributeNode("value");
	a.setValue(c_base_vig->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("modMagiqueVigueur");
	a = elem.attributeNode("value");
	a.setValue(c_magie_vig->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("modDiversVigueur");
	a = elem.attributeNode("value");
	a.setValue(c_divers_vig->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("modTmpVigueur");
	a = elem.attributeNode("value");
	a.setValue(c_tmp_vig->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("baseVolonte");
	a = elem.attributeNode("value");
	a.setValue(c_base_vol->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("modMagiqueVolonte");
	a = elem.attributeNode("value");
	a.setValue(c_magie_vol->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("modDiversVolonte");
	a = elem.attributeNode("value");
	a.setValue(c_divers_vol->text());
	
	elem = xmlManager.getCaracteristiques().firstChildElement("modTmpVolonte");
	a = elem.attributeNode("value");
	a.setValue(c_tmp_vol->text());
	
	emit saveDone();
}
