/* 模式名称：单例模式
 * 模式分类：创建型模式
 * 简单概述：保证一个类仅有一个实例，并提供一个访问它的全局访问点
 * 使用场景：
 */
#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton* GetInstance();

private:
	Singleton();
	//把复制构造函数和拷贝构造函数也设置为私有，防止被复制
	Singleton(const Singleton &);
	Singleton& operator=(const Singleton &);

	static Singleton* pInstance;
};

Singleton* Singleton::GetInstance()
{
	if(!pInstance)
	{
		pInstance = new Singleton();
	}

	return pInstance;
}

Singleton::Singleton()
{

}

Singleton::Singleton(const Singleton&)
{

}

Singleton& Singleton::operator=(const Singleton&)
{

}

