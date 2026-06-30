// LeetCode:-410
// Time Complexity :- O(nlog(sum(nums)-max(nums)+1))
// Space Complexity :- O(1)

class Solution
{
public:
    bool canSplit(vector<int> &nums, int k, int maxSum)
    {
        int count = 1;
        int currSum = 0;

        for (int num : nums)
        {
            if (currSum + num <= maxSum)
            {
                currSum += num;
            }
            else
            {
                count++;
                currSum = num;
            }
        }

        return count <= k;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};