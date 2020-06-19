/* 模式名称：中介者模式
 * 模式分类：结构型模式
 * 简单概述：定义一个中介对象来封装系列对象之间的交互。中介者使各个对象不需要显示地相互引用，
 * 				从而使其耦合性松散，而且可以独立地改变他们之间的交互
 * 使用场景：1.一组对象以定义良好但是复杂的方式进行通信。产生的相互依赖关系结构混乱且难以理解。
 * 			 2.一个对象引用其他很多对象并且直接与这些对象通信，导致难以复用该对象。
 * 			 3.想定制一个分布在多个类中的行为，而又不想生成太多的子类。
 * 模式优点：1.降低了系统对象之间的耦合性，使得对象易于独立的被复用。
 * 			 2.提高系统的灵活性，使得系统易于扩展和维护。
 * 模式缺点：由于我们这个“中介“承担了较多的责任，所以一旦这个中介对象出现了问题，
 * 				那么整个系统就会受到重大的影响。
 */

#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::string;
using std::list;

class ChatSoftware;

//抽象同事类（colleague）
class User
{
public:
	User(string name) {userName = name;}
	void SetChatSoftware(ChatSoftware* software) {mySoftware = software;}
	virtual void ReceiveMessage(string& message) = 0;
protected:
	string userName;
	ChatSoftware* mySoftware;
};

//抽象中介者类（mediator）
class ChatSoftware
{
public:
	ChatSoftware() {userList = list<User*>();}
	void AddUser(User *pUser) {userList.push_back(pUser);}
	void RemoveUser(User* pUser) {userList.remove(pUser);}
	void Notify(string& message)
	{
		for(list<User*>::iterator iter = userList.begin(); iter != userList.end(); iter++)
		{
			(*iter)->ReceiveMessage(message);
		}
	}
	virtual void SetMessage(string& message) = 0;
private:
	list<User*> userList;
};

//具体中介者类（concrete mediator）
class Weixin : public ChatSoftware
{
public:
	void SetMessage(string& message)
	{
		cout << "Weixin message" << endl;
		Notify(message);
	}
};

//具体同事类（concrete colleague）
class Manager : public User
{
public:
	Manager(string name) : User(name) {}
	void SendCommand(string& command)
	{
		cout << "Manager:" << userName.c_str() << " send command:" << command.c_str() << endl;
		mySoftware->SetMessage(command);
	}
	void ReceiveMessage(string& command)
	{
		cout << "Manager:" << userName.c_str() << " recv command:" << command.c_str() << endl;
	}
};

class Staff : public User
{
public:
	Staff(string name) : User(name) {}
	void ReceiveMessage(string& command)
	{
		cout << "Staff:"<< userName.c_str() << " recv command:" << command.c_str() << endl;
	}
};


int main(int argc, char const *argv[])
{
	ChatSoftware *myChatSoftware = new Weixin();

	Manager* user1 = new Manager("jingli");
	user1->SetChatSoftware(myChatSoftware);
	myChatSoftware->AddUser(user1);

	Staff* user2 = new Staff("zhangsan");
	user2->SetChatSoftware(myChatSoftware);
	myChatSoftware->AddUser(user2);

	Staff* user3 = new Staff("lisi");
	user3->SetChatSoftware(myChatSoftware);
	myChatSoftware->AddUser(user3);

	string myCommand = "work overtime tomorrow!";
	user1->SendCommand(myCommand);

	delete myChatSoftware;
	delete user1;
	delete user2;
	delete user3;

	return 0;
}
