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
int ShowRepos(Repository*& repos);
int InitRepos(Repository*& repos);
int CreateRepos(Repository*& repos);
int Destroyed(Repository*& repos);
int Import(Repository*& repos);
int ImportNewItems(Repository*& repos, int code, GoodsType*& target);
int UpdateInfo();
inline int IncreaseStorage(GoodsType*& target, int number);
inline int decreaseStorage(GoodsType*& target, int number);
inline int ChangeStorage(GoodsType*& target, int number);
inline int ChangeGoodsName(GoodsType*& target, const string name);
inline int ChangeGoodsCode(GoodsType*& target, const int code);
int ShowInfo(GoodsType*& target);
int InsertNewItems(Repository*&, GoodsType*&);

#endif  // Repository_HEADDER_INCLUDE