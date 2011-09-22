
#ifndef DRAW_SNAKE_H

#define DRAW_SNAKE_H

#include "OpenGl.h"
#include "sys.h"
void initializeSnake(snakePart_t part[100],GLfloat dim);
GLfloat drawSnake(GLfloat dim,DIRECTION direction,snakePart_t part[100]);
int drawPart(float actual_dim, DIRECTION direction, snakePart_t part[100],int count);

#endif