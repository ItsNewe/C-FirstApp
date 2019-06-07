#include <iostream>
#include <string>
#include "Guerrier.h"

Guerrier::Guerrier(std::string nom): Personnage(nom), m_vie=200{}

void Guerrier::crier(std::string phrase = "AAAAAAAH") {
	std::cout << phrase;
}

void Guerrier::sePresenter() const
{
	Personnage::sePresenter();
	std::cout << "Je suis un Guerrier redoutable." << std::endl;
}