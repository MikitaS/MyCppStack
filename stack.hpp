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
	Stack(Stack const & stack);
	~Stack();
	
	
	int pop();
	void push(int elem);
	size_t size() const;
	bool is_empty() const;
	Stack & operator = (Stack const & stack);
	
private:
	StackElement * last;
	size_t counter;
};


