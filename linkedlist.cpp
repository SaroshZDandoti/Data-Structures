#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class  Node
{
    public:
    int data;
    Node *next;

} *first = NULL , *second = NULL , *third = NULL ;


void create (int A[] , int n)
{
    int i ; 
    Node *t , *last;
    
    first = new Node(); // head

    first->data = A[0];
    first->next = NULL;

    last = first;

    for(i = 1 ; i<n ; i ++)
    {
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        
        last->next = t;
        last =t;

    }

}

void create2 (int A[] , int n)
{
    int i ; 
    Node *t , *last;
    
    second = new Node(); // head

    second->data = A[0];
    second->next = NULL;

    last = second;

    for(i = 1 ; i<n ; i ++)
    {
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        
        last->next = t;
        last =t;

    }

}

void display (Node *p)
{
   while (p != NULL)
   {
       cout << " " << p->data;
       p = p->next;
   }
 
}

void displayRecursion( Node *p)
{
    if (p!= NULL)
     {
         cout << " " << p->data;
         displayRecursion(p->next);
         // To display the list in reverse switch the lines above , 
         // Recursion will occur fully and then backtrack and print the numbers then.
     }
}

    int count( Node *p)
    {
        int c = 0;

        while(p!=NULL)
        {
        c++;
        p = p->next;
        }
    
    return c;

    /* For recursion make if else and return count(p.next)+ 1 adding will be done when backtracked.
        Time : O(n) , Space: O(n)
    */
    }

int sum(Node *p)
{
    int a = 0;
    while(p!= NULL)
    {
       a= a + p->data;
       p = p->next; 
    }

    return a;
}

int max(Node *p)
{   // For min just change < , > signs
    int m = INT_MIN;
    while(p)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;      
    }
    return m;
}

//Searching

// Linear Search , return type node pointer because we are returning the P Node
Node* search(Node *p , int key)
{
   while(p!=NULL)
   {
      if (key == p->data)
        return p;
 
     p = p->next;
 
   }
   

   return 0;
   
}


// Move key node to first node Linear search

Node* MovetoFirst(Node *p , int key )
{
     Node *q = NULL;

     while(p!=NULL)
     {
           if(key == p->data)
           {  // keep a pointer just behind p so we can attach previous ele with next element
               q->next = p->next;
               p->next = first;
               first = p;   
               return p;
           }
           q = p;
           p = p->next;


     }
  return NULL;
}

void Insert(Node *p , int index , int x)
{
    Node *t;
    int i;
    
    if(index < 0 || index > count(p))
       return;

    t = new Node();
    t->data = x;

    if( index == 0)
    {
        t->next = first;
        first = t;
    }
    else {
        for ( i= 0; i < index -1 ; i++)
        {
           p= p->next;
           t->next = p->next;
           p->next= t;
        }
    }




}

void InsertedSorted(Node *p , int x)
{
   
   Node *t;
   Node *q;
   q = NULL;
   t = new Node();
   t->data = x;

   while(p && p->data < x)
   {
       q = p;
       p = p->next;
   }
   
   t->next = q->next;
   q->next = t;
     

}
 
 int deleteNode( Node *p , int index)
 {
    Node *q=NULL;
    int x=-1,i;

   if(index < 1 || index > count(p))
        return -1; 

     if(index ==1)
     {   
         q= first;
         x = first->data;
         first = first->next;
         free(q);   // deleting node
         return x;
     }
     else
     {
         for(i=0;i <index -1 ; i++){
             q = p;
             p = p->next;   
         }
         q->next = p->next;
         x = p->data;
         free(p);
         return x;

     }




 }

 int isSorted( Node *p)
{
   int x=-65536;
 
    while(p!=NULL)
    {
        if(p->data < x)
        return 0;

        x=p->data;
        p=p->next;
    }
    return 1;

}

int reverseList(Node *p , int length){
    int array[length];
    int i = 0;
    while(p != NULL)
    {
        array[i]  = p->data;
        p = p->next;
        i++;
    }
   p = first;
   i--;
   
   while(p!=NULL){
       p->data = array[i--];
       p = p->next;
   }
  return 0 ;
}

int reverseSlidingPointers(Node *p)
{
     Node *q = NULL;
     Node *r = NULL;
    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;

  return 0;
}

void reverseRecursion(Node *q , Node *p)
{
    if(p!=NULL)
    {
         reverseRecursion(p , p->next);
         p->next = q;
    }
    else
      first = q;
}

void concat(Node *p ,Node *q)
{
   third = p;

    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next =  q;
  //  second = NULL;
}

void Merge( Node *p, Node *q)
{
  Node *last;
 if(p->data < q->data)
 {
    third=last=p;
    p=p->next;
    third->next=NULL;
 }
 else
 {
        third=last=q;
        q=q->next;
        third->next=NULL;
 }
    while(p && q)
    {
        
    if(p->data < q->data){
        last->next=p;
        last=p;
        p=p->next;
        last->next=NULL;

    }
    else{
        last->next=q;
        last=q;
        q=q->next;
        last->next=NULL;

    }

    }
    if(p)
    last->next=p;
    if(q)
    last->next=q;

}


int main()
{
  int A[] = {3,5,7,10,23,38,45,52,76};

  create(A , 9);
  
   int B[] = {2,24,68,1023};
   create2(B , 4);
 
  cout << " Display normally: \n";
  display(first);

/*
  cout << "\nDisplay Recursively: \n ";
  displayRecursion(first);

  cout << "\n The count of LL: " << count(first);

  cout << "\n The sum of data is : " << sum(first);

  cout << "\n The Max of data is : " << max(first);

  cout << "\n The Search of data is : " << search(first , 34);



  cout << "\n The old Position of First" << first;

  cout << "\n Move key data to first Position (head) : " << MovetoFirst(first , 38);
  
  cout << "\n The new Position of First" << first;

  cout << "\n  Display normally: \n";
  display(first);

 cout << "\n Inserting Data : "  ;
  Insert( first , 2 , 100 );

 cout << " Display normally: \n";
  display(first);

 cout << "\n Inserting Data Sorting Data : \n"  ;
  InsertedSorted( first , 27 );

 cout << " Display normally: \n";
  display(first);

 cout << "\n Delete Data at index : \n"  ;
  deleteNode( first , 2 );

 cout << " Display normally: \n";
  display(first);


 if(isSorted(first))
        cout << "\n is Sorted \n";


 cout << "\n Reversing list ... \n ";
  reverseList(first , count(first));

  cout << "Reversed List is  \n";
  display(first); 


  cout << "\n Reverse Using Pointers: \n";
  reverseSlidingPointers(first);
  display(first);



  cout << " \n Concatinating two linked list \n";
  concat(first, second);
  display(third);
*/
  
  
  
  
  return 0;


  
}
