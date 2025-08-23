#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node * prev;
    int data;
    struct Node * next;
};
void LinkedListTraversal(struct Node*);
struct Node * InsertAtBeginning(struct Node*,int);
struct Node * InsertAtIndex(struct Node*,int,int);
struct Node * InsertAtEnd(struct Node*,int);
void InsertAfterNode(struct Node*,int);
struct Node * DeleteAtBeginning(struct Node*);
struct Node * DeleteAtIndex(struct Node*,int);
struct Node * DeleteAtEnd(struct Node*);
void DeleteAfterNode(struct Node*);
int main()
{
    struct Node * head = (struct Node*)malloc(sizeof(struct Node));
    struct Node * second = (struct Node*)malloc(sizeof(struct Node));
    struct Node * third = (struct Node*)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node*)malloc(sizeof(struct Node));

    head->prev = fourth;
    head->data = 5;
    head->next = second;
    second->prev = head;
    second->data = 10;
    second->next = third;
    third->prev = second;
    third->data = 15;
    third->next = fourth;
    fourth->prev = third;
    fourth->data = 20;
    fourth->next = head;

    //Circular double Linked List Traversal
    // LinkedListTraversal(head);

    //Insert at beginning.
    // head = InsertAtBeginning(head, 34);
    // LinkedListTraversal(head);

    //Insert at an Index.
    // head = InsertAtIndex(head,56,3);
    // LinkedListTraversal(head);

    //Insert at End.
    // head = InsertAtEnd(head,45);
    // LinkedListTraversal(head);

    //Insert After Node.
    // InsertAfterNode(second, 49);
    // LinkedListTraversal(head);

    //Delete at beginning.
    // head = DeleteAtBeginning(head);
    // LinkedListTraversal(head);

    //Delete At Index.
    // head = DeleteAtIndex(head,2);
    // LinkedListTraversal(head);

    //Delete at End.
    // head = DeleteAtEnd(head);
    // LinkedListTraversal(head);

    //Delete After Node.
    // DeleteAfterNode(second);
    // LinkedListTraversal(head);

    //Uncomment and try these codes urslef.
    //Happy coding!!

    return 0;
}
void LinkedListTraversal(struct Node * head)
{
    struct Node * ptr = head;
    printf("LAST->");
    while(ptr->next !=head){
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("%d->",ptr->data);
    printf("HEAD\n");
}

struct Node * InsertAtBeginning(struct Node * head, int data)
{
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node * ptr = head;
    struct Node * q = ptr->next;
    while(q->next != head){
        q = q->next;
    }
    newnode->next = ptr;
    q->next = newnode;
    newnode->prev = ptr->prev;
    ptr->prev = newnode;
    return newnode;

}
struct Node * InsertAtIndex(struct Node * head, int data, int index)
{
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node * ptr = head;
    int i = 0;
    while (i<index-1)
    {
        ptr = ptr->next;
        i++;
    }
    newnode->next = ptr->next;
    ptr->next->prev = newnode;
    ptr->next = newnode;
    newnode->prev = ptr;
    return head;

}
struct Node * InsertAtEnd(struct Node * head, int data)
{
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node * q = head;
    struct Node * ptr = q->next;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    newnode->prev = ptr;
    q->prev = newnode;
    return head;
}
void InsertAfterNode(struct Node * prev, int data)
{
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = prev->next;
    prev->next->prev = newnode;
    prev->next = newnode;
    newnode->prev = prev;


}
struct Node * DeleteAtBeginning(struct Node * head)
{
    struct Node * ptr = head;
    struct Node * q = ptr->next;
    while(q->next != head){
        q = q->next;
    }
    q->next = ptr->next;
    head = head->next;
    head->prev = q;
    free(ptr);
    return head;
}
struct Node * DeleteAtIndex(struct Node * head,int index)
{
    struct Node * ptr = head;
    struct Node * q =ptr->next;
    int i = 0;
    while(i<index-1){
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    q->next->prev = q->prev->prev;
    free(q);
    return head;
}
struct Node * DeleteAtEnd(struct Node * head)
{
    struct Node * ptr = head;
    struct Node * q = ptr->next;
    while(q->next != head){
        q = q->next;
    }
    q->prev->next = q->next;
    ptr->prev = q->prev;
    free(q);
    return head;
}
void DeleteAfterNode(struct Node * prev)
{
    struct Node * ptr = prev->next;
    prev->next = prev->next->next;
    ptr->next->prev = ptr->prev;
    free(ptr);

}