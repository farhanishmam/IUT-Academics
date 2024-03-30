#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
    int data;
    struct linked_list *next;
};

typedef struct linked_list *node;

node create_node(void)
{
    node temp;
    temp = (node)malloc(sizeof(struct linked_list));
    temp -> next = NULL;
    return temp;
}

node add_node(node head, int value)
{
     node temp = create_node(),p;
     temp -> data = value;
     if(head == NULL) head = temp;
     else
     {
         p = head;
         while(p -> next != NULL)
         {
             p = p->next;
         }
         p ->next = temp;
     }
     return head;
}

node delete_nd(node n, int del)
{
    if(n->next == NULL)
    {
        return NULL;
    }
    else
    {
        while(n->next != NULL)
        {
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

int main(void)
{
    node n = NULL;
    int a,b;
    for(;;)
    {
        printf("1.Add a node\n2.Print the nodes\n3.Delete node\n4.Exit\n");
        scanf("%d",&a);
        if(a==1)
        {
            printf("Enter a value\n");
            scanf("%d",&b);
            n = add_node(n,b);
        }
        else if(a==2)
        {
            if(n == NULL)
            {
                printf("No node to print\n");
                continue;
            }

            printf("The nodes are:\n");
            for(node i = n; i != NULL; i = i -> next)
            {
                printf("%d ",i -> data);
            }
            printf("\n");
        }
        else if(a == 3)
        {
            n = NULL;
        }
        else exit(1);
    }
}
