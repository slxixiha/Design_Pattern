/* 模式名称：外观模式
 * 模式分类：结构型模式
 * 简单概述：为子系统中的一组接口提供一个一致的界面，此模式定义了一个高层接口，
 * 			 这个接口可以使得这一子系统更加容易使用
 * 使用场景：一、开发初期，有意识的将不同的两个层分离，在层与层之间建立外观模式
 * 			 二、开发过程中，子系统会因为不断重构演化变得越来越复杂，会产生很多
 * 			 		很小的类，增加一个外观接口可以减少对具体细节的依赖，
 * 			 		提高了子系统的独立性
 * 			 三、维护一个复杂的遗留的系统，又需要新系统的时候，外观模式作为一个
 * 			 		中间层在将两个系统隔开
 * 	
 */
/*要点
1．Facade模式对客户屏蔽了子系统组件，因而减少了客户处理的对象的数目并使得子系统使用起来更加方便。
2．Facade模式实现了子系统与客户之间的松耦合关系，而子系统内部的功能组件往往是紧耦合的。松耦合关系使得子系统的组件变化不会影响到它的客户。
3．如果应用需要，它并不限制它们使用子系统类。因此你可以在系统易用性与通用性之间选择。
4. 在外观模式中，通常只需要一个外观类，并且此外观类只有一个实例，换言之它是一个单例类。当然这并不意味着在整个系统里只能有一个外观类，而仅仅是说对每一个子系统只有一个外观类。或者说，如果一个系统有好几个子系统的话，每一个子系统有一个外观类，整个系统可以有数个外观类。
5. 外观模式的用意是为子系统提供一个集中化和简化的沟通管道，而不建议向子系统加入新的行为。
6. 外观模式注重的是简化接口，它更多的时候是从架构的层次去看整个系统，而并非单个类的层次。
优点
1. 松散耦合
    外观模式松散了客户端与子系统的耦合关系，让子系统内部的模块能更容易扩展和维护。即要点2.
2.  简单易用
    外观模式让子系统更加易用，客户端不再需要了解子系统内部的实现，也不需要跟众多子系统内部的模块进行交互，只需要跟外观交互就可以了，相当于外观类为外部客户端使用子系统提供了一站式服务。
3. 更好的划分访问层次
     通过合理使用Facade，可以帮助我们更好的划分访问的层次。有些方法是对系统外的，有些方法是系统内部使用的。把需要暴露给外部的功能集中到外观中，这样既方便客户端使用，也很好的隐藏了内部的细节。
缺点          
	过多的或者是不太合理的Facade也容易让人迷惑，到底是调用Facade好呢，还是直接调用模块好。
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class PreProcess
{
public:
	void PreProcessing() {cout << "pre-process" << endl;}
};

class Compile
{
public:
	void Compiling() {cout << "Compile" << endl;}
};

class Assemble
{
public:
	void Assembling() {cout << "Assemble" << endl;}
};

class Link
{
public:
	void Linking() {cout << "Link" << endl;}
};

//f高层接口
class Build
{
public:
	void Building()
	{
		PreProcess myPreProcess;
		myPreProcess.PreProcessing();
		Compile myCompile;
		myCompile.Compiling();
		Assemble myAssemble;
		myAssemble.Assembling();
		Link myLink;
		myLink.Linking();
	}
};

int main(int argc, char const *argv[])
{
	Build myBuild;
	myBuild.Building();

	return 0;
}