#include <windows.h>  
#include <GL/glut.h>  
#include <stdio.h>
 
void initGL() {
   glClearColor(0.0, 0.0, 0.0, 0.0); 
   glOrtho(-12.0, 12.0, -12.0, 12.0, -12.0, 12.0); // 12 x 12 graph
}
 
void display() {
   glClear(GL_COLOR_BUFFER_BIT);   
   glBegin(GL_QUADS);              
      glColor3f(1.0, 0.0, 0.0); // Red
      glVertex2f(-8.0, 3.0);     
      glVertex2f(-2.0, 3.0);     
      glVertex2f(-2.0, 7.0);
      glVertex2f(-8.0, 7.0);
    glEnd();

    glBegin(GL_LINES);
      glColor3f(0.0, 0.0, 1.0); // Blue
      glVertex2f(-7.0, -9.0);
      glVertex2f(-1.0, -9.0);
    glEnd();

   glBegin(GL_TRIANGLES);          
      glColor3f(0.0, 1.0, 0.0); // Green
      glVertex2f(3.0, -10.0);
      glVertex2f(9.0, -10.0);
      glVertex2f(6.0, -6.0);
   glEnd();

   glBegin(GL_TRIANGLE_STRIP);
      glColor3f(0.0, 1.0, 1.0); // Light Blue
      glVertex2f(-9.0, -4.0);
      glVertex2f(-9.0, 2.0);
      glVertex2f(-6.0, -3.0);
      glVertex2f(-6.0, 2.0);
      glVertex2f(-0.3, -1.0);
   glEnd();

   glBegin(GL_POLYGON);            
      glColor3f(1.0, 1.0, 1.0); // White
      glVertex2f(8.0, 4.0);
      glVertex2f(10.0, 4.0);
      glVertex2f(11.0, 6.0);
      glVertex2f(10.0, 8.0);
      glVertex2f(8.0, 8.0);
      glVertex2f(7.0, 6.0);
   glEnd();

   glBegin(GL_QUAD_STRIP);
      glColor3f(1.0, 1.0, 0.0); // Yellow
      glVertex2f(1.0, 3.0);
      glVertex2f(1.0, -3.0);
      glVertex2f(3.0, 3.0);
      glVertex2f(3.0, -3.0);
      glVertex2f(3.0, 5.0);
      glVertex2f(3.0, -5.0);
      glVertex2f(7.0, 5.0);
      glVertex2f(7.0, -5.0);
   glEnd();
 
   glFlush();  
}
 

int main(int argc, char** argv) {
   glutInit(&argc, argv);          
   glutCreateWindow("EXP 2");  
   glutInitWindowSize(1000, 1000);   
   glutInitWindowPosition(500, 500); 
   glutDisplayFunc(display);       
   initGL();                       
   glutMainLoop();                 
   return 0;
}
