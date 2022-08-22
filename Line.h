#pragma once

#include "Variables.h"
#include "Color.h"

class Line {
    private:
        int current_width;
        int line_width;
        int eraser_width;
        int type;
        Color color;

        float prev_x, prev_y;               // предыдущ. координаты курсора

    public:
        Line();
        Line(int x, int y);
        void drawLine(int x, int y);
        void drawEraser(int x, int y);
        void changeCoord(int x, int y);
        void setType(int type);
        void setWidth(int width);
        Color* getColor();
};

Line::Line() {
    line_width = 2;
    eraser_width = LARGE;
    type = LINE;
    color.SetLineColor(BLACK);
}

Line::Line(int x, int y)
{
    line_width = 2;
    eraser_width = LARGE;
    type = LINE;
    color.SetLineColor(BLACK);
    changeCoord(x, y);
}

void Line::drawLine(int x, int y) {
    switch (type) {
        case LINE:
            current_width = line_width;

            glLineWidth((GLfloat)current_width);    // Меняем толщину линии
            glBegin(GL_LINES);                      // Рисуем линию
                glVertex2f(prev_x, prev_y);
                glVertex2f(x, y);
            glEnd();

            glFlush();
            changeCoord(x, y);                      // Конец текущ. линии это начало след.
            break;

        case STRAIGHT:
            glLineWidth((GLfloat)current_width);    // Меняем толщину линии
            glBegin(GL_LINE);                      // Рисуем линию
                glVertex2f(prev_x, prev_y);
                glVertex2f(x, y);
            glEnd();

            glFlush();
            // changeCoord(x, y);                      // Конец текущ. линии это начало след.
            break;

        case ERASER:
            // drawEraser(x, y);

            color.SetLineColor(bg_color);
            // current_width = eraser_width;
            glLineWidth((GLfloat)eraser_width);    // Меняем толщину линии
            glBegin(GL_LINES);                      // Рисуем линию
                glVertex2f(prev_x, prev_y);
                glVertex2f(x, y);
            glEnd();

            glFlush();
            changeCoord(x, y);                      // Конец текущ. линии это начало след.
            
            break;
    }
				
    
}

void Line::drawEraser(int x, int y) {
    float one_per_cursor = WIDTH * 0.01;            // 1% от высоты в глоб. коорд. (0-WIDTH)
    float one_per_quad = one_per_cursor * 0.01;     // 1% от высоты окна в локальных коорд. (0-1)

    // double _x = (x * one_per_quad * 0.08) - 1;
    // double _y = (y * one_per_quad * 0.08) - 1;

    cout << "x: " << x << " y: " << y << endl;
    // cout << "local_x: " << _x << " local_y: " << _y << endl;

    glPushMatrix();
    glLoadIdentity();
    
    glClear (GL_COLOR_BUFFER_BIT);
    // glTranslatef(_x, _y, 0.0f);
    glTranslatef(x, y, 0.0f);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);                      // Рисуем квадрат    
        glVertex2f(-0.03, -0.03);
        glVertex2f(-0.03,  0.03);
        glVertex2f( 0.03,  0.03);
        glVertex2f( 0.03, -0.03);
    glEnd();

    glFlush();
    glPopMatrix();
}

void Line::changeCoord(int x, int y) {
    prev_x = x; 
    prev_y = y;
}

void Line::setType(int type) {
    this->type = type;
}

void Line::setWidth(int width) {
    this->line_width = width;
}

Color* Line::getColor() {
    return &color;
}
