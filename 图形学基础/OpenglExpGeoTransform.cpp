////Opengl���α��ʾ��
//
//#include<GL\glut.h>
//#include <cstdlib>
//
//GLfloat xwcMin = 0.0, xwcMax = 225.0;
//
//GLfloat ywcMin = 0.0, ywcMax = 225.0;
//GLsizei winWidth = 600, winHeight = 600;
//void displayFcn0() {
//	glMatrixMode(GL_MODELVIEW);
//
//	glColor3f(0.0, 0.0, 1.0);
//	glRecti(50, 100, 200, 150);//Display blue rectangle
//	
//	glColor3f(1.0, 0.0, 0.0);
//	glTranslated(-200.0, -50.0, 0.0);//set translation parameters
//	glRecti(50, 100, 200, 150);
//	
//	glLoadIdentity();//Reset current matrix to identity
//	glColor3f(1.0, 1.0, 0.0);
//	glRotatef(90.0, 0.0, 0.0, 1.0);//Set 90��,rotation about z axis
//	glRecti(50, 100, 200, 150);//dispaly red,rotated rectangle.
//	//
//	glLoadIdentity();//Reset current matrix to identity
//	glColor3f(0.0, 1.0, 0.0);
//	glScalef(-0.5, 1.0, 1.0);//Set scale-reflection parameters
//	glRecti(50, 100, 200, 150);//Display red ,transform rectangle
//
//	glFlush();
//}
//
////ͨ�� ջ��������ʹ�þ������������Ч
////�������һ��ʹ��ջ����ĳ���
//void displayFcn1() {
//	glMatrixMode(GL_MODELVIEW);
//
//	glColor3f(0.0, 0.0, 1.0);
//	glRecti(50, 100, 200, 150);//Display blue rectangle
//
//	glPushMatrix();//make copy ofr indentity top matrix.
//	glColor3f(1.0, 0.0, 0.0);//set color to red
//	glTranslated(-200.0, -50.0, 0.0);//set translation parameters
//	glRecti(50, 100, 200, 150);
//
//	glPopMatrix();//throw away the translation matrix
//	glPushMatrix();//make copy ofr indentity top matrix.
//	glColor3f(1.0, 1.0, 0.0);
//	glRotatef(90.0, 0.0, 0.0, 1.0);//Set 90��,rotation about z axis
//	glRecti(50, 100, 200, 150);//dispaly red,rotated rectangle.
//							   //
//	glPopMatrix();//throw away the translation matrix
//	glColor3f(0.0, 1.0, 0.0);
//	glScalef(-0.5, 1.0, 1.0);//Set scale-reflection parameters
//	glRecti(50, 100, 200, 150);//Display red ,transform rectangle
//
//	glFlush();
//}
//
///* ������������ϵ����ʾ��Χ */
//
//void winReshapeFcn(GLint newWidth, GLint newHeight)
//
//{
//
//	glMatrixMode(GL_PROJECTION);
//
//	glLoadIdentity();
//
//	gluOrtho2D(xwcMin, xwcMax, ywcMin, ywcMax);
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//}
//void init() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glLoadIdentity();
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(-500.0, 500.0,-500.0, 500.0);//���½�x ���Ͻ�x ���½�y ���Ͻ�y
//	glClear(GL_COLOR_BUFFER_BIT);
//}
//
//void main(int argc, char ** argv)
//
//{
//
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	glutInitWindowPosition(50, 50);
//
//	glutInitWindowSize(winWidth, winHeight);
//
//	glutCreateWindow("��ά���α任ʵ��-���ϱ任");
//
//	init();
//
//	glutDisplayFunc(displayFcn0);
//
//	//glutReshapeFunc(winReshapeFcn);
//
//	glutMainLoop();
//
//}