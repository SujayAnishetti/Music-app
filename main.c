#include <stdio.h>
#include <stdlib.h>
void search();
void reverselist();
struct node {
    int data;
    struct node *next;
};
int c = 0;
struct node *head;
int b=0;
void insert();
void deletes();
void display();
int main() {
    int n, a, p, ch;
    head = NULL;
    while(1) {
        scanf("%d", &ch);
        switch (ch) {
        case 1:insert();
        break;
        case 2:deletes();
        break;
        case 3: display();
        break;
        case 4: search(); 
        break;
        case 5: reverselist(head);
        break;
        case 6: exit (0);
        default:printf("invalid choice");
 
 }
 
 } 
 return 0;
}
void insert() {
    int p, i,n ;
    struct node *list1 = (struct node *)malloc(sizeof(struct node));
    struct node *list2;
    scanf("%s%d", &n, &p);
    if (p <= 0 || p > c + 1)
    {
        printf("Enter a valid position\n");
        exit (0);
    }
 
 else {
    c++;
    list1->data = n;
    list1->next = NULL;
    if (p == 1) {
    list1->next = head;
    head = list1;
 } 
 else {
    list2 = head;
    for (i = 0; i < p - 2; i++) {
    list2 = list2->next;
 }
    list1->next = list2->next;
    list2->next = list1;
 }
 }
}
void deletes() {
    int p, i;
    struct node *temp1 = head, *temp2;
    scanf("%d", &p);
    if ((p <= 0) || p > c) {
    printf("Enter a valid position\n");
 } 
 else {
    c--;
    if (p == 1) {
    head = temp1->next;
    free(temp1);
 } 
 else {
    for (i = 0; i < p - 2; i++) {
     temp1 = temp1->next;
 }
temp2 = temp1->next;
 temp1->next = temp2->next;
 free(temp2);
 }
 }
}
void display() {
     struct node *x = head;
     if (x == NULL) {
     printf("LinkedList is empty\n");
     return;
 }
 while (x != NULL) {
    printf("%d->", x->data);
    x = x->next;
 }
 
}
void search()
{
    int n, p=0;
    struct node *x;
    scanf("%d", &n);
    x= head;
    while (x != head)
    {
        p++;
        if(x -> data =n)
        {
        b=1;
         break;
        }
     x= x->next;
    }
    if ( b == 1)
    {
    printf("%d element found", n);
    }
    else
    printf("%d element not found", n);
}
void reverselist(struct node *head)
{
    if (head == NULL)
    return;
    else
    reverselist(head -> next);
    printf("%d->", head -> data);
}