#pragma once

#include "Variables.h"

class Line {
    private:
        int color;
        int type;
        int current_width;
        int dottedLine;
        int lineMirrorType;
        float red, green, blue;
        float prev_x, prev_y;               // предыдущ. координаты курсора
        vector<coord> coord;                // последовательность точек, из которых состоит линия

        void drawCurveLine(int color, int width);
        void drawStraightLine();
        void drawMirroredLine();
        
    public:
        Line();
        Line(int x, int y);
        void drawLine();
        void changeCoord(int x, int y);
        void SetLineColor(int color);
};

Line::Line() {
    color = lineColor;
    type = linetype;
    current_width = lineWidth;
    dottedLine = dotted;
    lineMirrorType = mirrorType;
}

Line::Line(int x, int y) {
    color = lineColor;
    type = linetype;
    current_width = lineWidth;
    dottedLine = dotted;
    lineMirrorType = mirrorType;
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

        case MIRRORED:
            drawMirroredLine();
            break;
    }
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
    int size = coord.size() - 1;

    SetLineColor(color);
    glLineWidth((GLfloat)current_width);             // Меняем толщину линии

    switch (dottedLine) {
        case STRING:
            glDisable(GL_LINE_STIPPLE); 
            break;
        case DOTTED:
            glLineStipple(4, 0xAAAA);
            glEnable(GL_LINE_STIPPLE); 
            break;
        case MIXED:
            glLineStipple(3, 0x1C47);
            glEnable(GL_LINE_STIPPLE); 
            break;
    }

    glBegin(GL_LINES);                               // Рисуем линию
        glVertex2f(coord[0].x, coord[0].y);
        glVertex2f(coord[size].x, coord[size].y);
    glEnd();
}

void Line::drawMirroredLine() {
    SetLineColor(color);
    glLineWidth((GLfloat)current_width);            // Меняем толщину линии
    glBegin(GL_LINE_STRIP);                         // Рисуем линию

    for (int i = 0; i < coord.size(); i++)
        glVertex2f(coord[i].x, coord[i].y);

    glEnd();

    glBegin(GL_LINE_STRIP);                         // Рисуем зеркальную линию

    if(lineMirrorType == VERTICAL) {
        for (int i = 0; i < coord.size(); i++) 
            glVertex2f(HEIGHT - coord[i].x, coord[i].y);
    }

    if(lineMirrorType == HORIZONTAL) {
        for (int i = 0; i < coord.size(); i++) 
            glVertex2f(coord[i].x, WIDTH - coord[i].y);
    }

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
