#pragma once
#include "Animaciones.h"
class EspirituA : public Animacion{
	//atributos

	GLdouble STy;
	bool salto;

	bool baila;



public:
	EspirituA(GLdouble _rangoX, GLdouble _rangoZ, GLdouble _ox, GLdouble _oy, GLdouble _oz, string modelPath, string texturePath, bool mode) 
		:Animacion(_rangoX, _rangoZ, _ox, _oy, _oz, modelPath, texturePath, mode) {
		baila = true;
	
	};

	GLdouble getSTy(){ return STy; }

	void animacion() {

		if (baila == false) {

		if (salto == 1) {
			//se escribe asi para darle el valor exacto en el que incrementa
			//asi saltamos mija vamos a ver como avanzar
			STy = STy + 0.5;
			if (STy >= 25) {
				salto = 0;
			}
		}

		if (salto == 0) {
			STy--;
			if (STy <= 17) {
				salto = 1;
				baila = true;
			}
		}
		


	}

	}

	bool getbaila() { return baila; }

	void  setbaila(bool _baila) { baila = _baila; }

};