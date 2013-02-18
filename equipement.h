#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QtGui>

class Equipement: public QWidget
{
private:
	//Armes
	
	//Armures
	
	//Objets
	
	//Argent
	QLineEdit* c_pc;
	QLineEdit* c_pa;
	QLineEdit* c_po;
	QLineEdit* c_pp;
	
	QLabel* l_pc;
	QLabel* l_pa;
	QLabel* l_po;
	QLabel* l_pp;
	
	//Séparateurs
	
public:
	Equipement();
};

#endif // EQUIPEMENT_H
