#pragma once

#include "Variables.h"
#include "Color.h"

class Line
{
    private:
        int width;
        int eraser_width;
        int type;
        Color color;

        float prev_x, prev_y;               // предыдущ. координаты курсора

    public:
        Line() {};
        Line(int x, int y);
        void addLine(int x, int y);
        void changeCoord(int x, int y);
        void setType(int type);
        void setWidth(int width);
};

Line::Line(int x, int y)
{
    width = 2;
    eraser_width = SMALL;
    type = STRING;

    changeCoord(x, y);
}

void Line::addLine(int x, int y) {
    glLineWidth((GLfloat)width);

	// glEnable(GL_LINE_STIPPLE); 		// разрешаем рисовать прерывистую линию
	// glLineStipple(2, 58360);    		// устанавливаем маску
	
	y = WIDTH - y;

	if(type == STRING) {
		glBegin(GL_LINES);
            glVertex2f(prev_x, prev_y);
            glVertex2f(x, y);
        glEnd();

        glFlush();

        changeCoord(x, y);
	}

	if(type == DOTTED) {
		glBegin(GL_LINES);
            glVertex2f(prev_x, prev_y);
            glVertex2f(x, y);
        glEnd();

        glFlush();

        changeCoord(x, y);
	}

	if(type == ERASER) {
		color.SetLineColor(bg_color);
		glLineWidth((GLfloat)eraser_width);
				
		glBegin(GL_LINES);
            glVertex2f(prev_x, prev_y);
            glVertex2f(x, y);
        glEnd();

        glFlush();

        changeCoord(x, y);
	}
}

void Line::changeCoord(int x, int y) {
    prev_x = x; 
    prev_y = y;
}

void Line::setType(int type) {
    this->type = type;
}

void Line::setWidth(int width) {
    this->width = width;
}
