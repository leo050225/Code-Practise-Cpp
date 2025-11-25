#include<iostream>
using namespace std;
#include<unordered_map>
#include<unordered_map>
#include<unordered_set>
#include<queue>

int main()
{   
    int n;
    string beginstr, endstr, str;
    cin>>n;
    cin>>beginstr>>endstr;

    unordered_set<string> strSet;

    for(int i = 0; i<n; i++)
    {
        cin>>str;
        strSet.insert(str);
    }

    unordered_map<string, int> visitedMap;
    queue<string> que;
    que.push(beginstr);

    visitedMap.insert(pair<string, int>{beginstr, 1});

    while(!que.empty())
    {
        string word = que.front();
        que.pop();

        int path = visitedMap[word];

        for(int i = 0; i<word.size(); i++)
        {
            string newWrod = word;

            for(int j = 0; j<26; j++)
            {
                newWrod[i] = j +'a';
                if(newWrod == endstr)
                {
                    cout<<path + 1<<endl;
                    return 0;
                }

                if(strSet.find(newWrod) != strSet.end() && visitedMap.find(newWrod) == visitedMap.end())
                {
                    visitedMap.insert(pair<string, int>{newWrod, path + 1});
                    que.push(newWrod);
                } 
            }
        }
    }

    cout<<0<<endl;
}
