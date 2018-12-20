//
// Created by kaiser on 18-12-3.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

int main() {
  std::string line, word;
  std::vector<PersonInfo> people;
  std::istringstream record;
  std::ifstream ifs{"person_info"};

  if (!ifs) {
    std::cerr << "can't open file\n";
    return EXIT_FAILURE;
  }

  while (std::getline(ifs, line)) {
    PersonInfo info;
    record.clear();
    record.str(line);
    record >> info.name;
    while (record >> word)
      info.phones.push_back(word);
    people.push_back(info);
  }

  for (const auto &info:people) {
    std::cout << info.name << ' ';
    for (const auto &phone:info.phones)
      std::cout << phone << ' ';
    std::cout << '\n';
  }
}