class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        unordered_map<int,int>robo;
        int leftcount =0;
        for(int i=0;i<positions.size();i++){
            robo[positions[i]]=i;
            if(directions[i]=='L') leftcount++;
        }
        if(leftcount==positions.size() || leftcount==0) return healths;
        sort(positions.begin(),positions.end());
        vector<int>ans = healths;
        stack<pair<int,int>>st;
        for(int i=0;i<positions.size();i++){
            int health = healths[robo[positions[i]]];
            char dir = directions[robo[positions[i]]];
            if(dir=='R'){
                st.push({robo[positions[i]],health});
            }
            else{
                if(!st.empty()){
                    bool check = false;
                    while(!st.empty()){
                        int currhealth = st.top().second;
                        int index = st.top().first;
                        st.pop();
                        if(currhealth==health){
                            ans[index] = -1;
                            ans[robo[positions[i]]] = -1;
                            check = true;
                            break;
                        }
                        else if(currhealth>health){
                            check = true;
                            ans[robo[positions[i]]] = -1;
                            st.push({index,currhealth-1});
                            break;
                        }
                        else{
                            ans[index] = -1;
                            health -=1;
                        }
                    }
                    if(!check) ans[robo[positions[i]]] = health;
                }
                else continue;
            }    
        }
        while(!st.empty()){
            int health = st.top().second;
            int index = st.top().first;
            st.pop();
            ans[index] = health;
        }
        vector<int>fans;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=-1) fans.push_back(ans[i]);
            else continue;
        } 
        return fans;   
    }
};