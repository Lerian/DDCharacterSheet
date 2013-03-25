#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include <QtXml>
#include <iostream>

class XmlManager : public QObject
{
	Q_OBJECT

private:
	bool used;

	QFile file;
	QString path;
	QString name;

	QDomDocument doc;
	QDomElement root;
	QDomElement caracteristiques;
	QDomElement equipement;
	QDomElement backpack;
	QDomElement competences;
	QDomElement dons;
	QDomElement roleplay;
	QDomElement element;
	QTextStream out;
	
public:
	XmlManager();
	void bindCharacter(QString name="Lerian.xml", QString path="Personnages");	// supprimer la valeur par défaut de name
	void loadFile();
	QDomDocument getDoc();
	QDomElement getCaracteristiques();
	QDomElement getEquipement();
	QDomElement getBackpack();
	QDomElement getCompetences();
	QDomElement getDons();
	QDomElement getRoleplay();
	QDomElement getElement();

signals:
	void saveDone();

	void requestCaracsSave();
	void requestEquipementSave();
	void requestBackpackSave();
	void requestCompetencesSave();
	void requestDonsSave();
	void requestRoleplaySave();

private slots:
	void receiveSaveRequest();
	void createSheet();
	
	void caracsSaved();
	void equipementSaved();
	void backpackSaved();
	void competencesSaved();
	void donsSaved();
	void roleplaySaved();
};
#endif	// XMLMANAGER_H
