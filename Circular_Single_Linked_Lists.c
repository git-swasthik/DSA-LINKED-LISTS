#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
void LinkedListTraversal_CSLL(struct Node*);
struct Node * InsertAtBeginning_CSLL(struct Node*,int);
struct Node * InsertAtIndex(struct Node*,int,int);
struct Node * InsertAtEnd(struct Node*,int);
void InsertAfterNode(struct Node*,int);
struct Node * DeleteAtFirst(struct Node*);
struct Node * DeleteAtIndex(struct Node*,int);
void DeleteAtEnd(struct Node*);
void DeleteAfterNode(struct Node*);
int main()
{
    struct Node * head = (struct Node*)malloc(sizeof(struct Node));
    struct Node * second = (struct Node*)malloc(sizeof(struct Node));
    struct Node * third = (struct Node*)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 6;
    head->next = second;
    second->data = 12;
    second->next = third;
    third->data = 18;
    third->next = fourth;
    fourth->data = 24;
    fourth->next = head;

    //Circular Linked List Traversal.
    //LinkedListTraversal_CSLL(head);

    //Insert at beginning.
    // head = InsertAtBeginning_CSLL(head,45);
    // LinkedListTraversal_CSLL(head);
    
    //Insert at Index.
    // head = InsertAtIndex(head,34,1);
    // LinkedListTraversal_CSLL(head);

    //Insert at End.
    // head = InsertAtEnd(head,23);
    // LinkedListTraversal_CSLL(head);

    //Insert after Node.
    // InsertAfterNode(second,29);
    // LinkedListTraversal_CSLL(head);

    //Delete at Beginning.
    // head = DeleteAtFirst(head);
    // LinkedListTraversal_CSLL(head);

    //Delete at Index.
    // head = DeleteAtIndex(head,2);
    // LinkedListTraversal_CSLL(head);

    //Delete at End.
    // DeleteAtEnd(head);
    // LinkedListTraversal_CSLL(head);

    //Delete After Node.
    // DeleteAfterNode(second);
    // LinkedListTraversal_CSLL(head);

    //Uncomment these and try it out urself.
    //Happy coding!!

    return 0;
}
void LinkedListTraversal_CSLL(struct Node * head)
{
   struct Node * ptr = head;
   if(ptr->next == head){
    printf("Your linked List has only one node.\n");
    printf("%d->",ptr->data);
    printf("HEAD\n");
   }
   if(ptr->next != head){
     while(ptr->next != head){
         printf("%d->",ptr->data);
         ptr = ptr->next;
        }
     printf("%d->",ptr->data);
     printf("HEAD\n");
    }
}
struct Node * InsertAtBeginning_CSLL(struct Node * head, int data)
{
    struct Node * ptr = head;
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = ptr;
    while(ptr->next!=head){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    return newnode;
}
struct Node * InsertAtIndex(struct Node * head, int data, int index)
{
    struct Node * ptr = head;
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    int i = 0;
    while(i<index-1){
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    return head;
}
struct Node * InsertAtEnd(struct Node * head, int data)
{
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node * ptr = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    newnode->next = head;
    ptr->next = newnode;
    return head;
}
void InsertAfterNode(struct Node * prev, int data)
{
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = prev->next;
    prev->next = newnode;
}
struct Node * DeleteAtFirst(struct Node * head)
{
    struct Node * ptr = head;
    struct Node * q = ptr->next;
    while(q->next != head){
        q = q->next;
    }
    head = head->next;
    q->next = head;
    free(ptr);
    return head;
}
struct Node * DeleteAtIndex(struct Node * head, int index)
{
    struct Node * ptr = head;
    struct Node * q = ptr->next;
    int i = 0;
    while(i<index-1){
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    free(q);
    return head;
}

void DeleteAtEnd(struct Node * head)
{
    struct Node * ptr = head;
    struct Node * q = ptr->next;
    while(q->next!=head){
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = head;
    free(q);

}
void DeleteAfterNode(struct Node * prev)
{
    struct Node * ptr = prev->next;
    prev->next = ptr->next;
    free(ptr);
}