#ifndef DICEROLLER_H
#define DICEROLLER_H

#include <QtGui>

class DiceRoller : public QWidget
{
	Q_OBJECT
	
private:
	QLineEdit* resD4;
	QLineEdit* resD6;
	QLineEdit* resD8;
	QLineEdit* resD10;
	QLineEdit* resD12;
	QLineEdit* resD20;
	QLineEdit* resD100;
	
	QPushButton* boutonD4;
	QPushButton* boutonD6;
	QPushButton* boutonD8;
	QPushButton* boutonD10;
	QPushButton* boutonD12;
	QPushButton* boutonD20;
	QPushButton* boutonD100;
	QPushButton* boutonClear;
	
	QLabel* avertissement;
	
	QGridLayout* layoutDes;
	QVBoxLayout* layout;
	
public:
	DiceRoller();

private slots:
	void generateD4();
	void generateD6();
	void generateD8();
	void generateD10();
	void generateD12();
	void generateD20();
	void generateD100();
	void clearValues();
};
#endif // DICEROLLER_H
