//
// Created by kaiser on 18-12-19.
//

#include "ex_12_32.h"

#include <sstream>

TextQuery::TextQuery(std::ifstream& input) {
  std::string line;
  LineNo line_number{1};

  while (std::getline(input, line)) {
    text_.push_back(line);
    std::istringstream iss{line};
    std::string word;

    while (iss >> word) {
      if (!words_and_line_number_.contains(word)) {
        words_and_line_number_[word] = std::make_shared<std::set<LineNo>>();
      }
      words_and_line_number_[word]->insert(line_number);
    }
    ++line_number;
  }
}

QueryResult TextQuery::query(const std::string& s) {
  static auto nodata{std::make_shared<std::set<LineNo>>()};

  auto iter{words_and_line_number_.find(s)};
  if (iter == std::end(words_and_line_number_)) {
    return QueryResult{s, text_, nodata};
  } else {
    return QueryResult{s, text_, iter->second};
  }
}

QueryResult::QueryResult(const std::string& word, const StrBlob& text,
                         const std::shared_ptr<std::set<LineNo>>& line_number)
    : word_{word}, text_{text}, line_number_{line_number} {}

std::ostream& print(std::ostream& os, QueryResult qr) {
  auto size{std::size(*qr.line_number_)};

  os << qr.word_ << " occurs " << size << (size > 1 ? " times" : " time")
     << '\n';

  for (auto i : *qr.line_number_) {
    os << "\t(line " << i << ") " << qr.text_.at(i - 1) << '\n';
  }

  return os;
}
