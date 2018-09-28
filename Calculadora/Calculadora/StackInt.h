#pragma once
#pragma once
#ifndef StackInt_H
#define StackInt_H
#include <iostream>
struct NodeInt {
	int data;
	struct NodeInt* next;
};
class StackInt {
private:
	NodeInt* top;
public:
	StackInt();
	~StackInt();
	bool isEmpty();
	void push(const int _data);
	const int pop();
	const int peek();
};
#endif // !StackInt_H