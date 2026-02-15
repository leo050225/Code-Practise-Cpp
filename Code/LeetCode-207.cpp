#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);//修了某堂課後能修的課程
        vector<int> inDegree(numCourses, 0);//修課程前需要修的課程數量

        for(const auto& pre : prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);// 修了pre[1]的課才能修pre[0]
            inDegree[pre[0]]++;// 修這堂課前有多少課要修
        }

        queue<int> que;// 不用先修任何課程就能修的課程
        for(int i = 0; i<numCourses; ++i)
        {
            if(inDegree[i] == 0)
            {
                que.push(i);
            }
        }

        int count = 0;
        while(!que.empty())
        {
            int curr = que.front();// 
            que.pop();
            count++;

            for(int nextCourse : adj[curr])
            {
                inDegree[nextCourse]--;// 修這堂課的所需要修的課程數量-1
                
                if(inDegree[nextCourse] == 0)
                {
                    que.push(nextCourse);
                }
            }
        }
        return count == numCourses;
    }
};

int main()
{
    
}


