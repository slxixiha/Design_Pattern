/* 模式名称：装饰模式
 * 模式分类：结构型模式
 * 简单概述：动态地给一个对象添加一些额外的职责，就增加功能来说，装饰模式比继承更灵活
 * 模式优点：把类中的装饰功能从类中搬移去除，这样可以简化原来的类
 * 			 有效地把类的核心职责和装饰功能区分开，去除了相关类中的重复逻辑
 * 模式缺点：把模式的选择放在了客户端中，暴露了太多细节
 *			 如果职责比较多的话，要写的类也会比较多
 * 使用场景：某些职责只有在特定情况下才需要，因此不能把这些职责写到主体类中，
 * 			 而使用了装饰类就可以对特定情况下的对象根据需要进行有选择、有顺序的装饰
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

//抽象主体类
class Person
{
public:
	virtual void ShowPerson() = 0;
	std::string PersonDiscription;
};

//具体主体类
class ConcretePersion : public Person
{
public:
	ConcretePersion()
	{
		PersonDiscription = "this person";
	}
	void ShowPerson()
	{
		cout << PersonDiscription.c_str();
	}
};

//抽象装饰类
class DecoratedPerson : public Person
{
public:
	DecoratedPerson(Person* person) : Person() {};
	Person* pPerson;
};

//具体装饰类
class Teacher : public DecoratedPerson
{
public:
	Teacher(Person* person) : DecoratedPerson(person)
	{
		pPerson = person;
	}
	void ShowPerson()
	{
		pPerson->ShowPerson();
		cout << " is a Teacher,";
	}
};

class Driver : public DecoratedPerson
{
public:
	Driver(Person* person) : DecoratedPerson(person)
	{
		pPerson = person;
	}
	void ShowPerson()
	{
		pPerson->ShowPerson();
		cout << "is a Driver," << endl;
	}
};

int main(int argc , char * argv[])
{
	Person* myPerson = new ConcretePersion();
	myPerson = new Teacher(myPerson);
	myPerson = new Driver(myPerson);
	myPerson->ShowPerson();

	return 0;
}
