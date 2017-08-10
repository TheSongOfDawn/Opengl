//中点画圆算法
//中点画椭圆算法
#include <GL\glut.h>
int round(const float a) { return int(a + 0.5); }

class screenPt {
private:
	GLint x, y;
public:
	/*default constructor:initializes coordinate position to (0,0)*/
	screenPt() {
		x = 0, y = 0;
	}
	void setCoords(GLint xCoordValue, GLint yCoordValue) {
		x = xCoordValue;
		y = yCoordValue;
	}
	GLint getx()const {
		return x;
	}
	GLint gety() const {
		return y;
	}
	void incrementx() {
		x++;
	}
	void decrementy() {
		y--;
	}
};
void setPixel(GLint xCoord, GLint yCoord) {
	glBegin(GL_POINTS);
	glVertex2i(xCoord, yCoord);
	glEnd();
}
 static void circleMidpoint(GLint xc, GLint yc, GLint radius) {
	screenPt circpt;
	GLint p = 1 - radius; //initial value for midpoint parameter
	circpt.setCoords(0, radius);//set coords for top point of circle
	void circlePlotPoints(GLint, GLint, screenPt);
	/*Plot the initial point in each circle quadrant. */
	circlePlotPoints(xc, yc, circpt);
	/*calculate next point and plot in each octant. */
	while (circpt.getx() < circpt.gety()) {
		circpt.incrementx();
		if (p < 0) {
			p += 2 * circpt.getx() + 1;
		}
		else {
			circpt.decrementy();
			p += 2 * (circpt.getx() - circpt.gety()) + 1;
		}
		circlePlotPoints(xc, yc, circpt);
	}
}
void circlePlotPoints(GLint xc, GLint yc, screenPt circpt) {
	setPixel(xc + circpt.getx(), yc + circpt.gety());
	setPixel(xc - circpt.getx(), yc + circpt.gety());

	setPixel(xc + circpt.getx(), yc - circpt.gety());
	setPixel(xc - circpt.getx(), yc - circpt.gety());

	setPixel(xc + circpt.getx(), yc + circpt.gety());
	setPixel(xc - circpt.getx(), yc + circpt.gety());

	setPixel(xc + circpt.getx(), yc - circpt.gety());
	setPixel(xc - circpt.getx(), yc - circpt.gety());
}
void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry) {
	int Rx2 = Rx*Rx;
	int Ry2 = Ry*Ry;
	int twoRx2 = 2 * Rx2;
	int twoRy2 = 2 * Ry2;

	int p;
	int x = 0;
	int y = Ry;
	int px = 0;
	int py = twoRx2*y;
	void ellipsePlotPoints(int, int, int, int);

	ellipsePlotPoints(xCenter, yCenter, x, y);
	p = round(Ry2 - (Rx2*Ry) + (0.25*Rx2));
	while (px < py) {
		x++;
		px += twoRy2;
		if (p < 0)
			p += Ry2 + px;
		else{
			y--;
			py -= twoRx2;
			p += Ry2 + px - py;
		}
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}
	/*region 2*/
	p = round(Ry2*(x + 0.5)*(x + 0.5) + Rx2*(y - 1)*(y - 1) - Rx2*Ry2);
	while (y > 0) {
		y--;
		py -= twoRx2;
		if (p > 0) {
			p += Rx2 - py;
		}
		else {
			x++; 
			px += twoRy2;
			p += Rx2 - py + px;
		}
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}
}
void ellipsePlotPoints(int xCenter, int yCenter, int x, int y) {
	setPixel(xCenter + x, yCenter + y);

	setPixel(xCenter - x, yCenter + y);

	setPixel(xCenter + x, yCenter - y);

	setPixel(xCenter - x, yCenter - y);
};