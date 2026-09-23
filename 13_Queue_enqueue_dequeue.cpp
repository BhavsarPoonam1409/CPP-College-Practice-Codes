#include<iostream>
using namespace std;

int queue[5];
int f=-1;
int r=-1;
int size=sizeof(queue)/sizeof(queue[0]);

void enqueue(int val){
    if(r==size-1){
        cout<<"Queue is full\n";
        return ;
    }
    r++;
    queue[r]=val;
    if(r==0){
        f=0;
    }
}

int dequeue(){
    if(f==-1){
        cout<<"Queue is Empty\n";
        return -1;
    }
    int value=queue[f];
    f++;
    if(f>r){
        f=-1;
        r=-1;
    }
    return value;
}

void display(){
    int i=f;
    while(i<=r){
        cout<<queue[i]<<endl;
        i++;
    }
}

int main(){

    int ch,val,result;
    while(1){
        cout<<"------------ Choose----------------\n";
        cout<<"1)Enqueue\n";
        cout<<"2)Dequeue\n";
        cout<<"3)Display\n";
        cout<<"4)Exit\n";
        cout<<"Enter Choice:";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"Enter value:";
                cin>>val;
                enqueue(val);
                break;
            case 2:
                result=dequeue();
                if(result!=-1){
                    cout<<"Removed element:"<<result<<endl;
                }
                break;

            case 3:
                display();
                break;
            
            case 4:
                return 0;

            default:
                cout<<"invalid Choice\n";
                break;

        }
    }

    return 0;
}