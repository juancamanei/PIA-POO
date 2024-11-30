#pragma once
#include "Animaciones.h"
class Rana :public Animacion {
	bool ubicacion = 1;
	GLdouble Tx;
	GLdouble Ty;
	GLdouble Tz;
	GLdouble Rotacion;
	bool mover = 1;
	bool detenerMov = 0;
	bool detenerGiro = 1;
	bool gira = 0;
public:
	Rana(GLdouble _rangoX, GLdouble _rangoZ, GLdouble _ox, GLdouble _oy, GLdouble _oz, string modelPath, string texturePath, bool mode)
		:Animacion(_rangoX, _rangoZ, _ox, _oy, _oz, modelPath, texturePath, mode) {
		Tx = _ox, Ty = _oy, Tz = _oz;

	};

	GLdouble getTy() { return Ty; }
	GLdouble getTx() { return Tx; }
	GLdouble getTz() { return Tz; }
	GLdouble getRotacion() { return Rotacion; }
	

	void animacion() {
		if (detenerMov == 0) {
			detenerGiro = 1;
			//"Y" para lo alto, vemos si x o z para el lado
			if (ubicacion == 1) {
				//se escribe asi para darle el valor exacto en el que incrementa
				//asi saltamos mija vamos a ver como avanzar
				setOy(getOy() + 0.5f); //Ty = Ty + 0.5;
				/*if (Ty >= 45) {
					ubicacion = 0;
				}*/
				
				if (getOy() >= 45) {
					ubicacion = 0;
				}
			}

			if (ubicacion == 0) {
				setOy(getOy() - 1); //Ty--;
				/*if (Ty <= 30) {
					ubicacion = 1;
				}*/
				if (getOy() <=30) {
					ubicacion = 1;
				}
			}

			////////////////////////////// avanza bien hecho mijaaaaa

			if (mover == 1) {
				//Tx++;
				setOX(getOX() + 1);
				if (getOX() >= -70 && getOy() <= 30) {
					mover = 0;
					detenerGiro = 0;//asi gira
				}
				//if (Tx >= -70 && Ty <= 30) {
				//	mover = 0;
				//	detenerGiro = 0;//asi gira
				//}

			}
			if (mover == 0) {
				//Tx--;
				setOX(getOX() - 1);
				if (getOX() <= -180 && getOy() <= 30) {
					mover = 1;
					detenerGiro = 0;//asi gira
				}
				//if (Tx <= -180 && Ty <= 30) {
				//	mover = 1;

				//	detenerGiro = 0;//asi gira
				//}
			}
		}//fin del bool para que detenga

		//////////////////ahora que gire cuando llegue a cada lugar
		if (detenerGiro == 0)
		{
			detenerMov = 1;

			if (gira == 1) {

				Rotacion = Rotacion + 2;
				if (Rotacion >= 180) {
					gira = 0;
					detenerMov = 0;//asi avanza
				}

			}
			if (gira == 0) {
				Rotacion = Rotacion - 2;

				if (Rotacion <= 0) {
					gira = 1;
					detenerMov = 0;//asi avanza
				}
			}
		}//fikn del bool para que gire al detenrse el salto y traslacion

	}

	/*bool getmover() { return mover; }
	bool getubicacion() { return ubicacion; }
	bool getdetenerMov() { return detenerMov; }
	bool getdetenerGiro() { return detenerGiro; }
	bool getgira() { return gira; }

	void setmover(){}*/
};