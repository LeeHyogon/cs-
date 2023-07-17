#include <string>
#include <vector>
using namespace std;
#define LINF 321321321321
typedef long long ll;

ll arr1[500001];
ll arr2[500001];

ll ret=-LINF;


long long solution(vector<int> sequence) {
    long long answer = 0;
    ll len=sequence.size();
    
    for(int i=0;i<sequence.size();i++){
        if(i%2==0){
            arr1[i]=sequence[i]*1;
            arr2[i]=sequence[i]*-1;
        }
        else{
            arr1[i]=sequence[i]*-1;
            arr2[i]=sequence[i]*1;
        }
    }
    ll start=0;
    ll val=arr1[0];
    ret=max(val,ret);
    for(int i=1;i<len;i++){
        if(val+arr1[i]<arr1[i]){
            val=arr1[i];
        }
        else{
            if(val<0){
                val=arr1[i];
            }
            else
                val+=arr1[i];
        }
        ret=max(val,ret);    
    }
    val=arr2[0]; 
    ret=max(val,ret);
    for(int i=1;i<len;i++){
        if(val+arr2[i]<arr2[i]){
            val=arr2[i];
        }
        else{
            if(val<0){
                val=arr2[i];
            }
            else
                val+=arr2[i];
        }
        ret=max(val,ret);    
    }
    answer=ret;
    return answer;
}