// https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> st;
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (st.find(temp) != st.end())
            {
                return temp;
            }
            st.insert(temp);
            temp = temp->next;
        }

        return NULL;
    }
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *entery = head;
        while (fast->next != NULL and fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                while (slow != entery)
                {
                    slow = slow->next;
                    entery = entery->next;
                }
                return entery;
            }
        }

        return NULL;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}