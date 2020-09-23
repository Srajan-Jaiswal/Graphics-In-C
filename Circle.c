#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
float x, y, r;
void init()
{
    gluOrtho2D(-350, 350, -350, 350);
}
void Polar_Circle()
{
    for (int i = 0; i <= 360; i++)
    {
        float theta = (i * 3.14) / 180;
        int a = (int)(x + (r * cos(theta)));
        int b = (int)(y + (r * sin(theta)));
        glVertex2f(a, b);
    }
}
void display(void)
{
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 1.0, 0.0);
    Polar_Circle();
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    printf("Enter centre cordinates\n");
    scanf("%f%f", &x, &y);
    printf("Enter radius\n");
    scanf("%f", &r);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(700, 700);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Polar Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
// gcc -o out Circle.c -lglut32 -lopengl32 -lglu32
//Enter center co-ordinates: 180 180
//Enter radius value: 90