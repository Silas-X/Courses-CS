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
  const int maxNumber{100};
  GoodsType* next;
};

struct UsersType {};

struct Info {
  string name;
  int series;
  const int maxGoods{100};
  int totalGoods{0};
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

inline bool isFull(Repository*& repos) {
  return (!(repos->info.totalGoods < repos->info.maxGoods));
}
inline bool isFull(GoodsType*& goods, int nums) {
  return (!(goods->remainCount + nums < goods->maxNumber));
}
#endif