#pragma once
#include "MaClasse.h"

class maClasse
{
public:
	maClasse();
	~maClasse();
	static void maMethode();
	static int nombreInstances();
private:
	static int compteur;
};