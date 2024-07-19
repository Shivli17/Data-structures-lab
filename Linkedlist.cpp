#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
class Linkedlist{
public:
    Node* head;
    Linkedlist(){
        head=nullptr;
    }
    void InsertAtBeginning(int data){
        Node* node=new Node(data);
        if(!head){
            head=node;
            return;
        }
        node->next= head;
        head=node;
    }
    void InsertAtEnd(int data){
        Node* node=new Node(data);
        if(!head){
            head=node;
            return;
        }
        Node* temp=head;
        while (temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=node;
    }
    void Delete(int data){
        if(!head){
            cout<<"Empty";
            return;
        }
        Node* temp=head;
        if(temp->data==data){
            head=temp->next;
            delete temp;
            return;
        }
        while (temp->next!=nullptr)
        {
            if(temp->next->data==data){
               Node* d=temp->next;
               temp->next=temp->next->next;
               delete d;
               return;
            }
            temp=temp->next;
        }
        cout<<"not found";
        return;
    }
    void print(){
        Node* temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        
    }
    void palindrome() {
    Node* current = head;
    Node* prev = nullptr;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        int original = current->data;
        int reversed = 0;
        int digit;
        int a = original;

        while (a > 0) {
            digit = a % 10;
            reversed = reversed * 10 + digit;
            a = a / 10;
        }

        if (reversed != original) {
            Delete(current->data);
            // nextNode = current->next;
            // delete current;

            // if (prev) {
            //     prev->next = nextNode;
            // } else {
            //     head = nextNode;
            // }

            current = nextNode;
        } else {
            prev = current;
            current = current->next;
        }
    }
}


};

int main(){
    Linkedlist l;
    l.InsertAtBeginning(121);
    l.InsertAtBeginning(211);
    l.InsertAtBeginning(313);
    l.print();
    l.palindrome();
    l.print();
    l.Delete(313);
    l.print();
}

