#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printLinkedList(Node *head)
{
    Node *current = new Node();
    current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void push_front(Node **head, int value)
{
    Node *current = new Node();
    current->data = value;
    current->next = *head;
    *head = current;
}

void pop_front(Node **head)
{
    *head = (*head)->next;
}

void pop_back(Node *head)
{
    Node *current = new Node();
    current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    current->next = NULL;
}

void deleteKey(Node *head, int key)
{
    Node *current = new Node();
    current = head;
    while (current->next != NULL and current->next->data != key)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        cout << "Value not found. ";
    }
    else
    {
        if (current->next != NULL)
            current->next = current->next->next;
        else
            current->next = NULL;
    }
}

int main()
{
    Node *list;
    list = NULL;

    for (int i = 7; i >= 1; i--)
    {
        push_front(&list, i * 10);
    }
    printLinkedList(list);
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            pop_front(&list);
            printLinkedList(list);
        }
        else if (q == 2)
        {
            pop_back(list);
            printLinkedList(list);
        }
        else if (q == 3)
        {
            int k;
            cin >> k;
            deleteKey(list, k);
            printLinkedList(list);
        }
    }
    return 0;
}