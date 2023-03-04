#define _USE_MATH_DEFINES
#include<Windows.h>
#include<iostream>
#include "glut.h"




#define SHAPE_CHARATERISTICS Color color,int startX,int startY,int lineWidth
#define SHAPE_VALUES color,startX,startY, lineWidth
//enum (Enumeration - Перечисление) - это набор именованных констант типа 'int'


void triangle(void) 
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glBegin(GL_TRIANGLES);
   glColor3f(1, 0, 0);   glVertex2f(-0.5, -0.5);
 
   glColor3f(0, 1, 0);   glVertex2f(0.5, -0.5);
  
   glColor3f(0, 0, 1);    glVertex2f(0.0, 0.5);
 
   glEnd();

   glutSwapBuffers();


}

void Chap(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0); 	glVertex2f(-0.5, -0.5);
	glColor3f(0, 1, 0); 	glVertex2f(0.0, -0.5);
	glColor3f(0, 0, 1);    glVertex2f(0.0, 0.5);

	glColor3f(1, 0, 0); 	glVertex2f(-0.5, -0.5);
	glColor3f(0, 1, 0); 	glVertex2f(0.0, 0.5);
	glColor3f(0, 0, 1);    glVertex2f(0.0, 0.0);

	//glColor3f(1, 0, 0); 	glVertex2f(0, 0);
	//glColor3f(0, 1, 0); 	glVertex2f(0, 1);
	//glColor3f(0, 0, 1);    glVertex2f(1, 1);
	
	glEnd();

	glutSwapBuffers();


}







int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 580);
	glutCreateWindow("Window");

	glutDisplayFunc(triangle);
	glutDisplayFunc(Chap);
	glutMainLoop();

	

}
