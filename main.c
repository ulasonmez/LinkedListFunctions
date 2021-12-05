#include <stdio.h>
#include <stdlib.h>

struct node{
	int x;
	struct node *next;
};
void printList(struct node *head){
	printf("%d\t",head->x);
	while(head->next!=NULL){
		head = head->next;
		printf("%d\t",head->x);
	}
}
 struct node* basaEkle(struct node *head,int a){
 	struct node *b = (struct node*)malloc(sizeof(struct node));
 	b->x = a;
 	b->next = head;
 	return b;
 }
void sonaEkle(struct node *head, int a){
 	while(head->next!=NULL){
 		head=head->next;
	 }
	 struct node *yeni = (struct node*)malloc(sizeof(struct node));
	 yeni->x=a;
	 head->next=yeni;
	 yeni->next=NULL;
 }
 void arayaEkle(struct node *head,int once,int sayi){
	 struct node *yeni = (struct node*)malloc(sizeof(struct node));
	 yeni->x=sayi;
	 while(head->x!=once && head->next!=NULL){
 		head = head->next;
	 }
	 struct node *sonra = (struct node*)malloc(sizeof(struct node));
	 sonra = head->next;
	
	 head->next=yeni;
	 yeni->next=sonra;
 }
 void sondanSil(struct node *head){
 	while(head->next->next!=NULL){
 		head = head->next;
	 }
	 struct node *temp = head->next;
	 head->next=NULL;
	 free(temp);
 }
 struct node* bastanSil(struct node *head){
 	return head->next;
 }
 void aradanSil(struct node *head,int sayi){
 	while(head->next->x!=sayi){
 		head = head->next;
	 }
	 struct node *yem = head->next->next;
	 struct node *silaga = head->next;
	 head->next = yem;
	 free(silaga);
 }
void sirala(struct node *head){
	struct node *tmp = head;
	struct node *tmp2 = head;
	for(tmp = head ; tmp->next != NULL ; tmp = tmp->next){
		for(tmp2 = tmp->next ; tmp2->next != NULL ; tmp2 = tmp2->next){
			if(tmp->x > tmp2->x){
				int temp = tmp->x;
				tmp->x = tmp2->x;
				tmp2->x = temp;
			}
		}
	}
}
int main(int argc, char *argv[]) {
	struct node *root = (struct node*)malloc(sizeof(struct node));
	root->x = 10;
	root->next=NULL;
	root = basaEkle(root,3);
	root = basaEkle(root,21);
	root = basaEkle(root,1);
	sonaEkle(root,31);
	sirala(root);
	//root = arayaEkle(root,2,99);

	printList(root);
	return 0;
}