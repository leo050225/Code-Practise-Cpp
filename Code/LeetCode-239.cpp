#include<iostream>
using namespace std;
#include<vector>
#include<deque>


class Solution {
public:
    class Myque
    {
    public:
        deque<int> que;

        void pop(int value)
        {
            if(!que.empty() && value == que.front())//還在代表都是之前的最大 消除 如果沒有就代表之前已經被消除
                que.pop_front();
        }

        void push(int value)
        {
            while(!que.empty() && value > que.back())//有比value小的就消除掉
                que.pop_back();
            que.push_back(value);
        }

        int front()//返回最大的數字
        {
            return que.front();
        }

    };
   
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        Myque que;
        for(int i = 0; i<k; i++)//先把前K個裝進去
        {
            que.push(nums[i]);
        }

        result.push_back(que.front());//先找出第一次最大的

        for(int i = k; i<nums.size(); i++)//開始移動框
        {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }

        return result;
    }
};

int main()
{

} 
