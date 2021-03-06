//
// Created by kaiser on 18-12-17.
//

#include <cstdint>
#include <iostream>

int main() {
  std::int32_t i{10};
  auto f{[&i] {
    if (i > 0) {
      --i;
    }
    return i == 0;
  }};

  while (!f()) {
    std::cout << i << '\n';
  }
}
