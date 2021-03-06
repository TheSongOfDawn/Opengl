//5.13 三维复合变换
//程序示例
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

Matrix4x4 matComposite;
class pt3D {
public:
	GLfloat x, y, z;
};

typedef GLfloat Matrix4x4[4][4];

//构造一个4x4的单位矩阵
void matrix4x4SetIdentity(Matrix4x4 matIdent4x4) {
	GLint row, col;
	for (row = 0; row < 4; row++)
		for (col = 0; col < 4; col++)
			matIdent4x4[row][col] = (row == col);
}
void translate3D(GLfloat tx, GLfloat ty, GLfloat tz) {
	Matrix4x4 matTransl3D;

	/*initialize translation matrix to identity*/
	matrix4x4SetIdentity(matTransl3D);

	matTransl3D[0][3] = tx;
	matTransl3D[1][3] = ty;
	matTransl3D[2][3] = tz;
}

/*Premultiply matrix m1 times matrix m2,store result in m2.*/

void matrix4x4PreMultiply(Matrix4x4 m1, Matrix4x4 m2) {
	GLint  row, col;
	Matrix4x4 matTemp;

	for (row = 0; row < 4; row++)
		for (col = 0; col < 4; col++)
			matTemp[row][col] = m1[row][0] * m2[0][col] + m1[row][1] *
			m2[1][col] + m1[row][2] * m2[2][col] +
			m1[row][3] * m2[3][col];

	for (row = 0; row < 4; row++)
		for (col = 0; col < 4; col++)
			m2[row][col] = matTemp[row][col];
}
void translate3D(GLfloat tx, GLfloat ty, GLfloat tz) {
	Matrix4x4 matTransl3D;
	/*Initialize translation matrix to identity*/
	matrix4x4SetIdentity(matTransl3D);

	matTransl3D[0][3] = tx;
	matTransl3D[1][3] = ty;
	matTransl3D[2][3] = tz;
	/*Concatenate translation matrix with matRot*/
	matrix4x4PreMultiply(matTransl3D, matComposite);
}



void rotate3D(pt3D p1, pt3D p2, GLfloat radianAngle) {
	//四元组
	Matrix4x4 matQuaternionRot;
	GLfloat axisVectLength = sqrt((p2.x - p1.x)*(p2.x - p1.x) +
		(p2.y - p1.y)*(p2.y - p1.y) +
		(p2.z - p1.z)*(p2.z - p1.z));
	GLfloat cosA = cos(radianAngle);
	GLfloat oneC = 1 - cosA;
	GLfloat sinA = sin(radianAngle);
	GLfloat ux = (p2.x - p1.x) / axisVectLength;
	GLfloat uy = (p2.y - p1.y) / axisVectLength;
	GLfloat uz = (p2.z - p1.z) / axisVectLength;

	/*Set up transltation matrix for moving p1 to origin*/

	translate3D(-p1.x, -p1.y, -p1.z);

	/*Initialize matQuaternionRot to identity matrix.*/

	matrix4x4SetIdentity(matQuaternionRot);

	matQuaternionRot[0][0] = ux*ux*oneC + cosA;
	matQuaternionRot[0][1] = ux*uy*oneC - uz*sinA;
	matQuaternionRot[0][2] = ux*uz*oneC + uy*sinA;
	matQuaternionRot[1][0] = uy*ux*oneC + uz*sinA;
	matQuaternionRot[1][1] = uy*uy*oneC + cosA;
	matQuaternionRot[1][2] = uy*uz*oneC - ux*sinA;
	matQuaternionRot[2][0] = uz*ux*oneC - uy*sinA;
	matQuaternionRot[2][1] = uz*uy*oneC + ux*sinA;
	matQuaternionRot[2][2] = uz*uz*oneC + cosA;

	/*Combine matQuatenionRot with translation matrix.*/

	matrix4x4PreMultiply(matQuaternionRot, matComposite);

	/*Set up inverse matTransl3d and concatenate with
	product of previous two matrices.
	*/
	translate3D(p1.x, p1.y, p1.z);
}

void scale3D(GLfloat sx, GLfloat sy, GLfloat sz, pt3D fixedPt) {
	Matrix4x4 matScale3D;
	/*Initialize scaling matrix to identity*/
	matrix4x4SetIdentity(matScale3D);

	matScale3D[0][0] = sx;
	matScale3D[0][3] = (1 - sx)*fixedPt.x;
	matScale3D[1][1] = sy;
	matScale3D[1][3] = (1 - sy)*fixedPt.y;
	matScale3D[2][2] = sz;
	matScale3D[2][3] = (1 - sz)*fixedPt.z;
}

void displayFcn(void) {
	/*Input object description. */
	/*input translation,rotation,and scaling parameters*/
	
	/*set up 3d Viewing-transformation routines.*/
	/* Initialize matComposite to identity matrix:*/

	matrix4x4SetIdentity(matComposite);
	/*Pass rotation parameters to procedure rotate3D*/
	rotate3D(p1, p2, radianAngle);
	scale3D(sx, sy, sz, fixedPt);
	glTranslated(tx, ty, tz);
	/*call routinues for displaying transformed objects.*/
	
}
















