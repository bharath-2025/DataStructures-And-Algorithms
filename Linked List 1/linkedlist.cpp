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

Node* deleteNode(Node *head,int pos){
    if(head == nullptr){
        return head;
    }

    if(pos == 0){
        head = head->next;
        return head;
    }

    int count=0;
    Node *temp = head;
    while(count < pos-1 && temp->next != nullptr){
        temp = temp->next;
        count++;
    }

    if(count == pos-1){
        temp->next = (temp->next)->next;
    }
    return head;
}

Node* insertNode(Node *head,int pos,int data){
    Node *newNode = new Node(data);
    if(pos == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    int count=0;
    Node *temp = head;
    while(count < pos-1 && temp->next != nullptr){
        temp = temp->next;
        count++;
    }
    if(count == pos-1){
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    
    return head;
}


//Th=ime Complexity is O(N^2)
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


//Improving the Effeciency of takeInput function to O(n) Time Complexity bu using a tail Pointer
Node* takeInput_Better(){                       
    //Let use -1 as terminator to take the input.
    int data;
    cin>>data;
    Node *head = nullptr;
    Node *tail = nullptr;
    while(data!=-1){
        Node *newNode = new Node(data);
        if(head==nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = tail -> next;  
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
    cout<<endl;
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

    Node *head = takeInput_Better();

    //cout<<head->data<<endl;

    print(head);

    head = insertNode(head,2,100);

    print(head);

    head = deleteNode(head,8);

    print(head);
    
}