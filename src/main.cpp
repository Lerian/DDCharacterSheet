#include <QtGui>

#include "mainWindow.h"
#include "databaseManager.h"

// Gestionnaire de base de données
DatabaseManager dataManager;

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	//Utilisation de l'utf8 pour afficher correctement les accents
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
	
	//Création de la base de données
	dataManager.constructionTables();
	dataManager.remplissageTables();
	
	MainWindow m;
	m.show();
	
	return app.exec();
};
