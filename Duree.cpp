#include "Duree.h"
#include <ostream>
Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{
}

bool Duree::estEgal(Duree const& b) const
{
	return (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes);     //Teste si a.m_heure == b.m_heure etc.  
}

void Duree::afficher(std::ostream& flux) const
{
	flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
}

int Duree::getHeures() const { return m_heures; }
int Duree::getMinutes() const { return m_minutes; }
int Duree::getSecondes() const { return m_secondes; }
void Duree::setHeures(int v) { m_heures = v; }
void Duree::setMinutes(int v) { m_minutes = v; }
void Duree::setSecondes(int v) { m_secondes = v; }

bool operator==(Duree const& a, Duree const& b)
{
	return (a.estEgal(b));
}
bool operator!=(Duree const& a, Duree const& b)
{
	return !(a == b);
}
Duree operator+(Duree const& a, Duree const& b)
{
	Duree resultat;
	resultat.setHeures(a.getHeures + b.getHeures);
	resultat.setMinutes(a.getMinutes + b.getSecondes);
	resultat.setSecondes(a.getSecondes + b.setSecondes);
	return resultat;
}

Duree& Duree::operator+=(const Duree& a)
{
	//1 : ajout des secondes
	m_secondes += a.getSecondes;
	//Si le nombre de secondes dépasse 60, on rajoute des minutes
	//Et on met un nombre de secondes inférieur à 60
	m_minutes += m_secondes / 60;
	m_secondes %= 60;

	//2 : ajout des minutes
	m_minutes += a.getMinutes;
	//Si le nombre de minutes dépasse 60, on rajoute des heures
	//Et on met un nombre de minutes inférieur à 60
	m_heures += m_minutes / 60;
	m_minutes %= 60;

	//3 : ajout des heures
	m_heures += a.m_heures;
	return *this;
}

std::ostream& operator<<(std::ostream& flux, Duree const& duree)
{
	duree.afficher(flux);
	return flux;
}