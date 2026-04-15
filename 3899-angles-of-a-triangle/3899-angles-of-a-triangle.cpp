class Solution {
public:
    vector<double> internalAngles(vector<int>& nums) {
        // Here First of all we check whether triangle is Exist or Not. ur("I mean Area is positive or Not")
        // We Know Sum of any two side of triangle is always greater than third side.
        if(((nums[0]+nums[1])>nums[2]) && ((nums[1]+nums[2])>nums[0]) && ((nums[0]+nums[2])>nums[1])){
            double rad1 = (nums[0]*nums[0]+nums[1]*nums[1]-nums[2]*nums[2])/(2.0*nums[0]*nums[1]);
            double rad2 = (nums[0]*nums[0]+nums[2]*nums[2]-nums[1]*nums[1])/(2.0*nums[0]*nums[2]);
            double rad3 = (nums[2]*nums[2]+nums[1]*nums[1]-nums[0]*nums[0])/(2.0*nums[2]*nums[1]);
            vector<double>angles = {(180*acos(rad1))/M_PI,(180*acos(rad2))/M_PI,(180*acos(rad3))/M_PI};
            sort(angles.begin(),angles.end());
            return angles;
        }
        else return {};
    }
};