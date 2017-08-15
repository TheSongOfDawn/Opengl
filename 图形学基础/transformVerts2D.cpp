//第五章 几何变换
//实例 开始时复合矩阵compMatrix是一个单位矩阵。在本例，使用从左往右合并的次序来构造复合变换矩阵
//且按其执行顺序调用变换子程序 在每变换函数被调用时 为该变换建立矩阵并从左边和
//复合矩阵相结合 在指定完所有变换后 使用复合矩阵对三角形进行变换 该三角形先对其中心
//位置进行缩放 然后绕其中心旋转 最后进行平移

#include <GL\glut.h>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;
//Set initial display-window size.
GLsizei winWidth = 600, weiHeight = 600;

/*set range for world coordinates.*/
GLfloat xwcMin = 0.0, xwcMax = 225.0;
GLfloat ywcMin = 0.0, ywcMax = 225.0;

class pt
{
	//定义一个二维平面的点 有(x，y)
public:
	GLfloat x, y;
};
typedef GLfloat Matrix3x3[3][3];

Matrix3x3 matComposite;
const GLdouble pi = 3.14159;
void init() {
	/*Set color of display window to white*/
	glClearColor(1.0, 1.0, 1.0, 0.0);
}
/*Construct the 3 by 3 identity matrix 构造3x3单位矩阵*/
void matrix3x3SetIdentity(Matrix3x3 matIdent3x3) {
	GLint row, col;
	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			matIdent3x3[row][col] = (row == col);
}
/*premultiply matrix m1 times matrix m2,store result in m2
	自左乘矩阵m1*m2 将结果放在m2中
*/
void matrix3x3PreMultiply(Matrix3x3 m1, Matrix3x3 m2) {
	GLint row, col;
	Matrix3x3 temp;//temp
	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++) {
			temp[row][col] = m1[row][0] * m2[0][col] + m1[row][1] *
				m2[1][col] + m1[row][2] * m2[2][col];
		}
	for (row = 0; row < 3; row++) {
		for (col = 0; col < 3; col++) {
			m2[row][col] = temp[row][col];
		}
	}
}
//2d 平移
void translate2D(GLfloat tx, GLfloat ty) {
	Matrix3x3 matTrans1;
	/*Initialize translation matrix to identity.*/
	matrix3x3SetIdentity(matTrans1);
	matTrans1[0][2] = tx;
	matTrans1[1][2] = ty;
	/*Concatenate matTrans1 with the composite matrix*/
	matrix3x3PreMultiply(matTrans1, matComposite);
}
//2d 旋转
void rotate2D(pt pivotPt, GLfloat  theta) {
	Matrix3x3 matRot;

	/*Initialize rotation matrix to identity. */
	matrix3x3SetIdentity(matRot);

	matRot[0][0] = cos(theta);
	matRot[0][1] = -sin(theta);
	//曾错写为 '=0'
	matRot[0][2] = pivotPt.x*(1-cos(theta))+pivotPt.y*sin(theta);

	matRot[1][0] = sin(theta);
	matRot[1][1] = cos(theta);
	matRot[1][2] = pivotPt.y*(1 - cos(theta)) - pivotPt.x*sin(theta);

	/*Concatenate matRot with the composite matrix*/
	matrix3x3PreMultiply(matRot, matComposite);

}

//2d 缩放
void scale2D(GLfloat sx, GLfloat sy, pt fixedPt) {
	Matrix3x3 matScale;
	/* Initialize scaling matrix to identity*/
	matrix3x3SetIdentity(matScale);

	matScale[0][0] = sx;
	matScale[0][2] = (1 - sx)*fixedPt.x;
	matScale[1][1] = sy;
	matScale[1][2] = (1 - sy)*fixedPt.y;

	/*Concatenate matScale with the composite matrix*/
	matrix3x3PreMultiply(matScale, matComposite);
}

void transformVerts2D(GLint nVerts, pt* verts) {
	GLint k;
	GLfloat temp;

	for (k = 0; k < nVerts; k++)
	{
		temp = matComposite[0][0] * verts[k].x + matComposite[0][1] * verts[k].y +
			matComposite[0][2];
		verts[k].y = matComposite[1][0] * verts[k].x + matComposite[1][1] * verts[k].y + matComposite[1][2];
		verts[k].x = temp;
	}
}
void triangle(pt *verts) {
	GLint k;
	glBegin(GL_TRIANGLES);
	for (k = 0; k < 3; k++)
		glVertex2f(verts[k].x, verts[k].y);
	glEnd();
}

void disPlayFcn() {
	/*define initial position for triangle*/
	GLint nVerts = 3;
	pt verts[3] = { {50.0,25.0},{150.0,25.0},{100.0,100.0} };
	/*Calculate position of triangle centroid. */
	pt centroidPt;

	GLint k, xSum = 0, ySum = 0;
	for (k = 0; k < nVerts; k++) {
		xSum += verts[k].x;
		ySum += verts[k].y;
	}
	centroidPt.x = GLfloat(xSum) / GLfloat(nVerts);
	centroidPt.y = GLfloat(ySum) / (GLfloat)(nVerts);

	/*Set geometric transformation parameters.*/
	pt pivPt, fixedPt;

	pivPt = centroidPt;
	fixedPt = centroidPt;

	GLfloat tx = 0.0, ty = 100.0;
	GLfloat sx = 0.5, sy = 0.5;
	GLdouble theta = pi / 2.0;

	glClear(GL_COLOR_BUFFER_BIT);//clear display window

	glColor3f(0.0, 0.0, 1.0);//set initial fill color to blue
	triangle(verts);//display blue triangle.

	/*initialize composite matrix to identity*/
	matrix3x3SetIdentity(matComposite);

	///*Construct composite matri for transformation sequence. */
	//scale2D(sx, sy, fixedPt);//缩放
	//rotate2D(pivPt,theta);//旋转
	//translate2D(tx, ty);//平移


	/*Construct composite matri for transformation sequence. */
	translate2D(tx, ty);//平移
	scale2D(sx, sy, fixedPt);//缩放
	rotate2D(pivPt, theta);//旋转



	transformVerts2D(nVerts, verts);

	glColor3f(1.0, 0.0, 0.0);
	triangle(verts);

	glFlush();

}
void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//
	//指定二维世界坐标系统 //左下角x 右上角x 左下角y 右上角y
	gluOrtho2D(xwcMin, xwcMax, ywcMin, ywcMax);

	glClear(GL_COLOR_BUFFER_BIT);

}
void main(int argc, char ** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(winWidth, weiHeight);
	glutCreateWindow("二维复合矩阵编程实例");

	init();
	glutDisplayFunc(disPlayFcn);
	glutReshapeFunc(winReshapeFcn);

	glutMainLoop();
}