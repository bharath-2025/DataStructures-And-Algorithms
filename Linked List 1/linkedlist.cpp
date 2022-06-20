#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        next = nullptr;
    }

};

Node* takeInput(){
    //Let use -1 as terminator to take the input.
    int data;
    cin>>data;
    Node *head = nullptr;
    while(data!=-1){
        Node *newNode = new Node(data);
        if(head==nullptr){
            head = newNode;
        }
        else{
            Node *temp = head;
            while(temp -> next != nullptr){
                temp = temp->next;
            }
            temp -> next = newNode; 
        }

        cin>>data;
    }
    return head;
}

void print(Node * head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


int main(){
    /*
    //Statically
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    Node *head = &n1;
    //cout<<"head ="<<head<<endl;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    */

    /*//Dynamically
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    n2.next = n3;
    n3->next = n4;*/

    Node *head = takeInput();

    cout<<head->data<<endl;

    print(head);
    
}