#include <windows.h>
#include<GL/glut.h>
#include <gl/gl.h>
#include<math.h>
#include<stdio.h>
#define MAX 10 

int choice, choice1, choice2;
int vertices, x[MAX], y[MAX];
int i, xaux[MAX], yaux[MAX];
int line_x[2], c;
float slope;

void init()
{
	glClearColor(0.101, 1.0, 0.980, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500, 500, -500, 500);
}

void display() 
{
    //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  	//glutInitWindowSize(1000, 750);
	///glutCreateWindow("2D Transformations");
	//init();
    glClear(GL_COLOR_BUFFER_BIT);
    if(choice == 4)                                                             
    {
        glBegin(GL_LINES);
            glColor3f(1, 1, 1);
            glVertex2f(0, 500);
            glVertex2f(0, -500);	
            glVertex2f(-500, 0);
            glVertex2f(500, 0);		
        glEnd();	
    }
    if(choice1 == 3 || choice1 == 4 )                                               
    {
        glBegin(GL_LINES);
            glColor3f(1, 1, 1);
            glVertex2f(500,500);
            glVertex2f(-500,-500);	
            glVertex2f(-500,500);
            glVertex2f(500,-500);		
        glEnd();	
    }
    if(choice1 == 6)                                                         
    {
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
            glVertex2f(line_x[0], ((slope*line_x[0]) + c));
            glVertex2f(line_x[1], ((slope*line_x[1]) + c));	
        glEnd();	
    }

    glLineWidth(5.0);							                              
	glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        for(i=0; i<vertices; i++)
            glVertex2f(x[i], y[i]);
	glEnd();	
    
    glLineWidth(5.0);
    glBegin(GL_LINE_LOOP);                                                 
        glColor3f(1, 0, 0);
        for(i=0; i<vertices; i++)
            glVertex2f(xaux[i], yaux[i]);
	glEnd();
    glFlush();
   // glutMainLoop();
}

void translation()
{
    printf("\n\nTRANSLATION\n");
    int dx, dy;
    printf("Enter translation factor (dx dy): ");
    scanf("%d%d", &dx, &dy);
    for(i=0; i < vertices; i++)
    {
        xaux[i] = xaux[i] + dx;                                                 
        yaux[i] = yaux[i] + dy;
    }
    display();
}

void rotation()
{
    printf("\n\nROTATION\n");
    int x_pivot, y_pivot, angle, x_shifted, y_shifted;
    printf("Enter pivot point: ");
    scanf("%d %d", &x_pivot, &y_pivot);
    printf("Enter angle of rotation (in degree): ");
    scanf("%d", &angle);

    for(i=0; i < vertices; i++)
    {
        x_shifted = xaux[i] - x_pivot;                                    
        y_shifted = yaux[i] - y_pivot; 
        xaux[i] = x_pivot + (x_shifted*cos(angle * 3.14/180) - y_shifted*sin(angle * 3.14/180));
        yaux[i] = y_pivot + (x_shifted*sin(angle * 3.14/180) + y_shifted*cos(angle * 3.14/180)); 
    }
    display();
    //glutDisplayFunc(display);
}

void scaling()
{
    printf("\n\nSCALING\n");
    int x_scale, y_scale;   
    printf("Enter the scaling factor: ");
    scanf("%d %d", &x_scale, &y_scale);                   

    for (i = 0; i < vertices; i++)                                          
    {
        xaux[i] *= x_scale;                                              
        yaux[i] *= y_scale;
    }
   display();
}
// reflection
void x_axis()
{
    printf("\n\nREFLECTION ABOUT X-AXIS\n");
    for (i = 0; i < vertices; i++)                                          
        yaux[i] = -yaux[i];
    display();
}

void y_axis()
{
    printf("\n\nREFLECTION ABOUT Y-AXIS\n");
    for (i = 0; i < vertices; i++)                                          
        xaux[i] = -xaux[i];
    display();
}

void y_equal_xp()           
{
    printf("\n\nREFLECTION ALONG LINE y = x\n");
    for(i=0; i<vertices; i++)
    {
        xaux[i] = y[i];
        yaux[i] = x[i];
    }                                          
    display();
}

