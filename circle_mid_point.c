#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x = 0, y, x2, y2, m, i, j, p;
int dx = 0, dy = 0, r;
void Circle_Midpoint()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    p = 1 - r; // decision parameter
    while ((x <= y))
    {
        if (p < 0)
        {
            x = x + 1;
            y = y;
            printf("%0.2f %0.2f\n", x, y);
            p = p + (2 * x) + 1;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            printf("%0.2f %0.2f\n", x, y);
            p = p + (2 * x) + 1 - (2 * y);
        }
        // eight octants
        glVertex2f((x / 100),(y / 100));
        glVertex2f((y / 100),(x / 100)));
        glVertex2f(-(x / 100), (-(y / 100)));
        glVertex2f(-(x / 100)), ((y / 100)));
        glVertex2f((x / 100)), (-(y / 100)));
        glVertex2f((y / 100)), (-(x / 100)));
        glVertex2f(-(y / 100)), (-(x / 100)));
        glVertex2f(-(y / 100)), ((x / 100)));
    }
    glEnd();
    glFlush();
}

void display()
{
    Circle_Midpoint();
}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char **argv)
{
    printf("Enter radius: ");
    scanf("%d", &r);
    y = r;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle_Mid_Point");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
// gcc -o out circle_mid_point.c -lglut32 -lopengl32 -lglu32