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

void displayIn(Node* root){
	if(root==NULL){
		printf("Kuch nhi hai andar\n");
		return;
	}
	if(root->left){
		displayIn(root->left);
	}
	printf(" %d-> ",root->data);
	if(root->right){
		displayIn(root->right);
	}
	
}

void displayPost(Node* root){
	if(root==NULL){
		printf("Kuch nhi hai andar \n");
		return;
	}
	
	if(root->left){
		displayPost(root->left);
	}
	if(root->right){
		displayPost(root->right);
	}
	printf(" %d-> ",root->data);
}

void displayPre(Node* root){
	if(root==NULL){
		printf("Kuch nhi hai andar \n");
		return;
	}
	printf(" %d-> ",root->data);
	if(root->left){
		displayPost(root->left);
	}
	if(root->right){
		displayPost(root->right);
	}
	
}


int main(){
	int choice;
	while(1){
	printf(" \n");
	printf("1. Insert Node \n");
	printf("2. Display in In-order \n");
	printf("3. Display in Post-order \n");
	printf("4. Display in Pre-order \n");
	printf(" \n");
	printf(" Enter Your Choice\n");
	
	scanf("%d",&choice);
	
	switch(choice){
		case 1:	insertNode();
				//display();
			break;
		case 2: printf("In-Order->");
				displayIn(root);
					printf("\n");
				printf("Post-Order->");
				displayPost(root);
					printf("\n");
				printf("Pre-Order->");
				displayPre(root);
					printf("\n");
		break;
	}
}
	return 0;
}
