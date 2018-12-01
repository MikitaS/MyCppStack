#include <cstdio>
#include <cstdlib>
#include <assert.h>
#include <iostream>
#include "stack.hpp"

using namespace std;
const int StackSize = 10000000;

int testStackDestructor();
int testStack();
int testStackWithOperatorCopy();
int testStackWithConstructorCopy();

int testStackWithOperatorCopy()
{
	Stack exp;
	int i = 0, value = 0;
	
	for(; i <= StackSize; i++)
	{
		exp.push(i);
	}
	
	Stack exp1;
	exp1 = exp;
	
	for(i = StackSize; i > 0; i--)
	{
		
		value = exp1.pop();
		if(value != i)
		{
			return 0;
		}
	}
	return 1;
}

int testStackWithConstructorCopy()
{
	Stack exp;
	int i = 0, value = 0;
	
	for(; i <= StackSize; i++)
	{
		exp.push(i);
	}
	Stack exp1(exp);
	
	for(i = StackSize; i > 0; i--)
	{
		value = exp1.pop();
		if(value != i)
		{
			return 0;
		}
	}
	return 1;
}

int testStack()
{
	Stack exp;
	int i = 0, value = 0;
	
	for(; i <= StackSize; i++)
	{
		exp.push(i);
	}
	
	for(i = StackSize; i > 0; i--)
	{
		
		value = exp.pop();
		if(value != i)
		{
			return 0;
		}
	}
	return 1;
}

int testStackDestructor()
{
	Stack exp;
	int i = 0, value = 0;
	
	for(; i <= StackSize; i++)
	{
		exp.push(i);
	}
	
	return 1;
}

int main()
{
	if(testStack())
		cout <<  " stack test passed correct\n";
	else 
		cout << "stack test failed\n";
		
	if(testStackWithOperatorCopy())
		cout <<  "copy operator test passed correct\n";
	else 
		cout << "copy operator test failed\n";
	
	if(testStackDestructor())
		cout << "destructor's test done\n";
		
	if(testStackWithConstructorCopy())
		cout <<  "constructor copy test passed correct\n";
	else 
		cout << "constructor copy test failed\n";
	
	return 0;
}
