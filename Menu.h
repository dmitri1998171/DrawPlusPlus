#pragma once
#include "Variables.h"
 
#define SHRINK 1
#define NORMAL 2

#define CLEAR 1

Figure* _figure;
vector<Figure*> figureCounter;

Line* line;
vector<Line*> linesCounter;		// учет созданных линий

// идентификаторы меню
int widthMenu, dottedMenu, mainMenu, colorMenu, BGcolorMenu, FiguresMenu, lineTypeMenu, eraserWidthMenu, mirroredLineMenu;
int menuFlag = 0;           	// статус меню

void changeBgcolorFunc(float r, float g, float b, int new_bg_color) {
	glClearColor (r, g, b, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	bg_color = new_bg_color;
}

// ===============================================================

void processMenuStatus(int status, int x, int y) {
	if (status == GLUT_MENU_IN_USE) menuFlag = 1;
	else menuFlag = 0;
}
 
void processMainMenu(int option) {
	switch(option) {
		case CLEAR: 
			glClearColor(1, 1, 1, 1);
			glClear (GL_COLOR_BUFFER_BIT); 
			
			for (int i = 0; i < linesCounter.size(); i++)
				delete linesCounter[i];
			
			linesCounter.clear();
			break;
	}
}
 
void processwidthMenu(int option) {
	lineWidth = option;
}
 
void processColorMenu(int option) {
	lineColor = option;
}

void processBGColorMenu(int option) {
	switch (option) {
		case RED :
			changeBgcolorFunc(1, 0, 0, RED);
			break;
		case GREEN :
			changeBgcolorFunc(0, 1, 0, GREEN);
			break;
		case INDIGO :
			changeBgcolorFunc(0, 0, 1, INDIGO);
			break;
		case ORANGE :
			changeBgcolorFunc(1, 0.5, 0.5, ORANGE);
			break;
		case YELLOW :
			changeBgcolorFunc(1, 1, 0, YELLOW);
			break;
		case PURPLE :
			changeBgcolorFunc(1, 0, 1, PURPLE);
			break;
		case BLUE :
			changeBgcolorFunc(0, 1, 1, BLUE);
			break;
		case BLACK :
			changeBgcolorFunc(0, 0, 0, BLACK);
			break;
		case WHITE :
			changeBgcolorFunc(1, 1, 1, WHITE);
			break;
	}
}

void processFiguresMenu(int option) {
	figure = option;
}

void processlineTypeMenu(int option) {
    linetype = option;
}

void processEraserWidthMenu(int option) {
	linetype = ERASER;
	eraser_width = option;
}

void processMirroredLineMenu(int option) {
	linetype = MIRRORED;
	mirrorType = option;
}

void processDottedMenu(int option) {
	linetype = STRAIGHT;
	dotted = option;
}

void menuPointsFunc() {
	glutAddMenuEntry("Red", RED);
	glutAddMenuEntry("Blue", BLUE);
	glutAddMenuEntry("Green", GREEN);
	glutAddMenuEntry("Orange", ORANGE);
	glutAddMenuEntry("Indigo", INDIGO);
	glutAddMenuEntry("Yellow", YELLOW);
	glutAddMenuEntry("Purple", PURPLE);
	glutAddMenuEntry("Black", BLACK);
	glutAddMenuEntry("White", WHITE);
}

void createPopupMenus() {
	widthMenu = glutCreateMenu(processwidthMenu);
	glutAddMenuEntry(" 1  ", 1);
	glutAddMenuEntry(" 2  ", 2);
	glutAddMenuEntry(" 3  ", 3);
	glutAddMenuEntry(" 4  ", 4);
	glutAddMenuEntry(" 5  ", 5);
	glutAddMenuEntry(" 6  ", 6);

	colorMenu = glutCreateMenu(processColorMenu);
	menuPointsFunc();

	BGcolorMenu = glutCreateMenu(processBGColorMenu);
	menuPointsFunc();

	eraserWidthMenu = glutCreateMenu(processEraserWidthMenu);
	glutAddMenuEntry("Small", SMALL);
	glutAddMenuEntry("Medium", MEDIUM);
	glutAddMenuEntry("Large", LARGE);

	mirroredLineMenu = glutCreateMenu(processMirroredLineMenu);
	glutAddMenuEntry("Vertical", VERTICAL);
	glutAddMenuEntry("Horizontal", HORIZONTAL);
	// glutAddMenuEntry("LARGE", LARGE);

	FiguresMenu = glutCreateMenu(processFiguresMenu);
	glutAddMenuEntry("Triangle", TRIANGLE);
	glutAddMenuEntry("Square", SQUARE);
	glutAddMenuEntry("Circle", CIRCLE);
	
	lineTypeMenu = glutCreateMenu(processlineTypeMenu);
	glutAddMenuEntry("Line", CURVE);
	glutAddMenuEntry("Straight line", STRAIGHT);
    glutAddSubMenu("Eraser", eraserWidthMenu);
    glutAddSubMenu("Mirrored line", mirroredLineMenu);

	dottedMenu = glutCreateMenu(processDottedMenu);
	glutAddMenuEntry("String", STRING);
	glutAddMenuEntry("Dotted line", DOTTED);
	glutAddMenuEntry("Mixed line", MIXED);

// =======================================================

	mainMenu = glutCreateMenu(processMainMenu);
	glutAddSubMenu("Width", widthMenu);
	glutAddSubMenu("Line Color", colorMenu);
	glutAddSubMenu("Background Color", BGcolorMenu);
	glutAddSubMenu("Figures", FiguresMenu);
    glutAddSubMenu("Line type", lineTypeMenu);
    glutAddSubMenu("Dotted", dottedMenu);
	glutAddMenuEntry("Clear", CLEAR);

	// прикрепить меню к правой кнопке
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//статус активности меню
	glutMenuStatusFunc(processMenuStatus);
}
 