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

    // Empty list
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    Node *temp = head;

    // Go to last node
    while (temp->next != head) {
        temp = temp->next;
    }

    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}


// Traverse
void display() {

    if (head == NULL) {
        cout << "Empty linked list\n";
        return;
    }

    Node *temp = head;

    cout << "Circular Linked List: ";

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "HEAD\n";
}


// Insert at End
void insert_end(int val) {

    Node *newnode = new Node;

    newnode->data = val;

    // Empty list
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    Node *temp = head;

    // Go to last node
    while (temp->next != head) {
        temp = temp->next;
    }

    newnode->next = head;
    temp->next = newnode;
}


// Insert After a Given Value
void insert_after(int val, int search) {

    if (head == NULL) {
        cout << "Empty linked list\n";
        return;
    }

    Node *temp = head;

    do {
        if (temp->data == search) {

            Node *newnode = new Node;

            newnode->data = val;
            newnode->next = temp->next;
            temp->next = newnode;

            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Value not found\n";
}


// Delete a Given Value
void del(int val) {

    if (head == NULL) {
        cout << "Empty linked list\n";
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    // Only one node
    if (head->next == head) {

        if (head->data == val) {
            delete head;
            head = NULL;
        }
        else {
            cout << "Value not found\n";
        }

        return;
    }


    // If first node
    if (head->data == val) {

        // Find last node
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = head->next;

        Node *deleteNode = head;
        head = head->next;

        delete deleteNode;

        return;
    }


    // Delete middle or last node
    temp = head;

    do {
        prev = temp;
        temp = temp->next;

        if (temp->data == val) {

            prev->next = temp->next;

            delete temp;

            return;
        }

    } while (temp != head);


    cout << "Value not found\n";
}


int main() {

    int ch, val, searchval;

    while (1) {

        cout << "\n----------- Choice ----------\n";

        cout << "1) Insert Beginning\n";
        cout << "2) Traverse\n";
        cout << "3) Insert End\n";
        cout << "4) Insert After\n";
        cout << "5) Delete\n";
        cout << "6) Exit\n";

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
                return 0;


            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}

