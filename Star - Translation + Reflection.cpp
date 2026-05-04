#include <GL/glut.h>
#include <math.h>

float tx = -150.0f;
int dir = 1;
bool isReflected = false;
int counter = 0;

void drawStar() {

    float outer = 100.0f, inner = 45.0f;

    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(0, 0);

    for (int i = 0; i <= 10; i++) {

        float r = (i % 2 == 0) ? outer : inner;

        float a = i * 3.14159f / 5.0f - 3.14159f / 2.0f;

        glColor3f(i % 2 == 0 ? 1.0f : 1.0f, i % 2 == 0 ? 0.8f : 0.4f, 0.0f);

        glVertex2f(r * cos(a), r * sin(a));

    }

    glEnd();

}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-300, 300, -300, 300);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(tx, 0, 0);

    if (isReflected) glScalef(1.0f, -1.0f, 1.0f);

    drawStar();

    glFlush();
}

void timer(int value) {

    tx += (3.0f * dir);

    if (tx > 150 || tx < -150) dir *= -1;

    counter++;

    if (counter >= 300) {

        isReflected = !isReflected;

        counter = 0;

    }

    glutPostRedisplay();

    glutTimerFunc(16, timer, 0);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutInitWindowPosition(400, 100);

    glutCreateWindow("Star - Translation + Reflection");

    glutDisplayFunc(display);

    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}