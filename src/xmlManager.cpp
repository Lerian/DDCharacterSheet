#include "xmlManager.h"

XmlManager::XmlManager()
{
	used = false;
	
	//bindCharacter();
}

void XmlManager::bindCharacter(QString name, QString path)
{
	// Enregistrement du fichier
	path.append(QDir::separator());
	file.setFileName(path.append(name));
	
	// Récupération des différentes parties
	if(doc.isNull())
	{
		QDomNode process = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
		doc.insertBefore(process, doc.firstChild());
		root = doc.createElement("character");
		doc.appendChild(root);
	}
	else
	{
		root = doc.documentElement();
	}
	roleplay = root.firstChildElement("roleplay");
	if(roleplay.isNull())
	{
		QDomElement roleplay2 = doc.createElement("roleplay");
		root.appendChild(roleplay2);
		
		QDomElement element2 = doc.createElement("taille");
		element2.setAttribute("value","");
		roleplay2.appendChild(element2);
		roleplay = roleplay2;
	}
}

void XmlManager::loadFile()
{
	// Récupération du contenu dans doc
	if(!file.open(QIODevice::ReadOnly))
		return;
	if(!doc.setContent(&file))
	{
		file.close();
		return;
	}
	file.close();
}

QDomDocument XmlManager::getDoc()
{
	return doc;
}

QDomElement XmlManager::getCaracteristiques()
{
	return caracteristiques;
}

QDomElement XmlManager::getEquipement()
{
	return equipement;
}

QDomElement XmlManager::getBackpack()
{
	return backpack;
}

QDomElement XmlManager::getCompetences()
{
	return competences;
}

QDomElement XmlManager::getDons()
{
	return dons;
}

QDomElement XmlManager::getRoleplay()
{
	return roleplay;
}

QDomElement XmlManager::getElement()
{
	return element;
}

void XmlManager::receiveSaveRequest()
{
	emit requestCaracsSave();
}

void XmlManager::createSheet()
{
	doc.clear();
	root.clear();
	backpack.clear();
	roleplay.clear();
	element.clear();
	
	QDomNode xmlProcess = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
	doc.insertBefore(xmlProcess, doc.firstChild());
	
	// section personnage
	root = doc.createElement("character");
	doc.appendChild(root);
		// section caractéristiques
		caracteristiques = doc.createElement("caracteristiques");
		root.appendChild(caracteristiques);

		element = doc.createElement("nomPersonnage");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("nomJoueur");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("listeClasses");
		caracteristiques.appendChild(element);
		element = doc.createElement("race");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("alignement");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("divinite");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("categorieTaille");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("for");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("dex");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("con");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("int");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("sag");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("cha");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("forTmp");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("dexTmp");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("conTmp");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("intTmp");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("sagTmp");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("chaTmp");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("bba");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("initiative");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("vd");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("resistanceMagie");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("reductionDegats");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("lutte");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("pvTotal");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("pvRestants");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("degatsNonLetaux");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("caContact");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("caDepourvu");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("armure");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("bouclier");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("taille");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("armureNaturelle");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("parade");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("divers");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("baseReflexes");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("modMagiqueReflexes");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("modDiversReflexes");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("modTmpReflexes");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("baseVigueur");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("modMagiqueVigueur");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("modDiversVigueur");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("modTmpVigueur");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("baseVolonte");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("modMagiqueVolonte");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("modDiversVolonte");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		element = doc.createElement("modTmpVolonte");
		element.setAttribute("value","");
		caracteristiques.appendChild(element);
		// section equipement
		equipement = doc.createElement("equipement");
		root.appendChild(equipement);
		
		element = doc.createElement("armes");
		equipement.appendChild(element);
		element = doc.createElement("armures");
		equipement.appendChild(element);
		element = doc.createElement("objets");
		equipement.appendChild(element);
		// section sac à dos
		backpack = doc.createElement("backpack");
		root.appendChild(backpack);
		
		element = doc.createElement("chargeLegere");
		element.setAttribute("value","");
		backpack.appendChild(element);
		element = doc.createElement("chargeIntermediaire");
		element.setAttribute("value","");
		backpack.appendChild(element);
		element = doc.createElement("chargeLourde");
		element.setAttribute("value","");
		backpack.appendChild(element);
		element = doc.createElement("surLaTete");
		element.setAttribute("value","");
		backpack.appendChild(element);
		element = doc.createElement("decoller");
		element.setAttribute("value","");
		backpack.appendChild(element);
		element = doc.createElement("pousser");
		element.setAttribute("value","");
		backpack.appendChild(element);
		element = doc.createElement("pc");
		element.setAttribute("value","");
		backpack.appendChild(element);
		element = doc.createElement("pa");
		element.setAttribute("value","");
		backpack.appendChild(element);
		element = doc.createElement("po");
		element.setAttribute("value","");
		backpack.appendChild(element);
		element = doc.createElement("pp");
		element.setAttribute("value","");
		backpack.appendChild(element);
		element = doc.createElement("autre");
		backpack.appendChild(element);
		element = doc.createElement("poidsTransporte");
		element.setAttribute("value","");
		backpack.appendChild(element);
		element = doc.createElement("possessions");
		backpack.appendChild(element);
		// section compétences
		competences = doc.createElement("competences");
		root.appendChild(competences);
		
		element = doc.createElement("pointsADepenser");
		element.setAttribute("value","");
		competences.appendChild(element);
		element = doc.createElement("degerMaitriseMax");
		element.setAttribute("deClasse","");
		element.setAttribute("inconnue","");
		competences.appendChild(element);
		element = doc.createElement("liste");
		competences.appendChild(element);
		// section dons
		dons = doc.createElement("dons");
		root.appendChild(dons);
		
		element = doc.createElement("raceClasses");
		dons.appendChild(element);
		element = doc.createElement("normaux");
		dons.appendChild(element);
		// section roleplay
		roleplay = doc.createElement("roleplay");
		root.appendChild(roleplay);
	
		element = doc.createElement("taille");
		element.setAttribute("value","");
		roleplay.appendChild(element);
		element = doc.createElement("poids");
		element.setAttribute("value","");
		roleplay.appendChild(element);
		element = doc.createElement("age");
		element.setAttribute("value","");
		roleplay.appendChild(element);
		element = doc.createElement("sexe");
		element.setAttribute("value","");
		roleplay.appendChild(element);
		element = doc.createElement("yeux");
		element.setAttribute("value","");
		roleplay.appendChild(element);
		element = doc.createElement("cheveux");
		element.setAttribute("value","");
		roleplay.appendChild(element);
		element = doc.createElement("peau");
		element.setAttribute("value","");
		roleplay.appendChild(element);
		element = doc.createElement("background");
		roleplay.appendChild(element);
}

