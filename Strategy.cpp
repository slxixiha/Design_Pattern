/* 模式名称：策略模式
 * 模式分类：行为型模式
 * 简单概述：它定义了算法家族，分别封装起来，让它们之间可以相互替换，此模式让算法的变化，
 * 			 不会影响到使用算法的用户。
 * 模式优点：1.定义的算法完成的工作相同，只是结构不同，它以相同的方式调用了所有的算法，
 * 				减少了算法类和使用算法类之间的耦合度。
 * 			 2.封装各种算法，简化了单元测试，可以通过自己的接口进行单独测试
 * 模式缺点：把模式的选择放在了客户端中，暴露了太多细节
 * 使用场景：同一个用户需要在不同的情景下使用不同的业务规则，
 * 			 用户的主体已经是确定的，变化的是主体的某个行为
 */

#include <iostream>
#include <string>

#define VERSION2

using std::cout;
using std::endl;

//排序算法
class SortAlgorithm
{
public:
	virtual void Sort() = 0;
};

class QuickSort : public SortAlgorithm
{
public:
	void Sort() override {cout << "Quick Sort" << endl;}
};

class SelectSort : public SortAlgorithm
{
public:
	void Sort() override {cout << "Select Sort" << endl;}
};

#ifdef VERSION0
//算法调用的主体
class numArrray
{
public:
	numArrray(SortAlgorithm* pSort){m_pSortAlgorithm = pSort;}
	void Sort() {m_pSortAlgorithm->Sort();}
private:
	SortAlgorithm* m_pSortAlgorithm;
};

int main(int argc, char const *argv[])
{
	numArrray myNumArray(new SelectSort());
	myNumArray.Sort();
	return 0;
}
#endif

#ifdef VERSION1
/*
 *利用简单工厂模式优化策略模式，将具体算法类的实例化放到
 *调用对象的主体里面，隐藏了客户端的修改
 */
 enum sortType
 {
	TYPE_QUICKSORT,
	TYPE_SELECTSORT,
	TYPE_NR,
 };
//算法调用的主体
class numArrray
{
public:
	numArrray(enum sortType type)
	{
		switch(type)
		{
			case TYPE_QUICKSORT:
				m_pSortAlgorithm = new QuickSort();
				break;
			case TYPE_SELECTSORT:
				m_pSortAlgorithm = new SelectSort();
				break;
			default:
				break;
		}
	}
	void Sort() {m_pSortAlgorithm->Sort();}
private:
	SortAlgorithm* m_pSortAlgorithm;
};

int main(int argc, char const *argv[])
{
	numArrray myNumArray(TYPE_SELECTSORT);
	myNumArray.Sort();
	return 0;
}
#endif

#ifdef VERSION2
//利用类模板来进一步减少选择
template <typename T> class numArrray
{
public:
	numArrray() {m_pSortAlgorithm = new T;}
	void Sort() {m_pSortAlgorithm->Sort();}
private:
	T* m_pSortAlgorithm;
};

int main(int argc, char const *argv[])
{
	numArrray<QuickSort> myNumArray;
	myNumArray.Sort();
	return 0;
}
#endif // VERSION2
