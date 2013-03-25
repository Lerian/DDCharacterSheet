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
	
	// Connection des signaux/slots
	connect(boutonAjoutLigne, SIGNAL(clicked()), this, SLOT(ajoutLigne()));
	
	connect(&xmlManager,SIGNAL(requestBackpackSave()),this,SLOT(receiveSaveRequest()));
	connect(this,SIGNAL(saveDone()),&xmlManager,SLOT(backpackSaved()));
}

void Sac::ajoutLigne()
{
	tableSac->setRowCount(tableSac->rowCount()+1);
}

void Sac::receiveSaveRequest()
{
	QDomElement elem;
	QDomAttr a;
	
	elem = xmlManager.getBackpack().firstChildElement("chargeLegere");
	a = elem.attributeNode("value");
	a.setValue(chargeLegere->text());
	
	elem = xmlManager.getBackpack().firstChildElement("chargeIntermediaire");
	a = elem.attributeNode("value");
	a.setValue(chargeIntermediaire->text());
	
	elem = xmlManager.getBackpack().firstChildElement("chargeLourde");
	a = elem.attributeNode("value");
	a.setValue(chargeLourde->text());
	
	elem = xmlManager.getBackpack().firstChildElement("surLaTete");
	a = elem.attributeNode("value");
	a.setValue(surLaTete->text());
	
	elem = xmlManager.getBackpack().firstChildElement("decoller");
	a = elem.attributeNode("value");
	a.setValue(decollerDuSol->text());
	
	elem = xmlManager.getBackpack().firstChildElement("pousser");
	a = elem.attributeNode("value");
	a.setValue(pousserTirer->text());
	
	elem = xmlManager.getBackpack().firstChildElement("pc");
	a = elem.attributeNode("value");
	a.setValue(pc->text());
	
	elem = xmlManager.getBackpack().firstChildElement("pa");
	a = elem.attributeNode("value");
	a.setValue(pa->text());
	
	elem = xmlManager.getBackpack().firstChildElement("po");
	a = elem.attributeNode("value");
	a.setValue(po->text());
	
	elem = xmlManager.getBackpack().firstChildElement("pp");
	a = elem.attributeNode("value");
	a.setValue(pp->text());
	
	elem = xmlManager.getBackpack().firstChildElement("poidsTransporte");
	a = elem.attributeNode("value");
	a.setValue(transporte->text());

	elem = xmlManager.getBackpack().firstChildElement("autre");
	elem.removeChild(elem.firstChild());
	QDomText valeur = xmlManager.getDoc().createTextNode(autresRichesses->toPlainText());
	elem.appendChild(valeur);
	
	elem = xmlManager.getBackpack().firstChildElement("possessions");
	while(!elem.firstChild().isNull())										// Suppression des anciennes lignes
	{
		elem.removeChild(elem.firstChild());
	}
	for(int i=0;i<tableSac->rowCount();i++)
	{
		QDomElement ligneTableau = xmlManager.getDoc().createElement("ligne");
		ligneTableau.setAttribute("numero",i);
		elem.appendChild(ligneTableau);
		
		for(int j=0;j<tableSac->columnCount();j++)
		{
			QDomElement elemLigne = xmlManager.getDoc().createElement(tableSac->horizontalHeaderItem(j)->text());
			if(tableSac->item(i,j) == NULL)
				elemLigne.setAttribute("value","");
			else
				elemLigne.setAttribute("value",tableSac->item(i,j)->text());
			ligneTableau.appendChild(elemLigne);
		}
	}
	
	emit saveDone();
}
