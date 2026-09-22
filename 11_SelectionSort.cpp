#include<iostream>
using namespace std;
void selection_sort(int *num,int size){
    int temp;
    for(int i=0;i<size-1;i++){
        int min=num[i];
        int min_index=i;
        for(int j=i+1;j<size;j++){
            if(num[j]<min){
                min=num[j];
                min_index=j;
            }
        }
        temp=num[i];
        num[i]=num[min_index];
        num[min_index]=temp;
    }
}
int main(){
    int num[5];
    int size=sizeof(num)/sizeof(num[0]);
    for(int i=0;i<size;i++){
        cout<<"enter element:";
        cin>>num[i];
    }
    selection_sort(num,size);
    for(int i=0;i<size;i++){
        cout<<"Element is:"<<num[i]<<endl;
    }
    return 0;
}