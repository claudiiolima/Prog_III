#include "../Headers/Coordinates.h"

Coordinates::Coordinates() {}

string Coordinates::getLatitude() { return latitude; }

string Coordinates::getLongitude() { return longitude; }

string Coordinates::getDirLat() { return dirLat; }

string Coordinates::getDirLon() { return dirLon; }

string Coordinates::getAltitude() { return altitude; }

void Coordinates::setLatitude(string coor) { latitude = coor; }

void Coordinates::setLongitude(string coor) { longitude = coor; }

void Coordinates::setDirLat(string dir) { dirLat = dir; }

void Coordinates::setDirLon(string dir) { dirLon = dir; }

void Coordinates::setAltitude(string coor) { altitude = coor; }
