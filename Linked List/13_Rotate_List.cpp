// https://leetcode.com/problems/rotate-list/
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
        {
            return head;
        }

        int len = 1;
        ListNode *newH, *tail;
        newH = tail = head;

        while (tail->next != NULL)
        {
            tail = tail->next;
            len++;
        }

        tail->next = head;

        if (k %= len)
        {
            for (int i = 0; i < len - k; i++)
            {
                tail = tail->next;
            }
        }

        newH = tail->next;
        tail->next = nullptr;
        return newH;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}