#include "CarteID.h"


mCarteID::mCarteID()
{
	setID(0); //on set l'id par défaut
}

mCarteID::~mCarteID()
{

}

int mCarteID::getID()
{
	return ID;
}

string mCarteID::getnom()
{
	return string(nom);
}

string mCarteID::getprenom()
{
	return string(prenom);
}

string mCarteID::getadresse()
{
	return string(adresse);
}

string mCarteID::getCP()
{
	return string(CP);
}

string mCarteID::getville()
{
	return string(ville);
}

void mCarteID::setID(int ID)
{
	this->ID = ID;
}

void mCarteID::setnom(string nom)
{
	this->nom = nom;
}

void mCarteID::setprenom(string prenom)
{
	this->prenom = prenom;
}

void mCarteID::setadresse(string adresse)
{
	this->adresse = adresse;
}

void mCarteID::setCP(string CP)
{
	this->CP = CP;
}

void mCarteID::setville(string ville)
{
	this->ville = ville;
}

void mCarteID::affiche() //fonction d'affichage d'une carte
{
	cout << "ID : " << getID() << endl;
	cout << "nom : " << getnom() << endl;
	cout << "prenom : " << getprenom() << endl;
	cout << "adresse : " << getadresse() << endl;
	cout << "CP : " << getCP() << endl;
	cout << "ville : " << getville() << endl;
}

void mCarteID::suppress() //fonction de suppression d'une carte
{
	setID(0);
	setnom("");
	setprenom("");
	setadresse("");
	setCP("");
	setville("");
}
