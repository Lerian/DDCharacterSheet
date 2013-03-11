#ifndef SAC_H
#define SAC_H

#include <QtGui>

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
	
private slots:
	void ajoutLigne();
};

#endif // SAC_H
