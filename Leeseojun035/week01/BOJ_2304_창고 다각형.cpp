#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int left = 1001, right = 0, maxHeight = 0, maxPos = 0;
    int arr[1001] = {0};

    for (int i = 0; i < n; i++){
        int l,h;
        cin >> l >> h;
        arr[l] = h;
        left = min(left, l);
        right = max(right, l);
        if (H > maxHeight) {
            maxHeight = h;
            maxPos = l;
        }
    }

    int area = 0;
    int current = 0;

    // 왼쪽 단조 증가
    for (int i = left; i <= maxPos; i++){
        if (arr[i] > current)
            current = arr[i];
        area += current;
    }

    current = 0;
    // 오른쪽 단조 감소
    for (int i = right; i >= maxPos; i--){
        if (arr[i] > current)
            current = arr[i];
        area += current;
    }

    // 두 번 더했으니 한 번 빼줌
    area -= maxHeight;

    cout << area;
    return 0;
}
