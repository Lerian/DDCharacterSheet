#include "equipement.h"

Equipement::Equipement()
{
	armes = new QTableWidget(this);
	armures = new QTableWidget(this);
	objets = new QTableWidget(this);
	
	armes->setColumnCount(11);
	armes->setRowCount(4);
	armures->setColumnCount(9);
	armures->setRowCount(4);
	objets->setColumnCount(7);
	objets->setRowCount(4);
	
	QStringList liste;
	// Création des en-tête
	liste << "Poids" << "Valeur" << "Maudit" << "Equipe" << "Objet" << "Touche" << "Degats" << "Critique" << "Portee" << "Type" << "Informations";
	armes->setHorizontalHeaderLabels(liste);
	liste.clear();
	liste << "Poids" << "Valeur" << "Maudit" << "Equipe" << "Emplacement" << "Objet" << "CA" << "DEX max" << "Informations";
	armures->setHorizontalHeaderLabels(liste);
	liste.clear();
	liste << "Poids" << "Valeur" << "Maudit" << "Type" << "Equipe" << "Objet" << "Informations";
	objets->setHorizontalHeaderLabels(liste);
	
	//Création des boutons
	boutonAjoutArme = new QPushButton("+");
	boutonAjoutArme->setFixedWidth(25);
	boutonRetraitArme = new QPushButton("-");
	boutonRetraitArme->setFixedWidth(25);
	boutonAjoutArmure = new QPushButton("+");
	boutonAjoutArmure->setFixedWidth(25);
	boutonRetraitArmure = new QPushButton("-");
	boutonRetraitArmure->setFixedWidth(25);
	boutonAjoutObjet = new QPushButton("+");
	boutonAjoutObjet->setFixedWidth(25);
	boutonRetraitObjet = new QPushButton("-");
	boutonRetraitObjet->setFixedWidth(25);
	// Création des traits
	trait1Armes = new QFrame();
		trait1Armes->setFrameStyle(QFrame::HLine | QFrame::Plain);
	trait2Armes = new QFrame();
		trait2Armes->setFrameStyle(QFrame::HLine | QFrame::Plain);
	trait1Armures = new QFrame();
		trait1Armures->setFrameStyle(QFrame::HLine | QFrame::Plain);
	trait2Armures = new QFrame();
		trait2Armures->setFrameStyle(QFrame::HLine | QFrame::Plain);
	trait1Objets = new QFrame();
		trait1Objets->setFrameStyle(QFrame::HLine | QFrame::Plain);
	trait2Objets = new QFrame();
		trait2Objets->setFrameStyle(QFrame::HLine | QFrame::Plain);
	// Création des labels
	l_arme = new QLabel("Armes");
		l_arme->setFixedWidth(50);
		l_arme->setAlignment(Qt::AlignCenter);
	l_armure = new QLabel("Armures");
		l_armure->setFixedWidth(75);
		l_armure->setAlignment(Qt::AlignCenter);
	l_objet = new QLabel("Objets");
		l_objet->setFixedWidth(50);
		l_objet->setAlignment(Qt::AlignCenter);
	// Création des layouts horizontaux
	layoutArme = new QHBoxLayout();
	layoutArmure = new QHBoxLayout();
	layoutObjet = new QHBoxLayout();
	// Remplissage des layouts horizontaux
	layoutArme->addWidget(boutonAjoutArme);
	layoutArme->addWidget(boutonRetraitArme);
	layoutArme->addWidget(trait1Armes);
	layoutArme->addWidget(l_arme);
	layoutArme->addWidget(trait2Armes);
	layoutArmure->addWidget(boutonAjoutArmure);
	layoutArmure->addWidget(boutonRetraitArmure);
	layoutArmure->addWidget(trait1Armures);
	layoutArmure->addWidget(l_armure);
	layoutArmure->addWidget(trait2Armures);
	layoutObjet->addWidget(boutonAjoutObjet);
	layoutObjet->addWidget(boutonRetraitObjet);
	layoutObjet->addWidget(trait1Objets);
	layoutObjet->addWidget(l_objet);
	layoutObjet->addWidget(trait2Objets);
	
	
	layout = new QGridLayout(this);
	layout->addLayout(layoutArme,0,0);
	layout->addWidget(armes,1,0,1,-1);
	layout->addLayout(layoutArmure,2,0);
	layout->addWidget(armures,3,0,1,-1);
	layout->addLayout(layoutObjet,4,0);
	layout->addWidget(objets,5,0,1,-1);
	
	//Connection des signaux/slots
	connect(boutonAjoutArme, SIGNAL(clicked()),this, SLOT(ajoutLigneArme()));
	connect(boutonRetraitArme, SIGNAL(clicked()),this, SLOT(retraitLigneArme()));
	connect(boutonAjoutArmure, SIGNAL(clicked()),this, SLOT(ajoutLigneArmure()));
	connect(boutonRetraitArmure, SIGNAL(clicked()),this, SLOT(retraitLigneArmure()));
	connect(boutonAjoutObjet, SIGNAL(clicked()),this, SLOT(ajoutLigneObjet()));
	connect(boutonRetraitObjet, SIGNAL(clicked()),this, SLOT(retraitLigneObjet()));
}

void Equipement::ajoutLigneArme()
{
	armes->setRowCount(armes->rowCount()+1);
}

void Equipement::retraitLigneArme()
{
	armes->setRowCount(armes->rowCount()-1);
}

void Equipement::ajoutLigneArmure()
{
	armures->setRowCount(armures->rowCount()+1);
}

void Equipement::retraitLigneArmure()
{
	armures->setRowCount(armures->rowCount()-1);
}

void Equipement::ajoutLigneObjet()
{
	objets->setRowCount(objets->rowCount()+1);
}

void Equipement::retraitLigneObjet()
{
	objets->setRowCount(objets->rowCount()-1);
}
