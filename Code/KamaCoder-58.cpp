#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>


int main()
{
    vector<int> v;
    vector<int> v2;

    int n = 0, num = 0, k = 0;
    
    int a,b;

    cin >> n;

    for(int i = 0; i<n; i++)
    {
        cin >>k;
        num+=k;
        v.push_back(num);
        v2.push_back(k);
    }

    while (cin >> a >> b)
    {
        if(a == 0) cout<<v[b]<<endl;
        else cout<<v[b] - v[a] + v2[a]<<endl;
    }

    return 0;
}
