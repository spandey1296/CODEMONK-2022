// https://leetcode.com/problems/copy-list-with-random-pointer/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mpp;
        Node *temp = head;
        while (temp != NULL)
        {
            mpp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL)
        {
            Node *copy = mpp[temp];
            copy->next = mpp[temp->next];
            copy->random = mpp[temp->random];
            temp = temp->next;
        }

        return mpp[head];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}