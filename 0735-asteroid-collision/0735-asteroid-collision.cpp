class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty()) st.push(asteroids[i]);
            else{
                bool kept = true;
                if(st.top()>0 && asteroids[i]<0){
                    while(!st.empty() && st.top()>0){
                        if(st.top()<abs(asteroids[i])){
                            st.pop();
                        }
                        else if(st.top()>abs(asteroids[i])){
                            kept = false;
                            break;
                        }
                        else{
                            st.pop();
                            kept = false;
                            break;
                        }
                    }
                }
                if(kept) st.push(asteroids[i]);
            }
        }
        vector<int>nums;
        while(!st.empty()){
            nums.push_back(st.top());
            st.pop();
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};