#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;
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
void drawCb(int boardSize)
{
    int squareSize = 600 / boardSize;
    bool isWhite = true;

    for (int i = 0; i <= boardSize; i++)
    {
        Line(0, i * squareSize, boardSize * squareSize, i * squareSize);
        Line(i * squareSize, 0, i * squareSize, boardSize * squareSize);
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