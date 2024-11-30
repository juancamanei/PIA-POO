#pragma once
#include <string>
using namespace std;
#include "glm.h"
#include "BMPLoader.h"
#include"colisones.h"

namespace EDXFramework {

	class Model:public Colision {
public:
	Model(GLdouble _rangoX, GLdouble _rangoZ, GLdouble _ox, GLdouble _oy, GLdouble _oz);
	Model(GLdouble _rangoX, GLdouble _rangoZ, GLdouble _ox, GLdouble _oy, GLdouble _oz,
		string modelPath, string texturePath, bool mode);
	virtual ~Model();
	void Draw();
private:
	GLMmodel* model;
	BMPClass texture;
	unsigned int textureId;
	unsigned int drawMode;
};

}
