// Inclusion des bibliothèques Qt
#include <QtGui>
// Inclusion du fichier mainWindow.h
#include "mainWindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	MainWindow m;
	m.show();
	
	return app.exec();
};
