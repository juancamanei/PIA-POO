#pragma once
#include<iostream>
//cuando hagas colision se quitan las dos de abajo
#include <gl\GLU.h>
#include <gl\GL.h>
#include<math.h>
#include"Model.h"
using namespace std;
//Refetencia explicita :: 
//tengo que declarar siempre de que manera se hereda en este caso public
class Animacion:public EDXFramework ::Model  {
public:
	
public:
	//constructor
	//ocupa los parametros del model.h
	Animacion(GLdouble _rangoX, GLdouble _rangoZ, GLdouble _ox, GLdouble _oy, GLdouble _oz,string modelPath, string texturePath, bool mode) 
		:Model(_rangoX, _rangoZ, _ox, _oy, _oz,modelPath, texturePath, mode) {
	};
	
	//metodo virtual 
	
	virtual void animacion() {

	}


};