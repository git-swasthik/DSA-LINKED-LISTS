#include<stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
void LinkedListTraversal(struct Node*); //Traversing through my Single Linked List.
struct Node * InsertAtBEginning(struct Node*,int); // Insertion at the beginning.
void InsertAtIndex(struct Node*,int,int); //Insetion at a specified Index.
void InsertAfterNode(struct Node*,int); //Insertion after a given Node.
struct Node * DeleteAtBeginning(struct Node*); //Deletion at the beginning of the list.
void DeleteAtIndex(struct Node*,int); //Delete at a specified Index.
void DeleteAtEnd(struct Node*); //Deleting the Last node.
void DeleteAfterNode(struct Node*); //Deleting after a given node.
int main()
{
    //Creating my starting 4 Nodes, and giving them memory dynamically.
    struct Node * head = (struct Node*)malloc(sizeof(struct Node));
    struct Node * second = (struct Node*)malloc(sizeof(struct Node));
    struct Node * third = (struct Node*)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node*)malloc(sizeof(struct Node));

    //Giving my nodes the values and the addresses to hold.
    head->data = 7;
    head->next = second;
    second->data = 14;
    second->next = third;
    third->data = 21;
    third->next = fourth;
    fourth->data = 28;
    fourth->next = NULL;

    //Traversing through my Single Linked List.
   // LinkedListTraversal(head);

    //Adding a Node at the beginning of my List,
    // head = InsertAtBEginning(head, 45);
    // LinkedListTraversal(head);

    //Adding a Node at a given Index.
    // InsertAtIndex(head,34,2);
    // LinkedListTraversal(head);

    //Insert After a Given Node.
    // InsertAfterNode(second,78); //I'm telling the function to insert a node after the second node.
    // LinkedListTraversal(head);

    //Deleting the First Node.
    // head = DeleteAtBeginning(head);
    // LinkedListTraversal(head);

    //Deleting at a given Index.
    // DeleteAtIndex(head,2);
    // LinkedListTraversal(head);

    //Deleting the Last Node.
    // DeleteAtEnd(head);
    // LinkedListTraversal(head);

    //Deleting after a Node.
    // DeleteAfterNode(second); //Deltes the Node after the second node in the list.
    // LinkedListTraversal(head);

    //Uncommnet them and try it urself.
    //Happy coding!!


    return 0;
}

void LinkedListTraversal(struct Node * ptr)
{
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct Node * InsertAtBEginning(struct Node * head,int data)
{
    struct Node * ptr = head;
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = ptr;
    return newnode;
}

void InsertAtIndex(struct Node * head, int data, int index)
{
    struct Node * ptr = head;
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    int i = 0;
    while (i<index-1)
    {
        ptr = ptr->next;
        i++;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    
}

void InsertAfterNode(struct Node * prev, int data)
{
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = prev->next;
    prev->next = newnode;
}

struct Node * DeleteAtBeginning(struct Node * head)
{
    
    head = head->next;
    return head;
}

void DeleteAtIndex(struct Node * head, int index)
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
}

void DeleteAtEnd(struct Node * head)
{
    struct Node * ptr = head;
    struct Node * q = ptr->next;
    while(q->next != NULL){
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);

}

void DeleteAfterNode(struct Node * prev)
{
    struct Node * ptr = prev->next;
    prev->next = ptr->next;
    free(ptr);
}