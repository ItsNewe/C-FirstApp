#include "Personnage.h"
#include <iostream>

using namespace std;

Personnage::Personnage(string nom)
{
	m_nom = nom;
	m_vie = 100;
	m_mana = 100;
	m_arme = new Arme("Épée rouillée", 10);
}
//Personnage::Personnage() : m_vie(100), m_mana(100), m_nomArme("Épée rouillée"), m_degatsArme(10){} //pareil, rien dans le corps

Personnage::Personnage(Personnage const& personnageACopier)
	: m_vie(personnageACopier.m_vie), m_mana(personnageACopier.m_mana), m_arme(0)
{
	m_arme = new Arme(*(personnageACopier.m_arme)); //On recupère les attributs du pointeur et on les passe au constructeur de copie par défaut Arme(Arme const& arme);
}

Personnage::~Personnage() {
	delete m_arme; //On supprime l'élément associé au pointeur m_arme pour eviter memory leak
}

void Personnage::recevoirDegats(int nbDegats)
{
	m_vie -= nbDegats;
}

void Personnage::attaquer(Personnage& cible)
{
	cible.recevoirDegats(m_arme->getDegats()); //Pour les méthodes d'un pointeur, on utilise "->" et non pas "."
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
	m_vie += quantitePotion;
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
	m_arme->changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant() const
{
	return m_vie > 0; //Renvoie true si m_vie > 0 et false sinon.
}

Personnage* Personnage::getAdress() const
{
	return this; //renvoie le pointeur, ici *this renvoie l'objet lui même (type retour fonc)
}

Personnage& Personnage::operator=(Personnage const& personnageACopier)
{
	if (this != &personnageACopier)
		//On vérifie que l'objet n'est pas le même que celui reçu en argument
	{
		m_vie = personnageACopier.m_vie; //On copie tous les champs
		m_mana = personnageACopier.m_mana;
		delete m_arme;
		m_arme = new Arme(*(personnageACopier.m_arme));
	}
	return *this; //On renvoie l'objet lui-même
}

void Personnage::sePresenter() const {
	cout << "Je m'appelle " << m_nom << "." << endl << "J'ai encore " << m_vie << "HP.";
}