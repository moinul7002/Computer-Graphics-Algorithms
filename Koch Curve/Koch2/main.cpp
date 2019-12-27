#include <bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
using namespace std;
int n;
double xx, yy, lngth, aalpha;


void line(double x1, double y1, double x2, double y2){
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
    glFlush();
}
double radian(double degree){
    return acos(-1)*degree/180.0;
}
double cosine(double alpha){
    return cos(radian(alpha));
}
double sine(double alpha){
    return sin(radian(alpha));
}
void Koch_Curve(double x, double y, double len, double alpha, int n){
    if(n>0){
        len=len/3.0;
        Koch_Curve(x, y, len, alpha, n-1);
        x=x+len*cosine(alpha); y=y+len*sine(alpha);
        Koch_Curve(x, y, len, alpha-60, n-1);
        x=x+len*cosine(alpha-60); y=y+len*sine(alpha-60);
        Koch_Curve(x, y, len, alpha+60, n-1);
        x=x+len*cosine(alpha+60); y=y+len*sine(alpha+60);
        Koch_Curve(x, y, len, alpha, n-1);
    }
    else line(x, y, x+len*cosine(alpha), y+len*sine(alpha));
}

void display(void){
    //glClearColor(0, 0.0, 0.0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    Koch_Curve(xx, yy, lngth, aalpha, n);
}
void init(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 1.0, 1.0, 0.0);
    glColor3f(1.0f,0.0f,0.0f);
    //glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,800.0,0.0,600.0);
}
int main(int argc, char** argv)
{
    cout<<"Enter Co-ordinate of (x,y): ";
    cin>>xx>>yy;
    cout<<"\nEnter Length: ";
    cin>>lngth;
    cout<<"\nEnter Degree of Angle: ";
    cin>>aalpha;
    cout<<"\nEnter No. of Iteration: ";
    cin>>n;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Koch Curve");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
