//������ ���α仯 
#include<GL/glut.h>
#include <cmath>
typedef struct { GLfloat x, y; } pt;

//5.1.2 ƽ��
//�����ƽ��
void translatePolygon(pt* verts, GLint nVerts, GLfloat tx, GLfloat ty) {
	//tx ty ��λ������
	//�����λ�ƺ�ı����ٽ�����Ƴ���
	//���Ҫɾ��ԭ���Ķ���� �������ƽ��ǰ�ñ���ɫ��ʾ��
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

//5.1.2  ��ά��ת
//һ���������ָ������������ϵ�еĻ�׼����ת
void rotatePolygon(pt* verts, GLint nVerts, pt pivPt, GLdouble theta) {
	//������� ԭʼ�Ķ���ζ��� ��׼��������û��ȱ�ʶ����ת��
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

//5.1.3 ����
//һ����������Ž��м�������ӡ� ����ζ���͹̶���������Լ�����ϵ�����������
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