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

int bg_color = WHITE;  // текущ. цвет фона
