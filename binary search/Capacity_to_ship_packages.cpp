//Leetcode:- 1011
//Time Complexity:- O(n log(sum(weight)-max(weight) +1))
//Space Complexity:- O(1)

class Solution {
public:

    int FindDays(vector<int> &weights, int capacity){
        int load=0;
        int TotalDays=1;
        for(int i=0;i<weights.size();i++){
             if(weights[i]+load>capacity){
                   TotalDays++;
                   load=weights[i];     
             }
               else{
                load += weights[i];
               }
        }
        return TotalDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low= *max_element(weights.begin(),weights.end());
        int high= accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid= low + (high-low)/2;

            if(FindDays(weights,mid) <= days){
                high=mid-1;
            }
             else{
                    low=mid+1;    
            }
        }
        return low;
    }
};