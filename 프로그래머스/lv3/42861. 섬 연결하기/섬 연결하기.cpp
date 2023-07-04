#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define INF 987654321
int visited[101];
int parent[101];
struct Link{
    int y,x,dist;
    
    bool operator<(const Link &p) const{
        return dist > p.dist;
    }
};
int find(int i){
    
    if(parent[i]==i)
        return i;
    
    return parent[i]=find(parent[i]);
}
void Union(int x, int y){
    x = find(x);
	y = find(y);
	if (x != y)
	{
		if (x < y)
			parent[y] = x;
		else
			parent[x] = y;
	}
    
    
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    priority_queue<Link> pq;
    for(int i=0;i<n; i++){
        parent[i]=i;
    }
    for(int i=0;i<costs.size(); i++){
        pq.push({costs[i][0],costs[i][1],costs[i][2]});
    }
    int ret=0;
    int cnt=0;
    while(!pq.empty()){
        int y=pq.top().y;
        int x=pq.top().x;
        int dist=pq.top().dist;
        pq.pop();
        int py=find(y);
        int px=find(x);
        if(py!=px){
            Union(y,x);
            ret+=dist;
            cnt++;
        }
    }
    return answer=ret;
}

