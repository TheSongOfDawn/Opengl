//第五章 几何变化 
#include<GL/glut.h>
#include <cmath>
typedef struct { GLfloat x, y; } pt;

//5.1.2 平移
//多边形平移
void translatePolygon(pt* verts, GLint nVerts, GLfloat tx, GLfloat ty) {
	//tx ty 是位移向量
	//先算出位移后的变量再将其绘制出来
	//如果要删除原来的多边形 则可以在平以前用背景色显示它
	GLint k;
	for (k = 0; k < nVerts; k++) {
		verts[k].x = verts[k].x + tx;
		verts[k].y = verts[k].y+ ty;
	}
	glBegin(GL_POLYGON);
	for (k = 0; k < nVerts; k++) {
		glVertex2f(verts[k].x, verts[k].y);
	}
	glEnd();
}

//5.1.2  二维旋转
//一个多边形绕指定的世界坐标系中的基准点旋转
void rotatePolygon(pt* verts, GLint nVerts, pt pivPt, GLdouble theta) {
	//输入参数 原始的多边形顶点 基准点坐标和用弧度标识的旋转角
	pt* vertsRot;
	GLint k;

	for (k = 0; k < nVerts; k++) {
		vertsRot[k].x = pivPt.x + (verts[k].x - pivPt.x)*cos(theta) - (verts[k].y - pivPt.y)*sin(theta);
		vertsRot[k].y = pivPt.y + (verts[k].x - pivPt.x)*sin(theta) + (verts[k].y - pivPt.y)*cos(theta);
	}
	glBegin(GL_POLYGON);
	for (k = 0; k < nVerts; k++)
		glVertex2f(vertsRot[k].x, vertsRot[k].y);
	glEnd();
}

//5.1.3 缩放
//一个多边形缩放进行计算的例子。 多边形顶点和固定点的坐标以及缩放系数是输入参数
void scalePolygon(pt* verts, GLint nVerts, pt fixedPt, GLfloat sx, GLfloat sy) {
	pt* vertsNew;
	GLint k;
	for (k = 0; k < nVerts; k++) {
		vertsNew[k].x = verts[k].x*sx + fixedPt.x*(1 - sx);
		vertsNew[k].y = verts[k].y*sy + fixedPt.y*(1 - sy);
	}
	glBegin(GL_POLYGON);
	for (k = 0; k < nVerts; k++) {
		glVertex2f(vertsNew[k].x, vertsNew[k].y);
		}
	glEnd();
}