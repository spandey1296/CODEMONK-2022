// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *mergeTwoLists(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;

    while (a != NULL and b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if (a)
    {
        temp->bottom = a;
    }
    else
    {
        temp->bottom = b;
    }

    return res->bottom;
}

Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
    {
        return root;
    }

    root->next = flatten(root->next);
    root = mergeTwoLists(root, root->next);

    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}