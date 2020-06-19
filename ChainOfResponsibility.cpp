/* 模式名称：职责链模式
 * 模式分类：行为型模式
 * 简单概述：使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。
 * 				将这个对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它为止
 * 模式优点：职责链简化了对象的相互链接，链中的对象只需要下一个对象，降低了耦合度；
 * 			 可以随时增加或修改处理一个请求的结构增强了给对象指派职责的灵活性；
 * 使用场景：
 */
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct Requset
{
	string RequsetType;
	int RequsetNumber;
};

class Manager
{
public:
	Manager(string name) {Name = name;}
	virtual void DealRequest(Requset* pRequest) = 0;
	void SetSuperior(Manager* pSuperior){Superior = pSuperior;}
protected:
	string Name;
	Manager *Superior;
};

class CommonManager : public Manager
{
public:
	CommonManager(string name):Manager(name){}
	void DealRequest(Requset* pRequest)
	{
		if(pRequest->RequsetType == "开通权限")
		{
			cout << Name << ":" << pRequest->RequsetType.c_str() << " agree" << endl;
		}
		else
		{
			Superior->DealRequest(pRequest);
		}
	}
};

class GeneralManager : public Manager
{
public:
	GeneralManager(string name):Manager(name){}
	void DealRequest(Requset* pRequest)
	{
		if(pRequest->RequsetType == "开通权限")
		{
			cout << Name << ":" << pRequest->RequsetType.c_str() << " agree" << endl;
		}
		else if(pRequest->RequsetType == "加薪")
		{
			if(pRequest->RequsetNumber <= 500)
			{
				cout << Name << ":" << pRequest->RequsetType.c_str() << ":" <<\
					pRequest->RequsetNumber << " agree" << endl;
			}
			else
			{
				cout << Name << ":" << pRequest->RequsetType.c_str() << ":" <<\
					pRequest->RequsetNumber << " not agree" << endl;
			}
		}

	}
};

int main(int argc, char const *argv[])
{
	CommonManager* myCommonManager = new CommonManager("jingli");
	GeneralManager* myGeneralManager = new GeneralManager("zongjingli");
	myCommonManager->SetSuperior(myGeneralManager);

	Requset myRequset = {"加薪", 1000};
	myCommonManager->DealRequest(&myRequset);

	return 0;
}
