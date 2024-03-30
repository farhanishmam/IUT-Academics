#include<stdio.h>
#include<stdlib.h>

struct linkedlist{

    int data;
    struct linkedlist *next;
};

typedef struct linkedlist *node;

node createnode(void)
{
    node temp;
    temp = (node) malloc(sizeof (struct linkedlist));
    temp -> next = NULL;
    return temp;
}


node addnode(node head, int value)
{
    node temp = createnode(), p;
    temp -> data = value;
    if (head==NULL) head=temp;
    else
    {
        p=head;
        while (p->next!=NULL)
        {
            p=p->next;
        }
    p->next = temp;
    }
    return head;
}

void insert_back(node n, int ins1, int ins_val)
{

    node new_nd = createnode();
    new_nd -> data = ins_val;

    while(n->next != NULL)
    {
        if(n->data == ins1)
        {
            new_nd -> next = n -> next;
            n -> next = new_nd;
            return;
        }
        n = n->next;
    }
    if((n->data == ins1)&&(n->next == NULL))
    {
        n->next = new_nd;
        new_nd -> next = NULL;
        return;
    }
}

void ins_sort(node n)
{
    for(;;)
    {
        while(n->next != NULL)
        {
            if(n>n->next)
            {

            }
        }
    }
}

int main(void)
{
    int n,a;
    node nd = NULL;
    for(;;)
    {
        printf ("1.Add element\n2.Print\n5.Insert Element\n0. Exit\n");
        scanf("%d", &n);
        if (n==1)
        {
            printf ("Enter the value\n");
            scanf ("%d", &a);
            nd = addnode(nd,a);
        }

        else if (n==2)
        {
            for (node temp = nd; temp != NULL; temp = temp -> next)
            {
                printf("%d ",temp->data);
            }
            printf("\n");
        }
        /*
        else if(n==4)
        {
            printf("%d",(nd->next)->data);
        }
        */

        else if(n==5)
        {
            int ins1,ins_val;
            printf("Enter the node value after which you want to insert:\n");
            scanf("%d",&ins1);
            printf("Enter the inserted value\n");
            scanf("%d",&ins_val);

            insert(nd,ins1,ins_val);
        }


        else if (n==0)
        {
            return 0;
        }

    }
}
