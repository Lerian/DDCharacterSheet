#include "databaseManager.h"

DatabaseManager::DatabaseManager(QObject * parent)
: QObject(parent)
{
	nom = new QString("DDData.db");
	path = new QString("Database");
	path->append(QDir::separator());
	
	db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
	db->setDatabaseName(path->append(nom));
}

bool DatabaseManager::connexion()
{
	return db->open();
}

void DatabaseManager::deconnexion()
{
	db->close();
}

void DatabaseManager::constructionTables()
{
	if(db->open())
	{
		requete = new QSqlQuery();
		if(!requete->exec("create table if not exists classes (nom varchar(50) primary key)"))
			std::cout << "échec création de table classes" << std::endl;
		if(!requete->exec("create table if not exists races (nom varchar(50) primary key)"))
			std::cout << "échec création de table races" << std::endl;
		if(!requete->exec("create table if not exists divinites (nom varchar(50) primary key)"))
			std::cout << "échec création de table divinites" << std::endl;
		db->close();
	}
	else
	{
		std::cout << "La connexion a échouée, tables non créées" << std::endl;
	}
}

void DatabaseManager::remplissageTables()
{
	if(db->open())
	{
		requete = new QSqlQuery();
		
		// Table classes
		requete->exec("insert into classes values('Barbare')");
		requete->exec("insert into classes values('Guerrier')");
		requete->exec("insert into classes values('Moine')");
		requete->exec("insert into classes values('Paladin')");
		requete->exec("insert into classes values('Prêtre')");
		requete->exec("insert into classes values('Rôdeur')");
		requete->exec("insert into classes values('Roublard')");
		
		// Table races
		requete->exec("insert into races values('Demi-elfe')");
		requete->exec("insert into races values('Demi-orque')");
		requete->exec("insert into races values('Elfe')");
		requete->exec("insert into races values('Halfelin')");
		requete->exec("insert into races values('Humain')");
		requete->exec("insert into races values('Nain')");
		
		// Table divinites
		requete->exec("insert into divinites values('Baine')");
		requete->exec("insert into divinites values('Mailiki')");
		requete->exec("insert into divinites values('Moradin')");
		requete->exec("insert into divinites values('Reine Corneille')");
		requete->exec("insert into divinites values('Tempus')");
		
		db->close();
	}
	else
	{
		std::cout << "La connexion a échouée, tables non remplies" << std::endl;
	}
}

void DatabaseManager::lectureTable()
{
	bool ret;
	
	if(db->open())
	{
		requete = new QSqlQuery();
		ret = requete->exec("select * from coucou");
		if(ret)
			std::cout << "réussi" << std::endl;
		else
			std::cout << "nan" << std::endl;
		db->close();
	}
	else
	{
		std::cout << "La connexion a échouée, désolé" << std::endl;
	}
}
