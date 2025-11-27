//Creating Binary tree using queue
#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;

    Node(int v){
        data=v;
        left=right=NULL;
    }
};
int main(){
    int x ,first,second;
    cout<<"Enter the root ele:";
    cin>>x;
    queue<Node*> q;
    Node* root=new Node(x);
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"Enter the left child "<<temp->data<<":";
        cin>>first;
        if(first!=-1){
            temp->left=new Node(first);
            q.push(temp->left);
        }
        cout<<"Enter the right child "<<temp->data<<":";
        cin>>second;
        if(second!=-1){
            temp->right=new Node(second);
            q.push(temp->right);
        }
    }
}