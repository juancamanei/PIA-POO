#pragma once
#include "Animaciones.h"
class TORN :public Animacion {
	bool ubicacion = 1;
	GLdouble Tx;
	GLdouble Ty;
	GLdouble Tz;
	GLdouble Rotacion;
	bool mover = 1;
	bool detenerMov = 0;
	bool moverz = 1;
	bool gira = 0;
public:
	TORN(GLdouble _rangoX, GLdouble _rangoZ, GLdouble _ox, GLdouble _oy, GLdouble _oz, string modelPath, string texturePath, bool mode,GLdouble _Tx, GLdouble _Tz)
		:Animacion(_rangoX, _rangoZ, _ox, _oy, _oz, modelPath, texturePath, mode) {
		//Tx = _Tx, Tz = _Tz;// pa que colisione again
		Tx = _ox, Ty = _oy, Tz = _oz;
	};

	GLdouble getTy() { return Ty; }
	GLdouble getTx() { return Tx; }
	GLdouble getTz() { return Tz; }
	GLdouble getRotacion() { return Rotacion; }


	void animacion() {


		Rotacion=Rotacion+1.8;
		if (Rotacion == 360)
			Rotacion = 0;
		if (mover == 1) {
			setOX(getOX() - 1);//Tx--;
			//el como avanzo

			if (getOX() <= 98) {
				mover = 0;
			}
		}
		else if (mover==0) {
			setOX(getOX() + 1);//Tx++;
			if (getOX() >= 238) {
				mover = 1;
			}

		}
	/// EN TZ
		if (moverz == 1) {
			setOz(getOz() - 1);//Tz--;
			//el como avanzo
			if (getOz() <=236) {
				moverz = 0;
			}
		}
		else if (moverz == 0) {
			setOz(getOz() + 1);//Tz++;
			if (getOz() >= 266) {
				moverz = 1;
			}

		}
	}

	

	
};