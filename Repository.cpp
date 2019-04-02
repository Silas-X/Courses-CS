// TODO::1. Create A find function to locate a goods.

#include "Repository.hpp"
#include <iostream>
#include <string>
using namespace std;

// Repository Functions
int CreateRepos(Repository*& repos) {
  // exception here
  if (repos == NULL) {
    repos = new Repository;
    InitRepos(repos);  // Init Repository
    return 0;
  }
  return -1;
}

int Destroyed(Repository*& repos) {
  // exceptions here
  if (repos != NULL) {
    delete repos;
    return 0;
  }
  return -1;
}

int Import(Repository*& repos) {
  // exceptions here;
  cout << "请输入商品唯一标识符" << endl;
  int code;
  cin >> code;
  GoodsType*& newGoods = Find(code, repos);
  if (newGoods == NULL) {
    ImportNewItems(repos, code, newGoods);
  }
  ModifyRepos(repos, newGoods, 1);  // TODO: need Update;
  showInfo(newGoods);
  return 0;
}

int ImportNewItems(Repository*& repos, int code, GoodsType*& target) {
  // exceptions here;
  //  cout << "商品标识码:  " << code << endl;
  cout << "请输入商品基本信息" << endl;
  target->code = code;
  cout << "请输入商品名称" << endl;
  string name;
  getline(cin, name);
  target->name = name;
  // cout << "商品名称为:  " << name << endl;
  target->remainCount = 0;
}

int UpdateINfo() {}

// Modification functions
int Modify() {}

int ModifyRepos(Repository*& repos, GoodsType*& target, int opt) {}

// Goods Functions

inline int IncreaseStorage(GoodsType*& target, int number) {
  target->remainCount += number;
  return 0;
}

inline int decreaseStorage(GoodsType*& target, int number) {
  target->remainCount -= number;
  return 0;
}

inline int ChangeStorage(GoodsType*& target, int number) {
  target->remainCount = number;
  return 0;
}

inline int ChangeGoodsName(GoodsType*& target, const string name) {
  target->name = name;
  return 0;
}

inline int ChangeGoodsCode(GoodsType*& target, const int code) {
  target->code = code;
  return 0;
}