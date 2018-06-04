#include "../Headers/Player.h"
#include <string>

using std::string;

Player::Player() {
  coordinates = new Coordinates[1];
  heading = new string[1];
  speed = new string[1];
}

Player::Player(string id, int sz) : trackID(id), size(sz) {
  coordinates = new Coordinates[sz];
  heading = new string[sz];
  speed = new string[sz];
}

Player::~Player() {
  delete[] coordinates;
  delete[] heading;
  delete[] speed;
}

string Player::getID() { return trackID; }

void Player::setID(string id) { trackID = id; }

int Player::getSize() { return size; }

void Player::setSize(int sz) {
  delete[] coordinates;
  delete[] heading;
  delete[] speed;

  coordinates = new Coordinates[sz];
  heading = new string[sz];
  speed = new string[sz];
}

string Player::getLatitudeC(int pos) { return coordinates[pos].getLatitude(); }
//
void Player::setLatitudeC(string lat, int pos) {
  coordinates[pos].setLatitude(lat);
}

string Player::getDirLatC(int pos) { return coordinates[pos].getDirLat(); }

void Player::setDirLatC(string dir_lat, int pos) {
  coordinates[pos].setDirLat(dir_lat);
}

string Player::getLongitudeC(int pos) {
  return coordinates[pos].getLongitude();
}

void Player::setLongitudeC(string lon, int pos) {
  coordinates[pos].setLongitude(lon);
}

string Player::getDirLonC(int pos) { return coordinates[pos].getDirLon(); }

void Player::setDirLonC(string dir_lon, int pos) {
  coordinates[pos].setDirLon(dir_lon);
}

string Player::getAltitudeC(int pos) { return coordinates[pos].getAltitude(); }

void Player::setAltitudeC(string alt, int pos) {
  coordinates[pos].setAltitude(alt);
}

string Player::getSpeed(int pos) { return speed[pos]; }

void Player::setSpeed(string sp, int pos) { speed[pos] = sp; }

string Player::getHeading(int pos) { return heading[pos]; }

void Player::setHeading(string hd, int pos) { heading[pos] = hd; }
