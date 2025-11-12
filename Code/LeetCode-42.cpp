#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        stack<int> st;

        for(int i = 0; i<height.size(); i++)
        {
            while(!st.empty() && height[i] > height[st.top()])
            {
                int mid = st.top();
                st.pop();

                if(!st.empty())
                {
                    int h = min(height[st.top()], height[i]) - height[mid];
                    int w = i - st.top() - 1;

                    sum += h * w;
                }
            }
            
            st.push(i);
        }

        return sum;
    }
};

int main()
{
}
