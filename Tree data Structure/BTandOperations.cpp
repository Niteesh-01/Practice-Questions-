//Binary tree and some operations
#include<iostream>
#include<climits>
using namespace std;
class Node{ //on leetcode TreeNode
public:
    int val;
    Node* left;
    Node* right;
    Node(int v){
        val=v; //also this->val=v
        left=right=nullptr; //or NULL
    }
};
//to display it using recursion
void Display(Node* head){ //head that is root
    if(head==nullptr) return;
    cout<<head->val<<" ";
    Display(head->left);
    Display(head->right); //if left ko pahle likhe then o/p=1 2 4 5 3 6 7 i.e preorder traversal
    //Display(head->left); //left ko bad me call kre then o/p=1 3 7 6 2 5 4 i.e phle right ke sare nodes print hinge then left wale
}

//to find the sum of all the nodes of the tree
int Sum(Node* head){
    //concept of left recursion and right recursion
    if(head==nullptr) return 0;
    // int ans=head->val + Sum(head->left) + Sum(head->right);
    // return ans; 
    return head->val + Sum(head->left) + Sum(head->right);
}

//to find the size of the tree
int Size(Node* root){
    if(root==nullptr) return 0;
    return 1 + Size(root->left) + Size(root->right);
}

//find the max node of the given binary tree
int MaxVal(Node* root){ //max(a,max(b,c))
    if(root==NULL) return INT_MIN;
    int leftmax=MaxVal(root->left); //left max
    int rmax=MaxVal(root->right); //right max
    return max(root->val,max(leftmax,rmax)); //in every call the comparision is done here
}

//to find the min value of the tree
int MinV(Node* root){
    if(root==nullptr) return INT_MAX;
    int lmin=MinV(root->left);
    int rmin=MinV(root->right);
    return min(root->val,min(lmin,rmin));
}

//to find the product of all the nodes of the tree
int product(Node* root){
    if(root==NULL) return 1;
    return root->val * product(root->left) * product(root->right);
}

//to find the levels of the tree
int Level(Node* root){
    if(root==nullptr) return 0;
    return 1 + max(Level(root->left),Level(root->right));
}

//to find height i.e level-1 or by fun
// int Height(Node* root){
//     if(root==nullptr) return 0;
//     int lheight=1 + Height(root->left);
//     int rheight=1 + Height(root->right);
//     return max(lheight,rheight)-1;
// }  //wrong answer

int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    //now connecting nodes so that they can form tree
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    //now to display it given only root add (recursion)
    cout<<"Entered tree is:";
    Display(a);
    cout<<"Sum of the nodes of the given tree is:"<<Sum(a);
    cout<<"\nThe size of the tree is:"<<Size(a);

    //add a new node to the tree ,to left of g
    Node* h=new Node(10);

    g->left=h;
    cout<<"\nSum:"<<Sum(a);
    cout<<"\nSize:"<<Size(a); 
    //to find max/min of the tree
    cout<<"\nMax node val of the tree:"<<MaxVal(a);
    cout<<"\nMin node val of the tree:"<<MinV(a);

    //product of all nodes
    cout<<"\nProduct of the all nodes of given tree:"<<product(a);

    //level and height of the tree
    cout<<"\nLevel of the given tree:"<<Level(a);
    //cout<<"\nHeight of the given tree:"<<Height(a);
}