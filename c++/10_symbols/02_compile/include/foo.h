#ifndef _FOO_H_
#define _FOO_H_

#include "utility.h"

extern int n;

struct Foo{
  static double f;
  std::string bar;
  Foo(){};
  Foo(const std::string& s) : bar{to_upper(s)} {};
};
double Foo::f;

#endif