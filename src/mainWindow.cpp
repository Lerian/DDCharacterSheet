#include "mainWindow.h"

MainWindow::MainWindow()
{
	this->setWindowIcon(QIcon("../Ressources/icone.png"));
	this->setWindowTitle("Feuille de personnage D&D 3.5");
	
	// Widget central, onglets des pages
	menuOnglets = new QTabWidget();
	ongletCaracs = new Caracs();
	ongletEquipement = new Equipement();
	ongletSac = new Sac();
	ongletCompetences = new Competences();
	ongletDons = new Dons();
	ongletRP = new RolePlay();
	
	menuOnglets->addTab(ongletCaracs,"Caractéristiques");
	menuOnglets->addTab(ongletEquipement,"Equipement");
	menuOnglets->addTab(ongletSac,"Sac à dos");
	menuOnglets->addTab(ongletCompetences,"Compétences");
	menuOnglets->addTab(ongletDons,"Dons");
	menuOnglets->addTab(ongletRP,"RolePlay");
	
	this->setCentralWidget(menuOnglets);
	
	// Barre de menus
	barreMenu = new QMenuBar(this);
	menuFichier = new QMenu("Fichier");
	menuOutils = new QMenu("Outils");
	
	barreMenu->addMenu(menuFichier);
	barreMenu->addMenu(menuOutils);
	
	menuFichier->addAction("Quitter",this,SLOT(close()));
	
	action = menuOutils->addAction("Afficher le lanceur de dés");
	action->setCheckable(true);
	action->setChecked(true);
	connect(action,SIGNAL(toggled(bool)),this,SLOT(afficherDiceRoller(bool)));
	
	action = menuOutils->addAction("Afficher les informations");
	action->setCheckable(true);
	action->setChecked(true);
	connect(action,SIGNAL(toggled(bool)),this,SLOT(afficherInformations(bool)));
	
	this->setMenuBar(barreMenu);
	
	// dockWidgetDes, lanceur de dés
	dockWidgetDes = new QDockWidget("Lanceur de dés", this);
	widgetDes = new DiceRoller();
	
	dockWidgetDes->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	dockWidgetDes->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dockWidgetDes->setWidget(widgetDes);
	
	this->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetDes);
	
	// dockWidgetInfos, affiche des infos sur les différents champs
	dockWidgetInfos = new QDockWidget("Informations", this);
	widgetInfos = new InfoWidget();
	
	dockWidgetInfos->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	dockWidgetInfos->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dockWidgetInfos->setWidget(widgetInfos);
	
	this->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetInfos);
	
	// Connexion signaux/slots
	connect(ongletCaracs,SIGNAL(modForChanged(int)),ongletCompetences,SLOT(modForChanged(int)));
	connect(ongletCaracs,SIGNAL(modDexChanged(int)),ongletCompetences,SLOT(modDexChanged(int)));
	connect(ongletCaracs,SIGNAL(modConChanged(int)),ongletCompetences,SLOT(modConChanged(int)));
	connect(ongletCaracs,SIGNAL(modIntChanged(int)),ongletCompetences,SLOT(modIntChanged(int)));
	connect(ongletCaracs,SIGNAL(modSagChanged(int)),ongletCompetences,SLOT(modSagChanged(int)));
	connect(ongletCaracs,SIGNAL(modChaChanged(int)),ongletCompetences,SLOT(modChaChanged(int)));
	
	connect(ongletCaracs,SIGNAL(infosToDisplay(std::vector<QString>, std::vector<int>)),widgetInfos,SLOT(afficheInfos(std::vector<QString>, std::vector<int>)));
	connect(ongletCaracs,SIGNAL(finAffichageInfos()),widgetInfos,SLOT(finAffichageInfos()));
}

void MainWindow::afficherDiceRoller(bool state)
{
	if(state)
		restoreDockWidget(dockWidgetDes);
	else
		removeDockWidget(dockWidgetDes);
}

void MainWindow::afficherInformations(bool state)
{
	if(state)
		restoreDockWidget(dockWidgetInfos);
	else
		removeDockWidget(dockWidgetInfos);
}
