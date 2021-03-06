/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-14 06:13:47
 * @ Modified time: 2020-05-19 04:37:50
 */

#include <cstdint>

class A {
 public:
  // explicit 说明符可以与常量表达式一同使用
  // 当且仅当该常量表达式求值为 true 时函数为显式
  explicit(false) A(std::int32_t) {}
};

void fun(A) {}

int main() { fun(1); }
