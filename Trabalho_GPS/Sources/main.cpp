#include "../Headers/Player.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  try {
    ifstream arq; // variavel stream do tipo input

    arq.open("../example.csv"); // Abrindo arquivo com nome example.csv em um
                                // diretório acima
    if (!arq.is_open())
      throw "Não foi possível abrir arquivo"s; // Exceção caso arquivo não foi
                                               // aberto

    Player p1, p2; // objetos da classe Player

    string index, aux;                    // quantidade
    string trackID;                       // ID do jogador
    string valid;                         // validade
    string utcDate, utcTime;              // data e hora utc
    string localDate, localTime;          // data e hora local
    string ms;                            // nao sei
    string latitude, longitude, altitude; // coordenadas do jogador
    string dirLat, dirLon;                // direcoes inicias das coordenadas
    string speed;                         // velocidade
    string heading;                       // rumo
    string GX, GY, GZ;                    // nao sei

    int size2ini, size2fin;

    while (getline(arq, aux, ',') && getline(arq, trackID, ',') &&
           getline(arq, valid, ',') && getline(arq, utcDate, ',') &&
           getline(arq, utcTime, ',') && getline(arq, localDate, ',') &&
           getline(arq, localTime, ',') && getline(arq, ms, ',') &&
           getline(arq, latitude, ',') && getline(arq, dirLat, ',') &&
           getline(arq, longitude, ',') && getline(arq, dirLon, ',') &&
           getline(arq, altitude, ',') && getline(arq, speed, ',') &&
           getline(arq, heading, ',') && getline(arq, GX, ',') &&
           getline(arq, GY, ',') && getline(arq, GZ, '\n')) {
      // Laço while com leituras, o retorno das leituras limitam o while, ou
      // seja quando qualquer leitura der erro o laço é interrompido

      index =
          aux; // inicialização do index, porque quando o laço for
               // interrompido, isso se tudo correr bem, a variavel aux
               // estará vazia, pois é a 1ª leitura a ser efetuada a dar erro
      if (trackID == "1") {
        size2ini = stoi(index);
        p1.setID("1");
        p1.setSize(size2ini);
      }
      // TESTES DE SAIDA
      // if (index != "INDEX") {
      // cout << "INDEX " << index << '\n';
      // cout << "TRACK ID " << trackID << '\n';
      // cout << valid << ' ';
      // cout << utcDate << ' ';
      // cout << utcTime << ' ';
      // cout << "LOCAL DATE " << localDate << '\n';
      // cout << "LOCAL TIME " << localTime << '\n';
      // cout << ms << ' ';
      // cout << "LATITUDE " << latitude << '\n';
      // cout << "N/S " << dirLat << '\n';
      // cout << "LONGITUDE " << longitude << '\n';
      // cout << "E/W " << dirLon << '\n';
      // cout << "ALTITUDE " << altitude << '\n';
      // cout << "SPEED " << speed << '\n';
      // cout << "HEADING " << heading << '\n';
      // cout << GX << ' ';
      // cout << GY << ' ';
      // cout << GZ << ' ';
      // cout << "------------------------" << endl;
      // }
    }
    size2fin = stoi(index);

    p2.setID("2");
    p2.setSize(size2fin - size2ini);

    arq.clear();
    arq.seekg(125);

    for (int i = 0; i < size2ini; i++) {
      getline(arq, index, ',');   // Já inserido
      getline(arq, trackID, ','); // Já inserido
      getline(arq, valid, ',');
      getline(arq, utcDate, ',');
      getline(arq, utcTime, ',');
      getline(arq, localDate, ',');
      getline(arq, localTime, ',');
      getline(arq, ms, ',');
      getline(arq, latitude, ',');  // Já inserido
      getline(arq, dirLat, ',');    // Já inserido
      getline(arq, longitude, ','); // Já inserido
      getline(arq, dirLon, ',');    // Já inserido
      getline(arq, altitude, ',');  // Já inserido
      getline(arq, speed, ',');     // Já inserido
      getline(arq, heading, ',');   // Já inserido
      getline(arq, GX, ',');
      getline(arq, GY, ',');
      getline(arq, GZ, '\n');

      p1.setLatitudeC(latitude, i);
      p1.setDirLatC(dirLat, i);
      p1.setLongitudeC(longitude, i);
      p1.setDirLonC(dirLon, i);
      p1.setAltitudeC(altitude, i);
      p1.setSpeed(speed, i);
      p1.setHeading(heading, i);
    }
    for (int i = 0; i < size2fin - size2ini; i++) {
      getline(arq, index, ',');   // Já inserido
      getline(arq, trackID, ','); // Já inserido
      getline(arq, valid, ',');
      getline(arq, utcDate, ',');
      getline(arq, utcTime, ',');
      getline(arq, localDate, ',');
      getline(arq, localTime, ',');
      getline(arq, ms, ',');
      getline(arq, latitude, ',');  // Já inserido
      getline(arq, dirLat, ',');    // Já inserido
      getline(arq, longitude, ','); // Já inserido
      getline(arq, dirLon, ',');    // Já inserido
      getline(arq, altitude, ',');  // Já inserido
      getline(arq, speed, ',');     // Já inserido
      getline(arq, heading, ',');   // Já inserido
      getline(arq, GX, ',');
      getline(arq, GY, ',');
      getline(arq, GZ, '\n');

      p2.setLatitudeC(latitude, i);
      p2.setDirLatC(dirLat, i);
      p2.setLongitudeC(longitude, i);
      p2.setDirLonC(dirLon, i);
      p2.setAltitudeC(altitude, i);
      p2.setSpeed(speed, i);
      p2.setHeading(heading, i);
    }

    // TESTES DE SAIDA
    // cout << "\n\n>>>" << p1.getSpeed(size2ini - 1) << "<<<\n";
    // cout << ">>>" << p1.getLatitudeC(size2ini - 1) << "<<<\n\n";
    // cout << "\n\n>>>" << p2.getSpeed(size2fin - size2ini - 1) << "<<<\n";
    // cout << ">>>" << p2.getLongitudeC(size2fin - size2ini - 1) << "<<<\n\n";

    arq.close(); // Fechando arquivo
    return 0;
  } catch (string erro) {
    cout << erro; // "Output" do erro
  }
}
