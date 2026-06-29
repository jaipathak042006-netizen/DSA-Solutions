//LeetCode:- 1552
//Time Complexity:- O(nlogn)
//Space Complexity:- O(1)
class Solution {
public:
bool canWePlace(vector<int> &position,int dist, int balls){
       int cntBalls=1;
       int last=position[0];
       for(int i=1;i<position.size();i++){
           if(position[i]-last>=dist){
               cntBalls++;
               last=position[i];
           }
           if(cntBalls>=balls){
               return true;
           }
           
       }
       return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        
        int low=1;
        int n= position.size();
        int high= position[n-1]-position[0];
        
        while(low<=high){
            
            int mid= low+(high-low)/2;
            
            if(canWePlace(position,mid,m)==true){
                low=mid+1;
            }
               else{
                   high=mid-1;
               }
        }
        return high;
    }
};