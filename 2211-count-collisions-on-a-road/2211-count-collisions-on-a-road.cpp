class Solution {
public:
    int countCollisions(string directions) {
        int Collision =0;
        bool IsStatic = false;
        stack<char>st;
        for(int i=0;i<directions.size();i++){
            if(st.empty()){
                if(directions[i]=='R') st.push(directions[i]);
                else if(directions[i]=='S') IsStatic=true;
                else if(directions[i]=='L' && IsStatic) Collision++;
                else continue;
            }
            else{
                if(directions[i]=='R') st.push(directions[i]);
                else if(directions[i]=='S'){
                    Collision+=st.size();
                    while(!st.empty()) st.pop();
                    IsStatic = true;
                }
                else{
                    Collision+=2;
                    st.pop();
                    Collision+= st.size();
                    while(!st.empty()) st.pop();
                    IsStatic = true;
                }
            }
        }
        return Collision;   
    }
};