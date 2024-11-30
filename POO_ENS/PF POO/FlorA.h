#pragma once
#include "Animaciones.h"
class FlorA:public Animacion {


	bool ubicacion = 1;
	GLdouble Rotacion;
	//si lo inicio en 0 creo que desaparece
	GLdouble Sx = 1;
	GLdouble Sy;
	GLdouble Sz;

	
	bool mover = 1;
	bool detenerMov = 0;
	bool detenerGiro = 1;
	bool gira = 0;
public:
	FlorA(GLdouble _rangoX, GLdouble _rangoZ, GLdouble _ox, GLdouble _oy, GLdouble _oz, string modelPath, string texturePath, bool mode)
		:Animacion(_rangoX, _rangoZ, _ox, _oy, _oz, modelPath, texturePath, mode){

	};
	GLdouble getSx() { return Sx; }
	GLdouble getSy() { return Sy; }
	GLdouble getSz() { return Sz; }
	GLdouble getRotacion() { return Rotacion; }

	void animacion()
	{
		Rotacion++;
		if (Rotacion == 360)
			Rotacion = 0;

		//Sx = Sx * sin(Rotacion)+2;


		if (ubicacion == 1)
		{
			Sx = Sx + .01;
			if (Sx >= 4) {
				ubicacion = 0;
			}

		}

		if (ubicacion == 0)
		{
			Sx = Sx - .01;
			if (Sx <= 2.5) {
				ubicacion = 1;
			}
		}

	}

};