#include<stdlib.h>
#include<stdio.h>

void insertAtBeginning(int);
void Print();

struct Node{
	int data;
	struct Node* next;
};


struct Node* head;

void insertAtBeginning(int x){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x; //temp->data
	temp->next = head;
	head = temp;
}

void Print(){
	struct Node* temp=head;
	printf("The list is : \n");
	
	while(temp != NULL){
		printf(" %d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	head = NULL;
	printf("How many number? \n");
	int n, i ,x;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("ENter the number: \n");
		scanf("%d",&x);
		insertAtBeginning(x);
		Print();
	}
}

