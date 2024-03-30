#include <iostream>
using namespace std;

const int QUEUE_MAX = 2;

void enqueue(int arr[],  int &rear, int &count, int val)
{
    if(count>QUEUE_MAX)
    {
        cout<<"QUEUE IS FULL"<<endl;
        return;
    }
    arr[rear] = val;
    rear = (rear+1)%QUEUE_MAX;
    count++;
}

void dequeue(int arr[], int &front, int rear, int &count)
{
    if(count == 0)
    {
        cout<<"QUEUE IS EMPTY"<<endl;
        return;
    }
    front = (front + 1)%QUEUE_MAX;
    count--;
}
void display(int arr[], int front, int rear, int count)
{
    //cout<<front<<" "<<rear<<" "<<count<<endl;
    if(count == 0)
    {
        cout<<"QUEUE IS EMPTY"<<endl;
        return;
    }
    for(int i = front;;i++)
    {
        i = i%QUEUE_MAX;
        if(count == 0) break;
        cout<<arr[i]<<" ";
        count--;
    }
    cout<<endl;
}


int main(void)
{
    int queue[QUEUE_MAX];
    int count = 0;
    int front = 0;
    int rear = 0;
    enqueue(queue, rear, count, 5);
    display(queue,front,rear,count);
    dequeue(queue, front, rear,count);
    display(queue,front,rear,count);
    enqueue(queue, rear,count, 7);
    display(queue,front,rear,count);
    enqueue(queue, rear,count, 8);
    display(queue,front,rear,count);
    dequeue(queue, front, rear,count);
    display(queue,front,rear,count);
    enqueue(queue, rear,count, 8);
    display(queue,front,rear,count);

}