#include<iostream>
using namespace std;

struct Node{
  int data;
  Node *next;  
};

Node *head=NULL;

void insertbeg(int val){
    Node *newnode=new Node;
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

void display(){
    Node *temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}



int main(){

    insertbeg(10);
    insertbeg(20);
    insertbeg(30);
    display();
    return 0;
}