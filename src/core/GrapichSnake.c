

#include "GrapichSnake.h"


void drawSnake(GLfloat dim){  
	GLdouble j = -dim;

	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(0,0,0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	while (j <= dim){
		glVertex2f(j,-0.0);
		j= j + 0.001;
	}
	glEnd();
	glFlush();
}