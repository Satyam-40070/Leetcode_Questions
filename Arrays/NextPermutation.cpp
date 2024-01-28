/*A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the 
array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the 
sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.*/

/*Brute-Force
1. Find all permutations in lexicographic/sequencial manner using recursion
2. search for permutation for which you want to find next permutation
3. print or return or change the given array -> next permutation in the search

Using STL
in-built function : next_permutation(nums.begin(), numd.end()) ;
//return nums;

Implementing
Observations/Intutions:
1. finding longest prefix match i.e. nums[i] < nums[i+1]
2. find the number just greater than nums[i] and replace nums[i] with that
3. arrange the remaining elements in sorted order*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx != -1){
            for(int j=n-1;j>idx;j--){
                if(nums[j] > nums[idx]){
                    swap(nums[j],nums[idx]);
                    break;
                }
            }
            sort(nums.begin()+idx+1,nums.end()); 
            //OR
            //reverse(nums.begin()+idx+1,nums.end());
            
        }else{
            reverse(nums.begin(),nums.end());
        }
    }
};
