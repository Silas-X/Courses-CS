// TODO::1. Create A find function to locate a goods.
#ifndef REPOSITORY_CPP
#define REPOSITORY_CPP
#include "Repository.hpp"
#include <iostream>
#include <string>
using namespace std;

// Repository Functions
int ShowRepos(Repository*& repos) {
  if (repos == NULL) return -1;
  Info reposInfo = repos->info;
  cout << "仓库代码:  " << reposInfo.series << endl;
  cout << "仓库名称:  " << reposInfo.name << endl;

  return 0;
}

int InitRepos(Repository*& repos) {
  cout << "请输入仓库基本信息" << endl << endl;
  cout << "请输入仓库代码" << endl;
  int code;
  cin >> code;
  repos->info.series = code;
  cout << "请输入仓库名称" << endl;
  string name;
  getchar();
  // while (getchar() == '\n')
  //;
  getline(cin, name);
  repos->info.name = name;
  repos->goodsList = NULL;
  repos->next = NULL;
  return 0;
}
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
    if (repos->goodsList != NULL) {
      GoodsType *p = repos->goodsList, *q;
      while (p != NULL) {
        q = p->next;
        delete p;
        p = NULL;
        p = q;
      }
    }
    delete repos;
    repos = NULL;
    return 0;
  }
  return -1;
}

int Import(Repository*& repos) {
  // exceptions here;
  cout << "请输入商品唯一标识符" << endl;
  int code;
  cin >> code;
  GoodsType* newGoods = NULL /*= Find(code, repos)*/;
  if (newGoods == NULL) {
    newGoods = new GoodsType;
    ImportNewItems(repos, code, newGoods);
    InsertNewItems(repos, newGoods);
  }
  IncreaseStorage(newGoods, 1);
  // ModifyRepos(repos, newGoods, 1);  // TODO: need Update;
  ShowInfo(newGoods);
  return 0;
}

int ImportNewItems(Repository*& repos, int code, GoodsType*& target) {
  // exceptions here;
  //  cout << "商品标识码:  " << code << endl;
  cout << "请输入商品基本信息" << endl;
  target->code = code;
  cout << "请输入商品名称" << endl;
  string name;
  getchar();
  getline(cin, name);
  target->name = name;
  // cout << "商品名称为:  " << name << endl;
  target->remainCount = 0;
  target->next = NULL;
  return 0;
}

// int UpdateINfo() {}

// Modification functions
// int Modify() {}

// int ModifyRepos(Repository*& repos, GoodsType*& target, int opt) { return 0;
// }

int InsertNewItems(Repository*& repos, GoodsType*& goods) {
  // Insert at the head of the single linked list;
  goods->next = repos->goodsList;
  repos->goodsList = goods;
  return 0;
}

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

int ShowInfo(GoodsType*& target) {
  cout << "商品标识码" << target->code << endl;
  cout << "商品名称  " << target->name << endl;
  cout << "商品剩余数量" << target->remainCount << endl;
  return 0;
}


#endif