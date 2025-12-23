//to print all possible subsets of a given array
#include<iostream>
#include<vector>
using namespace std;

//recursive fun to calculate subset
void subset(vector<int> &a,vector<int> &ans,int idx){
    if(idx==a.size()){
        for(int val:ans){
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }

    //include
    ans.push_back(a[idx]);
    subset(a,ans,idx+1);
    ans.pop_back(); //backtrack

    //exclude
    subset(a,ans,idx+1);
}
int main(){
    vector<int> v={1,2,3};
    vector<int> ans;
    subset(v,ans,0);
}