#pragma once

#include <GLUT/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>

#define WIDTH 500
#define HEIGHT 500

#define ERASER_SCALE 0.001

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
    CURVE = 0,
    STRAIGHT,
    ERASER, 
    MIRRORED
};

enum DOTTED_TYPES {
    STRING = 0,
    DOTTED,
    MIXED
};

enum ERASER_WIDTH {
    SMALL = 10,
    MEDIUM = 30,
    LARGE = 40
};

enum MIRROR_TYPE {
    VERTICAL = 0,
    HORIZONTAL
};

enum FIGURES {
    LINE = 0,
    TRIANGLE,
    SQUARE,
    CIRCLE
};

int linetype = MIRRORED;
int lineColor = BLACK;
int lineWidth = 2;
int bg_color = WHITE;  
int eraser_width = LARGE;
int dotted = STRING;
int mirrorType = VERTICAL;
int figure = CIRCLE;

typedef struct Coord {
    int x;
    int y;
}coord;

