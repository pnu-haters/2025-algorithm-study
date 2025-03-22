/* dp라는 틀에 너무 박혀있는 거 아닌가? 처음 시도 2와 3을 각각 모듈러 연산을 시도-> 너무 비효율적. 그러나 4이상의 수는 2와
3으로 나타낼 수 있음을 알아냄. 그래서 방향성을 모듈러 연산으로. n을 2로 나누면, 몫은 2를 하나 이상 사용해서 n을 만드는 경우의 가짓수.1만
사용해서 n을 만드는 건 나중에 1더해주는 걸로. 이로써, 1,2는 해결. 3만 해결하면 됨. n//3면 몫은 3을 최대로 사용할 수 있는 수를 의미함.
3을 0부터 몫까지 순회하면서 n에 빼주고, 2 mod 연산을 수행하면 모든 경우의 수 해결.

*/


#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int j = 0; j<T; j++){
    int n;
    cin>>n;
    int result = 0;
    for(int i = 0; i*3<=n; i++){
        int k = n - 3*i;
        result += k/2 +1;

    }
    cout<<result<<'\n';
    }

    return 0;
}
