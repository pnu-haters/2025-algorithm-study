#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Room {
	int min, max;
	vector<pair<int, string>> player;
};

bool compare(pair<int, string>&a, pair<int, string>&b) {
	return a.second < b.second;
}

int main() {
	int p, m;
	int level;
	string name;
	vector<Room> rooms;
	cin >> p >> m;
	while (p--) {
		bool game = false;
		cin >> level >> name;
		for (auto& room : rooms) {
			if (room.player.size() < m && level <= room.max && level >= room.min) {
				room.player.push_back({ level,name });
				game = true;
				break;
			}
		}
		
		if (!game) {
			Room newRoom;
			newRoom.min = level - 10;
			newRoom.max = level + 10;
			newRoom.player.push_back({ level,name });
			rooms.push_back(newRoom);
		}
		
	}
	for (auto& room : rooms) {
		if (room.player.size() == m)
			cout << "Started!" << "\n";
		else cout << "Waiting!" << "\n";

		sort(room.player.begin(), room.player.end(), compare);

		for (auto& Player : room.player)
			cout << Player.first << " " << Player.second << "\n";
	}
}
