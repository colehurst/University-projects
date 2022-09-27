#include "myQueue.h"

myQueue::myQueue()
{
    //initialize the value of the rear and front indicator based on your implementation.
}


bool myQueue::push(int x)
{

    if(!isFull())
    {
        //Todo:
            //Check if the queue is full or not.

            //If so, insert an item into the back of the myQueue.
            //Update the value of the front indicator
            //Otherwise, print a meaningful error message
        return true;
    }
    else
    {
        //Todo: print a meaningfull message
        return false;

    }
}

int myQueue::pop()
{
     //Todo:
        //Remove the front item from the myQueue
        //Update the value of the rear indicator
}

bool myQueue::isFull()
{
    //Check if the myQueue still has empty space at its rear or the front.
}

bool myQueue::isEmpty()
{
    //Check if the myQueue is empty based on the value of the front and rear indicator.
}


void myQueue::print()
{
	//Todo: print all items of the myQueue.
	//Hint: use a variable to store a copy of the front value. itterate over the queue until you reached
	//to the rear element.
}
