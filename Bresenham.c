#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
float a,b,c,d,x,y;
void init()
{
    gluOrtho2D(-20,20,-20,20);
}
void Bresenham(int a,int b,int c,int d)
{
    x=a;
    y=b;
    double dx=(b-a);double dy=(d-c);
    double m=dy/dx;
    glBegin(GL_LINE_STRIP);glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2d(x,y);
    if(m<=1)  //slope is less than 1
    {
    	double decision=2*dy-dx;
    	for(int i=x;i<c;i++)
    	{
	     if(decision<=0)
	     decision+=2*dy;
	     else
	     {
	     decision+=2*dy-2*dx; 
	     y=y+1;
	     }
	     x=x+1;
	     glVertex2d(x,y);
    	}
    }
    else
    {                   // slope>=1
    double decision=2*dx-dy;
    	for(int i=y;i<d;i++)
    	{
	     if(decision<=0)
	     decision+=2*dx;
	     else
	     {
	     decision+=2*dx-2*dy; 
	     x=x+1;
	     }
	     y=y+1;
	     glVertex2d(x,y);
    	}
    }
    glEnd();
    glFlush();
    
}
void display() { 
    Bresenham(a, b, c, d);
 }
int main(int argc, char** argv)
{
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
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
