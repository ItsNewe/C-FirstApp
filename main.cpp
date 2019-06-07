#include <iostream>
#include <string>
#include <vector> //Tableau dynamiques
#include <fstream> //File handling
#include "Personnage.h" //Classes, héritage
#include "Duree.h" //Opérateurs
#include "Vehicules.h" //Methodes virtuelles
#include "MaClasse.h" //Methodes & attributs statiques

using namespace std;

void direBonjour() //Fonction sans retour
{
	cout << "Bonjour !" << endl;
	//Comme rien ne ressort, il n'y a pas de return !
}

void f1(string const& texte)  //Pas de copie et pas de modification possible
{}
/*
 *  Fonction qui calcule la moyenne des éléments d'un tableau
 *  - tableau : Le tableau dont on veut la moyenne
 *  - tailleTableau : La taille du tableau
 */
double moyenne(double tableau[], int tailleTableau)
{
	double moyenne(0);
	for (int i(0); i < tailleTableau; ++i)
	{
		moyenne += tableau[i];   //On additionne toutes les valeurs
	}
	moyenne /= tailleTableau;

	return moyenne;
}

//POLYMORPHISME
void presenter(Vehicule const& v)  //Présente le véhicule passé en argument
{
	v.affiche();
}

int main()
{
	string stringLol = "Newezzz"; //Définition variable
	string stringMdr("Autre moyen de définir une variable");
	string& nom = stringLol; //Référence à une variable

	int const oui = 69; //Constante immutable
	int ageUser; //Définition objet variable fin bref tu m'a compris
	cout << "Adresse nom= " << &nom << endl;
	//INPUT
	cout << "Quel age avez vous?" << endl;
	cin >> ageUser; // Cela s'arrête au premier espace ou \n
	
	cout << "Quel est votre nom?" << endl;
	string nom2;
	getline(cin, nom2);
	nom2[0] = 'L';  //On modifie la première lettre
    cout << "Hello " << nom <<", vous avez " << ageUser<<" ans" << endl; //Console output
	cout << "Votre nom fait " << nom.size() << " caractères" << endl;

	//ARRAYS
	int meilleurScore[5];       //Déclare un tableau de 5 int 
	meilleurScore[2] = 69; //Redéfinition

	int multDimension[5][4]; //Array multi dimensionelle

	//VECTORS
	vector<int> tableau(2, 3);  //Crée un tableau de 2 entiers valant tous 3
	tableau[0] = 1;
	tableau[1] = 2;
	tableau.push_back(3); //On push l'array de 1 slot et on insère 3
	tableau.pop_back(); //On supprime un slot de l'array

	//FILE HANDLING
	string const nomFichier("C:/Users/Newe/Desktop/Dev/c++.txt");

	ofstream outFlux(nomFichier.c_str()); //Ouverture d'un flux w
	//ofstream outFlux(nomFichier.c_str(), ios::app); //Ouverture d'un flux a
	if (outFlux) { //Test si le flux est bien ouvert

		outFlux << "Lol j'écris" << endl;
		int position = outFlux.tellp(); //position du curseur
		outFlux.seekp(5, ios::beg); //Déplacement du curseur
		/*
		ios::beg : beggining
		ios::end : fin
		ios::cur : current
		*/
		cout << "Écriture réussie" << endl;
	}
	else { 
		cout << "ERREUR: impossible d'ouvrir le fichier" << endl;
	}

	ifstream inFlux(nomFichier.c_str());
	if (inFlux) {
		cout << "Curseur @ " << inFlux.tellg() << endl; //position du curseur
		double nombre;
		inFlux >> nombre; //Lit un nombre à virgule depuis le fichier
		string mot;
		inFlux >> mot;    //Lit un mot depuis le fichier
		char a;
		inFlux.get(a);

		inFlux.ignore(); //On change de mode
		string ligne;
		getline(inFlux, ligne); //On lit une ligne complète

		inFlux.ignore();
		inFlux.seekg(0, ios::beg);
		while (getline(inFlux, ligne)) //Tant qu'on n'est pas à la fin, on lit
		{
			cout << ligne << endl;
		}

		inFlux.close();  //Non nécessaire seulement si forcé, les flux se ferment automatiquement après sortie de scope
	}
	else {
		cout << "Erreur";
	}

	//POINTEURS
	int *pointeur(0); //toujours initialiser un pointeur avec 0 (adresse vide) pour éviter pick random de la ram

	pointeur = new int; //On demande manuellement une adresse mémoire
	*pointeur = 2;

	delete pointeur;  //On libère la case mémoire

	//CLASSES
	//Definition des classes dans deux fichiers séparés (.cpp pour les méthodes, .h pour les définitions)
	Personnage david("david");
	Personnage goliath(david);

	goliath.attaquer(david);
	david.boirePotionDeVie(20);
	goliath.attaquer(david);
	david.attaquer(goliath);

	goliath.changerArme("Katana", 40);
	goliath.attaquer(david);


	//SURCHARGES : Classe durée
	Duree duree1(0, 10, 28), duree2(0, 15, 2);

	//OPERATEURS
	if (duree1 == duree2)
		cout << "Les durees sont identiques";
	else
		cout << "Les durees sont differentes";

	//POLYMORPHISME, METH VIRTUELLES
	Vehicule v; //Ne compilera pas: classe abstraite

	Moto m;
	presenter(m);

	//COLLECTIONS HETEROGENES
	vector<Vehicule*> listeVehicules;
	listeVehicules.push_back(new Moto());
	listeVehicules.push_back(new Voiture());

	//On utilise les voitures et les motos

	//IL FAUT VIDER LA MEMOIRE UTILISEE PAR LES POINTEURS QUAND ON FAIT NEW
	for (int i(0); i < listeVehicules.size(); ++i)
	{
		delete listeVehicules[i];  //On libère la i-ème case mémoire allouée
		listeVehicules[i] = 0;  //On met le pointeur à 0 pour éviter les soucis
	}

	//elements statiques
	maClasse::maMethode(); //On peut appeler la méthode statique sans créer d'objet, partique pour rangement

	return 0; //Return code 0 = OK
}