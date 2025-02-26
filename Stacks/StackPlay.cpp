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

void demoMyStackUse()
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

		//Code below added after lecture: 
		someStackOfLetters.pop(); //removes 'e';
		someStackOfLetters.pop(); //removes 'd': 

		someStackOfLetters.push('z');

		std::cout << "Current top: " << someStackOfLetters.peek() << "\n";
		std::cout << "\n\n";
		//now print the entire stack: 
		while (someStackOfLetters.isEmpty() == false)
		{
			std::cout << someStackOfLetters.peek() << "\n";
			someStackOfLetters.pop();
		}
	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

/*
NOTE: this function is currently limited to only parentheses and brackets (, [
...add other "grouping symbols" if desired
*/
bool closeSymbolMatchesOpenSymbol(const char openSymbol, const char closeSymbol)
{
	if (openSymbol == '(' && closeSymbol == ')')
	{
		return true; 
	}

	else if (openSymbol == '[' && closeSymbol == ']')
	{
		return true; 
	}

	else
	{
		return false; 
	}
}

/*"Basic" syntax parsing is one well-known application of the stack data structure*/
bool isBalancedExpression(const std::string& theExpression)
{
	std::stack<char> openSymbolStack; //why not "closeSymbolStack"? 

	for (int i = 0; i < theExpression.size(); ++i)
	{
		//std::cout << theExpression[i] << "\n";
		if (theExpression[i] == '(' || theExpression[i] == '[')
		{
			openSymbolStack.push(theExpression[i]);
		}

		else if (theExpression[i] == ')' || theExpression[i] == ']')
		{
			//check to see if openSymbolStack's top character MATCHES:
			if (openSymbolStack.empty()) 
			{
				return false; // Unmatched closing symbol
			}

			char theOpenSymbolOnStacksTop = openSymbolStack.top(); 

			if (closeSymbolMatchesOpenSymbol(theOpenSymbolOnStacksTop, theExpression[i]) == false)
			{
				return false;
			}

			else
			{
				if (!openSymbolStack.empty()) {
					openSymbolStack.pop();
				}
				else {
					return false;
				}
				 
			}
		}

		else
		{
			//do nothing (current character is not a grouping symbol)
		}
	}

	if (openSymbolStack.empty())
	{
		return true; 
	}
	else
	{
		return false; 
	}

}

int main()
{
	using namespace MySpace; //homage to the "first" social media website

	std::string firstUNBalancedExpression = "((5+2)/7"; //scenario 1: open ( not matched by close  
	std::string secondUNBalancedExpression = "((5+2)/7))"; //scenario 2: close ) not matched by open  
	std::string thirdUNBalancedExpression = "((5+2)/7]"; //scenario 3: ... open matched by "wrong" close symbol

	std::string BalancedExpression = "((5 + 2)/7)";

	std::string theCurrentTestCase = secondUNBalancedExpression;
	std::cout << "Is " << theCurrentTestCase << "balanced? " 
		<< std::boolalpha << isBalancedExpression(theCurrentTestCase) << "\n\n";



}