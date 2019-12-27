#include<windows.h>
#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

int xc,yc,a,b;
void pp(int x,int y)
{
    glBegin(GL_POINTS);
            glVertex2i(x,y);
    glEnd();
}
void getpixel(int x,int y)
{
    pp(300+x,300+y);
    pp(300-x,300+y);
    pp(300-x,300-y);
    pp(300+x,300-y);
}

void display ()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x=0;
    int y=b;
    int e=a*a;
    int g=b*b;
    int fx=0;
    int fy=2*e*b;

    int p0=g-e*b+0.25*e;
    while(fx<fy){
        getpixel(x,y);
        x++;
        fx=fx+2*g;
        if(p0<0){
            p0=p0+fx+g;
        }
        else{
            y--;
            fy=fy-2*e;
            p0=p0+fx+g-fy;
        }


    }
    getpixel(x,y);
    p0=g*(x+0.5)*(x+0.5)+e*(y-1)*(y-1)-e*g;
    while(y>0)
    {
        y--;
        fy=fy-2*e;
        if(p0>=0)
            p0=p0-fy+e;
        else{
            x++;
            fx=fx+2*e;
            p0=p0+fx-fy+e;
        }
        getpixel(x,y);
    }
    glFlush();
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0); //clear values for RGBA
    glColor3f(1.0f,1.0f,1.0f); //set current color - RGB
    glPointSize(3.0); //diameters of rasterized points
    glMatrixMode(GL_PROJECTION); // specifies current matrix
    glLoadIdentity();
    gluOrtho2D(0.0,800.0,0.0,600.0); //left, right, top, bottom
}

int main (int argc, char **argv)
{
    cout<<"enter values of a and b:"<<endl;
    cin>>a>>b;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,50);
    glutCreateWindow("MidPoint Ellipse Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
