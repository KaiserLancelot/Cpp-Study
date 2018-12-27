//
// Created by kaiser on 18-12-17.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void ElimDups(std::vector<std::string> &words) {
  std::sort(std::begin(words), std::end(words));
  words.erase(std::unique(std::begin(words), std::end(words)), std::end(words));
}

int main() {
  std::vector<std::string> vs{"a", "a", "c", "c", "b"};
  ElimDups(vs);
  for (const auto &s : vs) {
    std::cout << s << '\n';
  }
}