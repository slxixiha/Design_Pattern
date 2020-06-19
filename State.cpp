/* 模式名称：状态模式
 * 模式分类：状态型模式
 * 简单概述：允许一个对象在其内部状态改变时改变它的行为，使对象看起来似乎修改了它的类
 * 使用场景：状态模式主要解决的是当控制一个对象状态装换的条件表达式过于复杂时的情况。
 *			把状态的判断逻辑转移到表示不同状态的一系列类中，可以把复杂的判断逻辑简单化。
 *		  当一个对象行为取决于它的状态，并且它必须在运行时刻根据状态改变它的行为时，
 *			就可以考虑使用状态模式了。
 * 模式优点：1、状态模式将与特定状态相关的行为局部化，并且将不同状态的行为分割开来。
 *		  2、所有状态相关的代码都存在于某个ConcereteState中，所以通过定义新的子类
 *				很容易地增加新的状态和转换，符合开放封闭原则。
 *		  3，状态模式通过把各种状态转移逻辑分不到State的子类之间，来减少相互间的依赖。
 *
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Person
{
public:
	virtual void GivenSnack() = 0;
};

class HungryPerson : public Person
{
public:
	void GivenSnack() {cout << "Thanks, I'm hungry now!" << endl;}
};

class FullPerson : public Person
{
public:
	void GivenSnack() {cout << "Thanks, but I'm full now!" << endl;}
};

class ConcretePerson
{
public:
	ConcretePerson()
	{
		pPerson = new HungryPerson();
	}
	void SetHungryState()
	{
		delete pPerson;
		pPerson = new HungryPerson();
		cout << "change to hungry state" << endl;
	}
	void SetFullState()
	{
		delete pPerson;
		pPerson = new FullPerson();
		cout << "change to full state" << endl;
	}
	void GivenSnack() {pPerson->GivenSnack();}
private:
	Person *pPerson;
	
};

int main(int argc, char *argv[])
{
	ConcretePerson * myPerson = new ConcretePerson();
	myPerson->SetFullState();
	myPerson->GivenSnack();

	myPerson->SetHungryState();
	myPerson->GivenSnack();
	return 0;
}

