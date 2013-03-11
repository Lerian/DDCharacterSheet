#ifndef DATABASE_H
#define DATABASE_H

#include <QtGui>
#include <QtSql>
#include <iostream>

class DatabaseManager: public QObject
{
	Q_OBJECT
	
private:
	QString * nom;
	QString * path;
	
	QSqlDatabase * db;
	
public:
	QSqlQuery * requete;
	
	DatabaseManager(QObject * parent=0);
	bool connexion();
	void deconnexion();
	void constructionTables();
	void remplissageTables();
	
public slots:
	void lectureTable();
};

#endif	// DATABASE_H
