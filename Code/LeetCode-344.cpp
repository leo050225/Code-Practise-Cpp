#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while(left<right)
        {
            swap(s[left], s[right]);

            left++;
            right--;
        }
    }
};

int main()
{
    return 0;
}
