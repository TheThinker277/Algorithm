#include<iostream>
#include <stdlib.h>
#include<stack>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    int left_thread,right_thread;
    
    Node()//default constructor
    {
        data=0;
        right=left=NULL;
        left_thread=right_thread=0;//left _thread and right_thread =1 means they are pointing towards ancestors , whereas =0 means they are pointing towards childs
    }

    Node(int n)//constructor
    {
        data=n;
        right=left=NULL;
        left_thread=right_thread=0;
    }
};


class TBT : public Node
{   
    
    public: 
    Node *root,*temp,*head;
    TBT()
    {
        head=new Node();//Creating the Dummy Node
        root=NULL;
        temp=NULL;
    }
    void Create();
    void inorder();
    void preorder();
    void postorder();
   
};
void TBT::Create()
{

    Node *newnode;
    int num;
    int k=0;
    do
    {
        cout<<"\n Enter the data :";
        cin>>num;
        newnode = new Node(num);
        if (root==NULL)
        {
            root=newnode;//It was empty 
            newnode->left=newnode->right=head;//to initialize the root pointing towards the head pointer , first step

        }
        else{
            
            temp=newnode;
            while (1)
            {
                if(num<temp->data){
                    if (temp->left_thread==0)
                    {
                        newnode->left=temp->left;//Step 2 where the root->left == NULL is now pointing towards head
                        temp->left=newnode;
                        temp->left_thread=1;//To establish that it is pointing towards head
                        break;
                    }
                    else
                        temp=temp->left;
                }
                else
                {
                    if (temp->right_thread==0)
                    {
                        newnode->right=temp->right;//Step 3 where the root->left == NULL is now pointing towards head
                        temp->right=newnode;
                        temp->right_thread=1;//To establish that it is pointing towards head
                        break;
                    }
                    else
                        temp=temp->right;
                }
            
            }
                   
        }
        cout<<"To continue press 0 , Else press anything";
        cin>>k; 
     
    } while (k==0);  
}
void TBT::inorder(){
    temp=root;
    do
    {
        while (temp->left_thread==1)//move to leftmost node
            temp=temp->left;
        cout<<temp->data;
        while ((temp->right_thread==0 )&&(temp!=head))//temp has a right child
            temp=temp->right;
        if(temp==head)
            return;
        temp=temp->right;        
    } while (temp!=head);
    /*
    while(temp!=dummy)
   {
            while(temp->lth==1)
             temp=temp->left;
   cout<<"  "<<temp->data;
   while(temp->rth==0)
   {
   temp=temp->right;
            if(temp==dummy)
             return;
            cout<<"  "<<temp->data;
   }
   temp=temp->right;
  }
    */
    
}

void TBT::preorder(){
    temp=root;
    while (1)
    {
        cout<<temp->data;
        while (temp->left_thread==1)//move to leftmost node
            temp=temp->left;
            cout<<temp->data;
        if(temp->right_thread==0)
            temp=temp->right;
        else
        {
            while(temp->right_thread==1){

                if(temp->right==head)
                    return;
                temp=temp->right;
            }
            if(temp->right_thread==1)
                temp=temp->right;
        }
            
    }
   
}
void TBT::postorder(){
    temp=root;
    do
    {
        while (temp->left_thread==1)//move to leftmost node
            temp=temp->left;
        while ((temp->right_thread==0 )&&(temp!=head))//temp has a right child
            temp=temp->right;
        if(temp==head)
            return;
        cout<<temp->data;
        temp=temp->right;        
    } while (temp!=head);
    
}




int main(){
    TBT t;
    int k=0;
    cout<<"Welcome to Threaded Binary Tree Using Linking  by Hridyesh ";
    do
    {
        int ch;
        cout<<"Press \n 1.Create a Threaded Binary  Tree \n 2.Inorder Traversal \n 3.PreOrder Traversal \n 4.PostOrder Traversal \n 5.To Quit \n";

        cin>>ch;
        int number;

        switch (ch)
        {
            case 1:
                    t.Create();
                    break;
           
            case 2:
                    t.inorder();
                    break;
            case 3:
                    t.preorder();
                    break;
            case 4:
                    t.postorder();
                    break;
                    
            case 5:
                    k=1;
                    break;

        }
      

    } while (k==0);
    return 0;
}
