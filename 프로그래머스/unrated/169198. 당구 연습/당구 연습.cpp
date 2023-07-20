#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int M,N;

int Mini(int x,int y,int x2,int y2){
    
    int ret=987654321;
    
    if( !(y==y2 &&x2<x) ){
        int ans1= pow(x2+x,2) + pow(y2-y,2);
        ret=min(ans1,ret);
    }
    if( !(y==y2 &&x<x2) ){
        int ans3= pow(x2-2*M+x,2)+ pow(y2-y,2);
        ret=min(ans3,ret);
    }
    if( !(x==x2 &&y2<y) ){
        int ans4= pow(x2-x,2)+pow(y2+y,2);
        ret=min(ans4,ret);
           
    }
    if( !(x==x2 &&y<y2)){
        int ans2= pow(x2-x,2) + pow( y2-2*N+y,2);
        ret=min(ans2,ret);
    }    
    return ret;
}



vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    M=m;
    N=n;
    for(int i=0; i< balls.size();i++){
        int ret=987654321;
        
        int x2=balls[i][0];
        int y2=balls[i][1];
        answer.push_back(Mini(startX,startY,x2,y2));
    }
    return answer;
}