#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head= NULL;

Node* createNode(){
	Node* newNode= (Node*)malloc(sizeof(Node*));
	if(newNode==NULL){
		printf("Memory not allocated");
	}
	int x;
	printf("Enter the data: ");
	scanf("%d", &x);
	
	newNode->data=x;
	newNode->next=NULL;
	
	return newNode;
}

void insertBeg(){
	Node* newNode=createNode();
	
	if(head==NULL){
		head=newNode;
		printf("Node created \n");
	}
	else{
		newNode->next=head;
		head=newNode;
		printf("Node created \n");
	}	
}

void insertMid(){
	Node* newNode=createNode();
	Node* current=head;
	int x;
	printf("Enter the position");
	scanf("%d",&x);
	
	if(current==NULL){
		head=newNode;
		printf("NodeCreated");
	}
	else{
		while(current->data!=x){
			current=current->next;
		}
		newNode->next=current->next;
		current->next=newNode;
	}
}

void insertEnd(){
	Node* newNode=createNode();
	Node* current=head;
	
	if(current==NULL){
		head=newNode;
		printf("Node Created \n");
		
	}
	else{
		while(current->next != NULL){
			current=current->next;
		}
		current->next=newNode;
		
	}
}

void display(){
	Node* temp=head;
	printf("The list is: ");
	while(temp!=NULL){
		printf(" %d ",temp->data);
		temp=temp->next;
	}
	printf(" \n");
	printf(" \n");
}

int main(){

	int choice;
	while(1){
	printf(" \n");
	printf("1. Add at Beg \n");
	printf("2. Add at End \n");
	printf("3. Add at middle \n");
	printf("5. Add at Display \n");
	printf(" \n");
	printf(" Enter Your Choice\n");
	
	scanf("%d",&choice);
	
	switch(choice){
		case 1:	insertBeg();
				display();
			break;
		case 2:	insertEnd();
				display();
			break;
		case 3:	insertMid();
				display();
			break;
		case 5: display();
			break;
	}
}
	return 0;
}
