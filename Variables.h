
// идентификаторы меню
int widthMenu, shrinkMenu, mainMenu, colorMenu, BGcolorMenu, lineTypeMenu;
int menuFlag = 0;           // статус меню
float shrink = 1;             // наличие пунктира

int point_size = 2;         // толщина линии
int line_type = 2;          // тип линии (кривые, прямые, зеркальные)

float red = 1.0f, blue=0.0f, green=0.0f;      // цвет
int current_bgcolor = 111;  // текущ. цвет фона

float X=0, Y=0;             // текущ. координаты курсора
float xx, yy;               // предыдущ. координаты курсора
int _count = 250;            // коэф. преобр. коорд. мыши к коорд. линий
