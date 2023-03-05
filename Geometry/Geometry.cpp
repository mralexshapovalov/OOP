#define _USE_MATH_DEFINES
#include<Windows.h>
#include<iostream>
#include "glut.h"





#define SHAPE_CHARATERISTICS Color color,int startX,int startY,int lineWidth
#define SHAPE_VALUES color,startX,startY, lineWidth
//enum (Enumeration - Перечисление) - это набор именованных констант типа 'int'

HWND hwnd;



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

void points(void) 
{

	glClearColor(0.7f, 1.0f, 0.7f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(5);
	glBegin(GL_POINT);
	glBegin(GL_LINE_LOOP);

	glPointSize(40);
	glColor3f(0,0, 0);
	glVertex2f(0.5,0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();

	glutSwapBuffers();

}

float cube[] = { 0,0,0, 0,1,0 , 1,1,0, 1,0,0, 0,0,1 ,0,1,1, 1,1,1, 1,0,1 };
GLuint kubeInd[] = { 0,1,2, 2,3,0, 4,5,6, 6,7,4, 3,2,5, 6,7,3, 0,1,5, 5,4,0, 1,2,6, 6,5,1, 0,3,7, 7,4,0 };

typedef struct {
	float r, g, b;
	
}TColor;


typedef struct {
	TColor clr;

}TCell;


TCell map[40][40];
void WndResize(int x, int y);


void Map_Init() 
{

	for(int i=0;i<40;i++)
		for (int j = 0; j < 40; j++)
		{
			float dc = (rand() % 20) * 0.01;
			map[i][j].clr.r = 0.31 + dc;
			map[i][j].clr.g = 0.5 + dc;
			map[i][j].clr.b = 0.13 + dc;
		}

	RECT rct;
	GetClientRect(hwnd, &rct);
	WndResize(rct.right, rct.bottom);

}

void Game_Init(void)
{

	glEnable(GL_DEPTH_TEST);
	Map_Init();

}


	




struct 
{

	float x, y, z;
	float Xrot, Zrot;

}camera ={0,0,1.7,70,-40};

void Camera_Apply() 
{
	glRotatef(-camera.Xrot, 1,0, 0);
	glRotatef(-camera.Zrot, 0, 0, 1);
	glTranslatef(-camera.x, -camera.y, -camera.z);

}

void Camera_Rotation(float xAngle, float zAngle) 
{
	camera.Zrot += zAngle;
	if (camera.Zrot < 0)camera.Zrot += 360;
	if (camera.Zrot > 360)camera.Zrot -= 360;
	camera.Xrot += xAngle;
	if (camera.Xrot < 0)camera.Xrot = 0;
	if (camera.Xrot > 180)camera.Xrot = 180;

}
void Player_Move() {

	if (GetForegroundWindow() != hwnd)return;

	POINT cur;
	static POINT base = { 400,300 };
	GetCursorPos(&cur);
	Camera_Rotation((base.y - cur.y) / 5.0,(base.x - cur.x) / 5.0);
	SetCursorPos(base.x, base.y);

}

void Game_Move() {
	Player_Move();
}

void GameShow()
{

	glClearColor(0.6, 1.8, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	Camera_Apply();
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, cube);
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 40; j++)
		{
			glPushMatrix();
			glTranslated(i, j, 0);
			glColor3f(map[i][j].clr.r, map[i][j].clr.g, map[i][j].clr.b);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, kubeInd);
			glPopMatrix();
		}
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}

void WndResize(int x, int y) 
{

	glViewport(0, 0, x, y);
	float k = x / (float)y;
	float sz = 0.1;
	glLoadIdentity();
	glFrustum(-k * sz, k * sz, -sz, sz, sz * 2, 100);

}


void triangle(void)
{
	WNDCLASSEX wcex;

	HDC hDC;
	HGLRC hRC;
	MSG msg;
	BOOL bQuit = FALSE;

	bool f = false;
	Game_Init();
	//float t = +1.0f;
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Задает цвет фона
	//glPushMatrix();

	//glRotatef(t, 0.0f, 0.0f, 1.0f);

	/*glBegin(GL_TRIANGLES);*///Начинает отрсовку изображения

	//glColor3f(1, 0, 0);   glVertex2f(-0.5f, -0.5f);
	//glColor3f(0, 1, 0);   glVertex2f(0.5f, -0.5f);
	//glColor3f(0, 0, 1);    glVertex2f(0.0f, 0.5f);
	

		Game_Move();
		GameShow();
		glutSwapBuffers();
	


	



	/*glEnd();
	glPopMatrix();*/



}
int main(int argc, char** argv)
{



	glutInit(&argc, argv);

	
	

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 580);
	glutCreateWindow("Window");
	


	
	

		glutDisplayFunc(triangle);
		glutMainLoop();

	
	
	

	/*glutDisplayFunc(triangle);*/


}
