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
	
	menuOnglets->addTab(ongletCaracs,"Caracteristiques");
	menuOnglets->addTab(ongletEquipement,"Equipement");
	menuOnglets->addTab(ongletSac,"Sac a dos");
	menuOnglets->addTab(ongletCompetences,"Competences");
	menuOnglets->addTab(ongletDons,"Dons");
	menuOnglets->addTab(ongletRP,"RolePlay");
	
	this->setCentralWidget(menuOnglets);
	
	//DockWidget, lanceur de dés
	dockWidget = new QDockWidget("Dice roller", this);
	widgetDes = new DiceRoller();
	
	dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dockWidget->setWidget(widgetDes);
	
	this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
}
