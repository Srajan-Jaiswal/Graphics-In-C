#include <windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

int r,h,k;

void init() {
    glEnable(GL_DEPTH_TEST);
    glOrtho(-100.0,100.0,-100.0,100.0,-100.0,100.0);
}

void sphere() {
   printf("\nEnter the radius of sphere: ");
   scanf("%d",&r);
   glColor3f(1.0f,1.0f,1.0f); 
   glutWireSphere(r, 50, 50);
   glFlush();
}

void cone() {
   printf("\nEnter the base radius of cone: ");
   scanf("%d",&r);
   printf("\nEnter the height of cone: ");
   scanf("%d",&h);
   glColor3f(1.0f,1.0f,1.0f); 
   glutWireCone(r,h, 50, 50);
   glFlush();
}

void cube() {
   printf("\nEnter the side of cube: ");
   scanf("%d",&r);
   glColor3f(0.0f,0.0f,1.0f); 
   glutSolidCube(r);
   glFlush();
}

void teapot() {
    
}

void display(void) {	
    glRotatef( 20, 1.0, 0.0, 0.0 );
    glRotatef( -20, 0.0, 1.0, 0.0 );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(k == 1)
        sphere();
    else if(k == 2)
        cone();
    else if(k == 3)
        cube();
    else
        teapot();
    
}
int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    printf("1.Sphere\n2.Cone\n3.Cube\n4.Teapot");
    printf("\nEnter Your Choice : ");
    scanf("%d",&k);
    
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("3D-Shapes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
