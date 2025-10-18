class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack <char> s;
        int index =0;
        string new1 ="";
        while(index<nums.size()){
            if(s.empty()){
                s.push(nums[index]);
                index++;
            }
            else if(s.top()>nums[index]){
                while(!s.empty()&& s.top()>nums[index] && k!=0){
                    s.pop();
                    k--;
                }
                s.push(nums[index]);
                index++;
            }
            else{
                s.push(nums[index]);
                index++;
            }
        }
        while(!s.empty() && k!=0){
            s.pop();
            k--;
        }
        while(s.size()){
            new1+=s.top();
            s.pop();
        }
        reverse(new1.begin(),new1.end());
        index =0;
        while(index<new1.size() && new1[index]=='0') index++;
        new1 = new1.substr(index);
        if (new1.empty()) return "0";
        return new1;
    }
};