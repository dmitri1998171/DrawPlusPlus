#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

#define WIDTH 500
#define HEIGHT 500

using namespace std;

void renderScene(void) {
	glFlush();
	glutPostRedisplay();
}

void mouseMove(int x, int y) {
	glPointSize(point_size);
	glColor3f(red, green, blue);
	// glEnable(GL_LINE_STIPPLE); 		// разрешаем рисовать прерывистую линию
	// glLineStipple(2, 58360);    		// устанавливаем маску
	
	y = WIDTH - y;

	if(line_type == 1){
		glBegin(GL_LINE_STRIP);
		glVertex2f(xx-1, -yy+1);
		glVertex2f(X-1, -Y+1);
		glEnd();
	}

	if(line_type == 2){
		glBegin(GL_LINES);
            glVertex2f(xx, yy);
            glVertex2f(x, y);
        glEnd();

        glFlush();

        xx = x;
        yy = y;
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
}

void MouseFunc(int button, int state, int x, int y) {
	y = WIDTH - y;
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		xx=x; yy=y;
}

void keyboardFunc(unsigned char key, int x, int y){
	if(key == 27) exit(0);
}

int main(int argc, char **argv) {
 
	// инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Draw++");
 
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);

	// регистрация обратных вызовов
	glutDisplayFunc(renderScene);
	glutKeyboardFunc(keyboardFunc);
	createPopupMenus();
	glutMouseFunc(MouseFunc);
	glutMotionFunc(mouseMove);

	gluOrtho2D(0,WIDTH,0,HEIGHT);

	// Основной цикл GLUT
	glutMainLoop();
 
	return 1;
}