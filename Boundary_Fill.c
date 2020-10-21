#include <windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

int xmin, ymin, xmax, ymax; 
float fill[3] = {0.0, 255, 0.0};  
float border[3] = {255, 0.0, 0.0};  

void Color_Pixel(int x, int y)  
{  
    glBegin(GL_POINTS);  
        glColor3fv(fill);  
        glVertex2i(x, y);  
    glEnd();  
    glFlush();  
}

void display()  
{  
    glClear(GL_COLOR_BUFFER_BIT);  
    glColor3fv(border);  
    glLineWidth(5);
    glBegin(GL_LINES);  
        glVertex2i(xmin, ymin);   glVertex2i(xmin, ymax);   
        glVertex2i(xmax, ymin);   glVertex2i(xmax, ymax);  
        glVertex2i(xmin, ymin);   glVertex2i(xmax, ymin);  
        glVertex2i(xmin, ymax);   glVertex2i(xmax, ymax);  
    glEnd();  
    glFlush();  
}

void BoundaryFill(int x,int y)  
{  
    float curr[3];  
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, curr);  

    if((curr[0] != border[0] && (curr[1]) != border[1] &&
       (curr[2])!= border[2]) && (curr[0] != fill[0] && 
       (curr[1]) != fill[1] && (curr[2]) != fill[2]))  
    {  
        Color_Pixel(x, y);  
        BoundaryFill(x+1, y);  
        BoundaryFill(x-1, y);  
        BoundaryFill(x, y+1);  
        BoundaryFill(x, y-1);  
        BoundaryFill(x+1, y+1);  
        BoundaryFill(x+1, y-1);  
        BoundaryFill(x-1, y+1);  
        BoundaryFill(x-1, y-1); 
    }  
}  

void mouse(int btn, int state, int x, int y)  
{  
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    {
        BoundaryFill(x, 500-y);  
    }
}

void init()
{
    glClearColor(0.101, 1.0, 0.980, 1.0); //Background color - cyan
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)  
{  
    printf("Enter Polygon Coordinates: ");
    scanf("%d%d%d%d", &xmin ,&ymin,&xmax,&ymax);
    glutInit(&argc, argv);  
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(500, 500);  
    glutCreateWindow("Boundary-Fill Algorithm");

    init();
    glutDisplayFunc(display);  
    glutMouseFunc(mouse); 
    glutMainLoop();  
    return 0;  
} 
