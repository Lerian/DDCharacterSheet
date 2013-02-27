#include "dons.h"

Dons::Dons()
{	
	//Création de la bande bonus
	boutonAjoutBonus = new QPushButton("+");
		boutonAjoutBonus->setFixedWidth(25);
	boutonRetraitBonus = new QPushButton("-");
		boutonRetraitBonus->setFixedWidth(25);
	ligne1 = new QFrame();
		ligne1->setFrameStyle(QFrame::HLine | QFrame::Plain);
	l_bonus = new QLabel("Bonus raciaux et de classe");
		l_bonus->setAlignment(Qt::AlignCenter);
		l_bonus->setFixedWidth(175);
	ligne2 = new QFrame();
		ligne2->setFrameStyle(QFrame::HLine | QFrame::Plain);
	
	layoutBandeBonus = new QHBoxLayout();
		layoutBandeBonus->addWidget(boutonAjoutBonus);
		layoutBandeBonus->addWidget(boutonRetraitBonus);
		layoutBandeBonus->addWidget(ligne1);
		layoutBandeBonus->addWidget(l_bonus);
		layoutBandeBonus->addWidget(ligne2);
		
	//Création du tableau bonus
	bonus = new QTableWidget();
		bonus->setRowCount(2);
		bonus->setColumnCount(3);	
	QStringList liste;
	liste << "Don/Bonus" << "Effets" << "Informations";
	bonus->setHorizontalHeaderLabels(liste);
	
	//Création de la bande dons
	boutonAjoutDon = new QPushButton("+");
		boutonAjoutDon->setFixedWidth(25);
	boutonRetraitDon = new QPushButton("-");
		boutonRetraitDon->setFixedWidth(25);
	ligne3 = new QFrame();
		ligne3->setFrameStyle(QFrame::HLine | QFrame::Plain);
	l_dons = new QLabel("Dons");
		l_dons->setAlignment(Qt::AlignCenter);
		l_dons->setFixedWidth(50);
	ligne4 = new QFrame();
		ligne4->setFrameStyle(QFrame::HLine | QFrame::Plain);
		
	layoutBandeDons = new QHBoxLayout();
		layoutBandeDons->addWidget(boutonAjoutDon);
		layoutBandeDons->addWidget(boutonRetraitDon);
		layoutBandeDons->addWidget(ligne3);
		layoutBandeDons->addWidget(l_dons);
		layoutBandeDons->addWidget(ligne4);
	
	//Création du tableau dons
	dons = new QTableWidget();
		dons->setRowCount(2);
		dons->setColumnCount(4);
	liste.clear();
	liste << "Don" << "Prerequis" << "Effets" << "Notes";
	dons->setHorizontalHeaderLabels(liste);
		
	//Création du layout principal
	layout = new QVBoxLayout(this);
		layout->addLayout(layoutBandeBonus);
		layout->addWidget(bonus);
		layout->addLayout(layoutBandeDons);
		layout->addWidget(dons);

	//Connexion des signaux/slots
	connect(boutonAjoutBonus,SIGNAL(clicked()),this,SLOT(ajoutLigneBonus()));
	connect(boutonRetraitBonus,SIGNAL(clicked()),this,SLOT(retraitLigneBonus()));
	connect(boutonAjoutDon,SIGNAL(clicked()),this,SLOT(ajoutLigneDons()));
	connect(boutonRetraitDon,SIGNAL(clicked()),this,SLOT(retraitLigneDons()));
}

void Dons::ajoutLigneBonus()
{
	bonus->setRowCount(bonus->rowCount()+1);
}

void Dons::retraitLigneBonus()
{
	bonus->setRowCount(bonus->rowCount()-1);
}

void Dons::ajoutLigneDons()
{
	dons->setRowCount(dons->rowCount()+1);
}

void Dons::retraitLigneDons()
{
	dons->setRowCount(dons->rowCount()-1);
}
