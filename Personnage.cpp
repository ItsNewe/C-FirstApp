#include "Personnage.h"
#include <iostream>

using namespace std;

Personnage::Personnage(string nom)
{
	m_nom = nom;
	m_vie = 100;
	m_mana = 100;
	m_arme = new Arme("�p�e rouill�e", 10);
}
//Personnage::Personnage() : m_vie(100), m_mana(100), m_nomArme("�p�e rouill�e"), m_degatsArme(10){} //pareil, rien dans le corps

Personnage::Personnage(Personnage const& personnageACopier)
	: m_vie(personnageACopier.m_vie), m_mana(personnageACopier.m_mana), m_arme(0)
{
	m_arme = new Arme(*(personnageACopier.m_arme)); //On recup�re les attributs du pointeur et on les passe au constructeur de copie par d�faut Arme(Arme const& arme);
}

Personnage::~Personnage() {
	delete m_arme; //On supprime l'�l�ment associ� au pointeur m_arme pour eviter memory leak
}

void Personnage::recevoirDegats(int nbDegats)
{
	m_vie -= nbDegats;
}

void Personnage::attaquer(Personnage& cible)
{
	cible.recevoirDegats(m_arme->getDegats()); //Pour les m�thodes d'un pointeur, on utilise "->" et non pas "."
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
	return this; //renvoie le pointeur, ici *this renvoie l'objet lui m�me (type retour fonc)
}

Personnage& Personnage::operator=(Personnage const& personnageACopier)
{
	if (this != &personnageACopier)
		//On v�rifie que l'objet n'est pas le m�me que celui re�u en argument
	{
		m_vie = personnageACopier.m_vie; //On copie tous les champs
		m_mana = personnageACopier.m_mana;
		delete m_arme;
		m_arme = new Arme(*(personnageACopier.m_arme));
	}
	return *this; //On renvoie l'objet lui-m�me
}

void Personnage::sePresenter() const {
	cout << "Je m'appelle " << m_nom << "." << endl << "J'ai encore " << m_vie << "HP.";
}