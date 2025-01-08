#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
node *head=NULL;
void create(int n1)
{
    int i,x;
    struct node *newnode,*temp;
    head = (struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Unable to allocate memory.");
        return;
    }
    else
    {
        printf("Enter the data in the position 0\n");
        scanf("%d",&x);
        head->data=x;
        head->next=NULL;
        temp=head;
        for(i=1; i<n1; i++)
        {
            newnode= (struct node *)malloc(sizeof(struct node));
            if(newnode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            printf("Enter the data in the position %d\n",i);
            scanf("%d",&x);
            newnode->data=x;
            newnode->next=NULL;
            temp->next=newnode;
            temp=temp->next;
        }
    }
}
void search(int element)
{
    int i,x,flag=0,c=1;
    struct node *present,*temp;
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            if(temp->data==element)
            {
                flag=1;
                printf("The element found at the node %d\n",c-1);
                break;
            }
            else
            {
                temp=temp->next;
                c++;
            }
        }
    }
    if(flag==0)
    {
        printf("Not found\n");
    }
}
void print()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void deletenode(int pos)
{
    int i;
    struct node *previous,*present;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        previous=head;
        present=head;
        for(i=1; i<pos+1; i++)
        {
            previous=present;
            present=present->next;
            if(present==NULL)
            {
                break;
            }
        }
        if(present!=NULL)
        {
            if(present==head)
            {
                head=head->next;
            }
            else
            {
                previous->next=present->next;
                present->next=NULL;
                free(present);
            }
            printf("Sucessfully delete node\n");
        }
        else
        {
            printf("Invalid position\n");
        }
    }
}
void insertnode(int pos)
{
    int i,x;
    struct node *present,*temp;
    printf("Enter the item you want to insert\n");
    scanf("%d",&x);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    present=head;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        if(pos==0)
        {
            temp->next=present;
            head=temp;
            return;
        }
        else
        {
            for(i=1; i<pos-2; i++)
            {
                present=present->next;
            }
            temp->next=present->next;
            present->next=temp;
        }
    }
}
int main()
{
    printf("~~~~~ Linked List ~~~~~\n");
    int n1,p;
    printf("\n\n\n\n");
    printf("Enter the number of nodes: \n");
    scanf("%d",&n1);
    create(n1);
    printf("The linked list is: \n");
    print();
    int choice;
    printf("Enter your choice of operation for the linked list: \n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice==1)
    {
        int p;
        printf("Enter the number of node where you want to insert\n");
        scanf("%d",&p);
        if(p>=n1)
        {
            printf("Invalid position\n");
        }
        else
        {
            insertnode(p);
        }
        printf("Linked list after insertion\n");
        print();
    }
    else if(choice==2)
    {
        int p;
        printf("Enter the number of node you want to delete\n");
        scanf("%d",&p);
        deletenode(p);
        printf("Linked list after deletation\n");
        print();
    }
    else if(choice==3)
    {
        int p;
        printf("Enter the number you want to search\n");
        scanf("%d",&p);
        search(p);
    }
}
