//划线算法
#include <Windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
//DDA算法实现
//inline int round(const float a) { return int(a + 0.5); }

void lineDDA(int x0, int y0, int xEnd, int yEnd) {
	
	int dx = xEnd - x0, dy = yEnd - y0, steps, k;
	float xIncrement, yIncrement, x = x0, y = y0;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xIncrement = float(dx) / float(steps);
	yIncrement = float(dy) / float(steps);
	
	

	SetPixel(hdc, round(x), round(y), RGB(1.0, 0.0, 0.0));

	//setPixel(round(x), round(y));
	for (k = 0; k < steps; k++) {
		x += xIncrement;
		y += yIncrement;
		SetPixel(hdc, round(x), round(y), RGB(1.0, 0.0, 0.0));
	}
}
//dda方法计算像素位置比直接使用直线方程计算的速度更快
void linebres(int x0, int y0, int xEnd, int yEnd)
{
	int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
	int x, y;
	if (x0 > xEnd) {
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	}
	else {
		x = x0;
		y = y0;
	}
	setPixel(x, y);
	while (x < xEnd) {
		x++;
		if (p < 0)
			p += twoDy;
		else
		{
			y++;
			p += twoDyMinusDx;
		}
		setPixel(x, y);
	}
}
//通过考虑xy平面各种八分和四分区域间的对称性 Bresenham算法对任意斜率的线段具有通用性
//对于斜率为正且大于1.0的线段 只要交换xy方向的规则 即沿y方向以单位步长移动并计算最接近路径的连续x的值
//我们总是选择其中较高或较低的像素
//对于绘制负斜率的线段 除非一个坐标递减而另一个递增 否则程序是类似的
//分别处理下列特殊情况 ：水平线 垂直线 和对角线 它们都可以直接装入帧缓存而无需进行划线算法处理
