// ��������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <iostream>
#include <deque>
#include <string>
using namespace std;


//�ж��Ƿ�Ϊ����
bool isPra(char c)
{
	if(c=='(' || c==')')
		return true;
	else 
		return false;
}


//��÷��ŵ�������
int getPri(char c)
{
	switch(c)
	{
	case'+':
	case'-':
		return 0;  //�����+ -������0
		break;
	case'*':
	case'/':
		return 1;  //�����* /������1
		break;
	case'(':
	case')':
		return -1;  //�����( )������-1  (��û�����������ţ������Ų��ᱻ����)
		break;
	}
}

//�жϷ��ŵ�������
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
			//��������Ԫ��ֱ������������
			while(coll2.top()!='(')
			{
				char ch =coll2.top();
				coll3.push_back(ch);
				coll2.pop();
			}

			//������������ʱ�������Ų�����coll3(��׺)
			coll2.pop();
		}

	}
	else   //�����������
	{
		//ȡ��ջ��Ԫ�أ��뵱ǰ���Ž��������ԱȽ�
		char sym = coll2.top();

		//�Ƚ������ŵ�������
		if(getPri(c)<=getPri(sym))
		{
			//���c�������Ա�ջ������С���ߵ��ڣ�����ջ����Ԫ��
			coll2.pop();
			//cѹ��coll3
			coll3.push_back(sym);
			//�ݹ����check,�Ƚϵ�ǰ����c����һ��ջ�����ŵ�������
			check(c,coll2,coll3);
		}
		else
		{
			//���c��ջ���������ȼ���cѹ��coll2��
			coll2.push(c);
		}
	}
}

//��coll��ȡ��Ԫ�أ�����Ԫ�ص�coll2,coll3��


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

