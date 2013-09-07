#include<stdio.h>
typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* child;
}Node;
Node* insertt(Node* head,int val)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    Node* iterate=head;
    temp->next=temp->child=NULL;
    temp->data=val;
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    while(iterate->next)
    {
        iterate=iterate->next;

    }
    iterate->next=temp;
    return head;
}
void add_random_child(Node** head)
{
    (*head)->child=insertt((*head)->child,6);
    (*head)->child=insertt((*head)->child,7);
    (*head)->child=insertt((*head)->child,8);


}
Node* flatten(Node* head) //code to flattenS
{
    Node* tail=head;
    Node* head1=head;
    while(head1)
    {
        while(tail->next)
            tail=tail->next;
        if(head1->child)
        {
            tail->next=head1->child;
            head1->child=NULL;

        }
         head1=head1->next;

    }
    return head;
}
void display(Node* head)
{
    while(head)
      {

        printf("%3d",head->data);
        head=head->next;
      }
}
int main()
{
    Node* head=NULL;
    head=insertt(head,2);
    head=insertt(head,3);
    head=insertt(head,4);
    head=insertt(head,5);
    add_random_child(&head);
    Node* flat=flatten(head);
    //display(head);
    display(flat);



}
