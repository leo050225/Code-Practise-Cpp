#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
        {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        // int totalLeft = m + (n - m + 1) / 2;
        int totalLeft = (m + n + 1) / 2;

        //在nums1[0, m]區間找分割線
        //nums1[i - 1] <= nums[j] && nums2[j - 1] <= nums1[i]
        int left = 0;
        int right = m;//代表nums1數組要取幾個數

        while(left < right)
        {
            int i = left + (right - left + 1) / 2;
            int j = totalLeft - i;//nums2數組需要取幾個數

            //分割線能再往右走
            if(nums1[i - 1] <= nums2[j])
            {
                //下一輪區間[i, right]
                left = i;
            }
            else
            {
                //下一輪區間[left, i - 1]
                right = i - 1;
            }
        }

        int i = left;//nums1分隔線
        int j = totalLeft - i;//nums2分隔線

        //左邊沒值 設為最小
        //右邊沒值 設為最大
        int nums1LeftMax = i == 0 ? INT_MIN : nums1[i - 1];
        int nums1RightMin = i == m ? INT_MAX : nums1[i];
        int nums2LeftMax = j == 0 ? INT_MIN : nums2[j - 1];
        int nums2RightMin = j == n ? INT_MAX : nums2[j];

        if(((m + n) % 2) == 1)
        {
            return max(nums1LeftMax, nums2LeftMax);
        }
        else
        {
            //最接近分隔線的兩個數/2 左邊最大和右邊最小
            return (double)((max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin))) / 2;
        }
    }
};

int main()
{

}

