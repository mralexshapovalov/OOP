#define _USE_MATH_DEFINES
#include<Windows.h>
#include<iostream>
#include "glut.h"


float WinWid = 400, WinHei = 400;

float angle = 0.0, scale = 1.0;

void Square(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_POLYGON);

	glColor3f(1, 0, 0); 	glVertex2f(-0.5f,0.5f);
	glColor3f(0, 1, 0); 	glVertex2f(0.5f, 0.5f);
	glColor3f(0, 0, 1);    glVertex2f( 0.5f, -0.5f);
	glColor3f(0, 0, 0); 	glVertex2f(-0.5f, -0.5f);

	//glColor3f(1, 0, 0); 	glVertex2f(0, 0);
	//glColor3f(0, 1, 0); 	glVertex2f(0, 1);
	//glColor3f(0, 0, 1);    glVertex2f(1, 1);
	
	glEnd();

	glutSwapBuffers();


}

void Circle(void) 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	float x, y;

	float cnt= 60;

	float I = 0.5;

	float a = M_PI * 2 / cnt;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0, 0); 	
	glColor3f(0, 1, 0); 	
	glColor3f(0, 0, 1);

	glVertex2f(0, 0);

	for (int i = -1; i < cnt; i++) 
	{

		x = sin(a * i) * I;
		y = cos(a * i) * I;
		glVertex2f(x, y);

	}
	glEnd();

	glutSwapBuffers();

}


void timer(int value) {

	glColor3f(0.2, 1.0, 0.0);

	angle++;

	glRotatef(15.0, 10.0, 20.0, 1.0);

	glutPostRedisplay();

	glutTimerFunc(80, timer, 0);

}

void init() {

	glClearColor(0.0, 0.0, 0.0, 1.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(-WinWid / 2, WinWid / 2, -WinHei / 2, WinHei / 2, -200.0, 200.0);

	glMatrixMode(GL_MODELVIEW);

}

void draw() {

	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	scale = 1.0 - abs(sin(3.14 * angle / 90.0) / sqrt(3.0) / 2);

	glRotatef(angle, 0.0, 0.0, 1.0);

	glScalef(scale, scale, 1.0);

	glBegin(GL_LINES);

	for (float i = -WinWid / 2; i <= WinWid / 2; i += 20.0) {

		glVertex2f(i, -WinHei / 2);

		glVertex2f(i, WinHei / 2);

	}

	for (float i = -WinWid / 2; i <= WinWid / 2; i += 20.0) {

		glVertex2f(-WinWid / 2, i);

		glVertex2f(WinWid / 2, i);

	}

	glEnd();

	glPopMatrix();

	glutSwapBuffers();

}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(WinWid, WinHei);

	glutInitWindowPosition(WinWid, WinHei);

	glutCreateWindow("Figura");

	glutDisplayFunc(draw);

	glutTimerFunc(60, timer, 0);

	init();

	glutMainLoop();

}
