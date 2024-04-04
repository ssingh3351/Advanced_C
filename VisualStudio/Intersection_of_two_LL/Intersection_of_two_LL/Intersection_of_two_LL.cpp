#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

}*head1 = NULL, * head2 = NULL;

void create1(int A[], int n) // creating a linked list
{
    head1 = new Node;
    head1->data = A[0];
    head1->next = NULL;
    Node* last = head1;
    Node* t;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int B[], int n, Node* q) // creating a linked list
{
    head2 = new Node;
    head2->data = B[0];
    head2->next = NULL;
    Node* last = head2;
    Node* t;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    last->next = q;
}
void Display(struct Node* head)
{
    Node* p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int IntersectionPointUsingStack(struct Node* head1, struct Node* head2) {
    stack<Node*> st1;
    stack<Node*> st2;
    Node* p = head1;
    Node* q = head2;

    while (p != NULL) {
        st1.push(p);
        p = p->next;
    }
    while (q != NULL) {
        st2.push(q);
        q = q->next;
    }

    Node* i = NULL;
    while (st1.top() == st2.top()) {
        i = st1.top();
        st1.pop();
        st2.pop();
    }
    return i->data;

}


int main()
{
    int A[] = { 8,6,3,9,10,4,2,2 };
    int B[] = { 20,30,40 };
    int n1 = sizeof(A) / sizeof(A[0]);
    create1(A, n1);

    Node* temp = head1;

    int i = 4;
    while (i > 0)
    {
        temp = temp->next;
        i--;
    }

    cout << "Here we have connected 2nd LL to 1st LL at Node = " << temp->data << endl;

    int n2 = sizeof(B) / sizeof(B[0]);
    create2(B, n2, temp);
    cout << "First Linked List: ";
    Display(head1);
    cout << "\nSecond Linked List: ";
    Display(head2);
    cout << endl;
    cout << "Intersection Point: " << IntersectionPointUsingStack(head1, head2) << endl;


}

