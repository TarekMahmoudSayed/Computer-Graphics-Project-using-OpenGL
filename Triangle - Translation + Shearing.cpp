#include <GL/glut.h>

float tx = -150.0f;
int dir = 1;

float shear = 0.0f;
float shearDir = 0.008f;

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-300, 300, -300, 300);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(tx, 0, 0);

    float shearMatrix[16] = {
        1,     0, 0, 0,
        shear, 1, 0, 0,
        0,     0, 1, 0,
        0,     0, 0, 1
    };

    glMultMatrixf(shearMatrix);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.2f, 0.5f); glVertex2f(0, 100);

    glColor3f(0.5f, 0.2f, 1.0f); glVertex2f(-80, -80);

    glColor3f(0.2f, 0.8f, 0.5f); glVertex2f(80, -80);

    glEnd();

    glFlush();

}

void timer(int value) {

    tx += (3.0f * dir);

    if (tx > 150 || tx < -150) dir *= -1;

    shear += shearDir;

    if (shear > 0.8f || shear < -0.8f) shearDir *= -1;

    glutPostRedisplay();

    glutTimerFunc(16, timer, 0);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutInitWindowPosition(500, 100);

    glutCreateWindow("Triangle - Translation + Shearing");

    glutDisplayFunc(display);

    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}