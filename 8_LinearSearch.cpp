#include<iostream>
using namespace std;

int linear_search(int *num,int size,int search_element){

    int i;

    for(i=0;i<size;i++){
        if(search_element==num[i]){
            break;
        }
    }

    return i;
}


int main(){

    int num[6];

    for(int i=0;i<sizeof(num)/sizeof(num[0]);i++){
        cout<<"Enter Array Element:";
        cin>>num[i];
    }

    int search;
    cout<<"Enter Searching Element";
    cin>>search;

    int size=sizeof(num)/sizeof(num[0]);

    int position=linear_search(num,size,search);

    if(position==size){
        cout<<"Element Not found";
    }
    else{
        cout<<"Element found with "<<position+1<<" Position";
    }



    return 0;
}