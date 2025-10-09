#include <iostream>
using namespace std;
#include<vector>
#include<algorith>

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);

        vector<vector<int>> result;

        for(int i = 0; i<people.size(); i++)
        {
            int position = people[i][1];

            result.insert(result.begin() + position, people[i]);
        }

        return result;
    }

    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] == b[0])return a[1] < b[1];

        return a[0] > b[0];
    }
};

int main()
{
    
}
