#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct node{
    int data;
    struct node *next;
} typedef node;
node *head;
node *end;
int size;
void insert_begin(int i){
    if(head==NULL){
        head=malloc(sizeof(node));
        head->data=i;
        head->next=NULL;
        end=head;
    }
    else{
        node *temp;
        temp=malloc(sizeof(node));
        temp->data=i;
        temp->next=head;
        head=temp;
    }
}
void insert_end(int i){
    node *temp;
    if(head==NULL){
        head=malloc(sizeof(node));
        head->data=i;
        head->next=NULL;
        end=head;
    }
    else{
        temp=malloc(sizeof(node));
        temp->data=i;
        temp->next=NULL;
        end->next=temp;
        end=temp;
    }
}
void print(){
    node *temp;
    temp=head;
    while(temp!=NULL){
        printf(" %d -> ",temp->data);
        temp=temp->next;
    }
}
void sort_ll(){
    node *new1 = head;
node *count;
	for( ; new1->next != NULL; new1 = new1->next)
	{
		for(count = new1->next; count != NULL; count = count->next)
		{
			if(new1->data > count->data)
			{
				int temp = new1->data;
				new1->data = count->data;
				count->data = temp;
			}
		}
	}
}
int main(){
    int ch,i,j,s,m;
    float a;
    head=NULL;
    size=0;
    while(1){
        printf("\n1. Insert (Beginning)\n2. Insert (End)\n3. Print\n4. Sort\n5. Exit\n Your Choice : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("\nEnter An Integer :  ");
            scanf("%d",&i);
            insert_begin(i);
            break;
        case 2:
            printf("\nEnter An Integer :  ");
            scanf("%d",&j);
            insert_end(j);
            break;
        case 3:
            printf("\nYour Linked List is : ");
            print();
            break;
        case 4:
            sort_ll();
            break;
        case 5:
            exit(0);
        default:
            printf("\n\n\t\tWrong Input!!!");
            break;
        }
    }
    return 0;
}
