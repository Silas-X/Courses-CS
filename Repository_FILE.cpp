#ifndef REPOS_FILL_CPP
#define REPOS_FILL_CPP
#include "Repository_FILE.hpp"
#include <iostream>
using namespace std;

int ShowInfo_FILE(ofstream& reposLog, GoodsType*& target) {
  reposLog << "商品标识码\t" << target->code << "\t";
  reposLog << "商品名称\t" << target->name << "\t";
  reposLog << "商品当前剩余数量\t" << target->remainCount << "\t";
  return 0;
}

int writeOff(fstream& reposData, fstream& goodsData, Repository*& repos) {
  if (repos == NULL) return -1;
  cout << "写出数据" << endl;
  reposData.close();
  goodsData.close();
  reposData.open("Data_repos.txt", ios_base::out);
  goodsData.open("Data_goods.txt", ios_base::out);
  if (!reposData.is_open()) {
    cout << "repos open failed";
  }
  if (!goodsData.is_open()) {
    cout << "goods open failed";
  }
  reposData << repos->info.series << endl;
  reposData << repos->info.name << endl;
  GoodsType* p = repos->goodsList->next;
  while (p != NULL) {
    goodsData << p->code << endl << p->name << endl << p->remainCount << endl;
    p = p->next;
  }
  return 0;
}

int writeOffLog(ofstream& reposLog, int opt, GoodsType*& target,
                int changes = 0) {
  reposLog.close();
  reposLog.open("repos.log", ios_base::app);
  if (target == NULL) {
    cout << "Error" << endl;
    system("PAUSE");
  }
  switch (opt) {
    case 0:
      reposLog << "删除商品记录\t";
      ShowInfo_FILE(reposLog, target);
      break;
    case 1:
      reposLog << "添加商品记录\t";
      ShowInfo_FILE(reposLog, target);
      break;
    case 2:
      reposLog << "变更商品库存\t";
      ShowInfo_FILE(reposLog, target);
      reposLog << "库存变更为\t" << target->remainCount + changes << "\t";
      break;
    case 3:

      break;
  }
  reposLog << endl;
  return 0;
}

int InitRepos(fstream& is, Repository*& repos) {
  int code;
  is >> code;
  repos->info.series = code;
  string name;
  is.get();
  getline(is, name);
  repos->info.name = name;
  repos->goodsList = new GoodsType;
  InitGoods(repos->goodsList, -1, "_RESERVED", 0);
  repos->next = NULL;
  return 0;
}

int CreateRepos(fstream& is, Repository*& repos) {
  // exception here
  if (repos == NULL) {
    repos = new Repository;
    InitRepos(is, repos);  // Init Repository
    return 0;
  }
  return -1;
}

int Import(fstream& is, Repository*& repos) {
  // exceptions here;
  if (!is.is_open()) return -1;
  if (is.eof()) return -2;
  int code;
  is >> code;
  GoodsType* newGoods = Find(code, repos->goodsList);
  if (newGoods->next == NULL || newGoods->next->code != code) {
    newGoods = new GoodsType;
    CreateGoods(is, code, newGoods);
    InsertNewItems(repos->goodsList, newGoods);

  } else {
    newGoods = newGoods->next;
  }
  return 0;
}

int CreateGoods(fstream& is, int code, GoodsType*& target) {
  // exceptions here;
  string name;
  is.get();
  getline(is, name);
  int remainNumber;
  is >> remainNumber;
  InitGoods(target, code, name, remainNumber);
  writeOffLog(reposLog, 1, target, 0);
  return 0;
}

#endif  // REPOS_FILL_CPP