#ifndef myQueue_H
#define myQueue_H
#define MAX 1000

class myQueue
{
    public:
        myQueue();
        bool push(int x);
        int pop();
        bool isFull();
        bool isEmpty();
        void print();
    private:
        int rear, front;
        int holder[MAX];
};

#endif // myQueue_H
