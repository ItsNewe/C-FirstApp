#pragma once

class Vehicule
{
public:
	virtual void affiche() const;  //Affiche une description du Vehicule
	virtual ~Vehicule(); //Un destructeur doit toujours être virtuel si l'objet utilise le polymorphisme
	virtual int nbrRoues() const = 0; //Méthode virtuelle pure, les classes filles l'ont mais pas la mère
protected:
	int m_prix;  //Chaque véhicule a un prix
};

//Les methodes des classes filles sont virtuelles par défaut (par héritage)
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