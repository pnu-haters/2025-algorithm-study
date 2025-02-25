#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Player {
public:
	string name_;
	int level_;

	Player(string name, int level) {
		name_ = name;
		level_ = level;
	}
	// ����
	bool operator<(const Player& other) const {
		return name_ < other.name_;
	}

};

class GameRoom {
public:
	int room_index; //�������� ���� (1���� ����)
	int max_num_;
	int min_level;
	int max_level;
	vector<Player> players;
	
	//�� �ʱ�ȭ �Լ�
	GameRoom(int index, int max_num, Player first_player ) {
		room_index = index;
		max_num_ = max_num;
		min_level = first_player.level_ - 10;
		max_level = first_player.level_ + 10;
		players.push_back(first_player);
	}

	void add_player(string name, int level);
};

void GameRoom::add_player(string name, int level) {
	Player p(name, level);
	players.push_back(p);
}

int max_num;
int search_match_room(int player_level, vector<GameRoom> game_rooms);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<GameRoom> game_rooms;
	int T;
	int player_level, room_index = 0, match_room_index;
	string player_name;

	cin >> T >> max_num;

	for (int i = 0; i < T; i++) {
		cin >> player_level >> player_name;
		Player p(player_name, player_level);

		//���� ���� �ϳ��� ���ų� ��Ī�Ǵ� ���� ������ -> ���ο� ���� �ʱ�ȭ �ϱ�
		if (game_rooms.empty() || !(match_room_index = search_match_room(player_level, game_rooms))) {
			GameRoom r(++room_index, max_num, p);
			game_rooms.push_back(r);
		}
		else { //��Ī�Ǵ� ���� ã���� �ش� �濡 �÷��̾� �ֱ�, �̶� ���� ������ room index �� 1�������� ������ �ε����� 0���� �̹Ƿ� 1 ���ֱ�
			game_rooms[match_room_index - 1].players.push_back(p);
		}
	}

	//���..���ĵ� �ؾ� �ϳ�,,
	for (GameRoom game_room : game_rooms) {
		if (game_room.players.size() == max_num) cout << "Started!\n";
		else cout << "Waiting!\n";

		sort(game_room.players.begin(), game_room.players.end());

		for (Player player : game_room.players) {
			cout << player.level_ << " " << player.name_ << "\n";
		}
	}


}

int search_match_room(int player_level, vector<GameRoom> game_rooms) {
	for (GameRoom room : game_rooms) {
		//�� �ο��� �����ְ�, ������ �´� ��� -> ���� �ε��� ��ȯ
		if (room.players.size() < max_num && (player_level <= room.max_level) && (player_level >= room.min_level)) {
			return room.room_index;
		}
	}
	return 0;
}