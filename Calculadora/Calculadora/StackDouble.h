#pragma once
#ifndef StackDouble_H
#define StackDouble_H
#include <iostream>
struct NodeDouble {
	double data;
	struct NodeDouble* next;
};
class StackDouble {
private:
	NodeDouble* top;
public:
	StackDouble();
	~StackDouble();
	bool isEmpty();
	void push(const double);
	const double pop();
	const double peek();
};
#endif // !StackDouble_H
