#ifndef PLAYER_H
#define PLAYER_H

#include "Coordinates.h"
#include <string>

using std::string;

class Player {
  string trackID; // ID do jogador
  int size; // Quantidade de dados
  // Substituir por Coordenada *coor; (Coordenada.h)
  Coordinates *coordinates;
  // double *latitude, *longitude, *altidude; // Vetor de coordenadas do jogador
  // char dirLat, dirLon; // Direcoes inicias das coordenadas
  //
  string *heading; // Vetor de rumos
  string *speed; // Vetor de velocidades

public:
  Player();
  Player(string id, int size);
  ~Player();
  string getID();
  void setID(string id);
  int getSize();
  void setSize(int sz);
  string getLatitudeC(int pos);
  void setLatitudeC(string lat, int pos);
  string getDirLatC(int pos);
  void setDirLatC(string dir_lat, int pos);
  string getLongitudeC(int pos);
  void setLongitudeC(string lon, int pos);
  string getDirLonC(int pos);
  void setDirLonC(string dir_lon, int pos);
  string getAltitudeC(int pos);
  void setAltitudeC(string alt, int pos);
  string getSpeed(int pos);
  void setSpeed(string sp, int pos);
  string getHeading(int pos);
  void setHeading(string hd, int pos);
};

#endif
