#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int,int> > edge[7];
int cost[7], INF = 987654321;

void dijk(int start)
{
    cost[start] = 0;
    priority_queue<pair<int,int> > pq;
    
    pq.push(make_pair(start, 0));
    
    while(!pq.empty())
    {
        int cur = pq.top().first;
        int distance = -pq.top().second;
        
        pq.pop();
        
        if(cost[cur] < distance) continue;
        
        for(int i=0; i < (int) edge[cur].size(); i++)
        {
            int next = edge[cur][i].first;
            
            int nextDist = distance + edge[cur][i].second;
            
            if(nextDist < cost[next])
            {
                cost[next] = nextDist;
                pq.push(make_pair(next, -nextDist));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int nodeCnt = 10;
    
    for(int i=1; i<= nodeCnt; i++)
    {
        cost[i] = INF;
    }
    dijk(1);
    return 0;
}
