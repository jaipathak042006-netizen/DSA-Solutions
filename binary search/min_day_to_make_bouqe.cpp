//LeetCode ;- 1482
//Time Complexity:- O(log n*max_element)
//Space Complexity;- O(1)

class Solution {
public:
    int canMakeMBouqe(vector<int> &bloomDay, int mid, int k){
        int bouqeCount=0;
        int consecutive_count=0;

        for(int i=0; i<bloomDay.size(); i++){

            if(bloomDay[i]<=mid){
                consecutive_count++;
            }
            else{
                consecutive_count=0;
            }

            if(consecutive_count==k){
                bouqeCount++;
                consecutive_count=0;
            }
        }
        return bouqeCount;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int start_day=0;
        int end_day=*max_element(bloomDay.begin(),bloomDay.end());

        int minDays=-1;

        while(start_day<=end_day){
             int mid= start_day+(end_day-start_day)/2;

             if(canMakeMBouqe(bloomDay,mid,k)>=m){
                minDays=mid;
                end_day = mid-1;
             }
             else{
                start_day = mid+1;
             }
        }
        return minDays;
    }
};