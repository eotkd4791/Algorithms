#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T,n;
    string str;
    
    cin >> T;
    while(T--)
    {
        priority_queue<pair<string,int>, vector<pair<string,int> >, greater<pair<string,int> > >pq;
        
        cin >> n >> str;
        
        /* 1
        --------------------------*/
        pq.push(make_pair(str, 1));
        
        /* 2
        --------------------------*/
        string tmp = str;
        
        tmp.push_back(tmp.front());
        
        tmp.erase(tmp.begin());
        
        pq.push(make_pair(tmp, 2));
        
        
        /* 3 ~ n - 1
        ------------------------------*/
        string temp = str.substr(0, 1);
        
        for(int k=3; k<n; k++)
        {
            temp += tmp.substr(0, 1);
            
            string newStr = tmp.substr(1, n - k + 1);
            
            if(n % 2 == 0) //문자열 길이가 짝수
            {
                if(k % 2 == 0) //짝수번째 re
                {
                    string rv = temp;
                    reverse(rv.begin(), rv.end());
                    newStr += rv;
                }
                else           //홀수번째
                {
                    newStr += temp;
                }
            }
            else           //문자열 길이가 홀수
            {
                if(k % 2 == 0)  //짝수번째
                {
                    newStr += temp;
                }
                else            //홀수번째 re
                {
                    string rv = temp;
                    reverse(rv.begin(), rv.end());
                    newStr += rv;
                }
            }
            pq.push(make_pair(newStr, k));
            
            tmp = newStr;
        }
        
        /* n
        -------------------------------*/
        reverse(str.begin(), str.end());
        
        pq.push(make_pair(str, n));
        
        cout << pq.top().first << '\n' << pq.top().second << '\n';
    }
    return 0;
}
