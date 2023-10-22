#include<iostream>
#include<stdlib.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int n) {
    	data=n;
	    next=nullptr;
	} 
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int n) {
        Node *p; 
		p=new Node(n);
        if (head == nullptr) {
            head =p;
            head->next = head;
        } 
		else {
            Node *ptr = head;
            while (ptr->next != head) {
                ptr = ptr->next;
            }
            ptr->next = p;
            p->next = head;
            head = p;
        }
    }

    void insert_end(int n) {
        Node *p = new Node(n);
        if (head == nullptr) {
            head = p;
            head->next = head;
        } 
		else {
            Node *ptr = head;
            while (ptr->next != head) {
                ptr= ptr->next;
            }
            ptr->next = p;
            p->next = head;
        }
    }

    void insert_at_value(int pos, int n) {
        Node *p= new Node(n);
        if (head == nullptr) {
            cout << "List is empty. Cannot insert at value." << endl;
            return;
        }
        Node *ptr = head;
        while (ptr->data != pos) {
            ptr = ptr->next;
            if (ptr == head) {
                cout << "Value " << pos << " not found in the list." << endl;
                return;
            }
        }
        p->next = ptr->next;
        ptr->next = p;
    }
void del_at_beg(){
	if(head==NULL){
		cout<<"empty";
	}
	else if(head->next==head){
		delete head;
		head=NULL;
	}
	else{	
	Node *ptr,*p;
	ptr=head;
	while(ptr->next!=head){
		ptr=ptr->next;
	}
	p=head;
	head=head->next;
	ptr->next=head;
	delete p;
	p=NULL;
}
}
void del_at_end(){
	if(head==NULL){
		cout<<"empty";
	}
	else if(head->next==head){
		delete head;
		head=NULL;
	}
	else{	
	Node *ptr,*p;
	ptr=head;
	while(ptr->next!=head){
		p=ptr;
		ptr=ptr->next;
	}
	p->next=head;
	delete ptr;
	ptr=NULL;
}
}
void del_at_spec(int pos){
	if(head==NULL){
		cout<<"empty";
	}
	else if(head->next==head){
		delete head;
		head=NULL;
	}
	else{	
	Node *ptr,*p;
	ptr=head;
	while(ptr->data!=pos){
		p=ptr;
		ptr=ptr->next;
	}
	p->next=ptr->next;
	delete ptr;
	ptr=NULL;
}
}
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node *ptr = head;
        do {
            cout << ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != head);
        cout << endl;
    }
};
int main(){
	CircularLinkedList n;
	int ch;
	do{
		cout<<endl;
		cout<<"Press 1 for insert a nodes"<<endl;
		cout<<"Press 2 for insert at specific value "<<endl;
		cout<<"Press 3 for display"<<endl;
		cout<<"Press 4 for deletion at begining"<<endl;
		cout<<"Press 5 for deletion at end"<<endl;
		cout<<"Press 6 for deletion at specific value"<<endl;
		cout<<"Press 7 for exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		
	if(ch==1){

			cout<<"insert a nodes"<<endl;
				n.insert(1);
				n.insert(2);
	            n.insert(3);
             	n.insert(4);
            	}
		
    else if(ch==2){
	
	cout<<"insert at specific value "<<endl;	
				n.insert_at_value(3,7);
				}
    else if(ch==3){
	
	cout<<"For display "<<endl;	
			
				n.display();	
			}
	
	else if(ch==4){
	
	cout<<"Press 4 for deletion at begining"<<endl;
			
				n.del_at_beg();
			}		
			
	else if(ch==5){
	
	cout<<"Press 5 for deletion at end"<<endl;	
			
				n.del_at_end();	
			}		
	else if(ch==6){
	
	cout<<"Press 6 for deletion at specific value"<<endl;	
			
				n.del_at_spec(2);
			}			
			
   else{
   	cout<<"invalid choice";
   }
	
	}
while(ch!=7);

	
	return 0;
}

