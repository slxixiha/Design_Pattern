/* 模式名称：工厂方法模式
 * 模式分类：创建型模式
 * 简单概述：在工厂基类中定义一个用于创建具体对象的接口，让具体工厂子类去生产对应的类。
 *           工厂基类的使用把一个类的实例化延迟到其子类
 * 模式优点：这个模式把工厂负责的内容也封装起来了，符合了开放封闭原则。
 * 模式缺点：每增加一个产品，就要增加一个对应的工厂类，增加了开发量，而且还要修改客户端的代码。
 * 使用场景：
 */

#include <iostream>
#include <string>
using std::cout;
using std::endl;

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
	virtual Item * createItem() = 0;
};

class ButtonFactory : public ItemFactory
{
public:
    Item *createItem() override {return new Button;}
};

class MenuFactory : public ItemFactory
{
public:
    Item *createItem() override {return new Menu;}
};

int main(int argc, char const *argv[])
{
	ItemFactory* myFactory = new MenuFactory();
	Item *myItem = myFactory->createItem();

	myItem->ShowItemType();

	delete myItem;
	delete myFactory;

	return 0;
}
