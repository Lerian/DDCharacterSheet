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
#include "infoWidget.h"
#include "xmlManager.h"

extern XmlManager xmlManager;

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
	QDockWidget * dockWidgetDes;
	DiceRoller * widgetDes;
	
	// Outils d'affichage des infos
	QDockWidget * dockWidgetInfos;
	InfoWidget * widgetInfos;
	
public:
	MainWindow();

private:
	void createTabs();
	void createDiceRoller();
	void createInfosDisplayer();

signals:
	void requestSave();
	void newSheetRequested();

private slots:
	void createNewSheet();
	void saveSheet();
	void loadSheet();
	void createEmptySheet();
	void afficherDiceRoller(bool state);
	void afficherInformations(bool state);
	
	void receiveCaracsSave();
	void receiveEquipementSave();
	void receiveBackpackSave();
	void receiveCompetencesSave();
	void receiveDonsSave();
	void receiveRoleplaySave();
};
#endif //MAIN_WINDOW
