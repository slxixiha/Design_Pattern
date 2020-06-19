/* 模式名称：组合模式
 * 模式分类：结构型模式
 * 简单概述：将对象组合成树形结构以表示'部分-整体'的层次结构。组合模式使得用户对
 * 				单个对象和组合对象和使用有一致性
 * 使用场景：需求中是体现部分与整体层次的结构时，以及你希望用户可以忽略组合对象与
 * 				单个对象的不同，统一地使用组合结构中的所有对象时。
 */
#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;

class Inode
{
public:
	Inode(std::string name) {myname = name;}
	virtual void Add(Inode* node) = 0;
	virtual void Remove(Inode* node) = 0;
	virtual void Display(int depth) = 0;
protected:
	std::string myname;
};

class File : public Inode
{
public:
	File(std::string name) : Inode(name){};
	void Add(Inode* node) override {cout << "Unable to add node to file" << endl;}
	void Remove(Inode* node) override {cout << "Unable to remove node from file" << endl;}
	void Display(int depth) override
	{
		cout << std::string(depth, '-').c_str() << myname.c_str() << endl;
	}
};

class Browse : public Inode
{
public:
	Browse(std::string name) : Inode(name)
	{
		children = new std::list<Inode *>;
	}
	void Add(Inode* node) override {children->push_back(node);}
	void Remove(Inode* node ) override {children->remove(node);}
	void Display(int depth) override
	{
		cout << std::string(depth, '-').c_str() << myname.c_str() << endl;
		for(std::list<Inode*>::iterator iter = children->begin();iter!=children->end();iter++)
		{
			(*iter)->Display(depth + 2);
		}
	}
private:
	std::list<Inode *> *children;
};

int main(int argc, char const *argv[])
{
	Browse root = Browse("root");

	File *FileA = new File("File A");
	root.Add(FileA);

	Browse *Browse1 = new Browse("Browse 1");
	root.Add(Browse1);

	File *FileB = new File("File B");
	Browse1->Add(FileB);

	root.Display(1);

	delete FileA;
	delete Browse1;
	delete FileB;
	return 0;
}
