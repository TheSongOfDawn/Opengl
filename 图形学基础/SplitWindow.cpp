////6.4.16 Opengl�Ķ�ά�۲����ʾ��
////�Ƚ��ӿڶ�������ʾ���ڵ������ ����ɫ��ʾԭʼ������ Ȼ���ӿڶ�������ʾ����
////���Ұ��� ����ͬ�Ĳü����ڽ���������ʾ�ɺ�ɫ������������������������ת
//#include <GL/glut.h>
//
//class pt2d {
//public:
//	GLfloat x, y;
//};
//
//void init() {
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
//
//	glMatrixMode(GL_MODELVIEW);
//
//}
//void triangle(pt2d *verts) {
//	GLint k;
//	glBegin(GL_TRIANGLES);
//	for (k = 0; k < 3; k++)
//		glVertex2f(verts[k].x, verts[k].y);
//	glEnd();
//}
//
//void displayFcn() {
//	pt2d verts[3] = { {-50.0,-25.0},{50.0,-25.0},{0.0,50.0} };
//
//	glClear(GL_COLOR_BUFFER_BIT);//Clear display window.
//
//	glColor3f(0.0, 0.0, 1.0);//set fill color to blue
//	glViewport(0, 0, 300, 300);//���Ӵ�
//	triangle(verts);//display triangle.
//	/*Rotate triangle and display in right half of display window. */
//
//	glColor3f(1.0, 0.0, 0.0);//set fill color to red
//	glViewport(300, 0, 300, 300);//set right viewport
//	glRotatef(90.0, 0.0, 0.0, 1.0);//Rotate about z axis.
//	triangle(verts);
//	glFlush();
//}
//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//��Ҫ���˼���ģʽ
//	glutInitWindowPosition(50, 50);
//	glutInitWindowSize(600, 300);
//	glutCreateWindow("Split-Screen Example");
//
//	init();
//	glutDisplayFunc(displayFcn);
//	glutMainLoop();
//}