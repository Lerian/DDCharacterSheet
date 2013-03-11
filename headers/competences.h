#ifndef COMPETENCES_H
#define COMPETENCES_H

#include <QtGui>

class Competences: public QWidget
{
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
};

#endif // COMPETENCES_H
