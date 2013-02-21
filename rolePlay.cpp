#include "rolePlay.h"

RolePlay::RolePlay()
{
	layoutApparence = new QGridLayout();
	layoutSeparation = new QHBoxLayout();
	layoutOptions = new QHBoxLayout();
	layout = new QVBoxLayout(this);

	//Création des champs
	c_age = new QLineEdit();
	c_sexe = new QLineEdit();
	c_taille = new QLineEdit();
	c_poids = new QLineEdit();
	c_yeux = new QLineEdit();
	c_cheveux = new QLineEdit();
	c_peau = new QLineEdit();
	
	//Création des labels
	l_age = new QLabel("Age:");
	l_sexe = new QLabel("Sexe:");
	l_taille = new QLabel("Taille:");
	l_poids = new QLabel("Poids:");
	l_yeux = new QLabel("Yeux:");
	l_cheveux = new QLabel("Cheveux:");
	l_peau = new QLabel("Peau:");
	
	//Alignement des textes
	l_age->setAlignment(Qt::AlignRight);
	l_sexe->setAlignment(Qt::AlignRight);
	l_taille->setAlignment(Qt::AlignRight);
	l_poids->setAlignment(Qt::AlignRight);
	l_yeux->setAlignment(Qt::AlignRight);
	l_cheveux->setAlignment(Qt::AlignRight);
	l_peau->setAlignment(Qt::AlignRight);
	
	//Placement des champs dans le layout
	layoutApparence->addWidget(c_taille,0,1);
	layoutApparence->addWidget(c_poids,0,3);
	layoutApparence->addWidget(c_age,1,1);
	layoutApparence->addWidget(c_sexe,1,3);
	layoutApparence->addWidget(c_yeux,1,5);
	layoutApparence->addWidget(c_cheveux,2,1);
	layoutApparence->addWidget(c_peau,2,3);
	
	//Placement des labels dans le layout
	layoutApparence->addWidget(l_taille,0,0);
	layoutApparence->addWidget(l_poids,0,2);
	layoutApparence->addWidget(l_age,1,0);
	layoutApparence->addWidget(l_sexe,1,2);
	layoutApparence->addWidget(l_yeux,1,4);
	layoutApparence->addWidget(l_cheveux,2,0);
	layoutApparence->addWidget(l_peau,2,2);
	
	// Création de la bande de séparation
	ligne1 = new QFrame();
		ligne1->setFrameStyle(QFrame::HLine | QFrame::Plain);
	ligne2 = new QFrame();
		ligne2->setFrameStyle(QFrame::HLine | QFrame::Plain);
	l_background = new QLabel("Background");
	l_background->setFixedWidth(100);
	l_background->setAlignment(Qt::AlignCenter);
	
	layoutSeparation->addWidget(ligne1);
	layoutSeparation->addWidget(l_background);
	layoutSeparation->addWidget(ligne2);
	
	// Création de la bande d'option
	mode = new QComboBox();
	mode->addItem("Texte");
	mode->addItem("HTML");
	mode->addItem("Edition");
	
	layoutOptions->addWidget(mode);
	
	// Création de la partie background
	zoneBackgroundText = new QTextEdit();
	zoneBackgroundHtml = new QTextEdit();
	zoneBackgroundHtml->setVisible(false);
	
	layout->addLayout(layoutApparence);
	layout->addLayout(layoutSeparation);
	layout->addLayout(layoutOptions);
	layout->addWidget(zoneBackgroundText);
	layout->addWidget(zoneBackgroundHtml);
	
	// Connexion des signaux/slots
	connect(mode,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(changeMode(const QString&)));
	connect(zoneBackgroundText,SIGNAL(textChanged()),this,SLOT(updateHtmlEditionMode()));
}

void RolePlay::changeMode(const QString& text)
{
	if(text == "HTML")
	{
		QString valeur = zoneBackgroundText->toPlainText();
		zoneBackgroundHtml->setHtml(valeur);
		zoneBackgroundHtml->setVisible(true);
		zoneBackgroundText->setVisible(false);
	}
	else if(text == "Texte")
	{
		zoneBackgroundHtml->setVisible(false);
		zoneBackgroundText->setVisible(true);
	}
	else
	{
		zoneBackgroundText->setVisible(true);
		zoneBackgroundHtml->setVisible(true);
	}
}

void RolePlay::updateHtmlEditionMode()
{
	if(mode->currentText() == "Edition")
	{
		QString valeur = zoneBackgroundText->toPlainText();
		zoneBackgroundHtml->setHtml(valeur);
	}
}
