#include<iostream>
using namespace std;

int binary_search(int *num,int size,int search){
    int low,high,mid;
    low=0,high=size;
    while(low<=high){
        mid=low+(high-low)/2;
        if(search==num[mid]){
            return mid;
            break;
        }
        else if(search>num[mid]){
            low=mid+1;
        }
        else if(search<num[mid]){
            high=mid-1;
        }
    }

    return -1;
}

int main(){

    int num[6]={1,2,3,4,5,6};

    int size,search;
    cout<<"Enter Search element";
    cin>>search;

    size=sizeof(num)/sizeof(num[0]);

    int result=binary_search(num,size,search);
    if(result==-1){
        cout<<"Elemeent Not found";
    }
    else{
        cout<<"element founded with "<<result+1<<" POSition";
    }


    

    return 0;
}