//
// Created by kaiser on 18-12-23.
//

#ifndef CPP_PRIMER_EX_14_07_H
#define CPP_PRIMER_EX_14_07_H

#include <string>
#include <cstddef>
#include <memory>
#include <utility>
#include <iostream>

class String {
  friend std::ostream &operator<<(std::ostream &os, const String &s);
 public:
  using SizeType=std::size_t;
  String() = default;
  String(const char *str);
  String(const String &item);
  String &operator=(const String &item);
  ~String();
  void PushBack(char ch);
  SizeType size() const;
  SizeType Capacity() const;
  char *begin();
  char *end();
  const char *begin() const;
  const char *end() const;
  void Reserve(SizeType new_cap);
  void Resize(SizeType size);
  void Resize(SizeType size, char value);
  const char *CStr() const;
 private:
  void CheckAlloc();
  std::pair<char *, char *>
  AllocCopy(const char *begin, const char *end);
  void Free();
  void Reallocate(SizeType new_cap);

  char *begin_{};
  char *end_{};
  char *cap_{};

  inline static std::allocator<char> alloc_;
};

std::ostream &operator<<(std::ostream &os, const String &s);

#endif //CPP_PRIMER_EX_14_07_H
