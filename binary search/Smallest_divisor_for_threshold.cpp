class Solution {
public:
       int SumOfD(vector<int> &nums, int Div){
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum= sum + ceil((double)(nums[i])/(double)(Div));
        }
        return sum;
       }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high= *max_element(nums.begin(),nums.end());
        while(low<=high){
         int mid= low+(high-low)/2;
         if(SumOfD(nums,mid)<=threshold){
            high=mid-1;
         }
         else{
            low=mid+1;
         }
        }
       return low; 
    }
};