Player::Player(Player other){ //copy constractor
    name = other.name;
    position = other.position;
    strategy = other.strategy;
}

Player& Player::operator=(const Player other){
    if (this!=&other){
    name = other.name;
    position = other.position;
    strategy = other.strategy;
    }
