#pragma once
#include <iostream>
#ifndef QueueString_H
#define QueueString_H
struct NodeQS {
	std::string data;
	NodeQS* next;
};
class QueueString {
private:
	NodeQS* head;
	NodeQS* tail;
public:
	QueueString();
	~QueueString();
	bool isEmpty();
	void enqueue(const std::string);
	const std::string dequeue();
	const std::string next();
};
#endif // !QueueString_H
