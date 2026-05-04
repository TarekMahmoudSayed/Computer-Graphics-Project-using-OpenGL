#include <GL/glut.h>

float tx = -200.0f;
int dir = 1;

float sc = 0.5f;
float scDir = 0.008f;

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-300, 300, -300, 300);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(tx, 0, 0);

    glScalef(sc, sc, 1.0f);

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.9f, 0.4f);

    glVertex2f(-100, 50);
    glVertex2f(-100, -50);
    glVertex2f(100, -50);
    glVertex2f(100, 50);

    glEnd();

    glFlush();

}

void timer(int value) {

    tx += (3.0f * dir);

    if (tx > 200 || tx < -200) dir *= -1;

    sc += scDir;

    if (sc > 1.8f || sc < 0.3f) scDir *= -1;

    glutPostRedisplay();

    glutTimerFunc(16, timer, 0);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutInitWindowPosition(300, 100);

    glutCreateWindow("Rectangle - Translation + Scaling");

    glutDisplayFunc(display);

    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}