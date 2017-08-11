//#include <GL\glut.h>
//#include <cstdlib>
//#include <math.h>
//#include <iostream>
//
//using namespace std;
//struct screenPt
//{
//	GLint x;
//	GLint y;
//};
//typedef enum{limacon=1,cardioid,threeLeaf,fourLeaf,spiral} curveName;
//GLsizei winWidth = 600, winHeight = 500;//initial display window size.
//
//void init() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(0.0, 200, 0.0, 150);//左下角x 右上角x 左下角y 右上角y
//}
//void lineSegment(screenPt pt1, screenPt pt2) {
//	glBegin(GL_LINES);
//		glVertex2i(pt1.x, pt1.y);
//		glVertex2i(pt2.x, pt2.y);
//	glEnd();
//}
//
//void drawCurve(GLint curveNum) {
//	const GLdouble twoPi = 6.283185;
//	const GLint a = 175, b = 60;
//
//	GLfloat r, theta, dtheta = 1.0/float(a);
//	GLint x0 = 200, y0 = 250;
//
//	screenPt curvePt[2];
//	glColor3f(0.0, 0.0, 0.0);//set curve color to black
//
//	curvePt[0].x = x0;
//	curvePt[0].y = y0;
//
//	switch (curveNum)
//	{
//		//帕斯卡蜗线
//	case limacon:curvePt[0].x += a + b; break;
//	case cardioid:curvePt[0].x += a + a; break;
//	case threeLeaf:curvePt[0].x += a; break;
//	case fourLeaf:curvePt[0].x += a; break;
//	case spiral:break;
//	default:
//		break;
//	}
//	theta = dtheta;
//	while (theta < twoPi) {
//		switch (curveNum)
//		{
//		case limacon:
//			r = a*cos(theta) + b; break;
//		case cardioid:
//			r = a*(1 + cos(theta)); break;
//		case threeLeaf:
//			r = a*cos(3 * theta); break;
//		case fourLeaf:
//			r = a*cos(2 * theta); break;
//		case spiral:
//			r = (a / 4.0)*theta; break;
//		default:
//			break;
//		}
//		curvePt[1].x = x0 + r*cos(theta);
//		curvePt[1].y = y0 + r*sin(theta);
//		lineSegment(curvePt[0], curvePt[1]);
//
//		curvePt[0].x = curvePt[1].x;
//		curvePt[0].y = curvePt[1].y;
//		theta += dtheta;
//	}
//}
//void displayFcn() {
//	GLint curveNum;
//	glClear(GL_COLOR_BUFFER_BIT);
//	cin >> curveNum;
//	if (curveNum == 1 || curveNum == 2 || curveNum == 3 || curveNum == 4 || curveNum == 5)
//		drawCurve(curveNum);
//	else
//		exit(0);
//	glFlush();
//		
//}
//void winReshapeFcn(GLint newWidth, GLint newHeight) {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();//
//	//指定二维世界坐标系统 //左下角x 右上角x 左下角y 右上角y
//	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//}
//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(500, 500);
//
//	glutInitWindowSize(winWidth, winHeight);
//	glutCreateWindow("Draw Curves");
//
//	init();
//	glutDisplayFunc(displayFcn);
//	glutReshapeFunc(winReshapeFcn);
//	glutMainLoop();
//}