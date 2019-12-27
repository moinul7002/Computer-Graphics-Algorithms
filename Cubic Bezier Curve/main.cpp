#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define CTRL_COUNT 100
int ctrlPointsCount;
int ctrlPointsX[CTRL_COUNT], ctrlPointsY[CTRL_COUNT];
int X1[3]={20,25,20}, Y1[3]={5,24,38};  //first point(x1[0],y1[0])    second(x1[1],y1[1]) third(x1[2],y1[2])

void myInit()
{
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(1.0,0.0,0.0);
glPointSize(8.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,128.0,0.0,96.0);
}
//p(t)=(1-t)^3*p0+3t(1-t)^2*p1+3t^2(1-t)p2+t^3p3
float getNextBezierPointX(float t)
{
float x=0.0;

for(int i=0; i<ctrlPointsCount; i++)
{
int c;
if(i==0 || i==ctrlPointsCount-1)
    c = 1;
else
{
    c = ctrlPointsCount-1;
}
x +=  c * pow(t, i) * pow(1-t, ctrlPointsCount-1-i) * ctrlPointsX[i];
}


return x;
}

float getNextBezierPointY(float t)
{
float y=0.0;

for(int i=0; i<ctrlPointsCount; i++)
{
int c;
if(i==0 || i==ctrlPointsCount-1)
    c = 1;
else
{
    c = ctrlPointsCount-1;
}
y +=  c * pow(t, i) * pow(1-t, ctrlPointsCount-1-i) * ctrlPointsY[i];
}
return y;
}

void drawline()
{
// draw control points using red color
for(int i=0; i < 3; i++)
{
glBegin(GL_POINTS);
glVertex2i(ctrlPointsX[i], ctrlPointsY[i]);
glEnd();
glFlush();
}
// draw bezier curve using control points by calculating next points using cubic bezier curve formula
float oldX=ctrlPointsX[0], oldY=ctrlPointsY[0];
for(double t = 0.0;t <= 1.0; t += 0.01) {

float x = getNextBezierPointX(t);
float y = getNextBezierPointY(t);
//glColor3f(1.0,t,1.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2f(oldX, oldY);
glVertex2f(x, y);
glEnd();
glFlush();

oldX = x;
oldY = y;
}
}

void myDisplay()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
ctrlPointsCount=3;
for(int i=0;i<3;i++)
{
ctrlPointsX[i] = X1[i];
ctrlPointsY[i] = Y1[i];
}
drawline();

glFlush();
}


int main(int argc, char *argv[])
{

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(100,150);
glutCreateWindow("Cubic Bezier Curve");
glutDisplayFunc(myDisplay);
myInit();
glutMainLoop();
return 0;
}
