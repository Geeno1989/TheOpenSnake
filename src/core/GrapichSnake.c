

#include "GrapichSnake.h"


GLfloat drawSnake(GLfloat dim,GLfloat *moviment){	
	GLfloat j = -dim + *moviment;
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(0,0,0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	while (j <= dim + *moviment){
		glVertex2f(j,0.0);
		j=j + 0.001;
	}
	glEnd();
	glFlush();
	*moviment = *moviment + 0.001;
}