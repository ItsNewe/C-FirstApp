#pragma once

class Vehicule
{
public:
	virtual void affiche() const;  //Affiche une description du Vehicule
	virtual ~Vehicule(); //Un destructeur doit toujours �tre virtuel si l'objet utilise le polymorphisme
	virtual int nbrRoues() const = 0; //M�thode virtuelle pure, les classes filles l'ont mais pas la m�re
protected:
	int m_prix;  //Chaque v�hicule a un prix
};

//Les methodes des classes filles sont virtuelles par d�faut (par h�ritage)
class Voiture : public Vehicule //Une Voiture EST UN Vehicule
{
public:
	void affiche() const;
	virtual ~Voiture(); //Poly
	virtual int nbrRoues() const;

private:
	int m_portes;  //Le nombre de portes de la voiture
};

class Moto : public Vehicule  //Une Moto EST UN Vehicule
{
public:
	void affiche() const;
	virtual ~Moto(); //Poly
	virtual int nbrRoues() const;

private:
	double m_vitesse;  //La vitesse maximale de la moto
};