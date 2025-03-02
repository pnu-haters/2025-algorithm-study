#include <bits/stdc++.h>

using namespace std;

#define MAX 300


typedef struct {
    int level;
    string nickname;
} Player;

typedef struct {
    Player players[MAX];
    int size;
} Room;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int p, m;
    cin >> p >> m;

    Room rooms[MAX];
    int roomCount = 0;

    for (int i = 0; i < p; i++) {
        int level;
        string nickname;
        cin >> level >> nickname;

        int check = 0; // 방을 찾았는지 체크
        //들어갈 수 있는 방 있는지 체크 
        for (int j = 0; j < roomCount; j++) {
            if (rooms[j].size < m &&   rooms[j].players[0].level - 10 <= level &&  level <= rooms[j].players[0].level + 10) {
                rooms[j].players[rooms[j].size].level = level;
                rooms[j].players[rooms[j].size].nickname = nickname;
                rooms[j].size++;
                check = 1;
                break;
            }
        }
        // 새 방 생성 

        if (!check) {
            rooms[roomCount].players[0].level = level;
            rooms[roomCount].players[0].nickname = nickname;
            rooms[roomCount].size = 1;
            roomCount++;
        }
    }

    for (int i = 0; i < roomCount; i++) {
        sort(rooms[i].players, rooms[i].players + rooms[i].size, [](const Player& a, const Player& b) {
            return a.nickname < b.nickname;
        });
    }

    for (int i = 0; i < roomCount; i++) {
        cout << (rooms[i].size == m ? "Started!" : "Waiting!") << "\n";
        for (int j = 0; j < rooms[i].size; j++) {
            cout << rooms[i].players[j].level << " " << rooms[i].players[j].nickname << "\n";
        }
    }

    return 0;
}
