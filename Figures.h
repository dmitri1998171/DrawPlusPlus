#pragma once
#include "Variables.h"

class Figure {
    protected:
        int figureType;
        float red, green, blue;
        vector<coord> coord;                // последовательность точек, из которых состоит фигура

    public:
        Figure() : figureType(figure) {};
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

        virtual void draw() = 0;
};

class Circle : public Figure {
    private:
        int start_x, start_y;
    public:
        Circle(int x, int y);
        void draw();
        ~Circle();
};

Circle::Circle(int x, int y) {
    start_x = x;
    start_y = y;

    changeCoord(x, y);
}

void Circle::draw() {
    SetLineColor(lineColor);
    glLineWidth((GLfloat)lineWidth);                    // Меняем толщину линии
    
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

// ==================================================================

class Factory {
  public:    
    virtual Figure* createFigure(int x, int y) = 0;
    virtual ~Factory() {}
};
  
class CircleFactory: public Factory {
  public:    
    Figure* createFigure(int x, int y) { 
      return new Circle(x, y); 
    }
};
