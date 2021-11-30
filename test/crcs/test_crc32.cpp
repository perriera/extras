/**
 * @brief the "MIT/X Consortium License", (adapted for EXPARX.COM)
 *
 * Copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 * Permission is hereby  granted,  free of charge,  to  any  person
 * obtaining a copy of this software and  associated  documentation
 * files   (the  "Software"),  to deal  in   the  Software  without
 * restriction, including  without  limitation the rights  to  use,
 * copy,  modify, merge,  publish,  distribute,  sublicense, and/or
 * sell copies of the  Software, and to permit persons  to whom the
 * Software  is  furnished to  do  so,  subject  to  the  following
 * conditions:
 *
 * (See LICENSE.md for complete details)
 *
 */

#include <cstdint>
#include <extras/crcs/crc32_support.hpp>

#include "../vendor/catch.hpp"

using namespace extras;
using namespace std;

#include <iostream>
#include <typeinfo>

using namespace std;

// struct A {};
// struct B {};

// template <typename T = A>
// struct X;

// template <>
// struct X<A> {
//   static void f() { cout << 1 << endl; }
// };

// template <>
// struct X<B> {
//   static void f() { cout << 2 << endl; }
// };

// template <template <typename T = A> class C>
// void g() {
//   C<>::f();
// }

// int mainx() { g<X>(); }

// #145
// struct E {
//   E() { std::cout << "1"; }
//   E(const E &) { std::cout << "2"; }
//   ~E() { std::cout << "3"; }
// };

// E f() { return E(); }

// int mainx() { f(); }

#include <variant>

// #279
// struct C {
//   C() : i(1) {}
//   int i;
// };

// struct D {
//   D() : i(2) {}
//   int i;
// };

// int main() {
//   const std::variant<C, D> v;
//   std::visit([](const auto &val) { std::cout << val.i; }, v);
// }

// #220
// bool f() {
//   std::cout << 'f';
//   return false;
// }
// char g() {
//   std::cout << 'g';
//   return 'g';
// }
// char h() {
//   std::cout << 'h';
//   return 'h';
// }

// int mainx() {
//   char result = f() ? g() : h();
//   std::cout << result;
// }

// #132
// using namespace std;

// int foo() {
//   cout << 1;
//   return 1;
// }

// void bar(int i = foo()) {}

// int mainx() {
//   bar();
//   bar();
// }

// #4
// struct A {
//   A() { std::cout << "A"; }
// };
// struct B {
//   B() { std::cout << "B"; }
// };

// class C {
//  public:
//   C() : a(), b() {}

//  private:
//   B b;
//   A a;
// };

// int mainx() { C(); }

// #144
// #include <limits>

// int mainx() {
//   int N[] = {0, 0, 0};

//   if (std::numeric_limits<long int>::digits == 63 &&
//       std::numeric_limits<int>::digits == 31 &&
//       std::numeric_limits<unsigned int>::digits == 32) {
//     long int x = -0xffffffff;
//     for (long int i = -0xffffffff; i; --i) {
//       N[i] = 1;
//     }
//   } else {
//     N[1] = 1;
//   }

//   std::cout << N[0] << N[1] << N[2];
// }

// #129
// #include <iostream>

// using namespace std;

// int mainx() {
//   vector<char> delimiters = {",", ";"};
//   cout << delimiters[0];
// }

// #224
// struct Base {
//     virtual int f() = 0;
// };

// int Base::f() { return 1; }

// struct Derived : Base {
//     int f() override;
// };

// int Derived::f() { return 2; }

// int mainx() {
//     Derived object;
//     std::cout << object.f();
//     std::cout << ((Base&)object).f();
// }

// #104
// using namespace std;

// class A {
//  public:
//   A() { cout << "a"; }
//   ~A() { cout << "A"; }
// };

// int i = 1;

// int mainx() {
// label:
//   A a;
//   if (i--) goto label;
// }

