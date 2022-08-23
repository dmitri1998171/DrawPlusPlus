#pragma once

#include "Variables.h"

class Line {
    private:
        int color;
        int type;
        int line_width;
        int current_width;
        float red, green, blue;
        float prev_x, prev_y;               // предыдущ. координаты курсора
        vector<coord> coord;                // последовательность точек, из которых состоит линия

        void drawCurveLine(int color, int width);
        void drawStraightLine();
        
    public:
        Line();
        Line(Coord newCoord);
        void drawLine();
        void changeCoord(Coord newCoord);
        void setWidth(int width);
        void SetLineColor(int color);
};

Line::Line() {
    line_width = 2;
    color = lineColor;
    type = linetype;
    SetLineColor(lineColor);
}

Line::Line(Coord newCoord) {
    line_width = 2;
    current_width = lineWidth;
    type = linetype;
    color = lineColor;
    changeCoord(newCoord);
}

void Line::drawLine() {
    switch (type) {
        case LINE:
            drawCurveLine(color, current_width);
            break;

        case STRAIGHT:
            drawStraightLine();
            break;

        case ERASER:
            drawCurveLine(bg_color, eraser_width);
            break;
    }
}

void Line::drawCurveLine(int color, int width) {
    SetLineColor(color);
    glLineWidth((GLfloat)width);    // Меняем толщину линии
    glBegin(GL_LINE_STRIP);                      // Рисуем линию

    for (int i = 0; i < coord.size(); i++)
        glVertex2f(coord[i].x, coord[i].y);

    glEnd();
}

void Line::drawStraightLine() {
    // glLineWidth((GLfloat)current_width);    // Меняем толщину линии
    // glBegin(GL_LINE);                      // Рисуем линию
    //     glVertex2f(prev_x, prev_y);
    //     glVertex2f(x, y);
    // glEnd();
}

void Line::changeCoord(Coord newCoord) {
	coord.push_back(newCoord);
}

void Line::setWidth(int width) {
    this->line_width = width;
}

void Line::SetLineColor(int color) {
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
