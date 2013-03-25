#ifndef ROLEPLAY_H
#define ROLEPLAY_H

#include <QtGui>
#include "xmlManager.h"

extern XmlManager xmlManager;

class RolePlay: public QWidget
{
	Q_OBJECT
	
private:
	QGridLayout* layoutApparence;
	QHBoxLayout* layoutSeparation;
	QHBoxLayout* layoutOptions;
	QVBoxLayout* layout;

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

	//Partie séparation
	QFrame* ligne1;
	QFrame* ligne2;
	QLabel* l_background;
	
	//Partie options
	QComboBox* mode;
	
	//Partie background
	QTextEdit* zoneBackgroundText;
	QTextEdit* zoneBackgroundHtml;
	
public:
	RolePlay();
	
signals:	
	void saveDone();
	
public slots:
	void changeMode(const QString&);
	void updateHtmlEditionMode();
	void receiveSaveRequest();
};

#endif // ROLEPLAY_H
