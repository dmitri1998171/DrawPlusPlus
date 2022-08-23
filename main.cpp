#include "Variables.h"
#include "Line.h"
#include "Menu.h"

int X, Y;

void drawEraser() {
    float one_per_cursor = WIDTH * 0.01;            // 1% от высоты в глоб. коорд. (0-WIDTH)
    float one_per_quad = one_per_cursor * 0.01;     // 1% от высоты окна в локальных коорд. (0-1)

    float coef = 0.08;

    double _x = (X * one_per_quad * coef) - 1;
    double _y = ((WIDTH - Y) * one_per_quad * coef) - 1;

    glPushMatrix();
    glLoadIdentity();

    glTranslatef(_x, _y, 0.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth((GLfloat)2);    					// Меняем толщину линии

    glBegin(GL_LINE_LOOP);                      	// Рисуем квадрат
        glVertex2f(-eraser_width * ERASER_SCALE, -eraser_width * ERASER_SCALE);
        glVertex2f(-eraser_width * ERASER_SCALE,  eraser_width * ERASER_SCALE);
        glVertex2f( eraser_width * ERASER_SCALE,  eraser_width * ERASER_SCALE);
        glVertex2f( eraser_width * ERASER_SCALE, -eraser_width * ERASER_SCALE);
    glEnd();

    glPopMatrix();
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
 
	for (int i = 0; i < linesCounter.size(); i++) 
		linesCounter[i]->drawLine();
	
	if(linetype == ERASER)
		drawEraser();

	glFlush();
	glutPostRedisplay();
}

void mouseMove(int x, int y) {
	X = x;
	Y = y;

	line->changeCoord(x, y);
}

void MouseFunc(int button, int state, int x, int y) {
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		line = new Line(x, y);
		linesCounter.push_back(line);
	}
}

void keyboardFunc(unsigned char key, int x, int y) {
	if(key == 27) exit(0);
}

void Init() {
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, WIDTH, HEIGHT, 0);
}

void reshape(int w, int h) {
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,0,(GLdouble)w, (GLdouble)h);
} 

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
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