// #6
// int mainx() {
//   for (int i = 0; i < 3; i++) std::cout << i;
//   for (int i = 0; i < 3; ++i) std::cout << i;
// }

// #162

// void f() { std::cout << "1"; }

// template <typename T>
// struct B {
//   void f() { std::cout << "2"; }
// };

// template <typename T>
// struct D : B<T> {
//   void g() { f(); }
// };

// int mainx() {
//   D<int> d;
//   d.g();
// }

// #1115
// void f(int) { std::cout << "i"; }
// void f(double) { std::cout << "d"; }
// void f(float) { std::cout << "f"; }

// int mainx() { f(1.0); }

// #158
// #include <vector>

// struct Foo {
//   Foo() { std::cout << "a"; }
//   Foo(const Foo &) { std::cout << "b"; }
// };

// int mainx() { std::vector<Foo> bar(5); }

//
// #289

// void f(int a = []() {
//   static int b = 1;
//   return b++;
// }()) {
//   std::cout << a;
// }

// int mainx() {
//   f();
//   f();
// }

// #16
// class A {
//  public:
//   A() { std::cout << 'a'; }
//   ~A() { std::cout << 'A'; }
// };

// class B {
//  public:
//   B() { std::cout << 'b'; }
//   ~B() { std::cout << 'B'; }
//   A a;
// };

// int mainx() { B b; }

// #113

// template <typename T>
// void f(T) {
//   cout << 1;
// }

// template <>
// void f(int) {
//   cout << 2;
// }

// void f(int) { cout << 3; }

// int mainx() {
//   f(0.0);
//   f(0);
//   f<>(0);
// }

// #277
// int mainx() { std::cout << sizeof(""); }

// #231
// struct override {};

// struct Base {
//   virtual override f() = 0;
// };

// struct Derived : Base {
//   virtual auto f() -> override override {
//     std::cout << "1";
//     return override();
//   }
// };
//
// int mainx() { Derived().f(); }

// Question #228 Difficulty: 3

// According to the C++17 standard, what is the output of this program?

// template <typename... Ts>
// struct X {
//   X(Ts... args) : Var(0, args...) {}
//   int Var;
// };

// int mainx() {
//   X<> x;
//   return 0;
// }

// Question #2 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>
// #include <string>

// void f(const std::string &) { std::cout << 1; }

// void f(const void *) { std::cout << 2; }

// int mainx() {
//   f("foo");
//   const char *bar = "bar";
//   f(bar);
// }

// Question #187 Difficulty : 1
//     According to the C++ 17 standard,
//     what is the output of this program ?

// #include <iostream>

// struct C {
//   C() { std::cout << "1"; }
//   C(const C &other) { std::cout << "2"; }
//   C &operator=(const C &other) {
//     std::cout << "3";
//     return *this;
//   }
// };

// int mainx() {
//   C c1;
//   C c2 = c1;
// }

// Question #235 Difficulty : 2

//     According to the C++ 17 standard,
//     what is the output of this program ?
// #include <initializer_list>
// #include <iostream>

// class C {
//  public:
//   C() = default;
//   C(const C &) { std::cout << 1; }
// };

// void f(std::initializer_list<C> i) {}

// int mainx() {
//   C c;
//   std::initializer_list<C> i{c};
//   f(i);
//   f(i);
// }

// Question #116 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>
// #include <utility>

// int y(int &) { return 1; }
// int y(int &&) { return 2; }

// template <class T>
// int f(T &&x) {
//   return y(x);
// }
// template <class T>
// int g(T &&x) {
//   return y(std::move(x));
// }
// template <class T>
// int h(T &&x) {
//   return y(std::forward<T>(x));
// }

// int mainx() {
//   int i = 10;
//   std::cout << f(i) << f(20);
//   std::cout << g(i) << g(20);
//   std::cout << h(i) << h(20);
//   return 0;
// }

// Question #251 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// template <class T>
// void f(T) {
//   std::cout << 1;
// }

