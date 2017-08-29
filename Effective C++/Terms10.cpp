//令operator= 返回一个reference to *this

#include <iostream>
using namespace std;
//关于赋值 连锁赋值形式
int x, y, z;
x = y = z = 15;//被解析为x=(y=(z=15));这里15先被赋值给z
				//然后其结果更新后的z再被赋值给y，然后其结果(更新后的y)
				//再被赋值给x
//为了实现连锁赋 赋值操作符必须返回一个reference指向操作符的左侧实参
class Widget {
public:
	Widget& operator=(const Widget& rhs) {//返回类型是个reference
											//指向当前对象
		return*this;//返回左侧对象
	//这个协议不仅适用于以上的标准赋值形式，也适用于所有赋值相关运算
	}
	Widget& operator=(int rhs) {
		return *this;
	}
};
/*请记住
令赋值(assignment)操作符返回一个reference to *this
*/