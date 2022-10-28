/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    priority_queue <int, vector<int>, greater<int> > q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i=0;i<lists.size();i++)
        {
            while(lists[i]!=NULL)
            {
                q.push(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        if(q.empty())
        {
            return NULL;
        }
        cout<<q.size();
        ListNode* head=new ListNode(q.top());
        q.pop();
        ListNode* a=head;
        while(!q.empty())
        {
           a->next=new ListNode(q.top());
            a=a->next;
            q.pop();
        }
        return head;
    }
};
