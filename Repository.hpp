#ifndef Repository_HEADDER_INCLUDE
#define Repository_HEADDER_INCLUDE
#include <fstream>
#include <string>
using namespace std;
// Data Structure for Repositories
// ifstream reposData("Data_repos.txt");
// ifstream GoodsData("Data_goods.txt");
// ofstream errLog("error.log");
// ofstream reposLog("repos.log");
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
int writeOff(fstream& reposData, fstream& goodsData, Repository*& repos);
int ShowRepos(Repository*& repos);
int InitRepos(fstream& is, Repository*& repos);
int InitRepos(istream& is, Repository*& repos);
int CreateRepos(fstream& is, Repository*& repos);
int CreateRepos(istream& is, Repository*& repos);
int Destroyed(Repository*& repos);
int Import(fstream& is, Repository*& repos);
int Import(istream& is, Repository*& repos);
int Export(Repository*& repos);
int UpdateInfo();
int InitGoods(GoodsType*& target, int code, string name, int remainNumber);
int CreateGoods(int code, GoodsType*& target);
int CreateGoods(fstream& is, int code, GoodsType*& target);
int RemoveGoods(GoodsType*& pre, GoodsType*& target);
inline int IncreaseStorage(GoodsType*& target, int number);
inline int DecreaseStorage(GoodsType*& target, int number);
inline int ChangeStorage(GoodsType*& target, int number);
inline int ChangeGoodsName(GoodsType*& target, const string name);
inline int ChangeGoodsCode(GoodsType*& target, const int code);
int ShowInfo(GoodsType*& target);
int InsertNewItems(GoodsType*& head, GoodsType*& goods);
GoodsType* Find(int target, GoodsType*& goodsHead);

#endif  // Repository_HEADDER_INCLUDE
