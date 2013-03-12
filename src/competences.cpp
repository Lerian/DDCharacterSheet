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

/*void Competences::setListCompetences()
{
	QStringList listeCompetences;
	QStringList listeInnee;
	QStringList listeStat;

	QFile file("Ressources/competences.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	QTextStream in(&file);
	while (!in.atEnd())
	{	
		QString line = in.readLine();
		while(line[0] == '#')	// élimination des lignes de commentaires
			line = in.readLine();
		nbCompetences++;
		listeCompetences << line;
		
		line = in.readLine();
		while(line[0] == '#')	// élimination des lignes de commentaires
			line = in.readLine();
		if(line[1] == 'I')
			listeInnee << "I";
		else
			listeInnee << "N";
		
		line = in.readLine();
		while(line[0] == '#')	// élimination des lignes de commentaires
			line = in.readLine();
		line.remove(0,1);
		listeStat << line;
	}
	
	table->setRowCount(listeCompetences.size());
	
	for(int i = 0;i<listeCompetences.size();i++)
	{
		//CheckBox de compétence de classe
		table->setCellWidget(i,0,new QCheckBox());
		//CheckBox de compétence innée
		table->setCellWidget(i,1,new QCheckBox());
		if(listeInnee[i] == "I")
			dynamic_cast<QCheckBox&>(*table->cellWidget(i,1)).setChecked(true);
		//Compétence
		newItem = new QTableWidgetItem(listeCompetences[i]);
		table->setItem(i, 2, newItem);
		//Stat associée
		newItem = new QTableWidgetItem(listeStat[i]);
		table->setItem(i, 3, newItem);
	}
}*/

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
	}
}
