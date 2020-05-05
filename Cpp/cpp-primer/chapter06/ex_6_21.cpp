//
// Created by kaiser on 20-5-5.
//

#include <cassert>
#include <cstdint>
#include <iostream>

std::int32_t Fun(std::int32_t i, const std::int32_t *p) {
  assert(p != nullptr);
  return i > *p ? i : *p;
}

int main() {
  std::int32_t i{10};
  std::cout << Fun(42, &i) << '\n';
}
