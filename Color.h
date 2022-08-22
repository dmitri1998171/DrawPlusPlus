#pragma once

#include "Variables.h"

class Color {
    private:
        float red;
        float green;
        float blue;

    public:
        Color() : red(0), green(0), blue(0) {};
        Color(float r, float g, float b);
        Color(float color);
        void SetLineColor(float r, float g, float b);
        void SetLineColor(int color);
        void changeBgcolorFunc(float r, float g, float b, int new_bg_color);
};

Color::Color(float r, float g, float b) {
    SetLineColor(r, g, b);
}

Color::Color(float color) {
    SetLineColor(color);
}

void Color::SetLineColor(float r, float g, float b) {
    red = r;
    green = g;
    blue = b;

    glColor3f(red, green, blue);
}

void Color::SetLineColor(int color) {
    if(color == BLACK) { red = 0; green = 0; blue = 0; }
    if(color == RED) { red = 1; green = 0; blue = 0; }
    if(color == GREEN) { red = 0; green = 1; blue = 0; }
    if(color == BLUE) { red = 0; green = 1; blue = 1; }
    if(color == ORANGE) { red = 1; green = 0.5; blue = 0.5; }
    if(color == YELLOW) { red = 1; green = 1; blue = 0; }
    if(color == PURPLE) { red = 1; green = 0; blue = 1; }
    if(color == WHITE) { red = 1; green = 1; blue = 1; }
    if(color == INDIGO) { red = 0; green = 0; blue = 1; }

    glColor3f(red, green, blue);
}

void Color::changeBgcolorFunc(float r, float g, float b, int new_bg_color) {
	glClearColor (r, g, b, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	bg_color = new_bg_color;
}

