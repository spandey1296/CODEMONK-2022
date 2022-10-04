// https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ans = new ListNode(-1);
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val > list2->val)
            {
                ans->next = list2;
                list2 = list2->next;
            }
            else
            {
                ans->next = list1;
                list1 = list1->next;
            }
            ans = ans->next;
        }

        while (list1 != NULL)
        {
            ans->next = list1;
            list1 = list1->next;
            ans = ans->next;
        }

        while (list2 != NULL)
        {
            ans->next = list2;
            list2 = list2->next;
            ans = ans->next;
        }

        return ans;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }

        if (l2 == NULL)
        {
            return l2;
        }

        if (l1->val > l2->val)
        {
            swap(l1, l2);
        }

        ListNode *res = l1;

        while (l1 != NULL && l2 != NULL)
        {
            ListNode *temp = NULL;
            while (l1 != NULL && l1->val <= l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }

            temp->next = l2;
            swap(l1, l2);
        }

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}