// Difference Between Element Sum and Digit Sum of an Array
#include<bits/stdc++.h>
using namespace std;

// You are given a positive integer array nums.
// The element sum is the sum of all the elements in nums.
// The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
// Return the absolute difference between the element sum and digit sum of nums.
// Note that the absolute difference between two integers x and y is defined as |x - y|.

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int digSum = 0, eleSum = 0;
        for(int i=0; i<n; i++) {
            eleSum += nums[i];
            int ele = nums[i];
            while(ele > 0) {
                int dig = ele % 10;
                ele = ele / 10;
                digSum += dig;
            }
        }
        
        return abs(eleSum - digSum);
    }
};