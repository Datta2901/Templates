#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int v;
		node *next;
		node(){
			next = NULL;
		}
};

class LinkedList{
	node *head;
	public:	
        void insert_at_begining(int v);
        void insert_at_end(int v);
        void insert_at_given_position(int v, int p);
        void delete_at_begining();
        void delete_at_end();
        void delete_at_given_position(int p);
        void print();
};

void LinkedList :: insert_at_begining(int v){
	node *temp = new node();
	temp->v = v;
	temp->next = head;
	head = temp;
}

void LinkedList :: insert_at_end(int v){
	node *temp = new node();
	temp->v = v;
	if (head == NULL){
		head = temp;
	}
	else{
		node *ptr = head;
		while (ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void LinkedList :: insert_at_given_position(int v, int p){
	node *temp = new node();
	temp->v = v;
	if (p == 0){
		temp->next = head;
		head = temp;
	}
	else{
		node *ptr = head;
		while(p>1) {
			ptr = ptr->next;
			--p;
		}
		temp->next = ptr->next;
		ptr->next = temp;
	}
}

void LinkedList :: delete_at_begining(){
	if (head == NULL){
		cout<<"List is Empty"<<endl;
	}
	else{
		cout<<"Element Deleted: "<<head->v<<endl;
		node *temp = head;
		head = head->next;
		delete(temp);
	}
}

void LinkedList :: delete_at_end(){
	if (head == NULL){
		cout<<"List is Empty"<<endl;
	}
	else if (head->next == NULL){
		cout<<"Element Deleted: "<<head->v<<endl;
		delete(head);
		head = NULL;
	}
	else{
		node *temp = head;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		cout<<"Element Deleted: "<<temp->next->v<<endl;
		delete(temp->next);
		temp->next = NULL;
	}					

}

void  LinkedList :: delete_at_given_position(int p){
	if (head == NULL){
		cout<<"List is Empty"<<endl;
	}
	else{
		node *temp, *ptr;
		if (p == 0) {
			cout<<"Element Deleted: "<<head->v<<endl;
			ptr = head;
			head = head->next;
			delete(ptr);
		}
		else{
			temp = ptr = head;
			while(p>0){
				--p;
				temp = ptr;
				ptr = ptr->next;
			}
			cout<<"Element Deleted: "<<ptr->v<<endl;
			temp->next = ptr->next;
			free(ptr);
		}
	}

}

void LinkedList :: print(){
	if (head == NULL){
		cout<<"List is empty"<<endl;
	}
	else{
		node *temp = head;
		cout<<"Linked List: ";
		while (temp != NULL){
			cout<<temp->v<<"->";
			temp = temp->next;
		}
		cout<<" NULL " << endl;
	}
}