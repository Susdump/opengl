#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
void initialize(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 600, 600, 0);
}
void primitives(void)
{
    glColor3f(1, 1, 1);
    // glutKeyboardFunc(keyboard);
}
int main(int argc, char **argv)
{1
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("test");
    // initialize();
    glutMainLoop();
    return 0;
}