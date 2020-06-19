/* 模式名称：模板方法模式
 * 模式分类：结构型模式
 * 简单概述：定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。模板方法使得
 * 			 子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤
 * 模式优点：把不变行为搬移到超类，去除子类中的重复代码
 * 使用场景：当不变的行为在子类中不断出现，需要把不变的行为提取到父类中来减少重复
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class CloudUpgrade
{
public:
	virtual void SendCheckRequest() = 0;
	void CheckNewVersion()
	{
		cout << "create socket" << endl;
		SendCheckRequest();
		cout << "recv response" << endl;
		cout << "parse data" << endl;
	}
};

class CloudUpgradeA : public CloudUpgrade
{
public:
	void SendCheckRequest()
	{
		cout << "send requset to server A" << endl;
	}
};

class CloudUpgradeB : public CloudUpgrade
{
public:
	void SendCheckRequest()
	{
		cout << "send requset to server B" << endl;
	}
};

int main(int argc, char const *argv[])
{
	CloudUpgrade *myCloudUpgrade = new CloudUpgradeA();
	myCloudUpgrade->CheckNewVersion();
	delete myCloudUpgrade;

	myCloudUpgrade = new CloudUpgradeB();
	myCloudUpgrade->CheckNewVersion();
	delete myCloudUpgrade;

	return 0;
}
