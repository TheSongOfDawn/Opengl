////13.10 һ��������������ӣ�
////��xyƽ������z��������תһ����������.��ά��Ļ�����ԭ�� ���ڴ�������
////Z�ᾭ���������� 
////Ŀ��������һ����ת��������
//#include <GL/glut.h>
//#include <cmath>
//#include <cstdlib>
//
//const double TWO_PI = 6.2831853;
//GLsizei winWidth = 500, winHeight = 500;
//GLuint regHex;//6���ε�list id
//static GLfloat rotTheta = 0.0;
//
//class scrPt {
//public:
//	GLint x, y;
//};
//static void init() {
//	scrPt hexVertex;
//	GLdouble hexTheta;
//	GLint k;
//
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	/*
//	set up a dispalylist for a red regular hexagon
//	vertices for the hexagon are six equally sapced
//	points around the circumference of a circle.
//	*/
//	regHex = glGenLists(1);
//	glNewList(regHex, GL_COMPILE);
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_POLYGON);
//	for (k = 0; k < 6; k++) {
//		hexTheta = TWO_PI*k / 6;
//		hexVertex.x = 150 + 100 * cos(hexTheta);
//		hexVertex.y = 150 + 100 * sin(hexTheta);
//		glVertex2i(hexVertex.x, hexVertex.y);
//		}
//	glEnd();
//	glEndList();
//}
//void displayHex() {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glPushMatrix();
//	glRotatef(rotTheta, 0.0, 0.0, 1.0);//����z����תrotTheta
//	glCallList(regHex);
//	glPopMatrix();
//	//����˫�����֪ʶû�о߱�
//	glutSwapBuffers();
//	glFlush();
//}
//
//void rotateHex() {
//	rotTheta += 3.0;
//	if (rotTheta > 360.0) {
//		rotTheta -= 360.0;
//	}
//	//�������֪ʶҲ��֪��
//	glutPostRedisplay();
//}
//
//void mouseFcn(GLint button, GLint action, GLint x, GLint y) {
//	switch (button)
//	{
//	case GLUT_LEFT_BUTTON://START THE ROTATION
//		if (action == GLUT_DOWN)
//			glutIdleFunc(rotateHex); break;
//	case GLUT_RIGHT_BUTTON:
//		if (action == GLUT_DOWN)
//			glutIdleFunc(NULL); break;
//	default:
//		break;
//	}
//}
//void winReshapeFcn(GLint newWidth, GLint newHeight)
//
//{
//	glViewport(0, 0, (GLsizei)newWidth, (GLsizei)newHeight);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	
//
//	gluOrtho2D(-320.0, 320.0, -320.0, 320.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//}
//void main(int argc, char ** argv)
//
//{
//
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//
//	//glutInitWindowPosition(150, 150);
//
////	glutInitWindowSize(winWidth, winHeight);
//
//	glutCreateWindow("Animation Example");
//
//	init();
//
//	glutDisplayFunc(displayHex);
//
//	glutReshapeFunc(winReshapeFcn);
//	glutMouseFunc(mouseFcn);
//
//	glutMainLoop();
//
//}