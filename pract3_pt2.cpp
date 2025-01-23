#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;

void displayPoint(int x, int y)
{
    glColor3f(1, 1, 1);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void SimpleLine(float x1, float y1, float x2, float y2)
{
    float step;
    float dx = x2 - x1;
    float dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    float Xinc = dx / step;
    float Yinc = dy / step;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= step; i++)
    {
        displayPoint(x, y);
        x = x + Xinc;
        y = y + Yinc;
    }
    glFlush();
}

void DottedLine(float x1, float y1, float x2, float y2)
{
    float step;
    float dx = x2 - x1;
    float dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }
    float Xinc = dx / (float)step;
    float Yinc = dy / (float)step;
    float x = x1;
    float y = y1;
    displayPoint(x, y);
    for (int i = 0; i <= step; i++)
    {
        x = x + Xinc;
        y = y + Yinc;
        if (i % 3 == 0)
        {
            displayPoint(x, y);
        }
    }
    glFlush();
}

void Line(int x1, int y1, int x2, int y2)
{
    int M, p, dx, dy, x, y;
    if (x2 - x1 == 0)
    {
        M = (y2 - y1);
    }
    else
    {
        M = (y2 - y1) / (x2 - x1);
    }
    if (abs(M) < 1)
    {
        if (x1 > x2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        dx = abs(x2 - x1);
        dy = abs(y2 - y1);

        p = 2 * dy - dx;

        x = x1;
        y = y1;

        glBegin(GL_POINTS);
        while (x <= x2)
        {
            glVertex2f(x, y);
            x = x + 1;

            if (p >= 0)
            {
                if (M < 1)
                {
                    y++;
                }
                else
                {
                    y--;
                }
                p = p + 2 * dy - 2 * dx;
            }
            else
            {
                y = y;
                p = p + 2 * dy;
            }
        }
        glEnd();
    }
    if (abs(M) >= 1)
    {
        if (x1 > x2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        dx = abs(x2 - x1);
        dy = abs(y2 - y1);

        p = 2 * dy - dx;

        x = x1;
        y = y1;

        glBegin(GL_POINTS);
        while (x <= x2)
        {
            glVertex2f(x, y);
            x = x + 1;

            if (p >= 0)
            {
                if (M < 1)
                {
                    y++;
                }
                else
                {
                    y--;
                }
                p = p + 2 * dy - 2 * dx;
            }
            else
            {
                y = y;
                p = p + 2 * dy;
            }
        }
        glEnd();
    }
    if (M >= 1)
    {
        if (y1 > y2)
        {
            swap(y1, y2);
            swap(x1, x2);
        }
        dx = abs(x2 - x1);
        dy = abs(y2 - y1);

        p = 2 * dx - dy;

        x = x1;
        y = y1;

        glBegin(GL_POINTS);

        while (y <= y2)
        {
            glVertex2f(x, y);
            y = y + 1;
            if (p >= 0)
            {
                if (M >= 1)
                {
                    x++;
                }
                else
                {
                    x--;
                    p = p + 2 * dx - dy;
                }
            }
            else
            {
                x = x;
                p = p + 2 * dx;
            }
        }
        glEnd();
    }
    glFlush();
}
void ThickLine(float x1, float y1, float x2, float y2)
{
    float step;
    float dx = x2 - x1;
    float dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }
    float Xinc = dx / (float)step;
    float Yinc = dy / (float)step;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= step; i++)
    {
        glColor3f(0, 1, 0);
        glPointSize(20);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        x = x + Xinc;
        y = y + Yinc;
    }
    glFlush();
}

void drawCb(int boardSize)
{
    int squareSize = 600 / boardSize;
    bool isWhite = true;

    for (int i = 0; i <= boardSize; i++)
    {
        ThickLine(0, i * squareSize, boardSize * squareSize, i * squareSize);
        ThickLine(i * squareSize, 0, i * squareSize, boardSize * squareSize);
    }

    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < boardSize; col++)
        {
            if ((row + col) % 2 == 0)
            {
                glColor3f(1.0f, 1.0f, 1.0f);
            }
            else
            {
                glColor3f(0.0f, 0.0f, 0.0f);
            }
            glBegin(GL_POLYGON);
            glVertex2i(col * squareSize, row * squareSize);
            glVertex2i((col + 1) * squareSize, row * squareSize);
            glVertex2i((col + 1) * squareSize, (row + 1) * squareSize);
            glVertex2i(col * squareSize, (row + 1) * squareSize);
            glEnd();
        }
    }
}

void initGL()
{
    glClearColor(0.8, 0.8, 0.8, 1.0);
    gluOrtho2D(0, 600, 0, 600);
    glPointSize(1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawCb(8);

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Chessboard");
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}