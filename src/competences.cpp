#include "competences.h"

Competences::Competences()
{	
	table = new QTableWidget();
	table->setColumnCount(8);

	QStringList liste;
	// Création des en-tête
	liste << "De classe" << "Innée" << "Compétence" << "Stat." << "Mod. compét." << "Mod. stat." << "Deg. maîtrise" << "Mod. divers";
	table->setHorizontalHeaderLabels(liste);

	nbCompetences = 0;
	setListCompetences();
	
	layoutPrincipal = new QVBoxLayout(this);
	layoutHaut = new QHBoxLayout();
	
	layoutPrincipal->addLayout(layoutHaut);
	layoutHaut->addWidget(new QLabel("Points à dépenser:"));
	aDepenser = new QLineEdit();
	aDepenser->setInputMask("99");
	aDepenser->setText("");
	aDepenser->setFixedSize(40,40);
	aDepenser->setAlignment(Qt::AlignCenter);
	layoutHaut->addWidget(aDepenser);
	
	layoutHaut->addStretch();
	
	layoutHaut->addWidget(new QLabel("Degré de maîtrise max.:"));
	degreMaitriseMaxI = new QLineEdit();
	degreMaitriseMaxI->setInputMask("99");
	degreMaitriseMaxI->setText("");
	degreMaitriseMaxI->setFixedSize(40,40);
	degreMaitriseMaxI->setAlignment(Qt::AlignCenter);
	layoutHaut->addWidget(degreMaitriseMaxI);
	
	layoutHaut->addWidget(new QLabel("/"));
	degreMaitriseMaxN = new QLineEdit();
	degreMaitriseMaxN->setInputMask("99");
	degreMaitriseMaxN->setText("");
	degreMaitriseMaxN->setFixedSize(40,40);
	degreMaitriseMaxN->setAlignment(Qt::AlignCenter);
	layoutHaut->addWidget(degreMaitriseMaxN);
	
	layoutPrincipal->addWidget(table);
	
	//Tri alphabétique des compétences
	table->sortItems(2);
	
	//Resize des colonnes
	table->resizeColumnsToContents();
	
	connect(&xmlManager,SIGNAL(requestCompetencesSave()),this,SLOT(receiveSaveRequest()));
	connect(this,SIGNAL(saveDone()),&xmlManager,SLOT(competencesSaved()));
}

void Competences::setListCompetences()
{
	QStringList listeCompetences;
	QStringList listeInnee;
	QStringList listeStat;

	if(dataManager.connexion())
	{
		if(dataManager.requete->exec("select nom, upper(stat), innee from competences"))
		{
			while(dataManager.requete->next())
			{
				nbCompetences++;
				listeCompetences << dataManager.requete->value(0).toString();
				listeStat << dataManager.requete->value(1).toString();
				listeInnee << dataManager.requete->value(2).toString();
			}
		}
		
		dataManager.deconnexion();
	}
	
	table->setRowCount(listeCompetences.size());
	
	for(int i = 0;i<listeCompetences.size();i++)
	{
		//CheckBox de compétence de classe
		table->setCellWidget(i,0,new QCheckBox());
		//CheckBox de compétence innée
		table->setCellWidget(i,1,new QCheckBox());
		if(listeInnee[i] == "O")
			dynamic_cast<QCheckBox&>(*table->cellWidget(i,1)).setChecked(true);
		//Compétence
		newLabel = new QLabel(listeCompetences[i]);
		table->setCellWidget(i, 2, newLabel);
		//Stat associée
		newLabel = new QLabel(listeStat[i]);
		newLabel->setAlignment(Qt::AlignCenter);
		table->setCellWidget(i, 3, newLabel);
		//Label de modificateur de carac
		newLabel = new QLabel("0");
		newLabel->setAlignment(Qt::AlignCenter);
		table->setCellWidget(i,5,newLabel);
	}
}

void Competences::changeCaracMod(QString carac, int newValue)
{
	for(int i = 0; i < table->rowCount(); i++)
	{
		if(dynamic_cast<QLabel *>(table->cellWidget(i,3))->text() == carac)
			dynamic_cast<QLabel *>(table->cellWidget(i,5))->setText(QString::number(newValue));
	}
}

void Competences::modForChanged(int newValue)
{
	changeCaracMod(QString::fromStdString("FOR"),newValue);
}

void Competences::modDexChanged(int newValue)
{
	changeCaracMod(QString::fromStdString("DEX"),newValue);
}

void Competences::modConChanged(int newValue)
{
	changeCaracMod(QString::fromStdString("CON"),newValue);
}

void Competences::modIntChanged(int newValue)
{
	changeCaracMod(QString::fromStdString("INT"),newValue);
}

void Competences::modSagChanged(int newValue)
{
	changeCaracMod(QString::fromStdString("SAG"),newValue);
}

void Competences::modChaChanged(int newValue)
{
	changeCaracMod(QString::fromStdString("CHA"),newValue);
}

void Competences::receiveSaveRequest()
{
	QDomElement elem;
	QDomAttr a;
	
	elem = xmlManager.getCompetences().firstChildElement("pointsADepenser");
	a = elem.attributeNode("value");
	a.setValue(aDepenser->text());
	
	elem = xmlManager.getCompetences().firstChildElement("degreMaitriseMax");
	a = elem.attributeNode("deClasse");
	a.setValue(degreMaitriseMaxI->text());
	a = elem.attributeNode("inconnue");
	a.setValue(degreMaitriseMaxN->text());
	
	elem = xmlManager.getCompetences().firstChildElement("liste");
	while(!elem.firstChild().isNull())										// Suppression des anciennes lignes
	{
		elem.removeChild(elem.firstChild());
	}
	for(int i=0;i<table->rowCount();i++)
	{
		QDomElement ligneTableau = xmlManager.getDoc().createElement("ligne");
		ligneTableau.setAttribute("numero",i);
		elem.appendChild(ligneTableau);
		
		QDomElement elemLigne;
		
		// compétence de classe ou non
		elemLigne = xmlManager.getDoc().createElement("deClasse");
		if(static_cast<QCheckBox*>(table->cellWidget(i,0))->isChecked())
			elemLigne.setAttribute("value","oui");
		else
			elemLigne.setAttribute("value","non");
		ligneTableau.appendChild(elemLigne);
		
		// nom de la compétence
		elemLigne = xmlManager.getDoc().createElement("nom");
		elemLigne.removeChild(elemLigne.firstChild());
		QDomText valeur = xmlManager.getDoc().createTextNode(static_cast<QLabel*>(table->cellWidget(i,2))->text());
		elemLigne.appendChild(valeur);
		ligneTableau.appendChild(elemLigne);
		
		// degré de maitrise
		elemLigne = xmlManager.getDoc().createElement("degreMaitrise");
		if(table->item(i,6) == NULL)
			elemLigne.setAttribute("value","");
		else
			elemLigne.setAttribute("value",table->item(i,6)->text());
		ligneTableau.appendChild(elemLigne);
		
		// modificateurs divers
		elemLigne = xmlManager.getDoc().createElement("modDivers");
		if(table->item(i,7) == NULL)
			elemLigne.setAttribute("value","");
		else
			elemLigne.setAttribute("value",table->item(i,7)->text());
		ligneTableau.appendChild(elemLigne);
	}
	
	emit saveDone();
}
