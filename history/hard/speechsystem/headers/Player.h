class Player {
public:
  Player() = default;
  Player(short ID) { this->ID = ID; }
  Player(Player &&) = default;
  Player(const Player &) = default;
  Player &operator=(Player &&) = default;
  Player &operator=(const Player &) = default;
  ~Player() = default;
  short ID;
  float avgScore = 0;
};
