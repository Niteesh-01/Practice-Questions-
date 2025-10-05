//creating own linked list
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
class Linkedlist{
public:
    int size;
    Node* head;
    Node* tail;
    Linkedlist(){
        size=0;
        head=NULL;
        tail=NULL;
    }
    // till now an empty linkedlist created
    //now a function to add nodes toend of the ll
    void insertAthead(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        if(size>0){
            temp->next=head;
            head=temp;
        }
        size++;
    }
    //now to insert at end
    void insertAtend(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        if(size>0){
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    //to print the entered ll
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Linkedlist ll;
    ll.insertAthead(10);
    ll.display();  //10
    ll.insertAthead(5);
    ll.display();  //5 10
    ll.insertAtend(15);
    ll.display();  //5 10 15
    //we can also print its size
    cout<<"Size of ll is:"<<ll.size<<endl; //Size of ll is:3
}