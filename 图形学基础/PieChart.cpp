////使用中点圆算法来构造一个饼图
////例子的值用于确定扇形的数量和大小
////一开始运行的时候发现自己的圆只画了一半 结果最后找出来是circlePlotPoints里后面的某一部分写错了
//#include <GL\glut.h>
//#include <cstdlib>
//#include <math.h>
//
//const GLdouble twoPi = 6.283185;
//class screenPt {
//public:
//	GLint x, y;
//public:
//	/*default constructor:initializes coordinate position to (0,0)*/
//	screenPt() {
//		x = 0, y = 0;
//	}
//	void setCoords(GLint xCoordValue, GLint yCoordValue) {
//		x = xCoordValue;
//		y = yCoordValue;
//	}
//	GLint getx()const {
//		return x;
//	}
//	GLint gety() const {
//		return y;
//	}
//	void incrementx() {
//		x++;
//	}
//	void decrementy() {
//		y--;
//	}
//};
//void setPixel(GLint xCoord, GLint yCoord) {
//	glBegin(GL_POINTS);
//	glVertex2i(xCoord, yCoord);
//	glEnd();
//}
//GLsizei winWidth = 400, winHeight = 300;//initial display window size.
//void init() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
//}
////半径坐标+圆心传递给circleMidpoint
// void circleMidpoint(GLint xc, GLint yc, GLint radius) {
//	screenPt circpt;
//	GLint p = 1 - radius; //initial value for midpoint parameter
//	circpt.setCoords(0, radius);//set coords（坐标） for top point of circle
//	void circlePlotPoints(GLint, GLint, screenPt);
//	/*Plot the initial point in each circle quadrant. */
//	circlePlotPoints(xc, yc, circpt);
//	/*calculate next point and plot in each octant. */
//	while (circpt.getx() < circpt.gety()) {
//		circpt.incrementx();
//		if (p < 0) {
//			p += 2 * circpt.getx() + 1;
//		}
//		else {
//			circpt.decrementy();
//			p += 2 * (circpt.getx() - circpt.gety()) + 1;
//		}
//		circlePlotPoints(xc, yc, circpt);
//	}
//}
//void circlePlotPoints(GLint xc, GLint yc, screenPt circpt) {
//	setPixel(xc + circpt.getx(), yc + circpt.gety());
//	setPixel(xc - circpt.getx(), yc + circpt.gety());
//
//	setPixel(xc + circpt.getx(), yc - circpt.gety());
//	setPixel(xc - circpt.getx(), yc - circpt.gety());
//
//	setPixel(xc + circpt.gety(), yc + circpt.getx());
//	setPixel(xc - circpt.gety(), yc + circpt.getx());
//
//	setPixel(xc + circpt.gety(), yc - circpt.getx());
//	setPixel(xc - circpt.gety(), yc - circpt.getx());
//}
//void pieChart() {
//	screenPt circCtr, piePt;
//	GLint radius = winWidth / 4;//circle radius.
//	//sliceangle 切片角度 以前的切片角度
//	GLdouble sliceAngle, previousSliceAngle = 0.0;
//	GLint k, nSlices = 12; //切片
//	GLfloat dataValues[12] = { 10.0,7.0,13.0,5.0,13.0,14.0,
//							3.0,16.0,5.0,3.0,17.0,8.0 };
//	GLfloat dataSum = 0.0;
//
//	circCtr.x = winWidth / 2;//circle center position
//	circCtr.y = winHeight / 2;
//	circleMidpoint(circCtr.x, circCtr.y, radius);
//
//	for (k = 0; k < nSlices; k++)
//		dataSum += dataValues[k];
//
//	for (k = 0; k < nSlices; k++) {
//		sliceAngle = twoPi*dataValues[k] / dataSum + previousSliceAngle;
//		piePt.x = circCtr.x + radius*cos(sliceAngle);
//		piePt.y = circCtr.y + radius*sin(sliceAngle);
//		glBegin(GL_LINES);
//		glVertex2i(circCtr.x, circCtr.y);
//		glVertex2i(piePt.x, piePt.y);
//		glEnd();
//		previousSliceAngle = sliceAngle;
//	}
//}
//void displayFcn() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 0.0, 1.0);//set circle color to blue 
//	pieChart();
//	glFlush();
//}
//
//void winReshapeFcn(GLint newWidth, GLint newHeight) {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();//
//	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	//reset display-window size parameters
//	winWidth = newWidth;
//	winHeight = newHeight;
//}
//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//
//	glutInitWindowSize(winWidth, winHeight);
//	glutCreateWindow("pie chart");
//
//	init();
//	glutDisplayFunc(displayFcn);
//	glutReshapeFunc(winReshapeFcn);
//	glutMainLoop();
//}