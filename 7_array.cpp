#include<iostream>
using namespace std;

int main(){

    int num[4]={1,2,3,45};

    for(int i=0;i<sizeof(num)/sizeof(num[0]);i++){
        cout<<num[i]<<endl;
    }
    return 0;
}