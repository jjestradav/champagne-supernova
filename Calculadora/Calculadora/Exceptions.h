#pragma once
#include <iostream>
class Exceptions{
public:
	virtual const std::string what() const throw() = 0;
	virtual ~Exceptions();
	virtual std::string toString() const  = 0;
};