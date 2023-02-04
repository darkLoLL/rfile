#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void fun(char* fname, char** str){
    FILE* file;
    long size, i;
    file = fopen(fname, "r");
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    *str = (char*)malloc(size + 1);
    i = 0;
    fseek(file, 0, SEEK_SET);
    while (!feof(file))
    {
        (*str)[i] = getc(file);
        i++;
    }
    (*str)[size] = '\0';
    fclose(file);
}

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