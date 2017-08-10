//�����㷨
#include <Windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
//DDA�㷨ʵ��
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
//dda������������λ�ñ�ֱ��ʹ��ֱ�߷��̼�����ٶȸ���
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
//ͨ������xyƽ����ְ˷ֺ��ķ������ĶԳ��� Bresenham�㷨������б�ʵ��߶ξ���ͨ����
//����б��Ϊ���Ҵ���1.0���߶� ֻҪ����xy����Ĺ��� ����y�����Ե�λ�����ƶ���������ӽ�·��������x��ֵ
//��������ѡ�����нϸ߻�ϵ͵�����
//���ڻ��Ƹ�б�ʵ��߶� ����һ������ݼ�����һ������ ������������Ƶ�
//�ֱ�������������� ��ˮƽ�� ��ֱ�� �ͶԽ��� ���Ƕ�����ֱ��װ��֡�����������л����㷨����
