#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;


// Insert at Beginning
void insertbeg(int val) {

    Node *newnode = new Node;

    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL) {
        head->prev = newnode;
    }

    head = newnode;
}


// Insert at End
void insert_end(int val) {

    Node *newnode = new Node;

    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    newnode->prev = temp;
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
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
}


// Delete a Given Value
void del(int val) {

    if (head == NULL) {
        cout << "Linked list is empty\n";
        return;
    }

    Node *temp = head;

    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }

    // If first node
    if (temp == head) {
        head = temp->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        delete temp;
        return;
    }

    // If last node
    if (temp->next == NULL) {
        temp->prev->next = NULL;

        delete temp;
        return;
    }

    // If middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

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

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
}


// Delete from End
void delete_end() {

    if (head == NULL) {
        cout << "Linked list is empty\n";
        return;
    }

    Node *temp = head;

    // Only one node
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    delete temp;
}


// Search
void search(int val) {

    Node *temp = head;
    int position = 1;

    while (temp != NULL) {

        if (temp->data == val) {
            cout << "Value found at position "
                 << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Value not found\n";
}


// Traverse Forward
void display_forward() {

    if (head == NULL) {
        cout << "Empty linked list\n";
        return;
    }

    Node *temp = head;

    cout << "Forward: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}


// Traverse Backward
void display_backward() {

    if (head == NULL) {
        cout << "Empty linked list\n";
        return;
    }

    Node *temp = head;

    // Go to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Backward: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    cout << "NULL\n";
}


int main() {

    int ch, val, searchval;

    while (1) {

        cout << "\n----------- Choice ----------\n";

        cout << "1) Insert Beginning\n";
        cout << "2) Traverse Forward\n";
        cout << "3) Insert End\n";
        cout << "4) Insert After\n";
        cout << "5) Delete Value\n";
        cout << "6) Delete Beginning\n";
        cout << "7) Delete End\n";
        cout << "8) Traverse Backward\n";
        cout << "9) Search\n";
        cout << "10) Exit\n";

        cout << "Enter Choice: ";
        cin >> ch;


        switch (ch) {

            case 1:
                cout << "Enter value: ";
                cin >> val;

                insertbeg(val);
                break;


            case 2:
                display_forward();
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
                display_backward();
                break;


            case 9:
                cout << "Enter value to search: ";
                cin >> val;

                search(val);
                break;


            case 10:
                return 0;


            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}