// template <>
// void f<>(int *) {
//   std::cout << 2;
// }

// template <class T>
// void f(T *) {
//   std::cout << 3;
// }

// int mainx() {
//   int *p = nullptr;
//   f(p);
// }

// Question #185 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// template <typename T>
// void f() {
//   static int stat = 0;
//   std::cout << stat++;
// }

// int mainx() {
//   f<int>();
//   f<int>();
//   f<const int>();
// }

// Question #296 Difficulty : 2

//     According to the C++ 17 standard,
//     what is the output of this program ?
// #include <iostream>

// struct S {
//   int one;
//   int two;
//   int three;
// };

// int mainx() {
//   S s{1, 2};
//   std::cout << s.one;
// }

// Question #124 Difficulty: 3

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// using namespace std;

// struct A {};
// struct B {};

// template <typename T = A>
// struct X;

// template <>
// struct X<A> {
//   static void f() { cout << 1 << endl; }
// };

// template <>
// struct X<B> {
//   static void f() { cout << 2 << endl; }
// };

// template <template <typename T = B> class C>
// void g() {
//   C<>::f();
// }

// int mainx() { g<X>(); }

// Question #107 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>
// #include <vector>

// int f() {
//   std::cout << "f";
//   return 0;
// }
// int g() {
//   std::cout << "g";
//   return 0;
// }

// void h(std::vector<int> v) {}

// int mainx() { h({f(), g()}); }

// Question #288 Difficulty: 1

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// int mainx() {
//   int I = 1, J = 1, K = 1;
//   std::cout << (++I || ++J && ++K);
//   std::cout << I << J << K;
// }

// Question #1 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// template <class T>
// void f(T &i) {
//   std::cout << 1;
// }

// template <>
// void f(const int &i) {
//   std::cout << 2;
// }

// int mainx() {
//   int i = 42;
//   f(i);
// }

// Question #148 Difficulty: 3

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// volatile int a;

// int mainx() { std::cout << (a + a); }

// Question #25 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>
// #include <limits>

// int mainx() {
//   int i = std::numeric_limits<int>::max();
//   std::cout << ++i;
// }

// Question #52 Difficulty : 1

//     According to the C++ 17 standard,
//     what is the output of this program ?

// #include <iostream>

// class A;

// class B {
//  public:
//   B() { std::cout << "B"; }
//   friend B A::createB();
// };

// class A {
//  public:
//   A() { std::cout << "A"; }

//   B createB() { return B(); }
// };

// int mainx() {
//   A a;
//   B b = a.createB();
// }

// Question #120 Difficulty: 1

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// int mainx() {
//   int a = 10;
//   int b = 20;
//   int x;
//   x = b, a;
//   std::cout << x;
// }

// Question #32 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// struct X {
//   X() { std::cout << "a"; }
//   X(const X &x) { std::cout << "b"; }
//   const X &operator=(const X &x) {
//     std::cout << "c";
//     return *this;
//   }
// };

// int mainx() {
//   X x;
//   X y(x);
//   X z = y;
//   z = x;
// }

// Question #33 Difficulty: 1

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// struct GeneralException {
//   virtual void print() { std::cout << "G"; }
// };

// struct SpecialException : public GeneralException {
//   void print() override { std::cout << "S"; }
// };

// void f() { throw SpecialException(); }

// int mainx() {
//   try {
//     f();
//   } catch (GeneralException e) {
//     e.print();
//   }
// }

// Question #157 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>
// #include <typeinfo>

// struct A {};

// int mainx() { std::cout << (&typeid(A) == &typeid(A)); }

// Question #140 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>
// using namespace std;

// size_t get_size_1(int *arr) { return sizeof arr; }

// size_t get_size_2(int arr[]) { return sizeof arr; }

// size_t get_size_3(int (&arr)[10]) { return sizeof arr; }

