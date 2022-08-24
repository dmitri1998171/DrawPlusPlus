#include "Variables.h"
#include "Line.h"
#include "Figures.h"
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
 
	switch (figure) {
		case LINE:
			for (int i = 0; i < linesCounter.size(); i++) 
				linesCounter[i]->drawLine();
			
			if(linetype == ERASER)
				drawEraser();

			break;

		case TRIANGLE:
		
			break;

		case SQUARE:
			for (int i = 0; i < figureCounter.size(); i++)
				figureCounter[i]->draw();

			break;

		case CIRCLE:
			for (int i = 0; i < figureCounter.size(); i++)
				figureCounter[i]->draw();
			
			break;
	}
	

	glFlush();
	glutPostRedisplay();
}

void mouseMove(int x, int y) {
	X = x;
	Y = y;

	if(line)
		line->changeCoord(x, y);

	if(figureCounter.size())
		figureCounter.back()->changeCoord(x, y);
}

void MouseFunc(int button, int state, int x, int y) {
	CircleFactory* circle_factory = new CircleFactory;
	SquareFactory* square_factory = new SquareFactory;

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		switch (figure) {
			case LINE:
				line = new Line(x, y);
				linesCounter.push_back(line);
				break;

			case TRIANGLE:
				// _figure = new Circle(x, y);
				// linesCounter.push_back(line);
				break;

			case SQUARE:
				figureCounter.push_back(square_factory->createFigure(x, y));
				break;

			case CIRCLE:
				figureCounter.push_back(circle_factory->createFigure(x, y));
				break;
		}
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