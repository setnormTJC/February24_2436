#include"MyStack.h"


#include<iostream> 
#include<stack> 
#include<queue> 


struct PokerCard
{
	std::string suit; //clubs, diamonds, hearts, etc. 
	std::string value; //Ace, 2, 3, ... Jack, Queen, King
};

/*NOTE the pass by value (not reference) -> makes a COPY of the stack */
void printStackOfCards(/*const */std::stack<PokerCard> stackOfCards)
{
	while (!stackOfCards.empty())
	{
		std::cout << stackOfCards.top().value << " of "
			<< stackOfCards.top().suit << "\n";

		stackOfCards.pop(); 
	}
}


void demoStdStackUse()
{
	PokerCard someCard{ "Diamonds", "Jack" };
	PokerCard someOtherCard{ "Clubs", "Deuce" };
	PokerCard finalCard{ "Spades", "Ten" };

	std::stack<PokerCard> stackOfCards; //=
	//{   //this doesn't work!
	//	someCard, 
	//	someOtherCard, 
	//	finalCard
	//}

	stackOfCards.push(someCard);
	stackOfCards.push(someOtherCard);
	stackOfCards.push(finalCard);

	printStackOfCards(stackOfCards);

	std::cout << "Now, after printing, the TOP element is: "
		<< stackOfCards.top().suit << " of " << stackOfCards.top().value << "\n";

}

int main()
{
	using namespace MySpace; 
	//StackAbstractDataType attemptAtAStackObject; 
	ArrayBasedStack someStackOfLetters; //instantiate an object of that class


	try
	{
		someStackOfLetters.push('a');
		someStackOfLetters.push('b');
		someStackOfLetters.push('c');
		someStackOfLetters.push('d');
		someStackOfLetters.push('e');

		someStackOfLetters.pop(); //removes 'e';
		someStackOfLetters.pop(); //removes 'd': 

		someStackOfLetters.push('z'); 

	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}