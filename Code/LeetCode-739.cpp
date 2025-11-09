#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> result(temperatures.size(), 0);

        stack<int> st;
        st.push(0);

        for (int i = 1; i < temperatures.size(); i++)
        {
            if(temperatures[st.top()] >= temperatures[i])
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && temperatures[i] > temperatures[st.top()])
                {
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};

int main()
{
}
