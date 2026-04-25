class Solution {
public:
    vector<string> split(string s){
        vector<string> parts;
        string temp = "";
        for (char c : s) {
            if (c == ':') {
                parts.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        parts.push_back(temp);
        return parts;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>TAT(n,0);
        stack<string>st;
        for(int i=0;i<logs.size();i++){
            vector<string>txt = split(logs[i]);
            int fun_id = stoi(txt[0]);
            string status = txt[1];
            int start = stoi(txt[2]);
            if(status=="start"){
                if(!st.empty()){
                   vector<string>txt1 = split(st.top());
                   int stat1 = stoi(txt1[2]);
                   TAT[stoi(txt1[0])] += start-stat1;
                   st.push(logs[i]);
                }
                else st.push(logs[i]);
            }
            else{
                vector<string>txt1 = split(st.top());
                st.pop();
                int stat1 = stoi(txt1[2]);
                TAT[fun_id]+= (start-stat1)+1;
                if(!st.empty()){
                    vector<string>txt2 = split(st.top());
                    txt2[2] = to_string(start+1);
                    string s = txt2[0] + ":" + txt2[1] + ":" + txt2[2];
                    st.pop();
                    st.push(s);
                };     
            }
        }
        return TAT;    
    }
};