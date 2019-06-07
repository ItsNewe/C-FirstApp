#include <iostream>
#include "Vehicules.h"

Vehicule::~Vehicule() {} //Même si les destruct ne servent a rien, on doit les mettre (poly)
void Vehicule::affiche() const
{
	std::cout << "Ceci est un vehicule." << std::endl;
}

Voiture::~Voiture() {}
void Voiture::affiche() const
{
	std::cout << "Ceci est une voiture." << std::endl;
}
int Voiture::nbrRoues() const
{
	return 4;
}

Moto::~Moto() {}
void Moto::affiche() const
{
	std::cout << "Ceci est une moto." << std::endl;
}
int Voiture::nbrRoues() const
{
	return 2;
}