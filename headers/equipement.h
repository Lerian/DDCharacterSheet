#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QtGui>
#include <iostream>

class Equipement: public QWidget
{
	Q_OBJECT
	
private:
	QTableWidget* armes;
	QTableWidget* armures;
	QTableWidget* objets;
	
	QGridLayout* layout;
	QHBoxLayout* layoutArme;
	QHBoxLayout* layoutArmure;
	QHBoxLayout* layoutObjet;
	
	QLabel* l_arme;
	QLabel* l_armure;
	QLabel* l_objet;
	
	QFrame* trait1Armes;
	QFrame* trait2Armes;
	QFrame* trait1Armures;
	QFrame* trait2Armures;
	QFrame* trait1Objets;
	QFrame* trait2Objets;
	
	QPushButton* boutonAjoutArme;
	QPushButton* boutonRetraitArme;
	QPushButton* boutonAjoutArmure;
	QPushButton* boutonRetraitArmure;
	QPushButton* boutonAjoutObjet;
	QPushButton* boutonRetraitObjet;
	
public:
	Equipement();

private slots:
	void ajoutLigneArme();
	void supprimerLigneArme();
	void ouvrirDialogArme();
	void retraitLigneArme();
	
	void ajoutLigneArmure();
	void supprimerLigneArmure();
	void ouvrirDialogArmure();
	void retraitLigneArmure();
	
	void ajoutLigneObjet();
	void supprimerLigneObjet();
	void ouvrirDialogObjet();
	void retraitLigneObjet();
};

#endif // EQUIPEMENT_H
