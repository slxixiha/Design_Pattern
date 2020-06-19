/* 模式名称：访问者模式
 * 模式分类：行为型模式
 * 简单概述：表示一个作用于某对象结构中的各元素的操作。它使你可以在不改变各元素的类的前提
 * 				下定义作用于这些元素的新操作
 * 模式优点：一、易于添加那些目前尚未考虑到的方法。（这也是使用访问者的原因：扩展功能）
 * 			 二、可以使类更加小巧，因为那些很少使用的方法，可以在外部定义。（意味着如果一个方法
 * 			 	经常使用，最好定义在类中；当然在第一次定义中没有考虑到此方法除外）
 * 模式缺点：一、访问者角色不适合具体元素角色经常发生变化的情况。
 * 			 二、访问者角色要执行与元素角色相关的操作，就必须让元素角色将自己内部属性暴露出来，
 * 			 	这就破坏了元素角色的封装性。访问者和被访问的对象的耦合性很大。
 * 			 三、元素与访问者之间能够传递的信息有限，这往往也会限制访问者模式的使用。
 * 			 	（因为访问者不能直接访问元素的私有数据）
 * 应用场景：一、一个对象结构包含很多类对象，它们有不同的接口，而你想对这些对象实施一些
 * 				依赖于其具体类的操作；
 * 			 二、需要对一个对象结构中的对象进行很多不同的并且不相关的操作，而你想避免让
 * 			 	这些操作“污染”这些对象的类。Visitor使得你可以将相关的操作集中起来定义在一个类中；
 * 			 三、当该对象结构被很多应用共享时，用Visitor模式让每个应用仅包含需要用到的操作；
 * 			 四、定义对象结构的类很少改变，但经常需要在此结构上定义新的操作。改变对象结构类
 * 			 	需要重定义对所有访问者的接口，这可能需要很大的代价。如果对象结构类经常改变，
 * 			 	那么可能还是在这些类中定义这些操作较好。
 * 例子简述：不同性别的人对不同的事件有不同的反应
 */
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Man;
class Woman;

 //visitor
class Action
{
public:
    virtual void GetManAction( Man *ConcreteElementA ) = 0;
    virtual void GetWomanAction( Woman *ConcreteElementB ) = 0;
};

//element
class Person
{
public:
	virtual void Accept( Action *visitor) = 0;
};

//concrete element
class Man : public Person
{
public:
	void Accept(Action *visitor)
	{
		cout << "Man : ";
		visitor->GetManAction(this);
	}
};

class Woman : public Person
{
public:
	void Accept(Action *visitor)
	{
		cout <<"Woman :";
		visitor->GetWomanAction(this);
	}
};

//concrete visitor
class BuyPhone : public Action
{
public:
	void GetManAction( Man *ConcreteElementA )
	{
		cout << "I want a practical one" << endl;
	}
	void GetWomanAction( Woman *ConcreteElementB )
	{
		cout << "I want a beautiful one" << endl;
	}
};

class FallInLove : public Action
{
public:
	void GetManAction( Man *ConcreteElementA )
	{
		cout << "I need to be active" << endl;
	}
	void GetWomanAction( Woman *ConcreteElementB )
	{
		cout << "I want to be passive" << endl;
	}
};

class PersonGroup
{
public:
	void Attach(Person* person)
	{
		group.push_back(person);
	}
	void Detach(Person* person)
	{
		group.remove(person);
	}
	void Display(Action* visitor)
	{
		for(list<Person*>::iterator iter = group.begin(); iter != group.end(); iter++)
		{
			(*iter)->Accept(visitor);
		}
	}
private:
	list <Person*> group;
};

int main(int argc, char const *argv[])
{
	PersonGroup HumanGroup = PersonGroup();

	Man *man = new Man();
	HumanGroup.Attach(man);

	Woman *woman = new Woman();
	HumanGroup.Attach(woman);

	BuyPhone *action = new BuyPhone();

	HumanGroup.Display(action);

	delete man;
	delete woman;
	delete action;

	return 0;
}


