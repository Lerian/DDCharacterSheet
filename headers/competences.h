#ifndef COMPETENCES_H
#define COMPETENCES_H

#include <QtGui>
#include "databaseManager.h"
#include "xmlManager.h"

extern DatabaseManager dataManager;
extern XmlManager xmlManager;

class Competences: public QWidget
{
	Q_OBJECT

private:
	int nbCompetences;
	QLineEdit* degreMaitriseMaxI;
	QLineEdit* degreMaitriseMaxN;
	QLineEdit* aDepenser;
	QTableWidget* table;
	
	QVBoxLayout* layoutPrincipal;
	QHBoxLayout* layoutHaut;
	QLabel* newLabel;

public:
	Competences();
	void setListCompetences();
	void changeCaracMod(QString carac, int newValue);

signals:
	void saveDone();

public slots:
	void modForChanged(int newValue);
	void modDexChanged(int newValue);
	void modConChanged(int newValue);
	void modIntChanged(int newValue);
	void modSagChanged(int newValue);
	void modChaChanged(int newValue);
	
	void receiveSaveRequest();
};

#endif // COMPETENCES_H
