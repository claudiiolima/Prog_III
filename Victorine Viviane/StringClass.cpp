// Classe String para tornar o uso de strings menos problematico
#include <cstring>
#include <iostream>

class String {
private:
  static const int MAX = 80;
  char str[MAX];

public:
  String() { str[0] = '\0'; }
  String(char ch, int n);
  /*explicit */ String(char s[]) { strcpy(str, s); }
  // String(int i) { itoa(i, str, 10); } // int x; String A = x;
  int Len() const { return strlen(str); }
  void Print() const { std::cout << str << std::endl; }
  // String GetStr() {
  //   gets(str);
  //   return String(str);
  // }
  operator int() const { return atoi(str); } // String A; int x = A
  String operator+=(String &s);              // Concatena
  String operator+(String &s) const;         // Concatena
  bool operator<(String &s) const;
  bool operator==(String &s) const;
};

String::String(char ch, int n) {
  int i;
  for (i = 0; i < n; i++)
    str[i] = ch;
  str[i] = '\0';
}

String String::operator+=(String &s) {
  if (this->Len() + s.Len() < MAX)
    strcat(str, s.str);

  return String(str);
}

String String::operator+(String &s) const {
  char temp[MAX];
  strcpy(temp, str);

  if (this->Len() + s.Len() < MAX)
    strcat(temp, s.str);

  return String(temp);
}

bool String::operator<(String &s) const {
  return (strcmp(str, s.str) < 0) ? true : false;
}

bool String::operator==(String &s) const {
  return (strcmp(str, s.str) == 0) ? true : false;
}

void ordena(String s[], int n) {
  String tmp;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++)
      if (s[j] < s[i]) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
      }
  }
}

const int String::MAX;

// int main() {
//   String S0('=', 45), S1("Feliz Anivesário! ");
//   String S2 = "Denise", S3 = "Bom dia!"; // Não funciona com Construtor
//   explicit
//   String S4, S5, S6;
//
//   S0.Print();
//   std::cout << "S1 = ";
//   S1.Print();
//   std::cout << "S2 = ";
//   S2.Print();
//   std::cout << "S3 = ";
//   S3.Print();
//
//   S3 += S2;
//   S4 = S1 + S2;
//   S5 = S1 + S1;
//
//   std::cout << std::endl;
//   std::cout << "S3 = ";
//   S3.Print();
//   std::cout << "S4 = ";
//   S4.Print();
//   std::cout << "S5 = ";
//   S5.Print();
//
//   S6 = S0;
//
//   S6.Print();
//
//   std::cout << std::endl;
//
//   return 0;
// }

int main(void) {
  String s[4] = {"José Carlos", "Denise", "André", "Hélio"};

  std::cout << "\n\nLista original:" << std::endl;

  for (int i = 0; i < 4; i++) {
    std::cout << "s[" << i << "] = ";
    s[i].Print();
  }

  ordena(s, 4);

  std::cout << "\n\nLista ordenada:" << std::endl;
  for (int i = 0; i < 4; i++) {
    std::cout << "s[" << i << "] = ";
    s[i].Print();
  }

  return 0;
}
