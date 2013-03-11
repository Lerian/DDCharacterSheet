#include "sac.h"

Sac::Sac()
{
	chargeLegere = new QLineEdit();
	chargeIntermediaire = new QLineEdit();
	chargeLourde = new QLineEdit();
	surLaTete = new QLineEdit();
	decollerDuSol = new QLineEdit();
	pousserTirer = new QLineEdit();
	transporte = new QLineEdit();
	pc = new QLineEdit();
	pa = new QLineEdit();
	po = new QLineEdit();
	pp = new QLineEdit();
	
	autresRichesses = new QTextEdit();
	
	transporte->setFixedSize(65,35);
	
	boutonAjoutLigne = new QPushButton("Ajouter une ligne");
	
	tableSac = new QTableWidget();
	tableSac->setColumnCount(4);
	tableSac->setRowCount(15);
	QStringList liste;
	// Création des en-tête
	liste << "Poids" << "Valeur" << "Objet" << "Informations";
	tableSac->setHorizontalHeaderLabels(liste);
	
	tableSac->resizeColumnsToContents();
	
	layoutRichesse = new QGridLayout();
	
	layoutRichesse->addWidget(new QLabel("PC:"),0,0);
	layoutRichesse->addWidget(pc,0,1);
	layoutRichesse->addWidget(new QLabel("PA:"),1,0);
	layoutRichesse->addWidget(pa,1,1);
	layoutRichesse->addWidget(new QLabel("PO:"),2,0);
	layoutRichesse->addWidget(po,2,1);
	layoutRichesse->addWidget(new QLabel("PP:"),3,0);
	layoutRichesse->addWidget(pp,3,1);
	layoutRichesse->addWidget(new QLabel("Autres richesses"),4,1);
	layoutRichesse->addWidget(autresRichesses,5,0,1,2);
	
	layoutPoids = new QGridLayout();
	
	layoutPoids->addWidget(new QLabel("Charge légère"),0,0);
	layoutPoids->addWidget(new QLabel("Charge intermédiaire"),0,1);
	layoutPoids->addWidget(new QLabel("Charge lourde"),0,2);
	layoutPoids->addWidget(new QLabel("Porter sur la tete"),0,3);
	layoutPoids->addWidget(new QLabel("Decoller du sol"),0,4);
	layoutPoids->addWidget(new QLabel("Pousser ou tirer"),0,5);
	layoutPoids->addWidget(chargeLegere,1,0);
	layoutPoids->addWidget(chargeIntermediaire,1,1);
	layoutPoids->addWidget(chargeLourde,1,2);
	layoutPoids->addWidget(surLaTete,1,3);
	layoutPoids->addWidget(decollerDuSol,1,4);
	layoutPoids->addWidget(pousserTirer,1,5);
	
	layoutInfosSac = new QHBoxLayout();
	
	layoutInfosSac->addWidget(boutonAjoutLigne);
	layoutInfosSac->addStretch();
	layoutInfosSac->addWidget(new QLabel("Possessions"));
	layoutInfosSac->addStretch();
	layoutInfosSac->addWidget(new QLabel("Poids total transporté:"));
	layoutInfosSac->addWidget(transporte);
	
	ligne1 = new QFrame();
		ligne1->setFrameStyle(QFrame::HLine | QFrame::Plain);
	ligne2 = new QFrame();
		ligne2->setFrameStyle(QFrame::VLine | QFrame::Plain);
	
	layoutBlocTable = new QVBoxLayout();
	
	layoutBlocTable->addLayout(layoutInfosSac);
	layoutBlocTable->addWidget(tableSac);
	
	layoutContenuSac = new QHBoxLayout();
	
	layoutContenuSac->addLayout(layoutRichesse);
	layoutContenuSac->addWidget(ligne2);
	layoutContenuSac->addLayout(layoutBlocTable);
	layoutContenuSac->setStretch(0,1);
	layoutContenuSac->setStretch(2,3);
	
	layoutPrincipal = new QVBoxLayout(this);
	
	layoutPrincipal->addLayout(layoutPoids);
	layoutPrincipal->addWidget(ligne1);
	layoutPrincipal->addLayout(layoutContenuSac);
	
	connect(boutonAjoutLigne, SIGNAL(clicked()), this, SLOT(ajoutLigne()));
}

void Sac::ajoutLigne()
{
	tableSac->setRowCount(tableSac->rowCount()+1);
}
