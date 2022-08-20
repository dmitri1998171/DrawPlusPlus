#pragma once

#include "Variables.h"
#include "Color.h"
 
#define SHRINK 1
#define NORMAL 2

#define CLEAR 1

Color color;

void processMenuStatus(int status, int x, int y) {
	if (status == GLUT_MENU_IN_USE) menuFlag = 1;
	else menuFlag = 0;
}
 
void processMainMenu(int option) {
 
	switch(option) {
		case CLEAR: 
		glClearColor(1, 1, 1, 1);
		glClear (GL_COLOR_BUFFER_BIT); 
		break;
	}
}
 
void processwidthMenu(int option) {
	switch (option) {
		case 1: line_width = 1; break;
		case 2: line_width = 2; break;
		case 3: line_width = 3; break;
		case 4: line_width = 4; break;
		case 5: line_width = 5; break;
		case 6: line_width = 6; break;
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
		case BLACK :
			color.SetLineColor(BLACK); break;
		case RED :
			color.SetLineColor(RED); break;
		case GREEN :
			color.SetLineColor(GREEN); break;
		case BLUE :
			color.SetLineColor(BLUE); break;
		case ORANGE :
			color.SetLineColor(ORANGE); break;
		case YELLOW :
			color.SetLineColor(YELLOW); break;
		case PURPLE :
			color.SetLineColor(PURPLE); break;
		case WHITE :
			color.SetLineColor(WHITE); break;
		case INDIGO :
			color.SetLineColor(INDIGO); break;
	}
}

void processBGColorMenu(int option) {
	switch (option) {
		case RED :
			color.changeBgcolorFunc(1, 0, 0, 100);
			break;
		case GREEN :
			color.changeBgcolorFunc(0, 1, 0, 010);
			break;
		case INDIGO :
			color.changeBgcolorFunc(0, 0, 1, 001);
			break;
		case ORANGE :
			color.changeBgcolorFunc(1, 0.5, 0.5, 10505);
			break;
		case YELLOW :
			color.changeBgcolorFunc(1, 1, 0, 110);
			break;
		case PURPLE :
			color.changeBgcolorFunc(1, 0, 1, 101);
			break;
		case BLUE :
			color.changeBgcolorFunc(0, 1, 1, 011);
			break;
		case BLACK :
			color.changeBgcolorFunc(0, 0, 0, 000);
			break;
		case WHITE :
			color.changeBgcolorFunc(1, 1, 1, 111);
			break;
	}
}

void processlineTypeMenu(int option) {
    line_type = option;

	// switch (option) {
	// 	case STRING :
	// 		line_type = STRING;
	// 		break;
    //     case DOTTED :
	// 		line_type = DOTTED;
	// 		break;
	// 	case ERASER :
	// 		line_type = ERASER;
	// 		break;
    // }
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
	shrinkMenu = glutCreateMenu(processShrinkMenu);
	glutAddMenuEntry("Shrink", SHRINK);
	glutAddMenuEntry("Normal", NORMAL);

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

	lineTypeMenu = glutCreateMenu(processlineTypeMenu);
	glutAddMenuEntry("Line", STRING);
	glutAddMenuEntry("Dotted line", DOTTED);
	glutAddMenuEntry("Eraser", ERASER);

// =======================================================

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
 