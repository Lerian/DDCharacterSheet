#include "diceRoller.h"

DiceRoller::DiceRoller()
{
	layoutDes = new QGridLayout();
	layout = new QVBoxLayout(this);

	resD4 = new QLineEdit();
	resD6 = new QLineEdit();
	resD8 = new QLineEdit();
	resD10 = new QLineEdit();
	resD12 = new QLineEdit();
	resD20 = new QLineEdit();
	resD100 = new QLineEdit();
	
	boutonD4 = new QPushButton("d4");
	boutonD6 = new QPushButton("d6");
	boutonD8 = new QPushButton("d8");
	boutonD10 = new QPushButton("d10");
	boutonD12 = new QPushButton("d12");
	boutonD20 = new QPushButton("d20");
	boutonD100 = new QPushButton("d100");
	boutonClear = new QPushButton("Effacer");
	
	avertissement = new QLabel("/!\\ Aléatoire approximatif /!\\");
	
	layoutDes->addWidget(avertissement,0,0,1,2);
	layoutDes->addWidget(boutonD4,1,0);
	layoutDes->addWidget(resD4,1,1);
	layoutDes->addWidget(boutonD6,2,0);
	layoutDes->addWidget(resD6,2,1);
	layoutDes->addWidget(boutonD8,3,0);
	layoutDes->addWidget(resD8,3,1);
	layoutDes->addWidget(boutonD10,4,0);
	layoutDes->addWidget(resD10,4,1);
	layoutDes->addWidget(boutonD12,5,0);
	layoutDes->addWidget(resD12,5,1);
	layoutDes->addWidget(boutonD20,6,0);
	layoutDes->addWidget(resD20,6,1);
	layoutDes->addWidget(boutonD100,7,0);
	layoutDes->addWidget(resD100,7,1);
	layoutDes->addWidget(boutonClear,8,1);
	
	layout->addStretch();
	layout->addLayout(layoutDes);
	layout->addStretch();
	
	// Connection des signaux/slots
	connect(boutonD4,SIGNAL(clicked()),this,SLOT(generateD4()));
	connect(boutonD6,SIGNAL(clicked()),this,SLOT(generateD6()));
	connect(boutonD8,SIGNAL(clicked()),this,SLOT(generateD8()));
	connect(boutonD10,SIGNAL(clicked()),this,SLOT(generateD10()));
	connect(boutonD12,SIGNAL(clicked()),this,SLOT(generateD12()));
	connect(boutonD20,SIGNAL(clicked()),this,SLOT(generateD20()));
	connect(boutonD100,SIGNAL(clicked()),this,SLOT(generateD100()));
	connect(boutonClear,SIGNAL(clicked()),this,SLOT(clearValues()));
}

void DiceRoller::generateD4()
{
	qsrand(QDateTime::currentDateTime().toMSecsSinceEpoch());
	resD4->setText(QString::number(qrand()%4+1));
}

void DiceRoller::generateD6()
{
	qsrand(QDateTime::currentDateTime().toMSecsSinceEpoch());
	resD6->setText(QString::number(qrand()%6+1));
}

void DiceRoller::generateD8()
{
	qsrand(QDateTime::currentDateTime().toMSecsSinceEpoch());
	resD8->setText(QString::number(qrand()%8+1));
}

void DiceRoller::generateD10()
{
	qsrand(QDateTime::currentDateTime().toMSecsSinceEpoch());
	resD10->setText(QString::number(qrand()%10+1));
}

void DiceRoller::generateD12()
{
	qsrand(QDateTime::currentDateTime().toMSecsSinceEpoch());
	resD12->setText(QString::number(qrand()%12+1));
}

void DiceRoller::generateD20()
{
	qsrand(QDateTime::currentDateTime().toMSecsSinceEpoch());
	resD20->setText(QString::number(qrand()%20+1));
}

void DiceRoller::generateD100()
{
	qsrand(QDateTime::currentDateTime().toMSecsSinceEpoch());
	resD100->setText(QString::number(qrand()%100+1));
}

void DiceRoller::clearValues()
{
	resD4->clear();
	resD6->clear();
	resD8->clear();
	resD10->clear();
	resD12->clear();
	resD20->clear();
	resD100->clear();
}