// int mainx() {
//   int array[10];
//   // Assume sizeof(int*) != sizeof(int[10])
//   cout << (sizeof(array)) << " " << (get_size_1(array)) << endl;
//   cout << (sizeof(array)) << " " << (get_size_2(array)) << endl;
//   cout << (sizeof(array)) << " " << (get_size_3(array)) << endl;
// }

// Question #15 Difficulty: 3

// According to the C++17 standard, what is the output of this program?

// #include <exception>
// #include <iostream>

// int x = 0;

// class A {
//  public:
//   A() {
//     std::cout << 'a';
//     if (x++ == 0) {
//       throw std::exception();
//     }
//   }
//   ~A() { std::cout << 'A'; }
// };

// class B {
//  public:
//   B() { std::cout << 'b'; }
//   ~B() { std::cout << 'B'; }
//   A a;
// };

// void foo() { static B b; }

// int mainx() {
//   try {
//     foo();
//   } catch (std::exception &) {
//     std::cout << 'c';
//     foo();
//   }
// }

// #include <iostream>
// #include <type_traits>

// using namespace std;

// int mainx() {
//   int i, &j = i;
//   [=] {
//     cout << is_same<decltype((j)), int>::value
//          << is_same<decltype(((j))), int &>::value
//          << is_same<decltype((((j)))), int const &>::value
//          << is_same<decltype(((((j))))), int &&>::value
//          << is_same<decltype((((((j)))))), int const &&>::value;
//   }();
// }

// Question #161 Difficulty: 3

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// int mainx() {
//   int n = 3;
//   int i = 0;

//   switch (n % 2) {
//     case 0:
//       do {
//         ++i;
//         case 1:
//           ++i;
//       } while (--n > 0);
//   }

//   std::cout << i;
// }

// Question #7 Difficulty: 1

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// class A {
//  public:
//   void f() { std::cout << "A"; }
// };

// class B : public A {
//  public:
//   void f() { std::cout << "B"; }
// };

// void g(A &a) { a.f(); }

// int mainx() {
//   B b;
//   g(b);
// }

// Question #191 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// namespace A {
//   extern "C" int x;
// };

// namespace B {
//   extern "C" int x;
// };

// int A::x = 0;

// int mainx() {
//   std::cout << B::x;
//   A::x = 1;
//   std::cout << B::x;
// }

// Question #222 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>
// #include <variant>

// using namespace std;

// int mainx() {
//   variant<int, double, char> v;
//   cout << v.index();
// }

// // Question #119 Difficulty: 2

// // According to the C++17 standard, what is the output of this program?

// #include <iostream>

// int mainx() {
//   void *p = &p;
//   std::cout << bool(p);
// }

// Question #219 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// template <typename T>
// T sum(T arg) {
//   return arg;
// }

// template <typename T, typename... Args>
// T sum(T arg, Args... args) {
//   return arg + sum<T>(args...);
// }

// int mainx() {
//   auto n1 = sum(0.5, 1, 0.5, 1);
//   auto n2 = sum(1, 0.5, 1, 0.5);
//   std::cout << n1 << n2;
// }

// Question #284 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>
// #include <string>

// auto mainx() -> int {
//   std::string out{"Hello world"};
//   std::cout << (out[out.size()] == '\0');
// }

// Question #130 Difficulty: 3

// According to the C++17 standard, what is the output of this program?

// #include <iostream>
// using namespace std;

// template <typename T>
// void adl(T) {
//   cout << "T";
// }

// struct S {};

// template <typename T>
// void call_adl(T t) {
//   adl(S());
//   adl(t);
// }

// void adl(S) { cout << "S"; }

// int mainx() { call_adl(S()); }

// Question #207 Difficulty: 1

// According to the C++17 standard, what is the output of this program?

// #include <iostream>
// #include <map>
// using namespace std;

// int mainx() {
//   map<int, int> m;
//   cout << m[42];
// }

// #include <iostream>

// extern "C" int x;
// extern "C" {
// int y;
// }

