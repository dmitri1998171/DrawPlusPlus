#include "Variables.h"
#include "Menu.h"

void renderScene(void) {
	glFlush();
	glutPostRedisplay();
}

void mouseMove(int x, int y) {
	glLineWidth((GLfloat)line_width);

	// glEnable(GL_LINE_STIPPLE); 		// разрешаем рисовать прерывистую линию
	// glLineStipple(2, 58360);    		// устанавливаем маску
	
	y = WIDTH - y;

	if(line_type == STRING) {
		glBegin(GL_LINES);
            glVertex2f(xx, yy);
            glVertex2f(x, y);
        glEnd();

        glFlush();

        xx = x;
        yy = y;
	}

	if(line_type == DOTTED) {
		glBegin(GL_LINES);
            glVertex2f(xx, yy);
            glVertex2f(x, y);
        glEnd();

        glFlush();

        xx = x;
        yy = y;
	}

	if(line_type == ERASER) {
		color.SetLineColor(bg_color);
		glLineWidth((GLfloat)eraser_width);
				
		glBegin(GL_LINES);
            glVertex2f(xx, yy);
            glVertex2f(x, y);
        glEnd();

        glFlush();

        xx = x;
        yy = y;
	}
}

void MouseFunc(int button, int state, int x, int y) {
	y = WIDTH - y;
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		xx=x; yy=y;
}

void keyboardFunc(unsigned char key, int x, int y) {
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

	gluOrtho2D(0, WIDTH, 0, HEIGHT);

	// Основной цикл GLUT
	glutMainLoop();
 
	return 1;
}