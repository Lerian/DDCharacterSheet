#ifndef DONS_H
#define DONS_H

#include <QtGui>
#include "xmlManager.h"

extern XmlManager xmlManager;

class Dons: public QWidget
{
	Q_OBJECT
	
private:
	QTableWidget* bonus;
	QTableWidget* dons;
	
	QFrame* ligne1;
	QFrame* ligne2;
	QFrame* ligne3;
	QFrame* ligne4;
	
	QLabel* l_bonus;
	QLabel* l_dons;
	
	QPushButton* boutonAjoutBonus;
	QPushButton* boutonRetraitBonus;
	QPushButton* boutonAjoutDon;
	QPushButton* boutonRetraitDon;
	
	QVBoxLayout* layout;
	QHBoxLayout* layoutBandeBonus;
	QHBoxLayout* layoutBandeDons;

public:
	Dons();

signals:
	void saveDone();

private slots:
	void ajoutLigneBonus();
	void retraitLigneBonus();
	void ajoutLigneDons();
	void retraitLigneDons();
	
	void receiveSaveRequest();	
};

#endif // DONS_H
