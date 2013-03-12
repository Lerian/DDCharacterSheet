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
	if(db->open())
	{
		requete = new QSqlQuery();
		return true;
	}
	else
		return false;
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
		if(!requete->exec("create table if not exists alignements (nom varchar(50) primary key)"))
			std::cout << "échec création de table alignements" << std::endl;
		if(!requete->exec("create table if not exists categoriesTailles (nom varchar(50) primary key)"))
			std::cout << "échec création de table categoriesTailles" << std::endl;
		if(!requete->exec("create table if not exists competences (nom varchar(50) primary key, stat varchar(3), innee varchar(1))"))
			std::cout << "échec création de table competences" << std::endl;
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
		
		// Table alignements
		requete->exec("insert into alignements values('Loyal bon')");
		requete->exec("insert into alignements values('Neutre bon')");
		requete->exec("insert into alignements values('Chaotique bon')");
		requete->exec("insert into alignements values('Loyal neutre')");
		requete->exec("insert into alignements values('Neutre')");
		requete->exec("insert into alignements values('Chaotique neutre')");
		requete->exec("insert into alignements values('Loyal mauvais')");
		requete->exec("insert into alignements values('Neutre mauvais')");
		requete->exec("insert into alignements values('Chaotique mauvais')");
		
		// Table categoriesTailles
		requete->exec("insert into categoriesTailles values('Très petite')");
		requete->exec("insert into categoriesTailles values('Petite')");
		requete->exec("insert into categoriesTailles values('Moyenne')");
		requete->exec("insert into categoriesTailles values('Grande')");
		requete->exec("insert into categoriesTailles values('Très grande')");
		
		// Table competences
		requete->exec("insert into competences values('Acrobaties','DEX','N')");
		requete->exec("insert into competences values('Art de la magie','INT','N')");
		requete->exec("insert into competences values('Artisanat','INT','O')");
		requete->exec("insert into competences values('Bluff','CHA','O')");
		requete->exec("insert into competences values('Concentration','CON','O')");
		requete->exec("insert into competences values('Connaissances','INT','N')");
		requete->exec("insert into competences values('Contrefaçon','INT','O')");
		requete->exec("insert into competences values('Crochetage','DEX','N')");
		requete->exec("insert into competences values('Décryptage','INT','N')");
		requete->exec("insert into competences values('Déguisement','CHA','O')");
		requete->exec("insert into competences values('Déplacement siencieux','DEX','O')");
		requete->exec("insert into competences values('Désamorçage/Sabotage','INT','N')");
		requete->exec("insert into competences values('Détection','SAG','O')");
		requete->exec("insert into competences values('Diplomatie','CHA','O')");
		requete->exec("insert into competences values('Discrétion','DEX','O')");
		requete->exec("insert into competences values('Dressage','CHA','N')");
		requete->exec("insert into competences values('Equilibre','DEX','O')");
		requete->exec("insert into competences values('Equitation','DEX','O')");
		
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
