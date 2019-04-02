#ifndef Repository_HEADDER_INCLUDE
#define Repository_HEADDER_INCLUDE

#include <string>
using namespace std;
// Data Structure for Repositories

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
};

struct UsersType {};

struct Repository {
  struct Info;
  struct GoodsType* goodsList;
  // struct UsersType* uersList;
};

#endif Repository_HEADDER_INCLUDE
