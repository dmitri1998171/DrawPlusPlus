#pragma once

#include <GLUT/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 500
#define HEIGHT 500

using namespace std;

enum COLORS {
	BLACK = 0,
	RED,
	GREEN,
	BLUE,
	ORANGE, 
	YELLOW,
	PURPLE,
	WHITE,
	INDIGO
};

enum LINE_TYPES {
    STRING = 0,
    DOTTED,
    ERASER
};

enum ERASER_WIDTH {
    SMALL = 10,
    MEDIUM = 20,
    LARGE = 30
};

// идентификаторы меню
int widthMenu, shrinkMenu, mainMenu, colorMenu, BGcolorMenu, lineTypeMenu;
int menuFlag = 0;           // статус меню
float shrink = 1;             // наличие пунктира

int line_width = 2;         // толщина линии
int eraser_width = SMALL;
int line_type = STRING;          // тип линии (кривые, прямые, зеркальные)

float red = 1.0f, blue = 0.0f, green = 0.0f;      // цвет
int bg_color = WHITE;  // текущ. цвет фона

float X = 0, Y = 0;             // текущ. координаты курсора
float xx, yy;               // предыдущ. координаты курсора
int _count = 250;            // коэф. преобр. коорд. мыши к коорд. линий
