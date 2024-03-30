#include<stdio.h>
#include<stdlib.h>

struct linkedlist{

    int data;
    struct linkedlist *next;
    struct linkedlist *prev;
};

typedef struct linkedlist *node;

node createnode(void)
{
    node temp;
    temp = (node) malloc(sizeof (struct linkedlist));
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}


node addnode_back(node head, int value)
{
    node temp = createnode(), p;
    temp -> data = value;
    if (head == NULL) head = temp;
    else
    {
        p = head;
        while (p->next!=NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
    return head;
}

node addnode_front(node head, int value)
{
    node temp = createnode(),p;
    temp -> data = value;
    if(head == NULL) head = temp;
    else
    {
        p = head;
        while(p->prev!=NULL)
        {
            p = p->prev;
        }
        p->prev = temp;
        temp->next = p;
    }
    return head;
}

void print_front(node n)
{
    if(n == NULL) printf("No element to print");
    else
    {
        printf("The elements are: ");
        while(n->prev != NULL)
        {
            n = n->prev;
        }
        while(n!=NULL)
        {
            printf("%d ",n->data);
            n = n->next;
        }
    }
    printf("\n");
}

void print_back(node n)
{
    if(n == NULL) printf("No element to print");
    else
    {
        printf("The elements are: ");
        while(n->next != NULL)
        {
            n = n->next;
        }
        while(n!=NULL)
        {
            printf("%d ",n->data);
            n = n->prev;
        }
    }
    printf("\n");
}

void update(node n)
{
    int u1,u2;
    printf("Enter the number to update:\n");
    scanf("%d",&u1);
    printf("Enter the changed value:\n");
    scanf("%d",&u2);
    while(n->prev != NULL)
    {
            n = n->prev;
    }
    while(n != NULL)
    {
        if(n->data == u1)
        {
            n -> data = u2;
            break;
        }
        n = n -> next;
    }
}

node delete_nd(node n, int del)
{
    while(n->prev != NULL)
    {
            n = n->prev;
    }

    if(n->next == NULL)
    {
        printf("All the elements in the linked list has been deleted\n");
        return NULL;
    }
    else
    {
        while(n->next != NULL)
        {
            if((n->data == del)&&(n->prev == NULL))
            {
                (n->next)->prev = NULL;
                 return n->next;
            }
            node nd_pre = n->prev;
            node nd_post = n->next;
            if(n->data == del)
            {
                nd_pre->next = nd_post;
                nd_post->prev = nd_pre;
                return n;
            }
            n = n -> next;
        }
        if((n->data == del)&&(n->next == NULL))
        {
            (n->prev)->next = NULL;
            return n->prev;
        }
    }

}

void insert_front(node n)
{
    int ins1,ins_val;
    printf("Enter the node value before which you want to insert:\n");
    scanf("%d",&ins1);
    printf("Enter the inserted value\n");
    scanf("%d",&ins_val);

    node new_nd = createnode();
    new_nd -> data = ins_val;

    while(n->next != NULL)
    {
            n = n->next;
    }
    while(n->prev != NULL)
    {
        if(n->data == ins1)
        {
            new_nd -> prev = n -> prev;
            n -> prev = new_nd;
            (new_nd->prev) -> next = new_nd;
            new_nd->next = n;
            return;
        }
        n = n->prev;
    }
    if((n->data == ins1)&&(n->prev == NULL))
    {
        n->prev = new_nd;
        new_nd -> prev = NULL;
        new_nd -> next = n;
        return;
    }
}


void insert_back(node n)
{
    int ins1,ins_val;
    printf("Enter the node value after which you want to insert:\n");
    scanf("%d",&ins1);
    printf("Enter the inserted value\n");
    scanf("%d",&ins_val);

    node new_nd = createnode();
    new_nd -> data = ins_val;

    while(n->prev != NULL)
    {
            n = n->prev;
    }
    while(n->next != NULL)
    {
        if(n->data == ins1)
        {
            new_nd -> next = n -> next;
            n -> next = new_nd;
            (new_nd->next) -> prev = new_nd;
            new_nd->prev = n;
            return;
        }
        n = n->next;
    }
    if((n->data == ins1)&&(n->next == NULL))
    {
        n->next = new_nd;
        new_nd -> next = NULL;
        new_nd -> prev = n;
        return;
    }
}



int main(void)
{
    int n,a;
    node nd = NULL;
    for(;;)
    {
        printf ("1. Add element(front)\n2. Add element (back)\n3. Print list (from the front)\n4. Print list (from the back)\n5. Update element\n6. Delete element\n7. Insert element(front)\n8. Insert element(back)\n9. Exit\n");
        scanf("%d", &n);
        if (n==1)
        {
            printf ("Enter the value\n");
            scanf ("%d", &a);
            nd = addnode_front(nd,a);
        }
        else if (n==2)
        {
            printf ("Enter the value\n");
            scanf ("%d", &a);
            nd = addnode_back(nd,a);
        }

        else if (n==3)
        {

            print_front(nd);
        }
        else if (n==4)
        {

            print_back(nd);
        }

        else if(n==5)
        {
            update(nd);
        }
        else if(n==6)
        {
            int del;
            printf("Enter the node value to delete:\n");
            scanf("%d",&del);
            nd = delete_nd(nd, del);
        }
        else if(n==7)
        {
            insert_front(nd);
        }

        else if(n==8)
        {
            insert_back(nd);
        }
        else if (n==9)
        {
            return 0;
        }
    }
}

