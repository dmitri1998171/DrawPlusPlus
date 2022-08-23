#pragma once

#include "Variables.h"

class Line {
    private:
        int color;
        int type;
        int current_width;
        float red, green, blue;
        float prev_x, prev_y;               // предыдущ. координаты курсора
        vector<coord> coord;                // последовательность точек, из которых состоит линия

        void drawCurveLine(int color, int width);
        void drawStraightLine();
        
    public:
        Line();
        Line(int x, int y);
        void drawLine();
        void changeCoord(int x, int y);
        void setWidth(int width);
        void SetLineColor(int color);
};

Line::Line() {
    current_width = lineWidth;
    type = linetype;
    color = lineColor;
}

Line::Line(int x, int y) {
    current_width = lineWidth;
    type = linetype;
    color = lineColor;
    changeCoord(x, y);
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

    for (int i = 0; i < coord.size(); i++)
        cout << "x: " << coord[i].x << " y: " << coord[i].y << endl;
}

void Line::drawCurveLine(int color, int width) {
    SetLineColor(color);
    glLineWidth((GLfloat)width);                    // Меняем толщину линии
    glBegin(GL_LINE_STRIP);                         // Рисуем линию

    for (int i = 0; i < coord.size(); i++)
        glVertex2f(coord[i].x, coord[i].y);

    glEnd();
}

void Line::drawStraightLine() {
    int size = coord.size();

    SetLineColor(BLACK);
    glLineWidth((GLfloat)current_width);            // Меняем толщину линии
    glBegin(GL_LINE);                               // Рисуем линию
        glVertex2f(coord[1].x, coord[1].y);
        glVertex2f(coord[size - 1].x, coord[size - 1].y);
    glEnd();
}

void Line::changeCoord(int x, int y) {
    Coord newCoord;
    newCoord.x = x;
    newCoord.y = y;

	coord.push_back(newCoord);
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
