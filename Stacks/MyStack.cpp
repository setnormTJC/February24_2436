#include "MyStack.h"
#include <exception>

void MySpace::ArrayBasedStack::push(char characterToPushOntoStack)
{
	if (topIndex > maxStackSize - 2)
	{
		throw std::exception("Stack overflow!");
	}

	topIndex++; //when the Stack gets created initially, this value = -1
	theStackData[topIndex] = characterToPushOntoStack; 
}

void MySpace::ArrayBasedStack::pop()
{

}
