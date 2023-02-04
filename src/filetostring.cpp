#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string rfilestr(std::string file_name) {
  std::stringstream str;
  char c;
  // std::string temp;
  std::ifstream file(file_name, std::ios::in);
  if (file.is_open()) {
    while (!file.eof()) {
      file.get(c);
      str << c;
    }
    file.close();
  }
  return str.str();
}

int main(int argc, char const *argv[]) {
  std::string s;
  s = rfilestr("hello.txt");
  std::cout << s;
  return 0;
}