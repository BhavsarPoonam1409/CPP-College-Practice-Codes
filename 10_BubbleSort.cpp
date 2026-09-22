#include<iostream>
using namespace std;

void bubble_sort(int *num,int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(num[j]>num[j+1]){
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
}

int main(){

    int num[5]={2,6,3,9,0};
    //20/4  sizeof(num) = total size and sizeof(num[0]) 2 bytes count memory
    
    int size=sizeof(num)/sizeof(num[0]);
    bubble_sort(num,size);

    for(int i=0;i<size;i++){
        cout<<"Element "<<i+1<<" :"<<num[i]<<endl;
    }
    return 0;
}