#include <windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

int xmin, ymin, xmax, ymax;  //Polygon boundaries

float old[3] = {0.0, 0.0, 0.0};  //Color of the polygon - black
float new[3] = {1.0, 0.0, 0.0};  //Color to be filled - red

void Color_Pixel(int x, int y)   
{   
    glBegin(GL_POINTS);   
        glColor3fv(new);   
        glVertex2i(x, y);   
    glEnd();   
    glFlush();   
}   

void display()   
{    
    glClear(GL_COLOR_BUFFER_BIT);   
    //Drawing polygon
    glColor3fv(old);   
    glBegin(GL_POLYGON);   
        glVertex2i(xmin, ymin);    
        glVertex2i(xmin, ymax);   
        glVertex2i(xmax, ymax);   
        glVertex2i(xmax, ymin);   
    glEnd();   
    glFlush();     
}   

void Flood_Fill(int x,int y)   
{   
    float curr[3];   
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, curr);  
    // if curr == old
    if(curr[0] == old[0] && (curr[1]) == old[1] && (curr[2]) == old[2])   
    {   
        Color_Pixel(x, y);   
        Flood_Fill(x+1, y);   
        Flood_Fill(x-1, y);   
        Flood_Fill(x, y+1);   
        Flood_Fill(x, y-1);   
        Flood_Fill(x+1, y+1);  
        Flood_Fill(x+1, y-1);  
        Flood_Fill(x-1, y+1);  
        Flood_Fill(x-1, y-1); 
    }   
}   

void mouse(int btn, int state, int x, int y)   
{   
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)       
        Flood_Fill(x, 500-y);   
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
    glutCreateWindow("Flood-Fill Algorithm");

    init();
    glutDisplayFunc(display);  
    glutMouseFunc(mouse); 
    glutMainLoop();  
    return 0;  
} 
//gcc -o out Flood_Fill.c -lglut32 -lopengl32 -lglu32
//.\out.exe
//100 100 150 150
