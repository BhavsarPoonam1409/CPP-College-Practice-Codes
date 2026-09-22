#include<iostream>
using namespace std;

void hello(){
    cout<<"This is a Hello Function\n";
}

int add(int n1,int n2){
    int sum=n1+n2;
    return sum;
}

int main(){

    int a,b;
    cout<<"Enter A and B\n";
    cin>>a>>b;

    hello();
    int result=add(a,b);
    cout<<"Result is:"<<result;
    return 0;
}