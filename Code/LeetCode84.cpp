#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(),0);
        heights.push_back(0);

        int result = 0;

        for(int i = 0; i<heights.size(); i++)
        {
            while(!st.empty() && heights[i] < heights[st.top()])
            {
                int mid = st.top();
                st.pop();

                int w = i - st.top() - 1;
                int h = heights[mid];
                
                result = max(result, h * w);
            }

            st.push(i);
        }

        return result;
    }
};

int main()
{
}
