#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.14
#include <stdio.h>
float major, minor, C_X, C_Y;
void init()
{
    gluOrtho2D(0, 300, 0, 300);
}
void DP(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}
void bresenham_ellipse()
{

    float res1, res2, p1, d2, x, y;
    x = 0;
    y = minor;

    // Region 1
    p1 = (minor * minor) - (major * major * minor) + (0.25 * major * major); // ry2-rx2*ry+0.25rx2
    res1 = 2 * minor * minor * x;
    res2 = 2 * major * major * y;

    while (res1 < res2)
    {
        DP(x + C_X, y + C_Y); // drawing points
        DP(-x + C_X, y + C_Y);
        DP(x + C_X, -y + C_Y);
        DP(-x + C_X, -y + C_Y);
        if (p1 < 0)
        {
            x++;
            res1 = res1 + (2 * minor * minor);
            p1 = p1 + res1 + (minor * minor);
        }
        else
        {
            x++;
            y--;
            res1 = res1 + (2 * minor * minor);
            res2 = res2 - (2 * major * major);
            p1 = p1 + res1 - res2 + (minor * minor);
        }
    }
    // Region 2
    d2 = ((minor * minor) * ((x + 0.5) * (x + 0.5))) + ((major * major) * ((y - 1) * (y - 1))) - (major * major * minor * minor);

    while (y >= 0)
    {
        DP(x + C_X, y + C_Y);
        DP(-x + C_X, y + C_Y);
        DP(x + C_X, -y + C_Y);
        DP(-x + C_X, -y + C_Y);

        if (d2 > 0)
        {
            y--;
            res2 = res2 - (2 * major * major);
            d2 = d2 + (major * major) - res2;
        }
        else
        {
            y--;
            x++;
            res1 = res1 + (2 * minor * minor);
            res2 = res2 - (2 * major * major);
            d2 = d2 + res1 - res2 + (major * major);
        }
    }
}
void display()
{
    bresenham_ellipse();
}

int main(int argc, char **argv)
{
    printf("ENTER THE MAJOR MINOR: ");
    scanf("%f %f", &major, &minor);
    printf("ENTER THE COORDINATES OF CENTER: ");
    scanf("%f %f", &C_X, &C_Y);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ellipse");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
// gcc -o out Ellipse.c -lglut32 -lopengl32 -lglu32
//Enter center co-ordinates: 50 50
//Enter radius value: 50 50