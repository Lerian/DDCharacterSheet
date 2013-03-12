#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <QtGui>
#include "caracs.h"
#include "equipement.h"
#include "sac.h"
#include "competences.h"
#include "dons.h"
#include "rolePlay.h"
#include "diceRoller.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT // Macro pour la création de signal/slot
	
private:
	// Onglets des différentes pages
	QTabWidget * menuOnglets;
	
	Caracs * ongletCaracs;
	Equipement * ongletEquipement;
	Sac * ongletSac;
	Competences * ongletCompetences;
	Dons * ongletDons;
	RolePlay * ongletRP;
	
	// Barre de menus
	QMenuBar * barreMenu;
	QMenu * menuFichier;
	QMenu * menuOutils;
	
	QAction * action;
	
	// Outils de simulation de dés
	QDockWidget * dockWidget;
	DiceRoller * widgetDes;
	
public:
	MainWindow();
	
private slots:
	void afficherDiceRoller(bool state);
};
#endif //MAIN_WINDOW
