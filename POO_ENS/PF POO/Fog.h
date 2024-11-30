#ifndef __Fog
#define __Fog

#include <gl\GLU.h>
#include <gl\GL.h>

class Fog
{
public:
	GLfloat Color[4];
	GLfloat density;

	Fog(GLfloat _color[4], GLfloat _density) {
		for (int i = 0; i < 4; i++)
		{
			Color[i] = _color[i];
		}
		density = _density;
	}

	void draw() {
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_FOG); 
		glFogi(GL_FOG_MODE, GL_EXP2); 
		glFogfv(GL_FOG_COLOR, Color); 
		glFogf(GL_FOG_DENSITY, density);
		glHint(GL_FOG_HINT, GL_NICEST);

	}
};

#endif