#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;


// Insert at Beginning
void insertbeg(int val) {
    Node *newnode = new Node;

    newnode->data = val;
    newnode->next = head;
    head = newnode;
}


// Insert at End
void insert_end(int val) {
    Node *newnode = new Node;

    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
}


// Insert After a Given Value
void insert_after(int val, int search) {
    Node *temp = head;

    while (temp != NULL && temp->data != search) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }

    Node *newnode = new Node;

    newnode->data = val;
    newnode->next = temp->next;
    temp->next = newnode;
}


// Delete a Given Value
void del(int val) {
    Node *temp = head;
    Node *prev = NULL;

    if (head == NULL) {
        cout << "Linked list is empty\n";
        return;
    }

    // If first node contains value
    if (temp->data == val) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
}


// Delete from Beginning
void delete_beg() {
    if (head == NULL) {
        cout << "Linked list is empty\n";
        return;
    }

    Node *temp = head;
    head = head->next;

    delete temp;
}


// Delete from End
void delete_end() {
    if (head == NULL) {
        cout << "Linked list is empty\n";
        return;
    }

    // Only one node
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}


// Search
void search(int val) {
    Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == val) {
            cout << "Value found at position " << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Value not found\n";
}


// Display / Traverse
void display() {
    Node *temp = head;

    if (head == NULL) {
        cout << "Empty linked list\n";
        return;
    }

    cout << "Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}


int main() {

    int ch, val, searchval;

    while (1) {

        cout << "\n----------- Choice ----------\n";
        cout << "1) Insert Beginning\n";
        cout << "2) Traverse / Display\n";
        cout << "3) Insert End\n";
        cout << "4) Insert After\n";
        cout << "5) Delete Value\n";
        cout << "6) Delete Beginning\n";
        cout << "7) Delete End\n";
        cout << "8) Search\n";
        cout << "9) Exit\n";

        cout << "Enter Choice: ";
        cin >> ch;


        switch (ch) {

            case 1:
                cout << "Enter value: ";
                cin >> val;

                insertbeg(val);
                break;


            case 2:
                display();
                break;


            case 3:
                cout << "Enter value: ";
                cin >> val;

                insert_end(val);
                break;


            case 4:
                cout << "Enter value to insert: ";
                cin >> val;

                cout << "Enter value after which you want to insert: ";
                cin >> searchval;

                insert_after(val, searchval);
                break;


            case 5:
                cout << "Enter value to delete: ";
                cin >> val;

                del(val);
                break;


            case 6:
                delete_beg();
                break;


            case 7:
                delete_end();
                break;


            case 8:
                cout << "Enter value to search: ";
                cin >> val;

                search(val);
                break;


            case 9:
                return 0;


            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}

