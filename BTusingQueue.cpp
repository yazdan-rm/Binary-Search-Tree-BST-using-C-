#include<iostream>
#include<queue>


class Node
{
    public:
        Node* lchild;
        int data ;
        Node* rchild;
};

class BinaryTree
{
    private:
        Node* root;
    public:
        BinaryTree(){root = nullptr;}
        Node* createBT();
        void preorder(Node * p);
        void postorder(Node* p);
        void inorder(Node* p);
        void levelorder(Node* p);
        int  Height(Node* root);
};

Node* BinaryTree::createBT()
{
    Node* p,*t;
    int x;
    std::queue< Node *> q;
    std::cout<<"Enter root value :\n";
    std::cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = t->rchild = nullptr;
    q.push(root);  // enqueue
    while(!q.empty())
    {
        p = q.front();
        q.pop(); // dequeue
        std::cout<<"Enter lchild "<<p->data <<" : \n";
        std::cin>>x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.push(t);
        }
        std::cout<<"Enter rchild "<<p->data <<" : \n";
        std::cin>>x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.push(t);
        }
    }
    return root;
}

void BinaryTree::preorder(Node* p)
{
    if(p)
    {std::cout<<p->data<<" ";
    preorder(p->lchild);
    preorder(p->rchild);}
}

void BinaryTree::inorder(Node* p)
{
    if(p)
    {inorder(p->lchild);
    std::cout<<p->data<<" ";
    inorder(p->rchild);}
}

void BinaryTree::postorder(Node* p)
{
    if(p)
    {postorder(p->lchild);
    postorder(p->rchild);
    std::cout<<p->data<<" ";}
}

void BinaryTree::levelorder(Node* p)
{
    std::queue<Node *> q;
    std::cout<<root->data<<" ";
    q.push(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();
        if(root->lchild)
        {
            std::cout<<root->lchild->data<<" ";
            q.push(root->lchild);
        }
        if(root->rchild)
        {
            std::cout<<root->rchild->data<<" ";
            q.push(root->rchild);
        }
    }
    
}

int BinaryTree::Height(Node * root)
{
    int x = 0,y = 0;
    if(root == NULL)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if(x > y)
        return x + 1;
    else
        return y  + 1;
}


int main()
{
    BinaryTree bt;
    Node * root;
    root = bt.createBT();
    bt.preorder(root);
    std::cout<<"\n";
    bt.postorder(root);
    std::cout<<"\n";
    bt.inorder(root);
    std::cout<<"\n";
    bt.levelorder(root);
    std::cout<<"\nHeight of tree is < ^ ^ > : "<<bt.Height(root);
}