//creating nodes 
#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int v){
        val=v;
        this->next=NULL;
    }
};
int main(){
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(40);
    cout<<a->val<<endl;
    cout<<b->val<<endl;
    cout<<c->val<<endl;
    cout<<d->val<<endl;

    //now to create linked list for above nodes we need to connect them together i.e
    a->next=b;
    b->next=c;
    c->next=d;
    //now we can fetch any value by using node a i.e
    cout<<a->next->next->val<<endl; //i.e c=30
}