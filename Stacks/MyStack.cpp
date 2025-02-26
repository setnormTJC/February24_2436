#include "MyStack.h"
#include <exception>

void MySpace::ArrayBasedStack::push(char characterToPushOntoStack)
{//peak
	if (topIndex >= maxStackSize - 1) //modified from topIndex > maxStackSize - 2 (which looks dumb)
	{
		throw std::exception("Stack overflow!");
	}

	topIndex++; //when the Stack gets created initially, this value = -1
	theStackData[topIndex] = characterToPushOntoStack; 
}

void MySpace::ArrayBasedStack::pop()
{
	if (topIndex == -1) //alternatively: if (isEmpty() == true)
	{
		throw std::exception("Stack UNDER-flow -> cannot pop from empty stack");
	}

	//must DECREMENT the topIndex; 
	topIndex--;
	//no "new" (dynamic memory allocation), so no need to "empty"/reinitialize the previous top position
}

char MySpace::ArrayBasedStack::peek()
{
	return theStackData[topIndex];
}

bool MySpace::ArrayBasedStack::isEmpty()
{
	if (topIndex == -1)
	{
		return true; 
	}
	else
	{
		return false; 
	}
}
