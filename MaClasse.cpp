#include <iostream>
#include "MaClasse.h"

//Initialiser l'attribut en dehors de toute fonction ou classe (espace global)
int maClasse::compteur = 0; //Se comporte comme une variable golbale

//On peut s'en servir de compteur
maClasse::maClasse()
{
	compteur++;
}
maClasse::~maClasse() {
	compteur--;
}
void maClasse::maMethode() //Ne pas remettre 'static' dans l'implémentation
{
	std::cout << "Bonjour !" << std::endl;
}
int maClasse::nombreInstances() {
	return compteur;
}