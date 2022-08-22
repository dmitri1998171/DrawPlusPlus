#pragma once

#include <GLUT/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

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
    LINE = 0,
    STRAIGHT,
    ERASER
};

enum DOTTED_TYPES {
    STRING = 0,
    DOTTED
};

enum ERASER_WIDTH {
    SMALL = 10,
    MEDIUM = 20,
    LARGE = 30
};

int lineColor = BLACK;
int bg_color = WHITE;  			// текущ. цвет фона

typedef struct Coord {
    int x;
    int y;
}coord;

