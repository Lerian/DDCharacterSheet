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
		newItem = new QTableWidgetItem(listeCompetences[i]);
		table->setItem(i, 2, newItem);
		//Stat associée
		newItem = new QTableWidgetItem(listeStat[i]);
		table->setItem(i, 3, newItem);
		//Label de modificateur de carac
		QLabel * label = new QLabel("0");
		label->setAlignment(Qt::AlignCenter);
		table->setCellWidget(i,5,label);
	}
}

void Competences::changeCaracMod(QString carac, int newValue)
{
	for(int i = 0; i < table->rowCount(); i++)
	{
		if(table->item(i,3)->text() == carac)
			dynamic_cast<QLabel&>(*table->cellWidget(i,5)).setText(QString::number(newValue));
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
