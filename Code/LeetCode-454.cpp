#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> num_map;
        
        int count = 0;

        for(int i = 0; i<nums1.size(); i++)
        {
            for(int j = 0; j<nums2.size(); j++)
            {
                num_map.insert(pair<int,int>{nums1[i]+nums2[j] , num_map[nums1[i]+nums2[j]]++});
            }
        }

        for(int i = 0; i<nums3.size(); i++)
        {
            for(int j = 0; j<nums4.size(); j++)
            {
                int target = 0 - (nums3[i] + nums4[j]);
                
                if(num_map.find(target)!= num_map.end())
                {
                    count+=num_map[target];
                }
            }
        }
        return count;
    }
};

// class Solution {
// public:
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//         unordered_map<int,int> num_map;

//         int count = 0;

//         for(int a : nums1)
//         {
//             for(int b : nums2)
//             {
//                 num_map[a+b]++;
//             }
//         }

//         for(int c : nums3)
//         {  
//             for(int d : nums4)
//             {
//                 int target = 0 - (c + d);

//                 if(num_map.find(target) != num_map.end())
//                 {
//                     count += num_map[target];
//                 }
//             }
//         }
//         return count;
//     }
// };

int main()
{
    return 0;
}
