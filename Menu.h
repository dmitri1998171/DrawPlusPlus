#include <GLUT/glut.h>
#include "Variables.h"

#define BLACK 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define ORANGE 4 
#define YELLOW 5
#define PURPLE 6
#define WHITE 7
#define INDIGO 8
 
#define SHRINK 1
#define NORMAL 2

#define STRING_LINE_TYPE 1
#define NORMAL_LINE_TYPE 2
#define ERASER_LINE_TYPE 3

#define CLEAR 1

void processMenuStatus(int status, int x, int y) {
	if (status == GLUT_MENU_IN_USE) menuFlag = 1;
	else menuFlag = 0;
}
 
void processMainMenu(int option) {
 
	switch(option){
		case CLEAR: 
		glClearColor(1,1,1,1);
		glClear (GL_COLOR_BUFFER_BIT); 
		break;
	}
}
 
void processwidthMenu(int option) {
	switch (option) {
		case 1: point_size = 1; break;
		case 2: point_size = 2; break;
		case 3: point_size = 3; break;
		case 4: point_size = 4; break;
		case 5: point_size = 5; break;
		case 6: point_size = 6; break;
	}
}
 
void processShrinkMenu(int option) {
	switch (option) {
		case SHRINK: shrink = 0.5f; break;
		case NORMAL: shrink = 1.0f; break;
	}
}
 
void processColorMenu(int option) {
	switch (option) {
		case RED :
			red = 1.0f;
			green = 0.0f;
			blue = 0.0f; break;
		case GREEN :
			red = 0.0f;
			green = 1.0f;
			blue = 0.0f; break;
		case INDIGO :
			red = 0.0f;
			green = 0.0f;
			blue = 1.0f; break;
		case ORANGE :
			red = 1.0f;
			green = 0.5f;
			blue = 0.5f; break;
		case YELLOW :
			red = 1.0f;
			green = 1.0f;
			blue = 0.0f; break;
		case PURPLE :
			red = 1.0f;
			green = 0.0f;
			blue = 1.0f; break;
		case BLUE :
			red = 0.0f;
			green = 1.0f;
			blue = 1.0f; break;
		case BLACK :
			red = 0.0f;
			green = 0.0f;
			blue = 0.0f; break;
		case WHITE :
			red = 1.0f;
			green = 1.0f;
			blue = 1.0f; break;
	}
}

void changeBgcolorFunc(float r, float g, float b, int k){
	glClearColor (r, g, b, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	current_bgcolor = k;
}

void processBGColorMenu(int option) {
	switch (option) {
		case RED :
			changeBgcolorFunc(1, 0, 0, 100);
			break;
		case GREEN :
			changeBgcolorFunc(0, 1, 0, 010);
			break;
		case INDIGO :
			changeBgcolorFunc(0, 0, 1, 001);
			break;
		case ORANGE :
			changeBgcolorFunc(1, 0.5, 0.5, 10505);
			break;
		case YELLOW :
			changeBgcolorFunc(1, 1, 0, 110);
			break;
		case PURPLE :
			changeBgcolorFunc(1, 0, 1, 101);
			break;
		case BLUE :
			changeBgcolorFunc(0, 1, 1, 011);
			break;
		case BLACK :
			changeBgcolorFunc(0, 0, 0, 000);
			break;
		case WHITE :
			changeBgcolorFunc(1, 1, 1, 111);
			break;
	}
}

void processlineTypeMenu(int option) {
    switch (option) {
		case STRING_LINE_TYPE :
			line_type = 1;
			break;
        case NORMAL_LINE_TYPE :
			line_type = 2;
			break;
		case ERASER_LINE_TYPE :
			line_type = 3;
			break;
    }
}

void menuPointsFunc(){
	glutAddMenuEntry("Red",RED);
	glutAddMenuEntry("Blue",BLUE);
	glutAddMenuEntry("Green",GREEN);
	glutAddMenuEntry("Orange",ORANGE);
	glutAddMenuEntry("Indigo",INDIGO);
	glutAddMenuEntry("Yellow",YELLOW);
	glutAddMenuEntry("Purple",PURPLE);
	glutAddMenuEntry("Black",BLACK);
	glutAddMenuEntry("White",WHITE);
}

void createPopupMenus() {
		shrinkMenu = glutCreateMenu(processShrinkMenu);
		glutAddMenuEntry("Shrink",SHRINK);
		glutAddMenuEntry("Normal",NORMAL);

		widthMenu = glutCreateMenu(processwidthMenu);
		glutAddMenuEntry(" 1  ",1);
		glutAddMenuEntry(" 2  ",2);
		glutAddMenuEntry(" 3  ",3);
		glutAddMenuEntry(" 4  ",4);
		glutAddMenuEntry(" 5  ",5);
		glutAddMenuEntry(" 6  ",6);

		colorMenu = glutCreateMenu(processColorMenu);
		menuPointsFunc();

		BGcolorMenu = glutCreateMenu(processBGColorMenu);
		menuPointsFunc();

        lineTypeMenu = glutCreateMenu(processlineTypeMenu);
		glutAddMenuEntry("Normal",NORMAL_LINE_TYPE);
        glutAddMenuEntry("String",STRING_LINE_TYPE);
		glutAddMenuEntry("Eraser",ERASER_LINE_TYPE);

	mainMenu = glutCreateMenu(processMainMenu);
	glutAddSubMenu("Width", widthMenu);
	glutAddSubMenu("Line Color", colorMenu);
	glutAddSubMenu("Background Color", BGcolorMenu);
    glutAddSubMenu("Line type", lineTypeMenu);
	glutAddSubMenu("Shrink", shrinkMenu);
	glutAddMenuEntry("Clear", CLEAR);

	// прикрепить меню к правой кнопке
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//статус активности меню
	glutMenuStatusFunc(processMenuStatus);
}
 