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
    bool isMin(vector<int> &arr, int k){
        return arr[k] < arr[k-1] && arr[k] < arr[k+1];
    }

    bool isMax(vector<int> &arr, int k){
        return arr[k] > arr[k-1] && arr[k] > arr[k+1];
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head)
            return {-1,-1};
        vector<int> arr;
        ListNode *temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();

        if (n<=2)
            return {-1,-1};
        
        vector<int> critical;
        for (int i=1; i<n-1; i++){
            if (isMin(arr, i) || isMax(arr, i))
                critical.push_back(i);
        }

        if (critical.size()==0 || critical.size()==1)
            return {-1,-1};

        sort(critical.begin(), critical.end());
        int mn=INT_MAX;
        int mx = critical[critical.size()-1] - critical[0];
        for (int i=1; i<critical.size(); i++){
            mn = min(mn, critical[i]-critical[i-1]);
        }
        return {mn,mx};
    }
};