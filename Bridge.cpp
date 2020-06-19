/* 模式名称：桥接模式
 * 简单概述：将抽象部分与它的实现部分分离，使它们都可以独立地变化
 * 使用场景：1.当一个对象有多个变化因素的时候，考虑依赖于抽象的实现，而不是具体的实现。
 * 				例如电脑的品牌和操作系统是两个变化因素
 * 			 2.当多个变化因素在多个对象间共享时，考虑将这部分变化的部分抽象出来再聚合/合成进来，
 *     		 3.当我们考虑一个对象的多个变化因素可以动态变化的时候，考虑使用桥接模式，
 *     		 	例如电脑品牌是变化的，手机的操作系统也是变化的，所以将他们分离出来，独立的变化。
 * 模式优点：1.将实现抽离出来，再实现抽象，使得对象的具体实现依赖于抽象，满足了依赖倒转原则。
 * 			 2.将可以共享的变化部分，抽离出来，减少了代码的重复信息。
 * 			 3.对象的具体实现可以更加灵活，可以满足多个因素变化的要求。
 * 模式缺点：1.客户必须知道选择哪一种类型的实现。
 * 			 2.如果只有一种变化因素，直接使用继承就好了
 */
#include <iostream>
#include <string>

using std::cout;
using std::endl;

//抽象的实现
class OperationSystem
{
public:
	virtual void InstallSystem() = 0;
};

class Windows : public OperationSystem
{
public:
	void InstallSystem() override {cout << "install Windows system." << endl;}
};

class Linux : public OperationSystem
{
public:
	void InstallSystem() override {cout << "install Linux system." << endl;}
};


class Computer
{
public:
	virtual void InstallSystem(OperationSystem* system) = 0;
};

class ShenzhouComputer : public Computer
{
public:
	void InstallSystem(OperationSystem* system) override
	{
		cout << "Shenzhou Computer ";
		system->InstallSystem();
	}
};

class AppleComputer : public Computer
{
public:
	void InstallSystem(OperationSystem* system) override
	{
		cout << "Apple Computer ";
		system->InstallSystem();
	}
};

int main(int argc, char const *argv[])
{
	Computer *myComputer = new ShenzhouComputer();
	OperationSystem *myOperationSystem = new Linux();

	myComputer->InstallSystem(myOperationSystem);

	return 0;
}

