#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float a, b, c, d;
void draw_point(GLint x, GLint y) { 
   glBegin(GL_POINTS);
   glVertex2i(x, y);
   glEnd();
   glFlush();
}
void dda(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int m = dy / dx;    
    if (m < 1) {                       // slope is less than 1
        int y = y1;                   // xn =x1+1 
        for (int i = x1; i <= x2; i++) {
            draw_point(i+0.5, y+0.5);
            y += m;                 // yn =y1+m
        }
    }
    else if (m > 1) {             // slope is greater than 1
        int x = x1;              // xn=x1+1/m
        for (int i = y1; i <= y2; i++) {
            draw_point(i+0.5, x+0.5);
            x += 1/m;
        }
    }
    else if (m == 1) {          // slope is equal than 1
        int x = x1;
        int y = y1;
        for (int i = y1; i <= y2; i++) {
            draw_point(i+0.5, y+0.5);
            x += 1;         // x=x1+1                    
            y += 1;         // y=y1+1
        }
    }
}

void display() { 
    dda(a, b, c, d);
 }

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

int main(int argc, char **argv) {
    printf("Enter co-ordinates: \n");
    printf(" Enter x1 = ");
    scanf("%f", &a);
    printf(" Enter y1 = ");
    scanf("%f", &b);
    printf(" Enter x2 = ");
    scanf("%f", &c);
    printf(" Enter y2 = ");
    scanf("%f", &d);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(200, 200);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("EXP. 4 ");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
