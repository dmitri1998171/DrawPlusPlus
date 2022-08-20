// #include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

using namespace std;

int I = 10000;
bool down = false;

void renderScene(void) {
	glPointSize(point_size);
	glColor3f(red, green, blue);
	// glEnable(GL_LINE_STIPPLE); 		// разрешаем рисовать прерывистую линию
	// glLineStipple(2, 58360);    		// устанавливаем маску
	
	if(line_type == 1){
		glBegin(GL_LINES);
		glVertex2f(xx-1, -yy+1);
		glVertex2f(X-1, -Y+1);
		glEnd();
	}

	if(line_type == 2){
		glBegin(GL_POINTS);
		glVertex2f(X-1, -Y+1);
		glEnd();
	}

	if(line_type == 3){
		if(current_bgcolor==100) red = 1; green = 0; blue = 0;
		if(current_bgcolor==010) red = 0; green = 1; blue = 0;
		if(current_bgcolor==001) red = 0; green = 0; blue = 1;
		if(current_bgcolor==10505) red = 1; green = 0.5; blue = 0.5;
		if(current_bgcolor==110) red = 1; green = 1; blue = 0;
		if(current_bgcolor==101) red = 1; green = 0; blue = 1;
		if(current_bgcolor==000) red = 0; green = 0; blue = 0;
		if(current_bgcolor==111) red = 1; green = 1; blue = 1;

		glColor3f(red, green, blue);
		glBegin(GL_POINTS);
		glVertex2f(xx-1, -yy+1);
		glVertex2f(X-1, -Y+1);
		glEnd();
	}

    glutSwapBuffers();
}

int frame=0,t,timebase=0,fps;

void mouseMove(int x, int y) {

	X = x; Y = y;
	X = X / _count; Y = Y / _count;		


	if(check == 1) xx=X; yy=Y;
	if(check == 2) check = 0;
	check++;
	
	frame++;
	t=glutGet(GLUT_ELAPSED_TIME);
	if (t - timebase > 1000) {
		fps = frame*1000.0/(t-timebase);
	 	timebase = t;
		frame = 0;
	}

	// cout <<"X: " << X << " Y: " << Y;
	// cout <<" xx: " << xx << " yy: " << yy;
	// cout << " check: " << check << " fps:" << fps << endl;
}

void MouseFunc(int button, int state, int x, int y) {
	if(button == GLUT_LEFT_BUTTON)
		if(state == GLUT_DOWN)
			{
				down = true;
			}
		if(state == GLUT_UP)
			{
				down = false;
			}

	//I = 0;	
}

void keyboardFunc(unsigned char key, int x, int y){
	if(key == 27) exit(0);
}

void timf(int value) {
  glutPostRedisplay();  // Redraw windows
  glutTimerFunc(millis, timf, 0); // Setup next timer
}

int main(int argc, char **argv) {
 
	// инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Draw++");
 
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);

	// регистрация обратных вызовов
	glutDisplayFunc(renderScene);
	glutTimerFunc(millis, timf, 0);
	glutKeyboardFunc(keyboardFunc);
	createPopupMenus();
	glutMouseFunc(MouseFunc);
	glutMotionFunc(mouseMove);

	// Основной цикл GLUT
	glutMainLoop();
 
	return 1;
}

/*
	TO DO

\/ 1. Отрисовка
2. Меню
	\/ - цвет
	\/ - толщина
	\/ - тип (прямые, зеркальные, кривые)
	\/ - пунктир
	\/ - фон
	\/ - очистка
	- ластик
\/ 3. смена фона
4. оптимизация
	- изменение размеров окна
5. тип (прямые, зеркальные, кривые)

*/