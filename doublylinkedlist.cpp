#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class DoublyNode{
    public:
    DoublyNode *prev;
    int data;
    DoublyNode *next;
} *first = NULL;

void create(int array[] , int length)
{
    int i;
    DoublyNode *t;
    DoublyNode *last;

    first = new DoublyNode();

    first->data = array[0];
    first->next = NULL;
    first->prev = NULL;
    last = first;

    for(i =1;i<length;i++)
    {
        t = new DoublyNode();
        t->data = array[i];
        last->next = t;
        t->prev = last;
        last = t;

    }

}

void display(DoublyNode *p)
{
   while(p!=NULL)
   {
       cout << " " << p->data;
       p = p->next;
   }
   
}

int count(DoublyNode *p)
{   int c = 0;
    while(p!=NULL)
    {
        p = p->next;
        c++;
    }
    return c;
}

void Insert(DoublyNode *p, int position, int data)
{
    DoublyNode *t = NULL;

    t = new DoublyNode();
    t->data = data;

   if (position < 0 || position > count(p))
     return ;

   if(position == 0)
   {
     t->next = first;
     first->prev = t;
     first = t;
   }
   else{
       int i = 0;
       for(i = 0; i< position -1 ;i++)
       {
           p = p->next;
       }

       t->next  =p->next;
       p->next->prev = t;
       p->next = t;
       t->prev = p;
   }

}

int deleteNode(DoublyNode*p , int position)
{
    DoublyNode *t = NULL;
    int x = 0;
    if (position < 0 || position > count(p))
     return 0;

    if(position == 1)
    {
        t = p;
        x = p->data;
        p = p->next;
        p->prev = NULL;
        free(t);
        first = p;
    } 
    else{
      int i ;
      for (i = 0; i < position - 1 ; i++)
      {
          p = p->next;
      }
      
      t = p;
      x = p->data;
      p->prev->next = p->next;
      p->next->prev = p->prev;
      free(t);

    }
  return x;
}

void reverse(DoublyNode *p)
{   
    while(p->next)
    {
       p = p->next;
       p->prev->next = p->prev->prev;
       p->prev->prev = p;
    }

    p->next = p->prev;
    p->prev = NULL;
    
    first = p;
}

int main (){

   int arr[] = {2,4,6,8,12,45,59,78};

   create(arr,8 );

   cout << "The Doubly Linked List is \n ";
   display(first);
/*
  cout<< "\nInserting val\n";
  Insert(first, 2 , 100);
  display(first);

  cout << "\nInserting at head \n";
  Insert(first, 0 ,1000);
display(first);
 
cout << "\ndeleting node :  \n"<< deleteNode(first, 1) << "\n";

  display(first);
*/


cout<< "\n The Reversed Doubly Linked List is\n";
reverse(first);
display(first);


}
