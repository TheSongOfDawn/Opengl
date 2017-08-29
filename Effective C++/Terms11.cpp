//在operator=中处理 "自我赋值"
#include <iostream>
using namespace std;
class Widget0{};
Widget0 w;
w = w;//自我赋值发生在对象被赋值给自己时

//不明显的情况
a[i] = a[j];//潜在的自我赋值 i,j相同的情况
*px = *py;//px,py指向同一个东西

//用来保存一个指针指向一块动态分配的位图(bitmap):
class Bitmap {};
class Widget {
public:
	Widget& operator=(const Widget& rhs);
private:
	Bitmap* pb;//指针 指向一个从heap分配而得到的对象
};
Widget& Widget::operator=(const Widget& rhs) {//一份不安全的operator=实现版本
	delete pb;//停止使用当前的bitmap
	pb = new Bitmap(*rhs.pb);//使用rhs's bitmap的副本
	return *this;
}
/*自我赋值问题时，operator=函数内的*this赋值的目的端和rhs有可能
 是同一个对象。此时，delete就不知是销毁当前对象的bitmap，它也销毁rhs的bitmap.在函数末尾，widget
 会发现自己持有一个指针指向一个已被删除的对象！
*/
//传统方法：在最前面做一个证同测试 来达到检测的目的
//不具备异常安全性。如果new Bitmap导致异常。widget最终会持有一个指针
//指向一块被删除的Bitmap。
Widget& Widget::operator=(const Widget& rhs) {//一份不安全的operator=实现版本
	if (this == &rhs) return *this;		//证同测试
										//如果是自我赋值，就不做任何事情
	delete pb;//停止使用当前的bitmap
	pb = new Bitmap(*rhs.pb);//使用rhs's bitmap的副本
	return *this;
}
//另一种方法：能够处理自我赋值因为我们对原来的bitmap做了一份复件，删除原
//bitmap,然后指向新制造的那个复件 不最高效 但行的通
Widget& Widget::operator=(const Widget& rhs) {//一份不安全的operator=实现版本
	Bitmap* pOrig = pb;//记住原先的pb
	pb = new Bitmap(*rhs.pb);//使用*pb的一个副本
	delete pOrig;
	return *this;
}

//operator= 函数内手工排列语句(确保代码不但异常安全而且自我赋值安全)
//的一个替代方案是，使用所谓的copy and swap技术 常见且够好
//template <class T> void swap(T& a, T& b)
//{
//	T c(a); a = b; b = c;
//}
class Widget1 {

	void swap(Widget1&rhs) {//交换*this和rhs的值
		Widget1 c(rhs);
		*this = rhs;
		rhs = c;
	}
	Widget1& operator=(Widget1 rhs);
	Widget1& operator=(const Widget1& rhs) {
		Widget1 temp(rhs);//为rhs数据制作一份复件
		swap(temp);		//将*this数据和上述复件的数据交换
		return *this;
	}
};
/*这个主题的另一个变奏曲乃利用一下事实:
1.某class的copy assignment操作符可能被声明为 "以by value方式接受实参"
2.以by value方式传递东西会造成意见复件/副本
*/
Widget1& Widget1::operator=( Widget1 rhs) {//rhs是被传对象的一份复件
	swap(rhs);		//注意这里是pass by value 数据交换
	return *this;//代码更高效
}
/*请记住：
确保当对象自我赋值时 operator=有良好行为。其中技术包括比较 "来源对象"
和目标对象"的地址，精心周到的语句顺序，以及copy-and-swap

确定任何函数如果操作一个以上的对象，而其中多个对象是同一个对象时，其运行为仍然正确。

*/	












