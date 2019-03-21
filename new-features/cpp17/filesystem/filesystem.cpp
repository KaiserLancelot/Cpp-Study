//
// Created by kaiser on 19-3-21.
//

#include <filesystem>
#include <iostream>

int main() {
  std::filesystem::path dir{"."};
  // 连接
  dir /= "cmake_install.cmake";
  // 相对地址和绝对地址都可以判断
  if (!std::filesystem::exists(dir)) {
    std::cerr << "Path " << dir << " does not exist.\n";
    std::exit(EXIT_FAILURE);
  }

  // 将路径转换为规范绝对路径
  // 规范路径指即在其通用格式表示中无点, 双点元素或符号链接的绝对路径
  // 直接打印会输出双引号, 需要使用 c_str()
  // 如果给定的 std::filesystem::path 不存在会抛出
  // filesystem_error 异常
  std::cout << std::filesystem::canonical(dir).c_str() << '\n';

  // 返回工作目录
  std::cout << std::filesystem::current_path().c_str() << '\n';
  // 返回与 dir 引用同一文件的绝对(尽管不必规范)路径名
  std::cout << std::filesystem::absolute(dir).c_str() << '\n';
  // 判断是否是相同的路径, 不必标准化
  std::cout << std::filesystem::equivalent("any", "../new-features/any") << '\n';
  // parent_path() 返回的不是绝对路径
  std::cout << std::filesystem::canonical(dir.parent_path()).c_str() << '\n';
  // 返回文件名
  std::cout << dir.stem().c_str() << '\n';
  // 返回拓展名
  std::cout << dir.extension().c_str() << '\n';
}