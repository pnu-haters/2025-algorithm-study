#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, D, start, end, dis; // N은 지름길 개수, D는 고속도로 길이

    cin >> N >> D;
    vector<int> road(D + 1, 10000); // i 지점까지 가는 최소 거리
    vector<pair<int, int>> sc[10001]; // i로 도착하는 지름길 리스트 
    for (int i = 0; i < N; i++) {
        cin >> start >> end >> dis;
        sc[end].push_back({ start,dis });
    }
    road[0] = 0;
    for (int i = 1; i <= D; i++) {
        // i-1 지점으로 가는 지름길 +1 vs road[i]에 들어있는 값  => i로 가는 지름길 사용 X
        road[i] = min(road[i], road[i - 1] + 1);

        // road[i]에 들어있는 값 vs i 지점으로 가는 지름길의 처음지점 + 지름길 길이  => i로 가는 지름길 사용 O
        for (auto v : sc[i]) {
            road[i] = min(road[i], road[v.first] + v.second);
        }
    }
    cout << road[D];
    return 0;
}
