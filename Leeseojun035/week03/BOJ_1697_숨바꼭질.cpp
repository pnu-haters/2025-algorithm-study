#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
queue<int> q;
map<int,int> rec;//key: node 번호, value: 시간
int x[2] = {-1,1};
int result;



void BFS(int subinPos,int SsubinPos){

    q.push(SsubinPos);// 그래프 간선을 줄이기 위해 역추적
    rec[SsubinPos] = 0;
    while(q.front()!=subinPos){
        int num = q.front();
        q.pop();

        for(int i = 0; i<2; i++){
            int N = num+x[i];
            if(rec[N]>0)continue;
            rec[N]= rec[num]+1;
            q.push(N);
        }


        if(num%2==0){
          int N = num/2;
          if(rec[N]>0)continue;
          rec[N]=rec[num]+1;
          q.push(N)
;
        }

        }
    result = rec[subinPos];
}


int main()
{
    int subinPos,SsubinPos;
    cin>>subinPos>>SsubinPos;// SsubinPos: 수빈 동생의 위치, subinPos: 수빈의 위치
    BFS(subinPos,SsubinPos);
    cout << result<< endl;
    return 0;
}
