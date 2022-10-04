// https://leetcode.com/problems/intersection-of-two-linked-lists/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }

        ListNode *a = headA, *b = headB;
        while (a != b)
        {
            a = (a == NULL ? headB : a->next);
            b = (b == NULL ? headA : b->next);
        }

        return a;
    }
};

int main()
{

    return 0;
}