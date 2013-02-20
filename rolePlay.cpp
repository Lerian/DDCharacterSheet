#include "rolePlay.h"

RolePlay::RolePlay()
{
	layoutApparence = new QGridLayout();
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
	
	zoneBackground = new QTextEdit();
	
	layout->addLayout(layoutApparence);
	layout->addWidget(zoneBackground);
	
}
