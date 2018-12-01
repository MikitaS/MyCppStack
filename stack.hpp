#pragma once


class StackElement
{
public:
	StackElement();
	StackElement(size_t elem, StackElement * next); 
	~StackElement();
	
	StackElement * take(int * am) const;
	StackElement * take() const;
	int getvalue() const;
	
private:
	StackElement * next;
	int amount;
};

class Stack : public StackElement
{
public:
	Stack();
	
	/* creates copy of given stack*/
	Stack(Stack const & stack);
	
	/* destructs stack and all alocated memory*/
	~Stack();
	
	/* return last element and destructs it*/
	int pop();
	
	/*creates new stack element*/
	void push(int elem);
	
	/*returns current size of stack*/
	size_t size() const;
	
	/*returns true if stack is empty*/ 
	bool is_empty() const;
	
	/*copyes given stack to current*/
	Stack & operator = (Stack const & stack);
	
private:
	StackElement * last;
	size_t counter;
};


