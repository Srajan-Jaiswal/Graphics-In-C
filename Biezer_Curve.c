#include <windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

int SCREEN_HEIGHT = 500;
int points = 0;
int clicks = 4;

void Init() {
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,500.0);

}

struct Point {
    float x, y;
};

struct Point abc[20];

int factorial(int n)
{
    if (n<=1)
        return(1);
    else
        n=n*factorial(n-1);
    return n;
}

float binomial_coff(float n,float k)
{
    float ans;
    ans = factorial(n) / (factorial(k)*factorial(n-k));
    return ans;
}

void drawDot(int x, int y) {
    glBegin(GL_POINTS);
     glVertex2i(x,y);
    glEnd();
    glFlush();
}

void drawLine(struct Point p1, struct Point p2) {
    glBegin(GL_LINES);
      glVertex2f(p1.x, p1.y);
      glVertex2f(p2.x, p2.y);
    glEnd();
    glFlush();
}

struct Point drawBezier(struct Point PT[], double t) {
    struct Point P;
    P.x = pow((1 - t), 3) * PT[0].x + 3 * t * pow((1 -t), 2) * PT[1].x + 3 * (1-t) * pow(t, 2)* PT[2].x + pow (t, 3)* PT[3].x;
    P.y = pow((1 - t), 3) * PT[0].y + 3 * t * pow((1 -t), 2) * PT[1].y + 3 * (1-t) * pow(t, 2)* PT[2].y + pow (t, 3)* PT[3].y;

    return P;
}

struct Point drawBezierGeneralized(struct Point PT[], double t) {
        struct Point P;
        P.x = 0; P.y = 0;   
        for (int i = 0; i<clicks; i++)
        {
            P.x = P.x + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].x;
            P.y = P.y + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].y;
        }
        return P;
    }

void myMouse(int button, int state, int x, int y) {
  
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    abc[points].x = (float)x;
    abc[points].y = (float)(SCREEN_HEIGHT - y);
    points++;

    drawDot(x, SCREEN_HEIGHT - y);

    if(points == clicks) {
        glColor3f(1.0f,0.0f,0.0f); 
        for(int k=0;k<clicks-1;k++)
            drawLine(abc[k], abc[k+1]);

        struct Point p1 = abc[0];
        for(double t = 0.0;t <= 1.0; t += 0.02)
        {
            struct Point p2 = drawBezierGeneralized(abc,t);
            drawLine(p1, p2);
            p1 = p2;
        }
        glColor3f(0.0,0.0,0.0);
        points = 0;
    }
  }
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,500);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Srajan-170");
    glutMouseFunc(myMouse);
    glutDisplayFunc(Display);
    Init();
    glutMainLoop();

    return 0;
}
