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
  string Name;      // goods Name;
  int remainCount;  // status of a goods
  ModifyRecords* records;
  GoodsType* nextGoods;
};

struct users {};

struct Repository {
  GoodsType* goodsList;
  int totalGoodsInRepository;
  users* userInfo;
};

#endif Repository_HEADDER_INCLUDE
