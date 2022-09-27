//cole hurst A04584613
#ifndef STACK_H
#define STACK_H
#define MAX 1000

template <class userType>
class myStack
{
    private:
    	int CurrentSize; //An indicator that contains the current size of the stack
    	userType holder[MAX];    //Maximum size of the stack
	public:
		myStack();
		bool push(userType x);
		userType pop();
		bool isEmpty();

};

template <class userType>
myStack::myStack()
{
    //Todo: initialize the value of the currentSize.
}

template <class userType>
bool myStack::push(userType x)
{
    if(isEmpty())
    {
		//Todo
			//Push the item x to myStack.
			//Update the value of the currentSize.
		return true;
	}
	else
	{
		//Todo:
			//print a meaningful error message
			return false;
	}
}

template <class userType>
userType myStack::pop()
{
	//Todo:
    	//Pop the currentSize element of the stack (e.g. x).
		//update the value of the currentSize.
		//return x.
}

template <class userType>
bool myStack::isEmpty()
{
    //Check if the size of the stack is still less than the MAX value.
}
#endif // STACK_H
