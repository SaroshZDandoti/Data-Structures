#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Node
{
    public:
    Node *lchild;
    int data;
    Node *rchild;
} *root = NULL;
// root is already globally accessible

void Insert (int key)
{
    Node *t = root;
    Node *r ,*p;

    if(root == NULL)
    {
        p = new Node();
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while(t!=NULL)
    {
        r = t;
        if(key < t->data)
         t = t->lchild;
        else if (key > t->data)
          t = t->rchild;
        else 
        return;
    }
    p = new Node();
    p->data = key;
    p->lchild = p->rchild = NULL;

   if (key < r->data)
       r->lchild = p;
   else
      r->rchild = p;


}

void Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);

    }
}

 Node * Search(int key)
{
  Node *t=root;

    while(t!=NULL)
    {
    if(key==t->data)
    return t;
    else if(key<t->data)
    t=t->lchild;
    else
    t=t->rchild;
    }
    return NULL;
}

int Height( Node *p)
{
    int x,y;

    if(p==NULL)return 0;

    x=Height(p->lchild);
    y=Height(p->rchild);
    
    return  x > y ? x+1 : y+1;
}

 Node *InPre( Node *p)
{
    while( p && p->rchild!=NULL)
    p=p->rchild;

    return p;
}

struct Node *InSucc(struct Node *p)
{
    while(p && p->lchild!=NULL)
    p=p->lchild;

 return p;
}

 Node *Delete( Node *p,int key)
{
   Node *q;

    if(p==NULL)
    return NULL;

 if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
        root=NULL;
        free(p);
        return NULL;
    }

    if(key < p->data)
       p->lchild=Delete(p->lchild,key);
    
    else if(key > p->data)
       p->rchild=Delete(p->rchild,key);
    
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }

    }
 return p;
}



int main()
{
  Node *temp;

  Insert(10);
  Insert(5);
  Insert(3);
  Insert(20);
  Insert(15);
  Insert(9);
  
  // Delete(root,20);


  Inorder(root);
  printf("\n");

   
  temp=Search(2);

    if(temp!=NULL)
    printf("element %d is found\n",temp->data);
    else
    printf("element is not found\n");



  return 0;
}
