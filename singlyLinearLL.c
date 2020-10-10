#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insertLastNode(struct node** head,int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data=data;
    newNode->next=NULL;

    if(*head==NULL)
    {
        *head=newNode;
        
    }
    else
    {
         struct node* temp=*head;
         while(temp->next!=NULL)
         {
            temp=temp->next; 
         }
         temp->next=newNode;
    }
}

struct node * Display(struct node *head)
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d -> \t",temp->data);
        temp=temp->next;
    } 
}

struct node* insertFirstNode(struct node** head,int data)
{
    struct node* newNode = (struct node* )malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL; 
    
    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        newNode->next=*head;
        *head=newNode;
    }
}

int count(struct node* temp)
{
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

struct node* deleteLastNode(struct node** head)
{
    if(*head==NULL)
    {
        return 0;
    }
    else if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
   {    struct node * temp=*head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

struct  node* deleteFirstNode(struct node** head)
{
    if(*head==NULL)
    {
        return 0;
    }
    else if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
    {
        struct node* temp=*head;
        *head=temp->next;
        free(temp);
    }
    
}

struct node* insertAtPosition(struct node** head,int data, int position)
{
    int pos=position;
    int size=count(*head);
    struct node* temp=*head;

    if(pos<1 || pos>size+1)
    {
        return 0;
    }
    else if(pos==1)
    {
        insertFirstNode(head,data);
    }
    else if(pos==size+1)
    {
        insertLastNode(head,data);
    }
    else
    {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data=data;
        newNode->next=NULL;

        int i=0;
        for(i=1;i<(pos-1);i++)
        {
            temp=temp->next;
        }
        newNode->next=temp->next->next;
        temp->next=newNode;
    }
    
}

struct node* deleteAtPosition(struct node** head,int position)
{
    int pos=position;
    int size=count(*head);
    if(pos<1 || pos>size)
    {
        return 0;
    }
    else if(pos==1)
    {
        deleteFirstNode(head);
    }
    else if(pos==size)
    {
        deleteLastNode(head);
    }
    else
    {
        struct node* target=NULL;
        struct node* temp=*head;
        int i=0;
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        target=temp->next;
        temp->next=target->next;
        free(target);
    }
}

struct node* reverseLinkedList(struct node** head)  
{
    struct node* temp1 = NULL; // Previous node
    struct node* temp2 = NULL; // Next node
    struct node* temp = *head; // Current Node
    if(*head==NULL)
    {
        return 0;
    }     
    while(temp!=NULL)
    {
        temp2=temp->next;
        temp->next=temp1;
        temp1=temp;
        temp=temp2;
    }
    *head=temp1;
}

int MiddleNode(struct node* head)
{
    struct node* slow = head;
    struct node* fast = head;

    if(head==NULL)
    {
        return 0;
    }

    while((fast!=NULL) && (fast->next!=NULL))
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}


int main()
{
    struct node *head=NULL;
    int ret=0;
   insertLastNode(&head,41);
   insertLastNode(&head,51);
   insertLastNode(&head,61);
    insertLastNode(&head,101);

    Display(head);

    insertFirstNode(&head,31);
    insertFirstNode(&head,21);
    insertFirstNode(&head,11);
    printf("\n\nInserting elements into linked list :\n ");    
    Display(head);

    ret=count(head);
    printf("\n\nThere are %d nodes in Linked list.\n",ret);

    deleteLastNode(&head);
    printf("\n\nAfter deleting Last node :\n");  
    Display(head);

    deleteFirstNode(&head);
    printf("\n\nAfter deleting First node :\n");  
    Display(head);

    insertAtPosition(&head,45,4);
     printf("\n\nInserting at position  4 :\n");  
    Display(head);
    
     deleteAtPosition(&head,4);
    printf("\n\nDeleting node at position 4 :\n");  
    Display(head);

     reverseLinkedList(&head);
    printf("\n\nReversing the Linked List :\n");  
    Display(head);

    ret=MiddleNode(head);
     printf("\n\nMiddle element of the linked List is : %d\n",ret);  
}