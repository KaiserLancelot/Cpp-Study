//
// Created by kaiser on 18-12-19.
//

#ifndef CPP_PRIMER_EX_12_33_H
#define CPP_PRIMER_EX_12_33_H

#include "ex_12_22.h"

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>

class QueryResult;

using LineNo = std::vector<std::string>::size_type;

class TextQuery {
 public:
  explicit TextQuery(std::ifstream &input);
  QueryResult Query(const std::string &s) const;

 private:
  StrBlob text_;
  std::map<std::string, std::shared_ptr<std::set<LineNo>>>
      words_and_line_number_;
};

class QueryResult {
  friend std::ostream &Print(std::ostream &os, QueryResult qr);
  friend std::ostream &Print(std::ostream &os, QueryResult qr,
                             std::size_t begin, std::size_t end);

 public:
  using ResultIterator = std::set<LineNo>::iterator;
  QueryResult(const std::string &word, const StrBlob &text,
              const std::shared_ptr<std::set<LineNo>> &line_number);
  ResultIterator begin() const;
  ResultIterator end() const;
  StrBlob GetFile() const;

 private:
  std::string word_;
  StrBlob text_;
  std::shared_ptr<std::set<LineNo>> line_number_;
};

std::ostream &Print(std::ostream &os, QueryResult qr);
std::ostream &Print(std::ostream &os, QueryResult qr, std::size_t begin,
                    std::size_t end);

#endif  // CPP_PRIMER_EX_12_33_H
