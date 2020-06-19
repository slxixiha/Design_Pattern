/* 模式名称：享元模式
 * 模式分类：结构型模式
 * 简单概述：运用共享技术有效地支持大量细粒度的对象
 * 使用场景：一、如果一个应用程序使用了大量的对象，而大量的这些对象造成了
 * 					很多的存储开销
 * 			 二、对象的大多数状态是外部状态，如果删除对象的外部状态，
 * 			 		那么可以用相对较少的共享对象取代很多组对象
 * 例子描述：我们都用过在window下打开目录页面去寻找某一些文件或者目录，
 * 				这些页面的各种寻找的操作都是一样的，只是最后需要选取的文件的类型不一样，
 * 				这些操作可以共用一个对象，只是对象过滤文件的类型不一样
 */
#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::map;

enum PAGEMODE
{
	MODE_FILE,
	MODE_BROWSE,
};

//搜索页面抽象类
class SearchPage
{
public:
	void Search() {cout << "Search Operation" << endl;}
	virtual void stringFilter(string str) = 0;
};

//文件搜索页面
class FileSearchPage : public SearchPage
{
public:
	void stringFilter(string str)
	{
		Search();
		cout << "FileSearchPage filter: " << str.c_str() << endl;
	}
};

//目录搜索页面
class BrowseSearchPage : public SearchPage
{
public:
	void stringFilter(string str)
	{
		Search();
		cout << "BrowseSearchPage filter: " << str.c_str() << endl;
	}
};

class PageFactory
{
public:
	SearchPage* createPage(int pageMode)
	{
		map<int, SearchPage*>::iterator iter = pages.find(pageMode);
		if(iter == pages.end())
		{
			if(pageMode == MODE_FILE)
			{
				pages[pageMode] = new FileSearchPage();
			}
			else if(pageMode == MODE_BROWSE)
			{
				pages[pageMode] = new BrowseSearchPage();
			}
		}
		return pages[pageMode];
	}
private:
	map<int, SearchPage*> pages;
};

int main(int argc, char const *argv[])
{
	PageFactory myPageFactory = PageFactory();

	SearchPage* mySearchPage = myPageFactory.createPage(MODE_FILE);

	mySearchPage->stringFilter(".avi");

	return 0;
}
