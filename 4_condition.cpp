#include<iostream>
using namespace std;

int main(){

    int a,b,c;

    cout<<"enter a and b\n";
    cin>>a>>b>>c;

    //IF And Else
    // if(a>b){
    //     cout<<"A is largest";
    // }
    // else{
    //     cout<<"B is largest";
    // }

    // Else if
    // if(a>b && a>c){
    //     cout<<"A is Big";
    // }
    // else if(b>a && b>c){
    //     cout<<"B is big";
    // }
    // else{
    //     cout<<"c is big";
    // }


    if(a>b){
        if(a>c){
            cout<<"A id big";
        }
        else{
            cout<<"C is big";
        }
    }
    else{
        if(b>c){
            cout<<"B is big";
        }
        else{
            cout<<"C is big";
        }
    }
    return 0;
}
