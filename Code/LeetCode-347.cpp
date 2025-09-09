#include <iostream>
using namespace std;
#include<queue>



class Solution {
public:
    class Mycompar
    {
    public:
        bool operator()(const pair<int,int> left, const pair<int,int> right)
        {
            return left.second > right.second;
        }
    };

    void umii(unordered_map<int,int>& m, vector<int>& nums)
    {
        for(int i : nums)
        {
            m[i]++;
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        umii(m, nums);

        priority_queue<pair<int,int>, vector<pair<int,int>>, Mycompar> pq;

        for(unordered_map<int,int> :: iterator it = m.begin(); it!= m.end(); it++)
        {
            pq.push(*it);
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> result(k);

        for(int i = k - 1; i >= 0; i--)
        {
            result[i] = pq.top().first;
            pq.pop();
        }

        return result;
    }
};

int main()
{
    
}
