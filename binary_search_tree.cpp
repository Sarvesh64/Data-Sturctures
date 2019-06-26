#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* root= NULL;

Node* createNode(){
	Node* newNode=(Node*)malloc(sizeof(Node*));
	
	int x;
	printf("Enter the data: ");
	scanf("%d", &x);
	
	newNode->data=x;
	newNode->left=NULL;
	newNode->right=NULL;
	
	return newNode;
}

void insertNode(){
	Node* current=root;
	Node* previous=root;
	
	Node* newNode=createNode();
	if(root==NULL){
		root=newNode;
		printf("Node Created");
	}
	else{
		while(1){
			previous=current;
			if(newNode->data < previous->data){
				current=previous->left;
				if(current==NULL){
					previous->left=newNode;
					return;
				}
			}
			else{
				current=previous->right;
				if(current==NULL){
					previous->right=newNode;
					return;
				}
			}
		}
	}
}

int main(){
	int choice;
	while(1){
	printf(" \n");
	printf("1. Insert Node \n");
	printf("5. Add at Display \n");
	printf(" \n");
	printf(" Enter Your Choice\n");
	
	scanf("%d",&choice);
	
	switch(choice){
		case 1:	insertNode();
				//display();
			break;
		
	}
}
	return 0;
}
