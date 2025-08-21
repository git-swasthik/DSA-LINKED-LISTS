#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node * prev;
    int data;
    struct Node * next;
};
void DLL_Traversal(struct Node*); //Traversing through my linked list and displaying it.
struct Node * InsertAtBeginning(struct Node*, int); //Inserting A Node at the beginning.
struct Node * InsertAtIndex(struct Node*, int, int); // Inserting at a given Index.
struct Node * InsertAtLast(struct Node*,int); //Inserting at Last.
void InsertAfterNode(struct Node*,int); //Inserting after a given node.
struct Node * DeleteAtBeginning(struct Node*); //Deleting at the beginning.
void DeleteAtIndex(struct Node*,int); //Deleting at a given index.
void DeleteAtEnd(struct Node*); // Deleting at the end of the Linked List.
void DeleteAfterNode(struct Node*); // Deleting after a specifie Node.
int main()
{
    //Defining my nodes and assigning them memory dynamically.
    struct Node * head = (struct Node*)malloc(sizeof(struct Node));
    struct Node * second = (struct Node*)malloc(sizeof(struct Node));
    struct Node * third = (struct Node*)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node*)malloc(sizeof(struct Node));

    //Giving values to my nodes
    head->prev = NULL;
    head->data = 7;
    head->next = second;
    second->prev = head;
    second->data = 11;
    second->next = third;
    third->prev = second;
    third->data = 15;
    third->next = fourth;
    fourth->prev = third;
    fourth->data = 19;
    fourth->next = NULL;

    //Traversing and Displaying the Double Linked List.
    //DLL_Traversal(head);

    //Inserting a newnode in the beginning of the Double Linked List.
    //head = InsertAtBeginning(head,78);
    //DLL_Traversal(head);

    //Inserting a newnode at a given Index.
    // head = InsertAtIndex(head,67,2);
    // DLL_Traversal(head);

    //Inserting a newnode at the last.
    // head = InsertAtLast(head,89);
    // DLL_Traversal(head);

    //Insert after a Node.
    // InsertAfterNode(second,54);
    // DLL_Traversal(head);

    //Deleting the first node.
    // head = DeleteAtBeginning(head);
    // DLL_Traversal(head);

    //Delete at a given Index
    // DeleteAtIndex(head,1);
    // DLL_Traversal(head);

    //Delete At End.
    // DeleteAtEnd(head);
    // DLL_Traversal(head);

    //Delete after a node.
    // DeleteAfterNode(second);
    // DLL_Traversal(head);


    //Uncomment and try out the operations by urself.
    //Happy coding :)

    return 0;
}

void DLL_Traversal(struct Node * ptr)
{
    printf("NULL->");
    while(ptr != NULL){
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct Node * InsertAtBeginning(struct Node * head, int data)
{
    struct Node * ptr = head; //Assigning a pointer to hold the address of my head node.
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    ptr->prev = newnode;
    newnode->next = ptr;
    newnode->prev = NULL;
    return newnode;
}

struct Node * InsertAtIndex(struct Node * head, int data, int index)
{
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node * ptr = head;
    int i = 0;
    while(i<index-1){
        ptr = ptr->next;
        i++;
    }
    newnode->next = ptr->next;
    ptr->next->prev = newnode;
    ptr->next = newnode;
    newnode->prev = ptr;
    return head;


}

struct Node * InsertAtLast(struct Node * head, int data)
{
    struct Node * ptr = head;
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
    newnode->next = NULL;
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
    head = head->next;
    head->prev = NULL;
    free(ptr);
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
    }
    ptr->next = q->next;
    q->next = ptr;
    free(q);
    
}

void DeleteAtEnd(struct Node * head){
    struct Node * ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
}

void DeleteAfterNode(struct Node * prev)
{
    struct Node * ptr = prev->next;
    prev->next = ptr->next;
    ptr->next->prev = prev;
    free(ptr);
}