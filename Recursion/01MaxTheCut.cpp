//maximize the cuts , That is given length and 3 numbers you can cut the length in these given nums return the max number of cuts
#include<iostream>
#include<climits>
using namespace std;

int MaxCut(int n,int x,int y,int z){
    if(n==0) return 0;
    if(n<0) return INT_MIN;
    int first=1+MaxCut(n-x,x,y,z);
    int second=1+MaxCut(n-y,x,y,z);
    int third=1+MaxCut(n-z,x,y,z);
    return max(first,max(second,third));
}
int main(){
    int n;
    cout<<"Enter the length:";
    cin>>n;
    int x,y,z;
    cout<<"Enter the cut size:x , y, z (respectively):";
    cin>>x>>y>>z;
    cout<<"The max number of cuts:"<<MaxCut(n,x,y,z);

}