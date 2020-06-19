/* 模式名称：命令模式
 * 模式分类：行为型模式
 * 简单概述：将一个请求封装为一个对象，从而使你可用不同的请求对客户进行参数化，
 * 				对请求排队或记录请求日志，以及支持可撤销的操作
 * 使用场景：需要对请求做一些操作的时候，把请求单独封装出来
 * 模式优点：一、它能较容易地设计一个命令队列
 * 			 二、在需要的情况下，可以较容易地将命令计入日志
 * 			 三、允许接受请求的乙方决定是否要否决请求
 * 			 四、可以容易地实现对请求的撤销和重做
 * 			 五、容易加新的具体命令类
 * 			 六、把请求一个操作的对象与知道怎么执行一个操作的对象分割开
 * 代码解析：领导接受客户需求给我们安排工作不就是最好的例子吗
 */
#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::list;

class Worker
{
public:
	void WriteScript(){cout << "write a script" << endl;}
	void WriteTool(){cout << "write a tool" << endl;}
};

class Command
{
public:
	Command(Worker *pWorker){worker = pWorker;}
	virtual void FinishTask() = 0;
protected:
	Worker *worker;
};

class ScriptCommand : public Command
{
public:
	ScriptCommand(Worker *pWorker) : Command(pWorker){}
	void FinishTask() override {worker->WriteScript();}
};

class ToolCommand : public Command
{
public:
	ToolCommand(Worker* pWorker) : Command(pWorker) {}
	void FinishTask() override {worker->WriteTool();}
};

class Leader
{
public:
	Leader()
	{
		commandList = list<Command*>();
	}
	void ReceiveTask(Command* pCommand)
	{
		commandList.push_back(pCommand);
	}
	void RemoveTask(Command* pCommand)
	{
		commandList.remove(pCommand);
	}
	void AssignTask()
	{
		for(list<Command*>::iterator iter = commandList.begin();iter!=commandList.end();iter++)
		{
			(*iter)->FinishTask();
		}
	}
private:
	list<Command*> commandList;
};

int main(int argc, char const *argv[])
{
	Worker* me = new Worker();
	ToolCommand* firstCommand = new ToolCommand(me);
	ScriptCommand* secondCommand = new ScriptCommand(me);

	Leader myleader = Leader();
	myleader.ReceiveTask(firstCommand);
	myleader.ReceiveTask(secondCommand);

	myleader.AssignTask();

	return 0;
}
