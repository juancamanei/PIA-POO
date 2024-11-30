#pragma once
#include<iostream>
#include <gl\GLU.h>
#include <gl\GL.h>
#include <math.h>

using namespace std;

class Colision{
	//ox, oz son las coordenadas del centro
	//Rgx y Rgz son las distancias del centro a los lados del cuadriletaro
	GLfloat  oy, ox, oz, rangoX, rangoZ;

	GLdouble distamcia;


public:
	Colision() {};
	Colision(GLdouble _rangoX, GLdouble _rangoZ, GLdouble _ox, GLdouble _oy, GLdouble _oz)
	{
		rangoX = _rangoX;
		rangoZ = _rangoZ;
		ox = _ox;
		oy = _oy;
		oz = _oz;
	};

	GLdouble getOX() { return ox; }
	GLdouble getOy() { return oy; }
	GLdouble getOz() { return oz; }
	GLdouble getRX() { return rangoX; }
	GLdouble getRZ() { return rangoZ; }


	void setOX(GLdouble _ox){  ox=_ox; }
	void setOy(GLdouble _oy) {  oy=_oy; }
	void setOz(GLdouble _oz) {  oz=_oz; }
	void setRX(GLdouble _rangoX) {  rangoX=_rangoX; }
	void setRZ(GLdouble _rangoZ) {  rangoZ=_rangoZ; }

public:
	bool Hitbox(GLfloat Px, GLfloat Pz)
	{
		if (Px > ox - rangoX && Px < ox + rangoX) {
			if (Pz > oz - rangoZ && Pz < oz + rangoZ) {
				return true;
			}
		}
		return false;

	}

	bool HitboxCircular(GLfloat Px, GLfloat Pz) {
		//distan entre dos pppuntos
		distamcia = sqrt(pow((Px - ox), 2) + pow((Pz - oz), 2));

		if (distamcia <= rangoX) {
			return true;
		}
		return false;
	}


	

};