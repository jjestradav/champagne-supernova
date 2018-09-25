#pragma once
#ifndef StackChar_H
#define StackChar_H
#include <iostream>
struct NodeChar {
	char data;
	struct NodeChar* next;
};
class StackChar {
private:
	NodeChar* top;
public:
	StackChar();
	~StackChar();
	bool isEmpty();
	void push(const char _data);
	const char pop();
	const char peek();
};
#endif // !StackChar_H
