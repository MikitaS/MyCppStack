#include <cstdio>
#include <cstdlib>
#include <assert.h>
#include <iostream>
#include "stack.hpp"

StackElement::StackElement() : next(0), amount(0)
{  
} 

StackElement::StackElement(size_t elem, StackElement * next) : amount(elem)
{ 
	 this->next = next;
}

StackElement::~StackElement()
{ 
	this->amount = 0;
	this->next = 0;
}

StackElement * StackElement :: take(int * am) const
{
	assert(am);
	*am = this->amount;
	return this->next;
}

StackElement * StackElement :: take() const
{
	return this->next;
}

int StackElement :: getvalue() const
{
	return this->amount;
}



Stack::Stack() : last(0), counter (0)
{ 

}

Stack::Stack(Stack const & stack) : counter(0), last(0)
{
	*this = stack;
}

Stack::~Stack()
{
	StackElement * copy = 0;
	while(this->last)
	{
		copy = this->last;
		this->last = copy->take();
		delete copy;
	}
	delete last;
	this->counter = 0;
}

size_t Stack::size() const
{
	return this->counter;
}

bool Stack::is_empty() const
{
	if(!counter)
		return true;
	else 
		return false;
}

void Stack::push(int elem)
{
	this->last = new StackElement(elem, this->last);
	this->counter ++;
}

int Stack::pop()
{
	if(!this->counter)
		return 0;
	int value = this->last->getvalue();
	StackElement * copy = this->last;
	
	this->last = copy->take();
	delete copy;
	this->counter--;
	
	return value;
}

Stack & Stack::operator = (Stack const & stack)
{
	Stack newstack;
	StackElement * prev = stack.last->take();
	
	newstack.push(stack.last->getvalue());
	
	while(prev)
	{
		newstack.push(prev->getvalue());
		prev = prev->take();
	}
	
	while(!newstack.is_empty())
	{
		this->push(newstack.pop());
	}
	
	return *this;
}






