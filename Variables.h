#pragma once

#include <GLUT/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

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
    LINE = 0,
    STRAIGHT,
    ERASER
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

int linetype = STRAIGHT;
int lineColor = BLACK;
int lineWidth = 2;
int bg_color = WHITE;  
int eraser_width = LARGE;
int dotted = STRING;

typedef struct Coord {
    int x;
    int y;
}coord;

