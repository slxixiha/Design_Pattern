/* 模式名称：备忘录模式
 * 模式分类：结构型模式
 * 简单概述：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象
 * 				之外保存这个状态。这样以后就可将该对象恢复到原先保存的状态
 * 使用场景：
 * 示例简述：这个模式的经典应用场景当然是游戏了，游戏里的存档就是典型的备忘录模式，
 * 				一个角色经过操作后，对应的属性会发生变化，存档的时候就是要记录下当时
 * 				角色的属性值，方便在后面读取存档的时候能够恢复这些数据
 */
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

//单个角色存档
class Memonto
{
public:
	Memonto(int vitality, int attack, int defense)
		:m_vitality(vitality), m_attack(attack),m_defense(defense) {}

	int m_vitality;
	int m_attack;
	int m_defense;
};

//游戏角色
class GemeRole
{
public:
	GemeRole() : m_vitality(100), m_attack(100), m_defense(100) {}
	Memonto Save()
	{
		return Memonto(m_vitality, m_attack, m_defense);
	}
	void Load(Memonto memo)
	{
		m_vitality = memo.m_vitality;
		m_attack = memo.m_attack;
		m_defense = memo.m_defense;
	}
	void ShowState()
	{
		cout << "vitality: " << m_vitality \
			<< " attack: " << m_attack \
			<< " defense: " << m_defense << endl;
	}
	void Fight()
	{
		m_vitality -= 50;
	}
private:
	int m_vitality;
	int m_attack;
	int m_defense;
};

//存档列表
class MemoList
{
public:
	void SaveData(Memonto memonto) {m_memoList.push_back(memonto);};
	Memonto& LoadData(int index) {return m_memoList[index];}
private:
	std::vector<Memonto> m_memoList;
};

int main(int argc, char const *argv[])
{
	MemoList myMemoList = MemoList();
	GemeRole myGameRole = GemeRole();

	myGameRole.ShowState();
	myMemoList.SaveData(myGameRole.Save());

	myGameRole.Fight();
	myGameRole.ShowState();

	myGameRole.Load(myMemoList.LoadData(0));
	myGameRole.ShowState();

	return 0;
}
