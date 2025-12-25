/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Updatefreq(TreeNode*root,unordered_map<int,int>&m){
        if(!root) return;
        m[root->val]++;
        Updatefreq(root->left,m);
        Updatefreq(root->right,m);
     }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>m;
        Updatefreq(root,m);
        vector<pair<int,int>>nums(m.begin(),m.end());
        sort(nums.begin(),nums.end(),
           [](const pair<int,int>&a, const pair<int,int>&b){
            return a.second>b.second;
        });
        int count = nums[0].second;
        vector<int>ans;
        for(auto it:nums){
            if(it.second==count){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};