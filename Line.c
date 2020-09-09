#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
void init() {
    gluOrtho2D(-20,20,-20,20);
}
void display(void) {
    float x1,y1,x2,y2; 
    printf("Enter x1,y1,x2,y2\n");
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    double m = 0.0;             
    double c = (y1 - m*x1);   // value of c  
    double y = y1;              
    if (x2-x1 == 0)  // slope=0 
        m = 0;
    else 
        m = (y2-y1)/(x2-x1);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 1.0f, 0.0f);
    for (int i=x1;i<x2;i++) {     // drawing the line
        y=(m*i+c);        
        glVertex2f(i,y);
    }
    glEnd();
    glFlush();
    
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line");
    gluOrtho2D(-20,20,-20,20);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
