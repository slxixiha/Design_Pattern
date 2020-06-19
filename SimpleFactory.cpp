/* 模式名称：简单工厂模式
 * 模式分类：创建型模式
 * 简单概述：这个模式使用一个类来充当工厂，由这个类来决定实例化哪一种类。
 * 模式优点：这个模式把类的具体实现过程封装起来了，方便修改（可维护，可复用）。
 * 			 如果要增加一个新的类时，只需要在工厂类中增加对应的实例化分支就好了（可扩展），
 * 			 不需要去修改客户端的代码。
 * 模式缺点：缺点也是增加新的类时修改工厂类，违反了开放封闭原则。如果是用来计算工资的话，
 *           程序员可以在这里修改自己的工资的计算方法为领导的计算方法，会出问题。
 * 使用场景：
 */

#include <iostream>
#include <string>
using std::cout;
using std::endl;

enum ITEMTYPE
{
	IT_BUTTON,
	IT_MENU,
	IT_NR,
};

//控件基类
class Item
{
public:
	virtual void ShowItemType() = 0;
};

class Button : public Item
{
public:
	void ShowItemType() override {cout << "I am a button" << endl;}
};

class Menu : public Item
{
public:
	void ShowItemType() override {cout << "I am a menu" << endl;}
};

class ItemFactory
{
public:
	static Item* createItem(enum ITEMTYPE itemType)
	{
		Item* pItem;
		switch(itemType)
		{
			case IT_BUTTON:
				pItem = new Button();
				break;
			case IT_MENU:
				pItem = new Menu();
				break;
			default:
				pItem = NULL;
		}
		return pItem;
    }
};

int main(int argc, char const *argv[])
{
	Item* myItem;
	myItem = ItemFactory::createItem(IT_BUTTON);

	myItem->ShowItemType();

	delete myItem;

	return 0;
}
