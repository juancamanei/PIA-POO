#pragma once
#include "Animaciones.h"
class Lobo :public Animacion {

	bool ubicacion = 1;
	GLdouble Sx = 1;
	GLdouble Sy;
	GLdouble Sz;

public:
	Lobo(GLdouble _rangoX, GLdouble _rangoZ, GLdouble _ox, GLdouble _oy, GLdouble _oz, string modelPath, string texturePath, bool mode)
		:Animacion(_rangoX, _rangoZ, _ox, _oy, _oz, modelPath, texturePath, mode) {

	};
	GLdouble getSx() { return Sx; }
	GLdouble getSy() { return Sy; }
	GLdouble getSz() { return Sz; }
	
	void animacion()
	{
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