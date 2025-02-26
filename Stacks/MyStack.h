#pragma once

namespace MySpace
{
	class StackAbstractDataType
	{
	protected:  //what does protected do? 
				//it gives CHILDREN CLASSES access (but main/client will NOT have access)

	//define what ALL stacks should be capable of: 
	virtual void push(char characterToPushOntoStack) = 0;  //this is a "pure" virtual function 
	virtual void pop() = 0; //virtual means children classes can override this method
	virtual char peek() = 0; 

	};

	//ftemplate<int maxStackSize>aasdfasdfasdfasdfasfasd
	class ArrayBasedStack : public StackAbstractDataType
	{
	private: 
		static const int maxStackSize = 5; //AKA: "capacity"
		int topIndex = -1; 
		//int currentStackSize; 
		//std::string  word; //""
		char theStackData[maxStackSize]; //this will consist of 5 uninitialized character values 
	public: 
		void push(char characterToPushOntoStack) override; 

		void pop() override;

		char peek() override; 

		//an extra function that is not "essential" for stacks: 
		bool isEmpty(); 
	};

	class LinkedListBasedStack
	{

	};
}


