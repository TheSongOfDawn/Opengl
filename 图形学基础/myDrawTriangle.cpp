//第一个程序
//第2章 图形系统概述
#include <Windows.h>//必须在所有的头文件前面
#include <GL/glut.h>
#include <iostream>
void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);//将显示窗口的背景色设置为白色 参数为rgb Alpha
	//这表示使用正投影将世界坐标系二维矩形区域的内容映射到屏幕上
	//区域的坐标值从0.0到200.0 y[0.0,150.0] 只要是在该矩形定义的对象 都会出现在显示窗口中
	//任何在坐标范围外的内容都不会显示出来 
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment() {
	glClear(GL_COLOR_BUFFER_BIT);//使赋值的窗口得到显示 该符号常量用来指定它是颜色缓存
	
	glColor3f(1.0, 0.0, 0.0);//将颜色设置为红色 rgb 值的范围[0.0,1.0]
	//定义了一个从整数笛卡尔端点坐标 180，15 到10，145的二维直线段
	//笛卡尔坐标是以左下角为0.0原点
	//以下画了一个直角三角形
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
	glutInit(&argc, argv);//glut初始化
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//显示窗口的缓存和颜色模型等选项
	glutInitWindowPosition(50, 100);//显示窗口的初始位置 以左上角为原点来表示
	glutInitWindowSize(400, 300);//设置显示窗口的初始宽度和高度
	//qq截图大小416*338 包括了菜单栏
	glutCreateWindow("An Example OpenGL Program");//窗口创建时给一个标题
	
	init();
	glutDisplayFunc(lineSegment);//将线段描述送到显示窗口
	glutMainLoop();//该函数必须是程序的最后一个
}