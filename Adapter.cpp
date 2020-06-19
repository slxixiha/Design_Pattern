/* 模式名称：适配器模式
 * 模式分类：结构型模式
 * 简单概述：将一个类的接口转换成客户希望的另外一个模式。Adapter模式使得原本由于接口
 * 				不兼容而不能一起工作的哪些类可以一起工作
 * 两种模式：适配器模式有类适配器和对象适配器两种模式，
 * 				类适配器模式通过多重继承对一个接口与另一个接口进行匹配；
 * 				而对象适配器模式则是把特殊类的对象作为适配器的一个成员。
 * 使用场景：1．系统需要使用现有的类，而此类的接口不符合系统的需要。
 *		  	 2．想要建立一个可以重复使用的类，用于与一些彼此之间没有太大关联的一些类，
 *				包括一些可能在将来引进的类一起工作。这些源类不一定有很复杂的接口。
 *		  	 3．（对对象适配器而言）在设计里，需要改变多个已有子类的接口，如果使用类的适配器模式，
 *				就要针对每一个子类做一个适配器，而这不太实际。
 * 实现要点：1．Adapter模式主要应用于“希望复用一些现存的类，但是接口又与复用环境要求不一致的情况”，
 *				在遗留代码复用、类库迁移等方面非常有用。
 *		  	 2．Adapter模式有对象适配器和类适配器两种形式的实现结构，但是类适配器采用“多继承”的实现方式，
 *				带来了不良的高耦合，所以一般不推荐使用。对象适配器采用“对象组合”的方式，更符合松耦合精神。
 *		  	 3．Adapter模式的实现可以非常的灵活，不必拘泥于GOF23中定义的两种结构。
 *				例如，完全可以将Adapter模式中的“现存对象”作为新的接口方法参数，来达到适配的目的。
 *		  	 4．Adapter模式本身要求我们尽可能地使用“面向接口的编程”风格，这样才能在后期很方便的适配。
 * 例子简述：
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

//#define OBJECT_MODE
#define CLASS_MODE

// "ITarget"
class Target
{
public:
	// Methods
	virtual void Methods()
	{
		cout << "Called Methods()" << endl;
	};
};

// "SpecificClass"
class SpecificClass
{
public:
	// Specific Methods
	void SpecificMethods()
	{
		cout << "Called Specific Methods()" << endl;
	}
};

#ifdef OBJECT_MODE
// "Adapter"
class Adapter : public SpecificClass, public Target
{
public:
	// Implements ITarget interface
	void Methods()
	{
		//make the realization like normal class
		this->SpecificMethods();
	}
};
#endif

#ifdef CLASS_MODE
class Adapter : public Target
{
public:
	Adapter() : Target()
	{
		pSpecificClass = new SpecificClass();
	}

	~Adapter()
	{
		delete pSpecificClass;
	}

	void Methods()
	{
		pSpecificClass->SpecificMethods();
	}
private:
	SpecificClass* pSpecificClass;
};
#endif

int main(int argc, char *argv[])
{
	Target * myTarget = new Adapter();
	myTarget->Methods();

	delete myTarget;
	return 0;
}