// int mainx() {
//   std::cout << x << y;

//   return 0;
// }

// Question #179 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// int mainx() {
//   const int i = 0;
//   int &r = const_cast<int &>(i);
//   r = 1;
//   std::cout << r;
// }

// Question #135 Difficulty: 1

// According to the C++17 standard, what is the output of this program?

// #include <iostream>
// #include <map>
// using namespace std;

// int mainx() {
//   map<bool, int> mb = {{1, 2}, {3, 4}, {5, 0}};
//   cout << mb.size();
//   map<int, int> mi = {{1, 2}, {3, 4}, {5, 0}};
//   cout << mi.size();
// }

// Question #192 Difficulty : 2

//     According to the C++ 17 standard,
//     what is the output of this program ?

// #include <iostream>
// #include <vector>

// std::vector<int> v;

// int f1() {
//   v.push_back(1);
//   return 0;
// }

// int f2() {
//   v.push_back(2);
//   return 0;
// }

// void g(int, int) {}

// void h() { g(f1(), f2()); }

// int mainx() {
//   h();
//   h();
//   auto &x = v;
//   std::cout << (v[0] == v[2]);
// }

// Question #188 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// int mainx() {
//   char *a = const_cast<char *>("Hello");
//   a[4] = ' ';
//   std::cout << a;
// }

// Question #27 Difficulty: 1

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// struct A {
//   virtual std::ostream &put(std::ostream &o) const { return o << 'A'; }
// };

// struct B : A {
//   virtual std::ostream &put(std::ostream &o) const { return o << 'B'; }
// };

// std::ostream &operator<<(std::ostream &o, const A &a) { return a.put(o); }

// int mainx() {
//   B b;
//   std::cout << b;
// }

// Question #286 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// int mainx() {
//   unsigned short x = 0xFFFF;
//   unsigned short y = 0xFFFF;
//   auto z = x * y;
//   std::cout << (z > 0);
// }

// Question #238 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// int mainx() { std::cout << +!!""; }

// Question #197 Difficulty: 1

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// int j = 1;

// int mainx() {
//   int& i = j, j;
//   j = 2;
//   std::cout << i << j;
// }

// Question #295 Difficulty: 1

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// char a[2] = "0";

// struct a_string {
//   a_string() { *a = '1'; }
//   ~a_string() { *a = '0'; }
//   const char *c_str() const { return a; }
// };

// void print(const char *s) { std::cout << s; }
// a_string make_string() { return a_string{}; }

// int mainx() {
//   a_string s1 = make_string();
//   print(s1.c_str());

//   const char *s2 = make_string().c_str();
//   print(s2);

//   print(make_string().c_str());
// }

// Question #48 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <future>
// #include <iostream>
// #include <string>

// int mainx() {
//   std::string x = "x";

//   std::async(std::launch::async, [&x]() { x = "y"; });
//   std::async(std::launch::async, [&x]() { x = "z"; });

//   std::cout << x;
// }

// Question #14 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// class A {
//  public:
//   A() { std::cout << "a"; }
//   ~A() { std::cout << "A"; }
// };

// class B {
//  public:
//   B() { std::cout << "b"; }
//   ~B() { std::cout << "B"; }
// };

// class C {
//  public:
//   C() { std::cout << "c"; }
//   ~C() { std::cout << "C"; }
// };

// A a;

// void foo() { static C c; }
// int mainx() {
//   B b;
//   foo();
// }

// Question #41 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>
// int mainx() { std::cout << 1 ["ABC"]; }

// Question #38 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// int mainx() {
//   int a = 0;
//   decltype((a)) b = a;
//   b++;
//   std::cout << a << b;
// }

// Question #193 Difficulty: 3

// According to the C++17 standard, what is the output of this program?

// #include <iostream>

// int mainx() {
//   int a[] = <%1%>;
//   std::cout << a <:0:> ;
// }

// Question #195 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

// #include <cstddef>
// #include <iostream>
// #include <type_traits>

