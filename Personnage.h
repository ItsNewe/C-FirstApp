#pragma once
#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include "Arme.h"

class Personnage
{
	public:
		Personnage(std::string nom); //Constructeur
		Personnage(Personnage const& personnageACopier); //Constructeur de copie
		~Personnage(); //Destructeur
		void recevoirDegats(int nbDegats);
		void attaquer(Personnage& cible);
		void boirePotionDeVie(int quantitePotion);
		void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
		bool estVivant() const;
		void sePresenter() const;
		Personnage* getAdress() const;
		Personnage& operator=(Personnage const& personnageACopier);

	protected: //Privé, mais accessible aux éléments enfants
		int m_vie; //Bonne habitude: m_[nom var] pour variables initiales, m= "membre"
		int m_mana;
		Arme *m_arme; //Pointeur, arme n'est plus contenue dans le personnega mais liée à lui
		std::string m_nom;
	};
#endif