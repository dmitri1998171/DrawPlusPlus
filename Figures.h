#pragma once
#include "Variables.h"

class Figure {
    protected:
        int color;
        int current_width;
        float red, green, blue;
        int start_x, start_y;
        vector<coord> coord;                // последовательность точек, из которых состоит фигура

    public:
        Figure() {};
        virtual void draw() = 0;
        virtual void destroy() = 0;

        void SetLineColor(int color) {
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
       
        void changeCoord(int x, int y) {
            Coord newCoord;
            newCoord.x = x;
            newCoord.y = y;

            coord.push_back(newCoord);
        }
};

// ------------------------------------------------------------------

class Line : public Figure {
    private:
        int type;
        int dottedLine;
        int lineMirrorType;

        void drawCurveLine(int color, int width);
        void drawStraightLine();
        void drawMirroredLine();
        
    public:
        Line(int x, int y);
        void draw();
        void destroy();
};

Line::Line(int x, int y) {
    color = lineColor;
    type = linetype;
    current_width = lineWidth;
    dottedLine = dotted;
    lineMirrorType = mirrorType;
    changeCoord(x, y);
}

void Line::draw() {
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
    glDisable(GL_LINE_STIPPLE); 
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

void Line::destroy() {
    delete this;
}
// ------------------------------------------------------------------

class Circle : public Figure {
    public:
        Circle(int x, int y);
        void draw();
        void destroy();
};

Circle::Circle(int x, int y) {
    color = lineColor;
    current_width = lineWidth;

    start_x = x;
    start_y = y;

    changeCoord(x, y);
}

void Circle::draw() {
    SetLineColor(color);
    glLineWidth((GLfloat)current_width);                    // Меняем толщину линии
    
    glPushMatrix();
    glTranslatef(start_x, start_y, 0);

    GLfloat theta;
    GLfloat pi = acos(-1.0);

    // r = sqrt(x^2 + y^2); (x = x1 - x0, y = y1 - y0)
    GLfloat radius = sqrt((pow((coord.back().x - start_x), 2)) + (pow((coord.back().y - start_y), 2)));

    glBegin(GL_LINE_STRIP);
    for(GLfloat a = 0.0f; a < 360.0f; a++) {
        theta = 2.0f * pi * a / 180.0f;
        glVertex2f(radius * cos(theta), radius* sin(theta));
    }
    glEnd();
    glPopMatrix();
}

void Circle::destroy() {
    delete this;
}

// ------------------------------------------------------------------

class Square : public Figure {
    private:
        int square_size;

    public:
        Square(int x, int y);
        void draw();
        void destroy();
};

Square::Square(int x, int y) {
    color = lineColor;
    current_width = lineWidth;
    square_size = 15;

    start_x = x;
    start_y = y;

    changeCoord(x, y);
}

void Square::draw() {
    SetLineColor(color);
    glLineWidth((GLfloat)current_width);                    // Меняем толщину линии
    
    glPushMatrix();
    GLfloat radius = sqrt((pow((coord.back().x - start_x), 2)) + (pow((coord.back().y - start_y), 2)));

    glTranslatef(start_x, start_y, 0);
    glScalef(radius, radius, 0);

    glBegin(GL_LINE_LOOP);                      	// Рисуем квадрат
        glVertex2f(-square_size, -square_size);
        glVertex2f(-square_size,  square_size);
        glVertex2f( square_size,  square_size);
        glVertex2f( square_size, -square_size);
    glEnd();

    glPopMatrix();
}

void Square::destroy() {
    delete this;
}

// ------------------------------------------------------------------

class Triangle : public Figure {
    private:
        int triangle_size;

    public:
        Triangle(int x, int y);
        void draw();
        void destroy();
};

Triangle::Triangle(int x, int y) {
    color = lineColor;
    current_width = lineWidth;
    triangle_size = 15;
    
    start_x = x;
    start_y = y;

    changeCoord(x, y);
}

void Triangle::draw() {
    SetLineColor(color);
    glLineWidth((GLfloat)current_width);                    // Меняем толщину линии
    
    glPushMatrix();
    GLfloat theta;
    GLfloat pi = acos(-1.0);
    GLfloat radius = sqrt((pow((coord.back().x - start_x), 2)) + (pow((coord.back().y - start_y), 2)));

    glTranslatef(start_x, start_y, 0);
    glScalef(radius, radius, 0);
    glRotatef(30, 0, 0, 1);

    glBegin(GL_LINE_LOOP);                      	// Рисуем треугольник
        for(GLfloat a = 0.0f; a < 360.0f; a += 120) {
        theta = 2.0f * pi * a / 180.0f;
        glVertex2f(radius * cos(theta), radius* sin(theta));
    }
        
    glEnd();
    glPopMatrix();
}

void Triangle::destroy() {
    delete this;
}

// ==================================================================

class Factory {
    public:    
        virtual Figure* createFigure(int x, int y) = 0;
};
  
class CircleFactory: public Factory {
    public:    
        Figure* createFigure(int x, int y) { 
            return new Circle(x, y); 
        }
};

class SquareFactory: public Factory {
    public:    
        Figure* createFigure(int x, int y) { 
            return new Square(x, y); 
        }
};

class TriangleFactory: public Factory {
    public:    
        Figure* createFigure(int x, int y) { 
            return new Triangle(x, y); 
        }
};

class LineFactory: public Factory {
    public:
        Figure* createFigure(int x, int y) { 
            return new Line(x, y); 
        }
};