// int mainx() { std::cout << std::is_pointer_v<decltype(nullptr)>; }

// Question #186 Difficulty: 2

// According to the C++17 standard, what is the output of this program?

#include <iostream>
#include <typeinfo>

// void takes_pointer(int *pointer) {
//   if (typeid(pointer) == typeid(int[])) std::cout << 'a';
//   if (typeid(pointer) == typeid(int *)) std::cout << 'p';
// }

// void takes_array(int array[]) {
//   if (typeid(array) == typeid(int[])) std::cout << 'a';
//   if (typeid(array) == typeid(int *)) std::cout << 'p';
// }

// int mainx() {
//   int *pointer = nullptr;
//   int array[1];

//   takes_pointer(array);
//   takes_array(pointer);

//   std::cout << (typeid(int *) == typeid(int[]));
// }

// #include <ctime>
// #include <list>

// class LoggedEvent {
//   friend ostream &operator<<(std::ostream &os, const LoggedEvent &l) {
//     cout << l._time << ": " << l._event << endl;
//     return os;
//   }

//   std::time_t _time;
//   std::string _event;

//  public:
//   LoggedEvent(const string &event) : _event(event),
//   _time(std::time(nullptr)){}; const string &event() { return _event; }
// };

// using LoggedEventList = std::list<LoggedEvent>;

// class Logger {
//   friend ostream &operator<<(std::ostream &os, const Logger &l) {
//     os << l._name << endl;
//     os << l._distributer << endl;
//     for (auto event : l._events) os << event;
//     return os;
//   }

//   std::string _name;
//   std::string _distributer;
//   LoggedEventList _events;

//  public:
//   Logger(const string &name, const string &distributer)
//       : _name(name), _distributer(distributer){};
//   void addEvent(const string &event) { _events.push_back(event); }
//   LoggedEventList search(const string &token) {
//     LoggedEventList results;
//     for (auto entry : _events) {
//       auto event = entry.event();
//       if (event.find(token) != std::string::npos) results.push_back(entry);
//     }
//     return results;
//   }
// };

// int mainx() {
//   Logger logger1("Application Service Logs", "abc company");
//   Logger logger2("Host Parameters", "abc company");
//   Logger logger3("Online User Clickstream", "abc company");
//   logger1.addEvent("started logger");
//   logger1.addEvent("logged event");
//   logger1.addEvent("logged another event");
//   cout << logger1 << endl;
//   for (auto entry : logger1.search("event")) cout << entry << endl;
// }

SCENARIO("Verify crc32 default", "[crc32]") {
  // const char *argv[] = {"const"};
  // int argc = sizeof(argv) / sizeof(const char *);
  // mainx();
  std::cout << std::flush;
  std::cout << std::endl;

  {
    const char *data_piece4 = "data_piece2;";
    crc32 crc;
    std::uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 2874410684);
  }
  {
    crc32 crc;
    const char *data_piece4 = "data_piece2;";
    std::uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 2874410684);
  }
  {
    crc32 crc("generate_table(table);");
    const char *data_piece4 = "data_piece2;";
    std::uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 3312197600);
  }
  {
    crc32 crc("abcdefg");
    const char *data_piece4 = "data_piece2;";
    std::uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 341281716);
  }
  {
    crc32 crc;
    const char *data_piece4 = "data_piece2;";
    std::uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 2874410684);
  }
}

SCENARIO("Verify crc32 bit collision", "[crc32X]") {
  {
    const char *data_piece4 =
        "r1bq1rk1/2p1bppp/p2p1n2/np2p3/4P3/1BPP1N2/PP3PPP/RNBQR1K";
    crc32 crc;
    std::uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 4171189273);
  }
  {
    crc32 crc;
    const char *data_piece4 =
        "2r2k2/p2bpp2/3p2p1/1pr4p/4PN1P/1P3P2/P1PR2P1/1K2R";
    std::uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 4171189273);
  }
}
