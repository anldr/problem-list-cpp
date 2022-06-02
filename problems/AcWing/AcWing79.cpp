/*
 * Visual Studio Code
 * 
 * Create By XuChen
 * 2022/01/23 18:53:05
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> mSet;
        int len = nums.size();
        int left = 0;
        int right = k - 1;
        for (int i = left; i <= right; i++) {
            mSet.insert(nums[i]);
        }
        while (right < len) {
            ans.push_back(*mSet.end());
            mSet.erase(mSet.find(nums[left]));
            left++;
            right++;
            if (right >= len) {
                break;
            }
            mSet.insert(nums[right]);
        }
        return ans;
    }
};

int main () {

    return 0;
}