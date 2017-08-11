////直方图程序
///*直方图 一组多点标记和位图字符图标号来生成一年内按月的折线图
//*/
//#include <GL/glut.h>
//GLsizei winWidth = 600, winHeight = 500;//initial display window size
//GLint xRaster = 25, yRaster = 150;//initialize raster position raster=光栅
//								  //无符号单字节整型，包含数值从0 到 255。
//GLubyte label[36] = { 'J','a', 'n',  'F', 'e', 'b',  'M', 'a', 'r',
//'A','p', 'r',  'M', 'a', 'y',  'J', 'u', 'n',
//'J','u', 'l',  'A', 'u', 'g',  'S', 'e', 'p',
//'O','c', 't',  'N', 'o', 'v',  'D', 'e', 'c' };
//GLint dataValue[12] = { 420,342,324,310,262,185,
//190,196,217,240,312,438 };
//void init() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);//white display window
//	glMatrixMode(GL_PROJECTION);//I WANT DO WHAT
//								//GL_PROJECTION 投影
//								//GL_MODELVIEW 模型视图	
//								//GL_TEXTURE 纹理
//	gluOrtho2D(0.0, 600.0, 0.0, 500.0);//指定二维世界坐标系统
//}
//void barChart() {
//	GLint month, k;
//	
//
//	//clear display window
//	glClear(GL_COLOR_BUFFER_BIT);//glClear（）函数的作用是用当前缓冲区清除值，也就是glClearColor或者glClearDepth、glClearIndex、glClearStencil、glClearAccum等函数所指定的值来清除指定的缓冲区，
//								 //也可以使用glDrawBuffer一次清除多个颜色缓存。
//	glColor3f(1.0, 0.0, 0.0);//set line color to red
//	for (k = 0; k < 12; k++) {
//		//显示xy平面上的一个填充区
//		glRecti(20 + k * 50, 165, 40 + k * 50, dataValue[k]);
//	}
//	glColor3f(0.0, 0.0, 0.0);//Set text color to black
//	xRaster = 20;			//display chart labels
//	for (month = 0; month < 12; month++) {
//		//为帧缓存指定一个二维或三维的当前位置
//		glRasterPos2i(xRaster, yRaster);
//		for (k = 3 * month; k < 3 * month + 3; k++) {
//			//选择一种字体和一个位图字符进行显示
//			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
//
//		}
//		xRaster += 50;
//	}
//	//强制刷新缓冲，保证绘图命令将被执行，而不是存储在缓冲区[2]  中等待其他的OpenGL命令。
//	glFlush();
//}
//
//void winReshapeFcn(GLint newWidth, GLint newHeight) {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();//无参的无值函数，其功能是用一个4×4的单位矩阵来替换当前矩阵，实际上就是对当前矩阵进行初始化。将当前点移到了屏幕中心
//	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
//
//	glClear(GL_COLOR_BUFFER_BIT);
//}
//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(winWidth, winHeight);
//	glutCreateWindow("Line Chart Data Plot");
//
//	init();
//	glutDisplayFunc(barChart);
//	glutReshapeFunc(winReshapeFcn);
//	glutMainLoop();
//}