void y_equal_xn()       
{
    printf("\n\nREFLECTION ALONG LINE y = -x\n");
    for(i=0; i<vertices; i++)
    {
        xaux[i] = -y[i];
        yaux[i] = -x[i];
    }                                          
    display();
}

void origin()
{
    printf("\n\nREFLECTION ABOUT ORIGIN\n");
    for (i = 0; i < vertices; i++) 
    {                                         
        xaux[i] = -xaux[i];
        yaux[i] = -yaux[i];
    }
    display();
}

void straight_line()
{
    printf("\n\nREFLECTION ALONG A STRAIGHT LINE\n");

    printf("Enter starting x-coordinate of line: ");
    scanf("%d", &line_x[0]);
    printf("Enter ending x-coordinate of line: ");
    scanf("%d", &line_x[1]);
    printf("Enter slope of line: ");
    scanf("%f", &slope);
    printf("Enter intercept of line: ");
    scanf("%d", &c);
    printf("\nEquation of given line is -> y = %0.2fx + %d\n", slope, c);

    for (i=0; i < vertices; i++)
    {
        xaux[i] = (((1 - slope*slope) * x[i]) + (2 * slope * (y[i] - c))) / (1 + slope*slope);
        yaux[i] = (((slope*slope - 1) * y[i]) + (2 * slope * x[i]) + 2*c) / (1 + slope*slope);
    }
    display();
}

void reflection()
{
    printf("\n\nOPERATIONS FOR REFLECTION\n\n1. About x-axis\n2. About y-axis\n3. y = x\n4. y = -x\n5. About origin\n6. y = mx +c\n\nEnter your choice: ");
    scanf("%d", &choice1);
    switch(choice1)
    {
        case 1: 
            x_axis();
            break;
        case 2: 
            y_axis();
            break;
        case 3: 
            y_equal_xp();
            break;
        case 4: 
            y_equal_xn();
            break;
        case 5: 
            origin();
            break;
        case 6: 
            straight_line();
            break;
        default: 
            printf("Wrong Choice\n");
            break;
    }
}

void shearing()
{
    printf("\n\nSHEARING\n");
    int shearfactor;
    printf("Enter the shearing factor: ");
    scanf("%d", &shearfactor);
    printf("Enter 1 for shearing along x-axis and 2 for shearing along y-axis: ");
    scanf("%d", &choice2);
    switch(choice2)
    {
        case 1:
        {
            for (i = 0; i < vertices; i++) 
            {                                         
                xaux[i] = x[i] + shearfactor * y[i];
                yaux[i] = y[i];
            }
            //display();
            break;
        }
        case 2: 
        {
            for (i = 0; i < vertices; i++) 
            {                                         
                xaux[i] = x[i];
                yaux[i] = y[i] + shearfactor * x[i];
            }
            display();
            break;
        }
        default: 
            printf("Wrong Choice\n"); 
            break;
    }
}

int main(int argc, char** argv) 
{
	glutInit(&argc, argv);

    printf("Enter the number of vertices of polygon: ");
    scanf("%d", &vertices);
    printf("Enter the coordinates in clockwise/anti-clockwise order:-\n");
    
    for(i=0; i<vertices; i++)
    {
        printf("Vertex-%d: ", i+1);
        scanf("%d %d", &x[i], &y[i]);
        xaux[i] = x[i]; 
        yaux[i] = y[i];
    }
    
    printf("\n\n2D TRANSFORMATION\n\n");
    printf("1. Translation\n2. Rotation\n3. Scaling\n4. Reflection\n5. Shearing\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: 
            translation(); 
            break;
        case 2: 
            rotation(); 
            break;
        case 3: 
            scaling(); 
            break;
        case 4: 
            reflection(); 
            break;
        case 5: 
            shearing(); 
            break;
        default: 
            printf("Wrong input\n"); 
            break;
    }
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 750);
	glutCreateWindow("2D Transformations");
	init();
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0; 
}
