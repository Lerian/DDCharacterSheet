#ifndef COMPETENCES_H
#define COMPETENCES_H

#include <QtGui>
#include "databaseManager.h"

extern DatabaseManager dataManager;

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
	QTableWidgetItem* newItem;

public:
	Competences();
	void setListCompetences();
	void changeCaracMod(QString carac, int newValue);

public slots:
	void modForChanged(int newValue);
	void modDexChanged(int newValue);
	void modConChanged(int newValue);
	void modIntChanged(int newValue);
	void modSagChanged(int newValue);
	void modChaChanged(int newValue);
};

#endif // COMPETENCES_H
