#include <iostream>
#include<stdio.h>
#include "Tqueue.h"

using namespace std;

class Tree
{
    Node *root;

    public:
    Tree(){ root = NULL; }
    void createTree();
    void Preorder(){ Preorder(root); }
    void Preorder(Node  *p);
    void Postorder(){Postorder(root);}
    void Postorder(Node *p);
    void Inorder(){Inorder(root);}
    void Inorder(Node *p);
    int Height(){return Height(root);}
    int Height(Node *root);
};

void Tree:: createTree()
{
    Node *p , *t;
    int x;
    Queue q(100);

    x = 10;

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;

    q.enqueue(root);

    while( !q.isEmpty() )
    {
        p = q.dequeue();
        printf("Enter left child of %d ",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = new Node();
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("Enter right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}


void Tree :: Preorder (Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        Preorder( p->lchild );
        Preorder( p->rchild );
    }
}


void Tree::Inorder( Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}



void Tree::Postorder( Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

int Tree :: Height(Node *root)
{
    int x=0,y = 0;

    if(root == NULL)
    return 0;

    x= Height(root->lchild);
    y= Height(root->rchild);

    if(x>y)
      return  x + 1;
    else
       return y + 1;
}

int main()
{
    Tree t;
    t.createTree();

    cout << " Preorder ";
    t.Preorder();
    cout << endl;

    cout<<"Inorder ";
    t.Inorder();
    cout<<endl << endl;

    cout << "Height " << t.Height();;
    
    cout<<endl;
  
  return 0;
}