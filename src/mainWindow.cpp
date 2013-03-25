#include "mainWindow.h"

MainWindow::MainWindow()
{
	this->setWindowIcon(QIcon("../Ressources/icone.png"));
	this->setWindowTitle("Feuille de personnage D&D 3.5");
	
	// Barre de menus
	barreMenu = new QMenuBar(this);
	menuFichier = new QMenu("Fichier");
	menuOutils = new QMenu("Outils");
	
	barreMenu->addMenu(menuFichier);
	barreMenu->addMenu(menuOutils);
	
	menuFichier->addAction("Nouveau personnage",this,SLOT(createNewSheet()));
	menuFichier->addAction("Sauvegarder personnage",this,SLOT(saveSheet()));
	menuFichier->addAction("Charger personnage",this,SLOT(loadSheet()));
	menuFichier->addAction("Quitter",this,SLOT(close()));
	
	this->setMenuBar(barreMenu);
	
	// Widget central
	QWidget * widgetCentral = new QWidget();
	
	QPushButton * nouveau = new QPushButton("Créer un nouveau personnage");
	QPushButton * charger = new QPushButton("Charger un personnage existant");
	QPushButton * later = new QPushButton("Choisir plus tard");
	QPushButton * quitter = new QPushButton("Quitter");
	QVBoxLayout * layoutTmp = new QVBoxLayout(widgetCentral);
	
	layoutTmp->addWidget(nouveau);
	layoutTmp->addWidget(charger);
	layoutTmp->addWidget(later);
	layoutTmp->addStretch();
	layoutTmp->addWidget(quitter);
	
	this->setCentralWidget(widgetCentral);
	
	// Manager de fichier XML
	connect(this,SIGNAL(requestSave()),&xmlManager,SLOT(receiveSaveRequest()));
	connect(this,SIGNAL(newSheetRequested()),&xmlManager,SLOT(createSheet()));
	
	// Connexion des signaux/slots
	connect(nouveau,SIGNAL(clicked()),this,SLOT(createNewSheet()));
	connect(charger,SIGNAL(clicked()),this,SLOT(loadSheet()));
	connect(later,SIGNAL(clicked()),this,SLOT(createEmptySheet()));
	connect(quitter,SIGNAL(clicked()),this,SLOT(close()));
}

void MainWindow::createNewSheet()
{
	createTabs();
	createInfosDisplayer();
	createDiceRoller();
	
	emit newSheetRequested();
}

void MainWindow::saveSheet()
{
	emit requestSave();
}

void MainWindow::loadSheet()
{

}

void MainWindow::createEmptySheet()
{

}

void MainWindow::createTabs()
{
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
	
	// Connexion des signaux/slots
	connect(ongletCaracs,SIGNAL(modForChanged(int)),ongletCompetences,SLOT(modForChanged(int)));
	connect(ongletCaracs,SIGNAL(modDexChanged(int)),ongletCompetences,SLOT(modDexChanged(int)));
	connect(ongletCaracs,SIGNAL(modConChanged(int)),ongletCompetences,SLOT(modConChanged(int)));
	connect(ongletCaracs,SIGNAL(modIntChanged(int)),ongletCompetences,SLOT(modIntChanged(int)));
	connect(ongletCaracs,SIGNAL(modSagChanged(int)),ongletCompetences,SLOT(modSagChanged(int)));
	connect(ongletCaracs,SIGNAL(modChaChanged(int)),ongletCompetences,SLOT(modChaChanged(int)));
}

void MainWindow::createDiceRoller()
{
	dockWidgetDes = new QDockWidget("Lanceur de dés", this);
	widgetDes = new DiceRoller();
	
	dockWidgetDes->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	dockWidgetDes->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dockWidgetDes->setWidget(widgetDes);
	
	this->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetDes);
	
	// Création de l'option d'affichage dans le menu
	action = menuOutils->addAction("Afficher le lanceur de dés");
	action->setCheckable(true);
	action->setChecked(true);
	connect(action,SIGNAL(toggled(bool)),this,SLOT(afficherDiceRoller(bool)));
}

void MainWindow::createInfosDisplayer()
{
	dockWidgetInfos = new QDockWidget("Informations", this);
	widgetInfos = new InfoWidget();
	
	dockWidgetInfos->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	dockWidgetInfos->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dockWidgetInfos->setWidget(widgetInfos);
	
	this->addDockWidget(Qt::LeftDockWidgetArea, dockWidgetInfos);
	
	// Création de l'option d'affichage dans le menu
	action = menuOutils->addAction("Afficher les informations");
	action->setCheckable(true);
	action->setChecked(true);
	connect(action,SIGNAL(toggled(bool)),this,SLOT(afficherInformations(bool)));
	
	// Connexion des signaux/slots
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

void MainWindow::receiveCaracsSave()
{

}

void MainWindow::receiveEquipementSave()
{

}

void MainWindow::receiveBackpackSave()
{

}

void MainWindow::receiveCompetencesSave()
{

}

void MainWindow::receiveDonsSave()
{

}

void MainWindow::receiveRoleplaySave()
{

}
