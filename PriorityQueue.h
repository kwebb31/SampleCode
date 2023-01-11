#include <iostream>
using namespace std;

class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();

    int Dequeue();
    void Enqueue(int value);

    int Size();


private:
    struct Node
    {
        Node* next;
        int data;
    };

    Node* head;
    int length;
};
