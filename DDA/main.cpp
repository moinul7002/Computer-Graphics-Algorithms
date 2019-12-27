#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
GLint x0,y0,xEnd,yEnd;
inline GLint round(const GLfloat a)
{
    return GLint(a+0.5);
}
void myInit(void)
{
    glClearColor(0.0,1.0,1.0,0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);
}
void readInput()
{

    printf("Enter x0, y0, xEnd, yEnd: ");
    scanf("%i %i %i %i",&x0,&y0,&xEnd,&yEnd);

}
void setPixel(GLint xcoordinate, GLint ycoordinate)
{
    glBegin(GL_POINTS);
    glVertex2i(xcoordinate,ycoordinate);
    glEnd();
    glFlush(); //forces execution in finite time
}

void lineDDA(GLint x0,GLint y0,GLint xEnd,GLint yEnd)
{
    GLint dx = abs(xEnd-x0);
    GLint dy = abs(yEnd-y0);
    GLint steps,k;
    GLfloat xIncrement,yIncrement,x=x0,y=y0;

    if(dx>dy)
        steps = dx;
    else
        steps = dy;

    xIncrement = GLfloat(dx) / GLfloat(steps);
    yIncrement = GLfloat(dy) / GLfloat(steps);
    setPixel(round(x),round(y));

    for(k=1;k<steps;k++)
    {
        x+= xIncrement;
        y+= yIncrement;
        setPixel(round(x),round(y));
    }
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    lineDDA(x0,y0,xEnd,yEnd);
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("DDA Line Algorithm");
    readInput();
    glutDisplayFunc(Display);
    myInit();
    glutMainLoop();
    return EXIT_SUCCESS;
}
