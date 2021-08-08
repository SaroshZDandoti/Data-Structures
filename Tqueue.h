#ifndef Tqueue_h
#define Tqueue_h



#include <iostream>
using namespace std;

class Node 
{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};


class Queue
{
  private:
   int front;
   int rear;
   int size;
   Node **Q;

public:
Queue(){
    front = rear = -1 ;
    size = 20;
    Q = new Node*[size];
}
Queue(int size){ front=rear=-1; this->size=size; Q=new Node*[this->size]; }
  
  void enqueue(Node *x);
  Node* dequeue();
  void Display();
  int isEmpty(){ return front == rear; }
};

void Queue :: enqueue(Node *x){
    if (rear == size )
    printf("Queue Full\n");

    else {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue :: dequeue()
{ 
    Node* x = NULL;
    if (front == rear)
    printf("Queue is Empty\n");
    else{
        x = Q[front + 1];
        front ++;
    }
    return x;
}

void Queue :: Display()
{
    for(int i = front +1 ; i<=rear ;i++)
       printf("%d " , Q[i]);

    printf("\n");
}


#endif