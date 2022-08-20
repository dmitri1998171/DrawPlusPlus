#include "Variables.h"
#include "Line.h"
#include "Menu.h"

void renderScene(void) {
	glFlush();
	glutPostRedisplay();
}

void mouseMove(int x, int y) {
	line.addLine(x, y);
}

void MouseFunc(int button, int state, int x, int y) {
	y = WIDTH - y;

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		line.changeCoord(x, y);
}

void keyboardFunc(unsigned char key, int x, int y) {
	if(key == 27) exit(0);
}

void Init() {
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Draw++");
 
	Init();
	glutDisplayFunc(renderScene);
	glutKeyboardFunc(keyboardFunc);
	createPopupMenus();
	glutMouseFunc(MouseFunc);
	glutMotionFunc(mouseMove);

	glutMainLoop();
 
	return 1;
}