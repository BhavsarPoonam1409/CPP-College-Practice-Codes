#include<iostream>
using namespace std;

int stack[5];
int top=-1; //first time stack empty hogha 

void push(int val){
    //==4 brcause 5 value hain 
    if(top==4){
        cout<<"Stack is overflow\n";
        return;
    }
    //val push hoghi isse
    top++;
    stack[top]=val;
}

int pop(){
    //check for stack empty toh nai hain
    if(top==-1){
        cout<<"Stack is underflow\n";
        return -1;
    }
    int val=stack[top];
    top--;
    return val;
}

void peek(){
    if(top==-1){
        cout<<"Stack is underflow\n";
        return ;
    }
    int val=stack[top];
    cout<<"Top most element is:"<<val<<endl;
}

int main(){

    int ch,val,result;

    while(1){
        cout<<"----------Choose-------------\n";
        cout<<"1)Push\n";
        cout<<"2)Pop\n";
        cout<<"3)Peek\n";
        cout<<"4)Exit\n";

        cout<<"Enter Choice:";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"Enter value";
                cin>>val;
                push(val);
                break;
            
            case 2:
                result=pop();
                if(result!=-1){
                    cout<<"Popped element is:"<<result<<endl;
                }
                break;

            case 3:
                peek();
                break;
            
            case 4:
                return 0;
            
            default:
                cout<<"Invalid Choice\n";
                break;

        }

    }
    return 0;
}