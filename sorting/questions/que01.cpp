//Given an array with N distinct ele, conert the given array to a form where all ele are in the range from 0 to n-1. The order of ele is same i.e 0 is placed in the place of the smallest ele ,1 at second smallest and ... n-1 at largest ele place
//ex-> i/p arr=[19 , 12 , 23 , 8 , 16]->o/p [3,1,4,0,2]
//que replace 0 to n-1
#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main(){
    int arr[]={19,12,23,8,16};
    cout<<"Entered arr is:";
    for(auto a:arr){
        cout<<a<<" ";
    }
    cout<<endl;
    int n=sizeof(arr)/sizeof(arr[0]);
    //now find min and replace it by 0 then second min replace by -1 and so on ,after all replaced just multiply the arr ele by -1 , but but what if negative ele is already present in the arr so this approach will be wrong
    //so now create an other arr of same size visited or not visited
    vector<int> v(n,0); //0 means not visited
    int x=0; //value to insert in ans arr
    for(int i=0;i<n;i++){ //traverse in arr
        int min=INT_MAX;
        int mindx=-1;
        for(int j=0;j<n;j++){ //traverse in vector
            if(v[j]==1) continue;
            else{
                if(arr[j]<min){
                    min=arr[j];
                    mindx=j;
                }
            }
        }
        arr[mindx]=x;
        v[mindx]=1; //visited
        x++;
    }
    cout<<"The replaced arr is:";
    for(auto a:arr){
        cout<<a<<" ";
    }
}