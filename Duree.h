#pragma once
#include <ostream>
#ifndef DEF_DUREE
#define DEF_DUREE

class Duree
{
	public:
		Duree(int heures = 0, int minutes = 0, int secondes = 0);
		int getHeures() const;
		int getMinutes() const;
		int getSecondes() const;
		void setHeures(int v);
		void setMinutes(int v);
		void setSecondes(int v);
		bool estEgal(Duree const& b) const;
		
		Duree& operator+=(Duree const& a);
		void afficher(std::ostream& flux) const;

	private:
		void afficher(std::ostream& flux) const;
		friend std::ostream& operator<< (std::ostream& flux, Duree const& duree); //operator<< est amie de Duree: elle a accès à tous ses attributs
		int m_heures;
		int m_minutes;
		int m_secondes;
};

bool operator==(Duree const& a, Duree const& b);
bool operator!=(Duree const& a, Duree const& b);
Duree operator+(Duree const& a, Duree const& b);

#endif
