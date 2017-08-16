//7.10.6 ��ά�۲����ʾ��

#include <GL/glut.h>

GLsizei winWidth = 600, winHeight = 600;
GLfloat x0 = 100, y0 = 50.0, z0 = 50.0;
GLfloat xref = 50.0, yref = 50.0, zref = 0.0;
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0;

GLfloat xwMin = -40.0, ywMin = -60.0, xwMax = 40.0, ywMax = 60.0;

GLfloat dnear = 25.0, dfar = 125.0;


void displayFcn() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);

	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(100.0, 0.0, 0.0);
	glVertex3f(100.0,100.0, 0.0);
	glVertex3f(0.0, 100.0, 0.0);
	glEnd();
	glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)

{

	glViewport(0, 0, newWidth, newHeight);

	winWidth = newWidth;
	winHeight = newHeight;


}
void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(x0, y0, z0, xref, yref, zref, Vx, Vy, Vz);
	glMatrixMode(GL_PROJECTION);
	glFrustum(xwMin, xwMax, ywMin, ywMax, dnear, dfar);
}

void main(int argc, char ** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(50, 50);

	glutInitWindowSize(winWidth, winHeight);

	glutCreateWindow("Perspective View of A Square");

	init();

	glutDisplayFunc(displayFcn);

	glutReshapeFunc(winReshapeFcn);

	glutMainLoop();

}