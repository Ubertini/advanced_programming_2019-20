#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <string>
#include <algorithm>
#include <iostream>


template <class T = std::string>
  T to_upper(const std::string& os){
  static int n = 0;
  ++n;
  auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), ::toupper);
  std::cout << "function " << __func__ << " has been called " << n << " times\n";
  return s;
}

inline std::string to_lower(const std::string& os){
  auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

#endif