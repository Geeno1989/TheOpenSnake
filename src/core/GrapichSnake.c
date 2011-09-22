

#include "GrapichSnake.h"

void initializeSnake(snakePart_t part[100],GLfloat dim){
	int j;

	for(j=0; j<=dim-1;j++)
	{
		part[j].direction_old = STOP;
		part[j].direction_new = STOP;
		part[j].startx = 0;
		part[j].stopx = 0;
		part[j].starty = 0;
		part[j].stopy = 0;
	}
	while(j<=99){
		part[j].direction_old = NOT_INIZIALIZED;
		part[j].direction_new = NOT_INIZIALIZED;
		part[j].startx = 0;
		part[j].stopx = 0;
		part[j].starty = 0;
		part[j].stopy = 0;
	j++;
	}
}

GLfloat drawSnake(float dim, DIRECTION direction,snakePart_t part[100]){	
	//GLfloat j = -dim + direction;
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(0,0,0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	drawPart(dim,direction,part,0);
	glEnd();
	glFlush();
	//moviment = moviment + 0.001;
}

int drawPart(float actual_dim, DIRECTION direction, snakePart_t part[100],int count){
	int maxcount;
	DIRECTION correctDir;
	GLfloat startp,endp; 

	if(part[count].direction_old == NOT_INIZIALIZED)
	{
		/*head is found*/
		count = count- 1;
				
		if(part[count].direction_new == DOWN && direction == UP || part[count].direction_new == UP && direction == DOWN)
			direction = part[count].direction_new;
		if(part[count].direction_new == LEFT && direction == RIGHT || part[count].direction_new == RIGHT && direction == LEFT)
			direction = part[count].direction_new;
		switch(direction)
		{
		case STOP:/*STOP situation*/
			part[count].direction_old = part[count].direction_new;
			part[count].direction_new = direction;
			part[count].startx = 0.0;/*Start of the part*/
			part[count].stopx = 0.1;/*End of the part*/
			while (part[count].startx < part[count].stopx)
			{
				
				glVertex2f(part[count].startx,part[count].starty);
				part[count].startx = part[count].startx + 0.001;
			}
			
			break;
		case RIGHT:/*right situation*/
			part[count].direction_old = part[count].direction_new;
			part[count].direction_new = direction;
			part[count].startx = (GLfloat) part[count].startx ;/*Start of the part*/
			part[count].stopx = (GLfloat) part[count].startx + 0.1;/*End of the part*/
			while (part[count].startx < part[count].stopx)
			{
				
				glVertex2f(part[count].startx,part[count].starty);
				part[count].startx = part[count].startx + 0.001;
			}
			break;
		case UP:/*up situation*/
			part[count].direction_old = part[count].direction_new;
			part[count].direction_new = direction;

			part[count].starty = (GLfloat) part[count].starty;/*Start of the part*/
			part[count].stopy = (GLfloat) part[count].starty + 0.1;/*End of the part*/
			while (part[count].starty < part[count].stopy)
			{
				glVertex2f((part[count].startx),part[count].starty);
				part[count].starty = part[count].starty + 0.001;
			}
			break;
		case LEFT:/*Left situation*/
				part[count].direction_old = part[count].direction_new;
				part[count].direction_new = direction;

				part[count].startx = (GLfloat) part[count].startx;/*Start of the part*/
				part[count].stopx = (GLfloat) part[count].startx - 0.1;/*End of the part*/

				while (part[count].startx > part[count].stopx)
				{
					glVertex2f(part[count].startx,part[count].starty);
					part[count].startx = part[count].startx - 0.001;
				}
			break;
		case DOWN:/*Down situation*/
				part[count].direction_old = part[count].direction_new;
				part[count].direction_new = direction;
				part[count].starty =(GLfloat)  part[count].starty;/*Start of the part*/
				part[count].stopy =(GLfloat)  part[count].starty - 0.1;/*End of the part*/
				while (part[count].starty > part[count].stopy)
				{
					glVertex2f((part[count].startx),part[count].starty);
					part[count].starty = part[count].starty - 0.001;
				}
		}
		
		return maxcount = count - 1; 
	}
	else
	{
		maxcount = drawPart(actual_dim,direction,part,count+1);	/*call ricorsively until the head is find*/
		
		/*GESTIRE DIMENSIONI E PARTI*/
		if(maxcount >= count){

		part[count].direction_old = part[count].direction_new; 
		part[count].direction_new = part[count+1].direction_old;
		
		/*Draw the part */
		
		switch(part[count].direction_new)
		{
		case STOP:/*STOP situation*/
			if(part[count+1].direction_new == STOP){
			part[count].startx = (GLfloat) part[count+1].startx - 0.2;/*Start of the part*/
			part[count].stopx = (GLfloat) part[count+1].startx  - 0.1;/*End of the part*/
			while (part[count].startx < part[count].stopx)
			{
				
				glVertex2f(part[count].startx,0.0);
				part[count].startx = part[count].startx + 0.001;
			}
			}
			else
			{
				part[count].startx = (GLfloat) part[count+1].startx - 0.1;/*Start of the part*/
				part[count].stopx = (GLfloat) part[count+1].startx;/*End of the part*/
				while (part[count].startx < part[count].stopx)
				{
					glVertex2f(part[count].startx,0.0);
					part[count].startx = part[count].startx + 0.001;
				}
			}
			break;
		case RIGHT:/*right situation*/
			if(part[count+1].direction_new == RIGHT){
				part[count].startx = (GLfloat) part[count+1].startx - 0.2 ;/*Start of the part*/
				part[count].stopx = (GLfloat) part[count+1].startx - 0.1;/*End of the part*/
				while (part[count].startx < part[count].stopx)
				{
					glVertex2f(part[count].startx,part[count].starty);
					part[count].startx = part[count].startx + 0.001;
				}
			}
			else if(part[count+1].direction_new == UP)
			{
				part[count].startx = (GLfloat) part[count+1].startx - 0.1;/*Start of the part*/
				part[count].stopx = (GLfloat) part[count+1].startx;/*End of the part*/
				part[count].starty =(GLfloat)  part[count+1].starty - 0.1;
				while (part[count].startx < part[count].stopx)
				{
					glVertex2f(part[count].startx,part[count].starty);
					part[count].startx = part[count].startx + 0.001;
				}
			}
			else if (part[count+1].direction_new == DOWN)
			{
				part[count].startx = (GLfloat) part[count+1].startx - 0.1;/*Start of the part*/
				part[count].stopx = (GLfloat) part[count+1].startx;/*End of the part*/
				part[count].starty = (GLfloat) part[count+1].starty + 0.1;
				while (part[count].startx < part[count].stopx)
				{
					glVertex2f(part[count].startx,part[count].starty);
					part[count].startx = part[count].startx + 0.001;
				}
			}
			break;
		case UP:/*up situation*/
			if(part[count+1].direction_new == UP){
				part[count].starty = (GLfloat) part[count+1].starty - 0.2;/*Start of the part*/
				part[count].stopy = (GLfloat) part[count+1].starty - 0.1;/*End of the part*/
				while (part[count].starty < part[count].stopy)
				{
					glVertex2f((part[count+1].startx),part[count].starty);
					part[count].starty = part[count].starty + 0.001;
				}
			}
			else if(part[count+1].direction_new == RIGHT || part[count+1].direction_new == LEFT)
			{
				part[count].starty = (GLfloat) part[count+1].starty - 0.1;/*Start of the part*/
				part[count].stopy =(GLfloat)  part[count+1].starty;/*End of the part*/
				while (part[count].starty < part[count].stopy)
				{
					glVertex2f((part[count].startx),part[count].starty);
					part[count].starty = part[count].starty + 0.001;
				}
			}
			
			break;

			case LEFT:/*right situation*/
			if(part[count+1].direction_new == LEFT){
				part[count].startx = (GLfloat) part[count+1].startx + 0.2 ;/*Start of the part*/
				part[count].stopx = (GLfloat) part[count+1].startx + 0.1;/*End of the part*/
				while (part[count].startx > part[count].stopx)
				{
					glVertex2f(part[count].startx,part[count].starty);
					part[count].startx = part[count].startx - 0.001;
				}
			}
			else if(part[count+1].direction_new == UP)
			{
				part[count].startx = (GLfloat) part[count+1].startx + 0.1;/*Start of the part*/
				part[count].stopx = (GLfloat) part[count+1].startx;/*End of the part*/
				part[count].starty = (GLfloat) part[count+1].starty - 0.1;
				while (part[count].startx > part[count].stopx)
				{
					glVertex2f(part[count].startx,part[count].starty);
					part[count].startx = part[count].startx - 0.001;
				}
			}
			else if(part[count+1].direction_new == DOWN)
			{
				part[count].startx = (GLfloat) part[count+1].startx + 0.1;/*Start of the part*/
				part[count].stopx = (GLfloat) part[count+1].startx;/*End of the part*/
				part[count].starty = (GLfloat) part[count+1].starty + 0.1;
				while (part[count].startx > part[count].stopx)
				{
					glVertex2f(part[count].startx,part[count].starty);
					part[count].startx = part[count].startx - 0.001;
				}
			}
			break;
		case DOWN:/*up situation*/
			if(part[count+1].direction_new == DOWN){
				part[count].starty = (GLfloat) part[count+1].starty + 0.2;/*Start of the part*/
				part[count].stopy =(GLfloat) part[count+1].starty + 0.1;/*End of the part*/
				while (part[count].starty > part[count].stopy)
				{
					glVertex2f((part[count+1].startx),part[count].starty);
					part[count].starty = part[count].starty - 0.001;
				}
			}
			else if(part[count+1].direction_new == RIGHT || part[count+1].direction_new == LEFT)
			{
				part[count].starty = (GLfloat) part[count+1].starty + 0.1;/*Start of the part*/
				part[count].stopy = (GLfloat) part[count+1].starty;/*End of the part*/
				while (part[count].starty > part[count].stopy)
				{
					glVertex2f((part[count].startx),part[count].starty);
					part[count].starty = part[count].starty - 0.001;
				}
			}
			
			break;
		}
		return maxcount;
		}
		return maxcount;
	}
}