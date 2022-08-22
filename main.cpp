#include "Variables.h"
#include "Line.h"
#include "Menu.h"

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
	for (int i = 0; i < linesCounter.size(); i++) {
		linesCounter[i]->drawLine();

		// glFlush();
		// glutPostRedisplay();
	}
	
	glutSwapBuffers();
	glutPostRedisplay();
}

void mouseMove(int x, int y) {
	
	Coord newCoord;
	newCoord.x = x;
	newCoord.y = y;

	line->changeCoord(newCoord);

	// glutSwapBuffers();
	// glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		Coord newCoord;
		newCoord.x = x;
		newCoord.y = y;
		
		line = new Line(newCoord);
		linesCounter.push_back(line);
	}
}

void keyboardFunc(unsigned char key, int x, int y) {
	if(key == 27) exit(0);
}

void Init() {
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	glOrtho(0, WIDTH, HEIGHT, 0, 0, 1);

	// glViewport(0, 0, WIDTH, HEIGHT);
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// gluOrtho2D(0, 0, WIDTH, HEIGHT);
}

void reshape(int w, int h) {
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,0,(GLdouble)w, (GLdouble)h);
} 

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Draw++");

	Init();
	glutDisplayFunc(renderScene);
	// glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardFunc);
	createPopupMenus();
	glutMouseFunc(MouseFunc);
	glutMotionFunc(mouseMove);

	glutMainLoop();
 
	return 1;
}