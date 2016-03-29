// 四则运算.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <iostream>
#include <deque>
#include <string>
using namespace std;


//判断是否为括号
bool isPra(char c)
{
	if(c=='(' || c==')')
		return true;
	else 
		return false;
}


//获得符号的优先性
int getPri(char c)
{
	switch(c)
	{
	case'+':
	case'-':
		return 0;  //如果是+ -，返回0
		break;
	case'*':
	case'/':
		return 1;  //如果是* /，返回1
		break;
	case'(':
	case')':
		return -1;  //如果是( )，返回-1  (在没有遇到右括号，左括号不会被弹出)
		break;
	}
}

//判断符号的优先性
void check(char c,stack<char>& coll2,deque<char>& coll3)
{
	if(coll2.empty())
	{
		coll2.push(c);
		return;
	}
	if(isPra(c))
	{
		if(c=='c');
			coll2.push(c);
		else
		{
			//弹出所有元素直到遇到左括号
			while(coll2.top()!='(')
			{
				char ch =coll2.top();
				coll3.push_back(ch);
				coll2.pop();
			}

			//当遇到左括号时，左括号不加入coll3(后缀)
			coll2.pop();
		}

	}
	else   //如果不是括号
	{
		//取出栈顶元素，与当前符号进行优先性比较
		char sym = coll2.top();

		//比较两符号的优先性
		if(getPri(c)<=getPri(sym))
		{
			//如果c的优先性比栈顶符号小或者等于，弹出栈顶的元素
			coll2.pop();
			//c压入coll3
			coll3.push_back(sym);
			//递归调用check,比较当前符号c与下一个栈顶符号的优先性
			check(c,coll2,coll3);
		}
		else
		{
			//如果c比栈顶符号优先级打，c压入coll2中
			coll2.push(c);
		}
	}
}

//从coll中取出元素，分配元素到coll2,coll3中


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

