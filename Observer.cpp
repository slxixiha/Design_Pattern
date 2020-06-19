/* 模式名称：观察者模式
 * 模式分类：行为型模式
 * 简单概述：定义了一种一对多的关系，让多个观察者对象同时监听一个主题对象。这个主题
 * 			 对象发生变化时，会通知所有观察者对象，使它们能够自动更新自己
 * 使用场景：当一个对象的改变同时改变其它对象，而且它不知道具体有多少对象有待改变
 * 模式优点：解除耦合，让耦合的双方都依赖于抽象，而不是依赖于具体，从而使得各自的
 * 			 	变化都不会影响另一边的变化
 * 例子讲解：当电脑关闭的时候会关闭电脑上正在运行的软件，软件就是一个观察者，
 * 			 而电源开关或者桌面上的关机菜单都是通知者
 */
#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::list;

//观察者基类
class Software
{
public:
	virtual void Close() = 0;
};

//具体观察者类
class QQ : public Software
{
public:
	void Close()
	{
		cout << "QQ, save all data and close" << endl;
	}
};

class Weixin : public Software
{
public:
	void Close()
	{
		cout << "Weixin, save all data and close" << endl;
	}
};

//通知者类
class System
{
public:
	virtual void StartClose() = 0;
	void Attach(Software * software) {m_softwares.push_back(software);}
	void Detach(Software * software) {m_softwares.remove(software);}
	void Notify()
	{
		list<Software *>::iterator iter = m_softwares.begin();
		for(;iter != m_softwares.end(); iter++)
		{
			(*iter)->Close();
		}
	}
private:
	list<Software* > m_softwares;
};

class Linux : public System
{
public:
	void StartClose()
	{
		cout << "Linux System will close" << endl;
		Notify();
	}
};

int main(int argc, char const *argv[])
{
	Linux myLinux = Linux();

	QQ *myQQ = new QQ();
	myLinux.Attach(myQQ);

	Weixin *myWeixin = new Weixin();
	myLinux.Attach(myWeixin);

	myLinux.StartClose();

	delete myQQ;
	delete myWeixin;

	return 0;
}
