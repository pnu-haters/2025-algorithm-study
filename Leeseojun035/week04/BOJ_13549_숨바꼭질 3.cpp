#include <iostream>
#include <deque>
#include <map>

/*이번에도 역주행으로 풀려고 했지만 (메모리초과, 틀렸습니다,시간초과 등등) 실패.. 역시 정석적으로 가야하는 것인가.
using namespace std;
deque<int> dq;
map<int,int> rec;
int x[2] = {-1,1};
int result;

//distance[100000];

int BFS(int subinPos,int SsubinPos){

    if(subinPos==SsubinPos) return 0;

    dq.push_front(subinPos);
    rec[subinPos] = 0;
    while(!dq.empty()){

        int num = dq.front();
        if(num==SsubinPos){
            return rec[num];
        }
        dq.pop_front();
         int N = num*2;

          if((N<=100000)&&(!(rec.count(N))||(rec[N]>rec[num]))){
          rec[N]=rec[num];
          dq.push_front(N);//0초 만에 가는 경로를 우선순위로 주기 위해 push_front()
        if(N==SsubinPos) return rec[N];
          }

        for(int i = 0; i<2; i++){

        int N = num+x[i];
        if(N<0)continue;
        if(!(rec.count(N))||(rec[N]>rec[num])){
          rec[N]= rec[num]+1;
          dq.push_back(N);
          if(N==SsubinPos) return rec[N];
          }

        }

        }

}


int main()
{
    int subinPos,SsubinPos;
    cin>>subinPos>>SsubinPos;
    result = BFS(subinPos,SsubinPos);
    cout << result<< endl;
    return 0;
}
