#include<stdio.h>
#include<stdlib.h>

struct linkedlist
{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist *node;

node createNode()
{
    node temp;
    temp = (node)malloc(sizeof(struct linkedlist));
    temp->data = NULL;
    temp->next = NULL;
    return temp;
}
node addNode(node head, int val)
{
    node temp = createNode(), p;
    temp->data = val;
    p = head;
    while(p->data<val && p->next!=NULL)
        p=p->next;
    if(p->data>val)
    {
        temp->next=p;
        head=temp;
    }
    else if(p->data<val)
    {
        p->next=temp;
    }
    return head;
}
void printNode(node temp)
{
    if(temp->data==NULL)
        printf(" No element in List");
    else
    {
        while(temp->next!=NULL)
        {
            printf(" %d", temp->data);
            temp=temp->next;
        }
        printf(" %d", temp->data);
    }
    printf("\n");
    return;
}
int main()
{
    int val, n=0, val1;
    node head=createNode();
    Loop:
    printf("1. Add element\n 2. Print List\n 3. Exit\n" );
    scanf("%d", &n);
    if(n==1)
    {
        printf(" Enter Value: " );
        scanf("%d", &val);
        if(head->data==NULL)
            head->data=val;
        else
            head=addNode(head, val);
    }
    else if(n==2)
        printNode(head);
    else if(n==3)
        goto END;
    else
        printf(" Wrong Input\n");
    goto Loop;
    END:
        return 0;
}

