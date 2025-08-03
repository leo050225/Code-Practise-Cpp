#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> num_set(nums1.begin(),nums1.end());

        for(int i : nums2)
        {
            if(num_set.find(i) != num_set.end())
            {
                result.insert(i);
            }
        }

        return vector<int>(result.begin(),result.end());
    }
};

// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         int hash[1005] = {0};
//         unordered_set<int> result;

//         for(int i = 0; i<nums1.size(); i++)
//         {
//             hash[nums1[i]] = 1;
//         }
        
//         for(int i = 0; i<nums2.size(); i++)
//         {
//             if(hash[nums2[i]] == 1)
//             {
//                 result.insert(nums2[i]);
//             }
//         }
//         return vector<int>(result.begin(),result.end());
//     }
// };

int main()
{
    return 0;
}
