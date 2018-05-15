#include <iostream>

using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;

class Month {
private:
  string name;
  unsigned int monthNumber;
  const string _month[13] = {
      "zero", "January", "February",  "March",   "April",    "May",     "June",
      "July", "August",  "September", "October", "November", "December"};

public:
  Month();
  Month(string m);
  Month(int n);

  string getName();
  void setName(string m);
  int getMonthNumber();
  void setMonthNumber(int n);

  Month operator++();
  Month &operator++(int);
  Month operator--();
  Month &operator--(int);
  Month &operator=(Month &M);
  friend ostream &operator<<(ostream &output, const Month &M);
  friend istream &operator>>(istream &input, Month &M);
};
