/* 模式名称：建造者模式
 * 模式分类：创建型模式
 * 简单概述：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同
 * 				的表示
 * 使用场景：用于创建一些复杂的对象，这些对象内部构建的建造顺序通常是固定的，但是
 * 				建造的具体内容通常面临着复杂的变化
 * 		  	 创建复杂对象的算法应该独立于该对象的组成部分及他们的装配方式时
 * 模式优点：使建造代码与表示代码分离，建造者隐藏了组装的步骤，需要改变具体内容的
 * 				的时候只需要去定义一个具体的建造者
 */
#include <iostream>
#include <string>

using std::cout;
using std::endl;

//Builder class
class Builder
{
public:
	void virtual PreProcessing() = 0;
	void virtual Compiling() = 0;
	void virtual Assembling() = 0;
	void virtual Linking() = 0;
};

//Concrete Builder class
class CBuilder : public Builder
{
public:
	void PreProcessing(){cout << "C pre-process" << endl;}
	void Compiling(){cout << "C compile" << endl;}
	void Assembling(){cout << "C assemble" << endl;}
	void Linking(){cout << "C link" << endl;}
};

class JavaBuilder : public Builder
{
public:
	void PreProcessing(){cout << "Java pre-process" << endl;}
	void Compiling(){cout << "Java compile" << endl;}
	void Assembling(){cout << "Java assemble" << endl;}
	void Linking(){cout << "Java link" << endl;}
};

//Director class  --指挥者类
class IDE
{
public:
	void Build(Builder& builder)
	{
		builder.PreProcessing();
		builder.Compiling();
		builder.Assembling();
		builder.Linking();
	}
};

int main(int argc, char const *argv[])
{
	CBuilder myCBuilder = CBuilder();
	IDE myIDE = IDE();
	myIDE.Build(myCBuilder);

	return 0;
}
