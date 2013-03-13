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
	
	this->setMenuBar(barreMenu);
	
	// DockWidget, lanceur de dés
	dockWidget = new QDockWidget("Lanceur de dés", this);
	widgetDes = new DiceRoller();
	
	dockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dockWidget->setWidget(widgetDes);
	
	this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
	
	// Connexion signaux/slots
	connect(ongletCaracs,SIGNAL(modForChanged(int)),ongletCompetences,SLOT(modForChanged(int)));
	connect(ongletCaracs,SIGNAL(modDexChanged(int)),ongletCompetences,SLOT(modDexChanged(int)));
	connect(ongletCaracs,SIGNAL(modConChanged(int)),ongletCompetences,SLOT(modConChanged(int)));
	connect(ongletCaracs,SIGNAL(modIntChanged(int)),ongletCompetences,SLOT(modIntChanged(int)));
	connect(ongletCaracs,SIGNAL(modSagChanged(int)),ongletCompetences,SLOT(modSagChanged(int)));
	connect(ongletCaracs,SIGNAL(modChaChanged(int)),ongletCompetences,SLOT(modChaChanged(int)));
}

void MainWindow::afficherDiceRoller(bool state)
{
	if(state)
		restoreDockWidget(dockWidget);
	else
		removeDockWidget(dockWidget);
}
