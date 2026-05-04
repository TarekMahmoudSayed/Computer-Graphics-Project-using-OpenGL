#include <GL/glut.h>

float sc = 0.1f;

bool growing = true;

void circlePoints(int cx, int cy, int x, int y) {

    glVertex2i(cx + x, cy + y);
    glVertex2i(cx - x, cy + y);
    glVertex2i(cx + x, cy - y);
    glVertex2i(cx - x, cy - y);
    glVertex2i(cx + y, cy + x);
    glVertex2i(cx - y, cy + x);
    glVertex2i(cx + y, cy - x);
    glVertex2i(cx - y, cy - x);

}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-300, 300, -300, 300);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glScalef(sc, sc, 1.0f);

    int radius = 150;

    int x = 0, y = radius;

    int p = 1 - radius;

    glBegin(GL_POINTS);

    glColor3f(0.2f, 0.8f, 1.0f);

    circlePoints(0, 0, x, y);

    while (x < y) {

        x++;

        if (p < 0)
            p += 2 * x + 1;

        else {

            y--;

            p += 2 * (x - y) + 1;

        }

        circlePoints(0, 0, x, y);

    }

    glEnd();

    glFlush();

}

void timer(int value) {

    if (growing) {

        sc += 0.01f;

        if (sc > 1.8f)
            growing = false;

    }
    else {

        sc -= 0.01f;

        if (sc < 0.1f)
            growing = true;

    }

    glutPostRedisplay();

    glutTimerFunc(1000 / 60, timer, 0);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Circle - Scaling");

    glutDisplayFunc(display);

    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}