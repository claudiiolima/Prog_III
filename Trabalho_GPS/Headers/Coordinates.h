#ifndef COORDINATES_H
#define COORDINATES_H

#include <string>

using std::string;

class Coordinates {
  string latitude;
  string longitude;
  string dirLat;
  string dirLon;
  string altitude;

public:
  Coordinates();

  string getLatitude(/*int i*/);
  string getLongitude(/*int i*/);
  string getDirLat(/*int i*/);
  string getDirLon(/*int i*/);
  string getAltitude(/*int i*/);
  void setLatitude(string coor);
  void setLongitude(string coor);
  void setDirLat(string dir);
  void setDirLon(string dir);
  void setAltitude(string coor);
};

#endif
