#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "CarteID.h"

using namespace std;

//déclaration des fonctions
int menu();
int FindVide(mCarteID CarteID[]);

void AjouterCarte(mCarteID CarteID[]);
void ModifierCarte(mCarteID CarteID[]);
void SupprimerCarte(mCarteID CarteID[]);
void AfficherCarte(mCarteID CarteID[]);

int main() 
{
	//déclaration d'un tableau
	mCarteID CarteID[100];
	bool run = true;
	
	while (run) {

		//choix de l'action de l'utilisateur
		switch (menu()) {

		case 1: 
			AjouterCarte(CarteID);
			break;

		case 2: 
			ModifierCarte(CarteID);
			break;

		case 3: 
			SupprimerCarte(CarteID);
			break;

		case 4: 
			AfficherCarte(CarteID);
			break;

		case 0: 
			run = false;
			break;

		default: break;

		}
	}

	system("pause");

	return 0;
}

int menu() { //mise en page du menu
	int choix;

	system("cls");
	cout << "Bienvenue\n" << endl;
	cout << "1. Ajouter une carte" << endl;
	cout << "2. Modifier une carte" << endl;
	cout << "3. supprimer une carte" << endl;
	cout << "4. Afficher une carte" << endl;
	cout << "0. Quitter" << endl;
	cin >> choix;

	return choix;
}

void AjouterCarte(mCarteID CarteID[]) { // ajout d'une nouvelle carte

	string mot;
	
	int vide = FindVide(CarteID);//On regarde si l'id de la carte n'est pas le même qu'une autre pour ne pas la remplacé et met l'id suppérieur

	system("cls");

	CarteID[vide].setID(vide);

	cin.ignore();
	cout << "Entrez votre Nom : ";
	getline(cin, mot);
	CarteID[vide].setnom(mot);

	cout << "Entrez votre prenom : ";
	getline(cin, mot);
	CarteID[vide].setprenom(mot);

	cout << "Entrez votre adresse : ";
	getline(cin, mot);
	CarteID[vide].setadresse(mot);

	cout << "Entrez votre Code Postal : ";
	getline(cin, mot);
	CarteID[vide].setCP(mot);

	cout << "Entrez votre ville : ";
	getline(cin, mot);
	CarteID[vide].setville(mot);

	cout << "\nCarte cree avec succes\n" << endl;
	system("pause");


}

void ModifierCarte(mCarteID CarteID[]) // modification d'une ligne de la carte
{

	int id;
	int choix;
	string mot;

	system("cls");

	cout << "Entrer l'id de la carte que vous souhaitez modifier : " << endl; //on cherche a savoir quelle carte l'utilisateur souhaite modifier
	cin >> id;

	if (CarteID[id].getID() == 0) {
		cout << "Cette id n'existe pas" << endl; //si il entre une id de carte non existante
	}
	else {
		CarteID[id].affiche(); //on affiche la carte correspondante

		cout << "\nQue souhaitez vous modifier?\n" << endl; // on demande quelle ligne de la carte l'utilisateur souhaite modifier
		cout << "1. nom" << endl;
		cout << "2. prenom" << endl;
		cout << "3. adresse" << endl;
		cout << "4. Code Postal" << endl;
		cout << "5. ville" << endl;
		cout << "\n0. Je ne souhaite rien modifier\n" << endl;
		cin >> choix;

		cin.ignore();

		switch (choix) { //choix de la ligne à changer

		case 1:
			cout << "Entrer le nouveau nom" << endl;
			getline(cin, mot);
			CarteID[id].setnom(mot);
			break;

		case 2:
			cout << "Entrer le nouveau prenom" << endl;
			getline(cin, mot);
			CarteID[id].setprenom(mot);
			break;

		case 3:
			cout << "Entrer la nouvelle adresse" << endl;
			getline(cin, mot);
			CarteID[id].setadresse(mot);
			break;

		case 4:
			cout << "Entrer le nouveau Code Postal" << endl;
			getline(cin, mot);
			CarteID[id].setCP(mot);
			break;

		case 5:
			cout << "Entrer la nouvelle ville" << endl;
			getline(cin, mot);
			CarteID[id].setville(mot);
			break;

		case 0:
			cout << "Retour au menu" << endl; //si l'utilisateur ne veut plus changer de ligne
			break;

		default: break;

		}
	}
	system("pause");

}

void SupprimerCarte(mCarteID CarteID[]) //suppression d'une carte
{

	int id;

	system("cls");

	cout << "Entrer l'id de la carte que vous souhaitez supprimer " << endl; // on demande a l'utilisateur quelle carte il souhaite supprimer
	cin >> id;

	if (CarteID[id].getID() == 0){
		cout << "Cette id n'existe pas" << endl; // si l'id entrée n'est associée à aucune carte
	}
	else {
		CarteID[id].suppress(); //on supprime la carte
	}

	cout << "\nVotre carte a bien ete supprime\n" << endl;// on signale a l'utilisateur que sa manoeuvre a aboutis

	system("pause");

}

void AfficherCarte(mCarteID CarteID[])// affichage d'une carte
{
	int id;

	system("cls");

	cout << "Entrer l'id de la carte que vous souhaitez afficher : " << endl; // on demande a l'utilisateur quelle carte il souhaite afficher
	cin >> id;
	cout << "\n" << endl;

	if (CarteID[id].getID() == 0) {
		cout << "Cette id n'existe pas" << endl;//dans le cas ou l'id n'est associée à aucune carte
	}
	else {
		CarteID[id].affiche();// affichage de la carte correspondante
	}
	cout << "\n" << endl;
	system("pause");


}

int FindVide(mCarteID CarteID[]) { //Empêche a une carte d'être remplacée par une autre lors de l'entrée d'une nouvelle carte

	int i = 1;

	while (CarteID[i].getID() != 0) { //tant que l'id n'est pas égal à 0
		i++;//on met l'id a id+1 pour que quand on rentre un nouvel utilisateur le précédent ne soit pas effacer et remplacé
	}

	return i;

}