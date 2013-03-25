#ifndef SAC_H
#define SAC_H

#include <QtGui>
#include "xmlManager.h"

extern XmlManager xmlManager;

class Sac : public QWidget
{
	Q_OBJECT

private:
	QLineEdit* chargeLegere;
	QLineEdit* chargeIntermediaire;
	QLineEdit* chargeLourde;
	QLineEdit* surLaTete;
	QLineEdit* decollerDuSol;
	QLineEdit* pousserTirer;
	QLineEdit* transporte;
	QLineEdit* pc;
	QLineEdit* pa;
	QLineEdit* po;
	QLineEdit* pp;
	
	QTextEdit* autresRichesses;
	
	QPushButton* boutonAjoutLigne;
	
	QTableWidget* tableSac;
	
	QVBoxLayout* layoutPrincipal;
	QGridLayout* layoutRichesse;
	QGridLayout* layoutPoids;
	QHBoxLayout* layoutContenuSac;
	QHBoxLayout* layoutInfosSac;
	QVBoxLayout* layoutBlocTable;
	
	QFrame* ligne1;
	QFrame* ligne2;
	
public:
	Sac();

signals:
	void saveDone();
	
private slots:
	void ajoutLigne();
	void receiveSaveRequest();
};

#endif // SAC_H
