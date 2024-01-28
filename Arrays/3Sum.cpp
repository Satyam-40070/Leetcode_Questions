/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.*/

/*Base cases after sorting:
If array size is < 3, means no triplet would exist from that array. Return empty vector of vectors.
If first element is +ve, that means there is no -ve number by which we can make a 0 triplet sum. Return empty vector of vectors.
    
Two Pointer Approach:
The basic thinking logic for this is: Fix any one number in sorted array and find the other two numbers after it. The other two numbers can be easily found using 
two pointers (as array is sorted) and two numbers should have sum = -1*(fixed number).

Traverse the array and fix a number at every iteration.
If number fixed is +ve, break there because we can't make it zero by searching after it.
If number is getting repeated, ignore the lower loop and continue. This is for unique triplets. We want the last instance of the fixed number, if it is repeated.
Make two pointers high and low, and initialize sum as 0.
Search between two pointers, just similiar to binary search. Sum = num[i] + num[low] + num[high].
If sum is -ve, means, we need more +ve numbers to make it 0, increament low (low++).
If sum is +ve, means, we need more -ve numbers to make it 0, decreament high (high--).
If sum is 0, that means we have found the required triplet, push it in answer vector.
Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively. Update the low and high with last occurences 
of low and high.*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(),nums.end());
        if(nums.size()<3 || nums[0]>0){
            return {};
        }
        
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0){
                break;
            }
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int low=i+1, high=nums.size()-1;
            int sum=0;
            while(low<high){
                sum=nums[i]+nums[low]+nums[high];
                if(sum>0){
                    high--;
                }
                else if(sum<0){
                    low++;
                }
                else{
                    result.push_back({nums[i],nums[low],nums[high]});
                    int last_low=nums[low], last_high=nums[high];
                    while(low<high && nums[low]==last_low){
                        low++;
                    }
                    while(low<high && nums[high]==last_high){
                        high--;
                    }
                    
                }
            }
        }
        return result;
    }
};

/*
