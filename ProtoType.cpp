/* 模式名称：原型模式
 * 模式分类：创建型模式
 * 模式优点：使用拷贝模式比直接new一个对象开销要小的多
 *			 可以在程序运行时（对象属性发生了变化）时，得到一份内容相同的实例，
				相互之间还互不干扰
 * 简单概述：用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象
 * 使用场景：这里有浅拷贝和深拷贝两种
 * 使用疑问：浅拷贝的时候如何处理指针成员指向的内存?
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

//#define SHALLOW_COPY	//浅拷贝
#define DEEP_COPY		//深拷贝

#define MAX_EXPERIENCE_LEN 64

class Resume
 {
 public:
 	virtual Resume* Clone() = 0;
 	virtual void Show() = 0;
 	virtual void SetExperience(const char *experience) = 0;
 	std::string myName;
 	char *myExperience;
 };

 class ConcreteResume : public Resume
 {
 public:
 	ConcreteResume(std::string name);
 	ConcreteResume(const ConcreteResume& resume);
 	ConcreteResume* Clone();
 	void Show();
 	void SetExperience(const char * experience);
 };

 ConcreteResume::ConcreteResume(std::string name)
 {
	myName = name;
	myExperience = new char[MAX_EXPERIENCE_LEN];
 }

 #ifdef SHALLOW_COPY
 ConcreteResume::ConcreteResume(const ConcreteResume& resume)
 {
 	myName = resume.myName;
 	myExperience = resume.myExperience;
 }
#elif defined(DEEP_COPY)
 ConcreteResume::ConcreteResume(const ConcreteResume& resume)
 {
 	myName = resume.myName;
 	myExperience = new char[MAX_EXPERIENCE_LEN];
 	memcpy(myExperience, resume.myExperience, MAX_EXPERIENCE_LEN);
 }
 #endif

 ConcreteResume* ConcreteResume::Clone()
 {
 	return new ConcreteResume(*this);
 }

 void ConcreteResume::Show()
 {
 	cout << "name: " << myName << endl;
 	cout << "experience: " << myExperience << endl;
 }

void ConcreteResume::SetExperience(const char * experience)
{
    memcpy(myExperience, experience, MAX_EXPERIENCE_LEN);
}

 int main(int argc, char const *argv[])
 {
 	ConcreteResume* myResume1 = new ConcreteResume("zhangsan");
 	myResume1->SetExperience("Primary School");
	ConcreteResume* myResume2 = myResume1->Clone();
    myResume2->SetExperience("High School");
    myResume1->Show();
    myResume2->Show();

    delete myResume1;
    delete myResume2;

 	return 0;
 }