void XmlManager::caracsSaved()
{
	if(name == NULL)
	{
		// A modifier pour demander le nom du fichier
		file.setFileName("Personnages/Lerian");
		name = "Lerian";
	}

	if(!file.open(QIODevice::WriteOnly))
		return;
	
	// Association du flux et du fichier
	out.setDevice(&file);

	doc.save(out,3);
	
	file.close();
	
	emit requestEquipementSave();
}

void XmlManager::equipementSaved()
{
	if(name == NULL)
	{
		// A modifier pour demander le nom du fichier
		file.setFileName("Personnages/Lerian");
		name = "Lerian";
	}

	if(!file.open(QIODevice::WriteOnly))
		return;
	
	// Association du flux et du fichier
	out.setDevice(&file);

	doc.save(out,3);
	
	file.close();
	
	emit requestBackpackSave();
}

void XmlManager::backpackSaved()
{
	if(name == NULL)
	{
		// A modifier pour demander le nom du fichier
		file.setFileName("Personnages/Lerian");
		name = "Lerian";
	}

	if(!file.open(QIODevice::WriteOnly))
		return;
	
	// Association du flux et du fichier
	out.setDevice(&file);

	doc.save(out,3);
	
	file.close();
	
	emit requestCompetencesSave();
}

void XmlManager::competencesSaved()
{
	if(name == NULL)
	{
		// A modifier pour demander le nom du fichier
		file.setFileName("Personnages/Lerian");
		name = "Lerian";
	}

	if(!file.open(QIODevice::WriteOnly))
		return;
	
	// Association du flux et du fichier
	out.setDevice(&file);

	doc.save(out,3);
	
	file.close();
	
	emit requestDonsSave();
}

void XmlManager::donsSaved()
{
	if(name == NULL)
	{
		// A modifier pour demander le nom du fichier
		file.setFileName("Personnages/Lerian");
		name = "Lerian";
	}

	if(!file.open(QIODevice::WriteOnly))
		return;
	
	// Association du flux et du fichier
	out.setDevice(&file);

	doc.save(out,3);
	
	file.close();
	
	emit requestRoleplaySave();
}

void XmlManager::roleplaySaved()
{
	if(name == NULL)
	{
		// A modifier pour demander le nom du fichier
		file.setFileName("Personnages/Lerian");
		name = "Lerian";
	}

	if(!file.open(QIODevice::WriteOnly))
		return;
	
	// Association du flux et du fichier
	out.setDevice(&file);

	doc.save(out,3);
	
	file.close();
	
	emit saveDone();
}
