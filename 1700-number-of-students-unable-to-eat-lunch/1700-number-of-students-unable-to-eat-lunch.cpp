class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count1=0;
        int count0=0;
        for(int i=0;i<students.size();i++){
            if(students[i]==0){
                count0++;
            }
            else count1++;
        }
        for(int i=0;i<sandwiches.size();i++){
            if(sandwiches[i]==0 && count0!=0 || sandwiches[i]==1 && count1!=0){
                if(sandwiches[i]==0) count0--;
                else count1--;
            }
            else return count0+count1;
        }
        return count0+count1;
    }
};