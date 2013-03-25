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
	liste << "Don" << "Prérequis" << "Effets" << "Notes";
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
	
	connect(&xmlManager,SIGNAL(requestDonsSave()),this,SLOT(receiveSaveRequest()));
	connect(this,SIGNAL(saveDone()),&xmlManager,SLOT(donsSaved()));
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

void Dons::receiveSaveRequest()
{
	QDomElement elem;
	QDomAttr a;
	
	elem = xmlManager.getDons().firstChildElement("raceClasses");
	while(!elem.firstChild().isNull())										// Suppression des anciennes lignes
	{
		elem.removeChild(elem.firstChild());
	}
	for(int i=0;i<bonus->rowCount();i++)
	{
		QDomElement ligneTableau = xmlManager.getDoc().createElement("ligne");
		ligneTableau.setAttribute("numero",i);
		elem.appendChild(ligneTableau);
		
		for(int j=0;j<bonus->columnCount();j++)
		{
			QDomElement elemLigne;
		
			if(bonus->horizontalHeaderItem(j)->text() == "Don/Bonus")
				elemLigne = xmlManager.getDoc().createElement("donBonus");
			else
				elemLigne = xmlManager.getDoc().createElement(bonus->horizontalHeaderItem(j)->text());
				
			if(bonus->item(i,j) == NULL)
				elemLigne.setAttribute("value","");
			else
				elemLigne.setAttribute("value",bonus->item(i,j)->text());
			ligneTableau.appendChild(elemLigne);
		}
	}
	
	elem = xmlManager.getDons().firstChildElement("normaux");
	while(!elem.firstChild().isNull())										// Suppression des anciennes lignes
	{
		elem.removeChild(elem.firstChild());
	}
	for(int i=0;i<dons->rowCount();i++)
	{
		QDomElement ligneTableau = xmlManager.getDoc().createElement("ligne");
		ligneTableau.setAttribute("numero",i);
		elem.appendChild(ligneTableau);
		
		for(int j=0;j<dons->columnCount();j++)
		{
			QDomElement elemLigne;
		
			if(dons->horizontalHeaderItem(j)->text() == "Prérequis")
				elemLigne = xmlManager.getDoc().createElement("Prerequis");
			else
				elemLigne = xmlManager.getDoc().createElement(dons->horizontalHeaderItem(j)->text());
				
			if(dons->item(i,j) == NULL)
				elemLigne.setAttribute("value","");
			else
				elemLigne.setAttribute("value",dons->item(i,j)->text());
			ligneTableau.appendChild(elemLigne);
		}
	}
	
	emit saveDone();
}
