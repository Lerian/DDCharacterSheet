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
	liste << "Poids" << "Valeur" << "Maudit" << "Equipé" << "Objet" << "Toucher" << "Dégâts" << "Critique" << "Portée" << "Type" << "Informations";
	armes->setHorizontalHeaderLabels(liste);
	liste.clear();
	liste << "Poids" << "Valeur" << "Maudit" << "Equipé" << "Emplacement" << "Objet" << "CA" << "DEX max" << "Informations";
	armures->setHorizontalHeaderLabels(liste);
	liste.clear();
	liste << "Poids" << "Valeur" << "Maudit" << "Type" << "Equipé" << "Objet" << "Informations";
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

void Equipement::supprimerLigneArme()
{
	armes->setRowCount(armes->rowCount()-1);
}

void Equipement::ouvrirDialogArme()
{
	QDialog dialog(this);

	QLabel message("La dernière ligne du tableau contient des données.\nVoulez vous vraiment la supprimer?",&dialog);
	QPushButton oui("Oui",&dialog);
	oui.setCheckable(true);
	oui.setChecked(true);
	QPushButton non("Non",&dialog);
	non.setCheckable(true);
	QGridLayout layoutDialog(&dialog);
	layoutDialog.addWidget(&message,0,0,1,4);
	layoutDialog.addWidget(&oui,1,1);
	layoutDialog.addWidget(&non,1,2);
	
	connect(&oui,SIGNAL(clicked()),this,SLOT(supprimerLigneArme()));
	connect(&oui,SIGNAL(clicked()),&dialog,SLOT(close()));
	connect(&non,SIGNAL(clicked()),&dialog,SLOT(close()));
	
	dialog.exec();
}

void Equipement::retraitLigneArme()
{
	bool vide = true;
	
	for(int i = 0;i < armes->columnCount();i++)
	{
		bool noWidget = armes->item(armes->rowCount()-1,i) == NULL;
		if(!noWidget)
			noWidget = armes->item(armes->rowCount()-1,i)->text() == "";
		vide = vide && noWidget;
	}
	if(vide)
		supprimerLigneArme();
	else
		ouvrirDialogArme();
}

void Equipement::ajoutLigneArmure()
{
	armures->setRowCount(armures->rowCount()+1);
}

void Equipement::supprimerLigneArmure()
{
	armures->setRowCount(armures->rowCount()-1);
}

void Equipement::ouvrirDialogArmure()
{
	QDialog dialog(this);

	QLabel message("La dernière ligne du tableau contient des données.\nVoulez vous vraiment la supprimer?",&dialog);
	QPushButton oui("Oui",&dialog);
	oui.setCheckable(true);
	oui.setChecked(true);
	QPushButton non("Non",&dialog);
	non.setCheckable(true);
	QGridLayout layoutDialog(&dialog);
	layoutDialog.addWidget(&message,0,0,1,4);
	layoutDialog.addWidget(&oui,1,1);
	layoutDialog.addWidget(&non,1,2);
	
	connect(&oui,SIGNAL(clicked()),this,SLOT(supprimerLigneArmure()));
	connect(&oui,SIGNAL(clicked()),&dialog,SLOT(close()));
	connect(&non,SIGNAL(clicked()),&dialog,SLOT(close()));
	
	dialog.exec();
}

void Equipement::retraitLigneArmure()
{
	bool vide = true;
	
	for(int i = 0;i < armures->columnCount();i++)
	{
		bool noWidget = armures->item(armures->rowCount()-1,i) == NULL;
		if(!noWidget)
			noWidget = armures->item(armures->rowCount()-1,i)->text() == "";
		vide = vide && noWidget;
	}
	if(vide)
		supprimerLigneArmure();
	else
		ouvrirDialogArmure();
}

void Equipement::ajoutLigneObjet()
{
	objets->setRowCount(objets->rowCount()+1);
}

void Equipement::supprimerLigneObjet()
{
	objets->setRowCount(objets->rowCount()-1);
}

void Equipement::ouvrirDialogObjet()
{
	QDialog dialog(this);

	QLabel message("La dernière ligne du tableau contient des données.\nVoulez vous vraiment la supprimer?",&dialog);
	QPushButton oui("Oui",&dialog);
	oui.setCheckable(true);
	oui.setChecked(true);
	QPushButton non("Non",&dialog);
	non.setCheckable(true);
	QGridLayout layoutDialog(&dialog);
	layoutDialog.addWidget(&message,0,0,1,4);
	layoutDialog.addWidget(&oui,1,1);
	layoutDialog.addWidget(&non,1,2);
	
	connect(&oui,SIGNAL(clicked()),this,SLOT(supprimerLigneObjet()));
	connect(&oui,SIGNAL(clicked()),&dialog,SLOT(close()));
	connect(&non,SIGNAL(clicked()),&dialog,SLOT(close()));
	
	dialog.exec();
}

void Equipement::retraitLigneObjet()
{
	bool vide = true;
	
	for(int i = 0;i < objets->columnCount();i++)
	{
		bool noWidget = objets->item(objets->rowCount()-1,i) == NULL;
		if(!noWidget)
			noWidget = objets->item(objets->rowCount()-1,i)->text() == "";
		vide = vide && noWidget;
	}
	if(vide)
		supprimerLigneObjet();
	else
		ouvrirDialogObjet();
}
