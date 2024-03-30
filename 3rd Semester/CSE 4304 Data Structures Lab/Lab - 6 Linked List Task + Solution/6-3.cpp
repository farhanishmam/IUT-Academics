#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *previous;
};

void printLinkedList(Node *head)
{
    Node *current = new Node();
    current = head;
    cout << "Actual: ";
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void reversePrint(Node *head)
{
    Node *current = new Node();
    current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    cout << "Reverse: ";
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->previous;
    }
    cout << endl;
}

void push_front(Node **head, int value)
{
    Node *current = new Node();
    current->data = value;
    if (*head != NULL)
        (*head)->previous = current;
    current->next = *head;
    *head = current;
}

void push_back(Node *head, int value)
{
    Node *current = new Node();
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->previous = current;
}

void insert(Node *head, int key, int value)
{
    Node *current = new Node();
    current = head;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    while (current != NULL and current->data != key)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        cout << "Value not found." << endl;
    }
    else
    {
        newNode->next = current->next;
        newNode->previous = current;
        if (current->next != NULL)
        {
            current->next->previous = newNode;
        }
        current->next = newNode;
    }
}

int main()
{
    Node *list;
    list = NULL;

    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int n;
            cin >> n;
            push_front(&list, n);
            printLinkedList(list);
            reversePrint(list);
        }
        else if (q == 2)
        {
            int n;
            cin >> n;
            push_back(list, n);
            printLinkedList(list);
            reversePrint(list);
        }
        else if (q == 3)
        {
            int k, n;
            cin >> k >> n;
            insert(list, k, n);
            printLinkedList(list);
            reversePrint(list);
        }
    }
    return 0;
}