//��һ������
//��2�� ͼ��ϵͳ����
#include <Windows.h>//���������е�ͷ�ļ�ǰ��
#include <GL/glut.h>
#include <iostream>
void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);//����ʾ���ڵı���ɫ����Ϊ��ɫ ����Ϊrgb Alpha
	//���ʾʹ����ͶӰ����������ϵ��ά�������������ӳ�䵽��Ļ��
	//���������ֵ��0.0��200.0 y[0.0,150.0] ֻҪ���ڸþ��ζ���Ķ��� �����������ʾ������
	//�κ������귶Χ������ݶ�������ʾ���� 
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment() {
	glClear(GL_COLOR_BUFFER_BIT);//ʹ��ֵ�Ĵ��ڵõ���ʾ �÷��ų�������ָ��������ɫ����
	
	glColor3f(1.0, 0.0, 0.0);//����ɫ����Ϊ��ɫ rgb ֵ�ķ�Χ[0.0,1.0]
	//������һ���������ѿ����˵����� 180��15 ��10��145�Ķ�άֱ�߶�
	//�ѿ��������������½�Ϊ0.0ԭ��
	//���»���һ��ֱ��������
	glBegin(GL_LINES);
	glVertex2i(180, 15);
	glVertex2i(10, 145);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glVertex2i(10, 145);
	glVertex2i(10, 15);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glVertex2i(10, 15);
	glVertex2i(180, 15);
	glEnd();
	glFlush();
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);//glut��ʼ��
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//��ʾ���ڵĻ������ɫģ�͵�ѡ��
	glutInitWindowPosition(50, 100);//��ʾ���ڵĳ�ʼλ�� �����Ͻ�Ϊԭ������ʾ
	glutInitWindowSize(400, 300);//������ʾ���ڵĳ�ʼ��Ⱥ͸߶�
	//qq��ͼ��С416*338 �����˲˵���
	glutCreateWindow("An Example OpenGL Program");//���ڴ���ʱ��һ������
	
	init();
	glutDisplayFunc(lineSegment);//���߶������͵���ʾ����
	glutMainLoop();//�ú��������ǳ�������һ��
}