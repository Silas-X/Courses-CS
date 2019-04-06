#ifndef REPOS_TYPE_HPP
#define REPOS_TYPE_HPP
#include <string>
using std::string;

struct ModifyRecords {
  // date Info
  int year;
  int month;
  int day;
  bool status;  // true for in, and false for out
  ModifyRecords* nextRecords;
};

struct GoodsType {
  int code;         // Serial Numbers,eg
  string name;      // goods Name;
  int remainCount;  // status of a goods
  GoodsType* next;
};

struct UsersType {};

struct Info {
  string name;
  int series;
};
struct Repository {
  Info info;
  GoodsType* goodsList;
  Repository* next;
  // struct UsersType* usersList;
};

struct Company {
  Repository* reposList;
  int totalNums;
};

#endif