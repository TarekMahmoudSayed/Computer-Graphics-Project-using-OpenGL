#include <GL/glut.h>

float tx = 0.0f;
int dir = 1;

float angle = 0.0f;

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-300, 300, -300, 300);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(tx, 0, 0);

    glRotatef(angle, 0, 0, 1);

    glBegin(GL_QUADS);

    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(0, 100);
    glVertex2f(-70, 0);
    glVertex2f(0, -100);
    glVertex2f(70, 0);

    glEnd();

    glFlush();
}

void timer(int value) {

    tx += (3.0f * dir);

    if (tx > 180 || tx < -180)
        dir *= -1;

    angle += 2.0f;

    if (angle > 360) angle = 0;


    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutInitWindowPosition(200, 100);

    glutCreateWindow("Diamond - Translation + Rotation");

    glutDisplayFunc(display);

    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}
