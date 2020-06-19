/* 模式名称：抽象工厂模式
 * 模式分类：创建型模式
 * 简单概述：提供一个创建一系列相关或相互依赖对象的接口，而无需指定他们具体的类。
 * 			 其实感觉就是在工厂方法模式的基础上再加了一层。
 * 模式优点：假定我有多套界面框架，比如MiniGUI和QT，这个时候简单工厂模式和工厂方法模式就不能处理，
 * 			 只能使用抽象工厂模式。
 * 模式缺点：缺点也是增加新的类时修改工厂类，违反了开放封闭原则。如果是用来计算工资的话，
 *           程序员可以在这里修改自己的工资的计算方法为领导的计算方法，会出问题。
 * 使用场景：
 */

#include <iostream>
#include <string>
using std::cout;
using std::endl;

//QT的控件类
class QTItem
{
public:
	virtual void ShowItemType() = 0;
};

class QTButton : public QTItem
{
public:
	void ShowItemType() override {cout << "I am a QT button" << endl;}
};

class QTMenu : public QTItem
{
public:
	void ShowItemType() override {cout << "I am a QT menu" << endl;}
};

//MiniGUI的控件类
class MiniGUIItem
{
public:
	virtual void ShowItemType() = 0;
};

class MiniGUIButton : public MiniGUIItem
{
public:
	void ShowItemType() override {cout << "I am a MiniGUI button" << endl;}
};

class MiniGUIMenu : public MiniGUIItem
{
public:
	void ShowItemType() override {cout << "I am a MiniGUI menu" << endl;}
};

class ItemFactory
{
public:
	virtual QTItem *createQTItem() = 0;
	virtual MiniGUIItem *createMiniGUIItem() = 0;
};

class MenuFactory : public ItemFactory
{
public:
	QTItem *createQTItem() override {return new QTMenu;}
	MiniGUIItem *createMiniGUIItem() override {return new MiniGUIMenu;}
};

class ButtonFactory : public ItemFactory
{
public:
	QTItem *createQTItem() override {return new QTButton;}
	MiniGUIItem *createMiniGUIItem() override {return new MiniGUIButton;}
};

int main(int argc, char const *argv[])
{
	ItemFactory* myFactory = new ButtonFactory();

	QTItem* myQTItem = myFactory->createQTItem();
	myQTItem->ShowItemType();

	MiniGUIItem* myMiniGUIItem = myFactory->createMiniGUIItem();
	myMiniGUIItem->ShowItemType();

	delete myMiniGUIItem;
	delete myQTItem;
	delete myFactory;

	return 0;
}
