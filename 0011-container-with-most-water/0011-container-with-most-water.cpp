class Solution {
public:
    int maxArea(vector<int>& height) {
        int MaxArea=INT_MIN;
        int pointer1=0;
        int pointer2 = height.size()-1;
        while(pointer1<pointer2){
            int currArea = (pointer2-pointer1)*(min(height[pointer1],height[pointer2]));
            if(currArea>MaxArea) MaxArea = currArea;
            if(height[pointer1]==min(height[pointer1],height[pointer2])){
                pointer1++;
            }
            else{
                pointer2--;
            }
        }
        return MaxArea;
    }
};