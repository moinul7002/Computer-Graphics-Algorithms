#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
float x, y, len, alpha;
int n;

void line (float x1, float y1, float x2, float y2)
{
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
}

void c_curve (float x, float y, float len, float alpha, int n)
{
    if(n > 0){
        len = len / sqrt(2.0);
        c_curve(x, y, len, alpha+45, n-1);

        x += len*cos(alpha+45);
        y += len*sin(alpha+45);
        c_curve(x, y, len, alpha-45, n-1);
    }
    else{
        line(x, y, x+len*cos(alpha), y+len*sin(alpha));
    }
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);
	glPointSize(1);
	glBegin(GL_LINES);
	c_curve(x, y, len, alpha, n);
	glEnd();
	glFlush ();
}

void init (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.7,0.7,0.7,0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200,500,-200,500);
}

int main(int argc, char** argv)
{
    cout<<"Co-ordinate of C(x,y): ";
    cin>>x>>y;
    cout<<"\nLength: ";
    cin>>len;
    cout<<"\nAngle: ";
    cin>>alpha;
    cout<<"\nValue of n: ";
    cin>>n;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(850, 600);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("C CURVE");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}
