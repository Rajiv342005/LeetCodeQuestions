class ExamTracker {
public:
    int BinarySearch(vector<int>&nums,int target){
        int low=0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]>=target) high=mid-1;
            else low = mid+1;
        }
        return low;
    }
    vector<int>nums;
    vector<long long>prefixsum;
    ExamTracker() {  
        nums.push_back(0);
        prefixsum.push_back(0);   
    }
    void record(int time, int score) {
        nums.push_back(time);
        prefixsum.push_back(prefixsum.back()+score);
        return;
    } 
    long long totalScore(int startTime, int endTime) {
        int index1 = BinarySearch(nums,startTime);
        int index2 = BinarySearch(nums,endTime);
        if(index1>index2) return 0;
        if(nums[index2]>endTime) index2--;
        return prefixsum[index2]-prefixsum[index1-1];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */