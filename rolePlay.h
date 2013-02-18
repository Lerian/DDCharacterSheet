#ifndef ROLEPLAY_H
#define ROLEPLAY_H

#include <QtGui>

class RolePlay: public QWidget
{
private:
	QGridLayout* layoutApparence;

	//Partie apparence
	QLineEdit* c_age;
	QLineEdit* c_sexe;
	QLineEdit* c_taille;
	QLineEdit* c_poids;
	QLineEdit* c_yeux;
	QLineEdit* c_cheveux;
	QLineEdit* c_peau;
	
	QLabel* l_age;
	QLabel* l_sexe;
	QLabel* l_taille;
	QLabel* l_poids;
	QLabel* l_yeux;
	QLabel* l_cheveux;
	QLabel* l_peau;
	
public:
	RolePlay();
};

#endif // ROLEPLAY_H
