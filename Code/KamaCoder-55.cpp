#include<iostream>
using namespace std;
#include<algorithm>

int main()
{
    string s;
    int n;
    cin>>n;
    cin>>s;

    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin()+n);
    reverse(s.begin()+n, s.end());

    cout<<s<<endl;
}
