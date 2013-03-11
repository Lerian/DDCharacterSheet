#include "mainWindow.h"

MainWindow::MainWindow()
{
	this->setWindowIcon(QIcon("Ressources/icone.png"));
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
	
	menuOutils->addAction("Afficher le dice roller",this,SLOT(afficheDiceRoller()));
	menuOutils->addAction("Enlever le dice roller",this,SLOT(cacheDiceRoller()));
	
	this->setMenuBar(barreMenu);
	
	// DockWidget, lanceur de dés
	dockWidget = new QDockWidget("Dice roller", this);
	widgetDes = new DiceRoller();
	
	dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dockWidget->setWidget(widgetDes);
	
	this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
}

void MainWindow::afficheDiceRoller()
{
	restoreDockWidget(dockWidget);
}

void MainWindow::cacheDiceRoller()
{
	removeDockWidget(dockWidget);
}
