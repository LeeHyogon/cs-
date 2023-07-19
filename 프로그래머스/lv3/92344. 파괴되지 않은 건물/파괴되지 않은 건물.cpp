#include <string>
#include <vector>

using namespace std;
int N,M;
int arr[1001][1001];

void range(int y1,int x1, int y2, int x2,int degree){
    
    arr[y1][x1]+=degree;
    arr[y2+1][x1]-=degree;
    arr[y2+1][x2+1]+=degree;
    arr[y1][x2+1]-=degree;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    N=board.size();
    M=board[0].size();
    for(int i=0;i<skill.size();i++){
        int type=skill[i][0];
        int y1=skill[i][1];
        int x1=skill[i][2];
        int y2=skill[i][3];
        int x2=skill[i][4];
        int degree=skill[i][5];
        if(type==1){
            range(y1,x1,y2,x2,-degree);
        }
        else
            range(y1,x1,y2,x2,degree);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            arr[i][j+1]+=arr[i][j];
        }
    }
    for(int j=0;j<M;j++){
        for(int i=0; i<N; i++){
             arr[i+1][j]+=arr[i][j];    
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j]+arr[i][j]>0)
                answer++;
        }
    }
    
    return answer;
}