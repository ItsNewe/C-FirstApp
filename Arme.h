#pragma once
#ifndef DEF_ARME
#define DEF_ARME

#include <string>

class Arme {
	public:
		Arme();
		Arme(std::string nom, int degats);
		void changer(std::string nom, int degats);
		void afficher() const;
		int getDegats() const;
		std::string getName() const;

	private:
		std::string m_nom;
		int m_degats;
	};
#endif