/* 模式名称：解释器模式
 * 模式分类：行为型模式
 * 简单概述：给定一个语言，定义它的文法的一种表示，并定义一个解释器，这个解释器使用
 * 				该表示来解释语言中的句子
 * 模式缺点：解释器模式为文法中的每一条规则至少定义了一个类，因此包含许多规则的文法
 * 				可能难以管理和维护。建议当文法非常复杂时，使用其他的技术如语法分析
 * 				程序或编译器生成器来处理。
 * 解决问题：如果一种特定类型的问题发生的频率足够高，那么可能就值得将该问题的各个
 * 				实例表述为一个简单语言中的句子。这样就可以构建一个解释器，该解释器
 * 				通过解释这些句子来解决该问题。
 * 使用场景：有一个语言需要解释执行，并且你可将该语言中的句子表示为一个抽象语法树时
 */
#include <iostream>
#include <string>
#include <stdio.h>

using std::cout;
using std::endl;
using std::string;

//抽象表达式
class AbstractExpression
{
public:
	virtual int Interpreter(int leftValue, string &context) = 0;
};

//终端表达式
class AddExpression : public AbstractExpression
{
public:
	int Interpreter(int leftValue, string& context)
	{
		return leftValue + context[0] - 0x30;
	}
};

class SubExpression : public AbstractExpression
{
public:
	int Interpreter(int leftValue, string& context)
	{
		return leftValue - context[0] + 0x30;
	}
};

class EqualExpression : public AbstractExpression
{
public:
	int Interpreter(int leftValue, string& context)
	{
		if(!context.compare("="))
		{
			return leftValue;
		}
		else
		{
			return -1;
		}
	}
};

class CaculateExpression : public AbstractExpression
{
public:
	CaculateExpression()
	{
		pAddExp = new AddExpression();
		pSubExp = new SubExpression();
	}

	int Interpreter(int leftValue, string& context)
	{
		string rightValue = context.substr(1,1);
		switch (context[0])
		{
			case '+':
				return pAddExp->Interpreter(leftValue, rightValue);
			case '-':
				return pSubExp->Interpreter(leftValue, rightValue);
			default:
				return -1;
		}
	}
private:
	AddExpression* pAddExp;
	SubExpression* pSubExp;
};

class Caculator
{
public:
	Caculator()
	{
		pCaculateExp = new CaculateExpression();
		pEqualExp = new EqualExpression();
	}

	int Caculate(string expression)
	{
		int result = expression[0] - 0x30;
		int i;
		string singleExpres = "";
		for(i = 1; i < expression.length()-1; i += 2)
		{
			singleExpres = expression.substr(i, 2);
			result = pCaculateExp->Interpreter(result, singleExpres);
		}
		singleExpres = expression.substr(i);
		return pEqualExp->Interpreter(result, singleExpres);
	}
private:
	CaculateExpression* pCaculateExp;
	EqualExpression* pEqualExp;
};

int main(int argc, char const *argv[])
{
	string expstr = "9+4-5+8-2-4=";	//为了简化代码，这里的表达式是正确的

	Caculator myCaculator = Caculator();

	cout << expstr.c_str() << myCaculator.Caculate(expstr) << endl;

	return 0;
}
