#include <windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

const int MAX_POINTS = 20; 
int poly_size = 4; 
int poly_points[20][2]; 

void display();

void init() {
    gluOrtho2D(0, 300, 0, 300);
}

int x_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) { 
    int num = (x1*y2 - y1*x2) * (x3-x4) - (x1-x2) * (x3*y4 - y3*x4); 
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4); 
    return num/den; 
} 
 // window                       // line
int y_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) { 
    int num = (x1*y2 - y1*x2) * (y3-y4) - (y1-y2) * (x3*y4 - y3*x4); 
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4); 
    return num/den; 
} 
  
void clip(int x1, int y1, int x2, int y2) { 

    int new_points[MAX_POINTS][2], new_poly_size = 0; 
  
    for (int i = 0; i < poly_size; i++) { 
        
        int k = (i+1) % poly_size; 
        int ix = poly_points[i][0], iy = poly_points[i][1]; 
        int kx = poly_points[k][0], ky = poly_points[k][1]; 
  
        // Calculating position of first point w.r.t. clipper line 
        int i_pos = (x2-x1) * (iy-y1) - (y2-y1) * (ix-x1); 
  
        // Calculating position of second point w.r.t. clipper line 
        int k_pos = (x2-x1) * (ky-y1) - (y2-y1) * (kx-x1); 
  
        // inside 
        if (i_pos < 0  && k_pos < 0) { 
            new_points[new_poly_size][0] = kx; 
            new_points[new_poly_size][1] = ky; 
            new_poly_size++; 
        } 
  
        // first point is outside 
        else if (i_pos >= 0  && k_pos < 0) { 
            new_points[new_poly_size][0] = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky); 
            new_points[new_poly_size][1] = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky); 
            new_poly_size++; 
  
            new_points[new_poly_size][0] = kx; 
            new_points[new_poly_size][1] = ky; 
            new_poly_size++; 
        } 
  
        // second point is outside 
        else if (i_pos < 0  && k_pos >= 0) { 
            new_points[new_poly_size][0] = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky); 
            new_points[new_poly_size][1] = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky); 
            new_poly_size++; 
        } 
    } 
  
    poly_size = new_poly_size; 
    for (int i = 0; i < poly_size; i++) 
    { 
        poly_points[i][0] = new_points[i][0]; 
        poly_points[i][1] = new_points[i][1]; 
    } 

} 

void suthHodgClip(int clipper_points[][2], int clipper_size) { 

    for (int i = 0; i < clipper_size; i++) { 
        int k = (i+1) % clipper_size; 
        clip(clipper_points[i][0], clipper_points[i][1], clipper_points[k][0], clipper_points[k][1]); 
    } 
  
    display();
} 

void ClipKey(unsigned char key, int x, int y)
{
    if(key == 'a') {
        
       int clipper_size = 4; 
       int clipper_points[][2] = {{100,100}, {100,200}, {200,200}, {200,100}}; 
       suthHodgClip(clipper_points, clipper_size); 
       glFlush();

    }
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    // Box code
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(100,100);
    glVertex2i(100,200);
    glVertex2i(200,200);
    glVertex2i(200,100);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);

    for (int i=0; i < poly_size; i++) 
        glVertex2i(poly_points[i][0], poly_points[i][1]);

    glEnd();

    glFlush();
}
int main(int argc,char** argv) {

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);

    printf("Enter the Square clipping Box co-ordinates: %d %d \n", 100, 200);
    printf("Enter total number of the sides of the polygon: %d \n", poly_size);
    printf("Enter the co-ordinates of a %d sided polygon: ", poly_size);

    for(int i = 0; i < poly_size; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &poly_points[i][j]);
        }
    }

    glutCreateWindow("Sutherland – Hodgeman polygon clipping algorithm");

    glutDisplayFunc(display);
    glutKeyboardFunc(ClipKey);
    init();
    glutMainLoop();

    return 0; 
} 

