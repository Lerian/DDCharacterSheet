// Inclusion des bibliothèques Qt
#include <QtGui>
// Inclusion du fichier mainWindow.h
#include "mainWindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	//Utilisation de l'utf8 pour afficher correctement les accents
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
	
	MainWindow m;
	m.show();
	
	return app.exec();
};
