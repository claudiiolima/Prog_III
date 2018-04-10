#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student {
private:
  int age, std;
  string f_name, l_name;

public:
  int get_age();
  void set_age(int n_age);
  string get_first_name();
  void set_first_name(string n_f_name);
  string get_last_name();
  void set_last_name(string n_l_name);
  int get_standard();
  void set_standard(int n_std);
  string to_string();
};

int Student::get_age() { return age; }

void Student::set_age(int n_age) { age = n_age; }

string Student::get_first_name() { return f_name; }

void Student::set_first_name(string n_f_name) { f_name = n_f_name; }

string Student::get_last_name() { return l_name; }

void Student::set_last_name(string n_l_name) { l_name = n_l_name; }

int Student::get_standard() { return std; }

void Student::set_standard(int n_std) { std = n_std; }

string Student::to_string() {
  stringstream out;
  out << age << ',' << f_name << ',' << l_name << ',' << std;
  return (out.str());
}

int main() {
  int age, standard;
  string first_name, last_name;

  cin >> age >> first_name >> last_name >> standard;

  Student st;
  st.set_age(age);
  st.set_standard(standard);
  st.set_first_name(first_name);
  st.set_last_name(last_name);

  cout << st.get_age() << "\n";
  cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
  cout << st.get_standard() << "\n";
  cout << "\n";
  cout << st.to_string();

  return 0;
}
