#ifndef REPOS_FILL_CPP
#define REPOS_FILL_CPP
#include "Repository_FILE.hpp"
#include <ctime>
#include <iostream>
#include <string>
#include "Repository.hpp"
using namespace std;

int copy(ifstream& src, string target) {
  ofstream dest(target.c_str());
  while (src.eof()) {
    string temp;
    getline(src, temp);
    dest << temp;
  }
  return 0;
}

int backup() {
  ifstream repos("Data_repos.txt");
  ifstream goods("Data_goods.txt");
  if (repos.is_open()) {
    copy(repos, "Data_repos.backup");
    repos.close();
  }
  if (goods.is_open()) {
    copy(goods, "Data_goods.backup");
    goods.close();
  }
  return 0;
}
int ReadIn(Repository*& root) {
  reposData.open("Data_repos.txt", ios_base::in);
  if (!reposData.is_open())
    cout << "OpenFailed" << endl;
  else
    CreateRepos(reposData, root);
  goodsData.open("Data_goods.txt", ios_base::in);
  if (goodsData.is_open()) {
    cout << "读取存档" << endl;
    system("PAUSE");
    while (Import(goodsData, root) == 0)
      ;
  } else {
    cout << "Not Open" << endl;
    system("PAUSE");
  }
  return 0;
}
int ShowInfo_FILE(ofstream& reposLog, GoodsType*& target) {
  reposLog << "商品代码\t" << target->code << "\t";
  reposLog << "商品名称\t" << target->name << "\t";
  reposLog << "商品当前库容\t" << target->remainCount << "\t";
  return 0;
}
int ShowInfo_FILE(ofstream& reposLog, Repository*& target) {
  reposLog << "仓库代码\t" << target->info.series << "\t";
  reposLog << "仓库名称\t" << target->info.name << "\t";
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

int writeOffLog(ofstream& reposLog, const int opt, GoodsType* target = NULL,
                int changes = 0, string name = "", int code = -1,
                Repository* repos = NULL) {
  reposLog.close();
  reposLog.open("repos.log", ios_base::app);
  /*if (target == NULL) {
    cout << "Error" << endl;
    system("PAUSE");
  }*/
  time_t currentTime = time(NULL);
  reposLog << asctime(localtime(&currentTime)) << "\t";
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
      reposLog << "库存变更为" << target->remainCount + changes << "\t";
      break;
    case 3:
      reposLog << "变更商品代号\t";
      ShowInfo_FILE(reposLog, target);
      reposLog << "代号变更为" << code << "\t";
      break;
    case 4:
      reposLog << "变更商品名称\t";
      ShowInfo_FILE(reposLog, target);
      reposLog << "名称变更为" << name << "\t";
      break;
    case 5:
      reposLog << "变更仓库代号\t";
      ShowInfo_FILE(reposLog, repos);
      reposLog << "代号变更为" << code << "\t";
      break;
    case 6:
      reposLog << "变更仓库名称\t";
      ShowInfo_FILE(reposLog, repos);
      reposLog << "名称变更为" << name << "\t";
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
  //repos->next = NULL;
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
    if (isFull(repos)) {
      cout << "商品入库失败,仓库已满" << endl;
      return -1;
    }
    newGoods = new GoodsType;
    if (CreateGoods(is, code, newGoods) == -1) {
      return -1;
    }
    InsertNewItems(repos->goodsList, newGoods);
    repos->info.totalGoods++;
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
  if (isFull(target, remainNumber)) {
    cout << "新建商品失败,商品数超出库容限制" << endl;
    return -1;
  }
  InitGoods(target, code, name, remainNumber);
  writeOffLog(reposLog, 1, target, 0);
  return 0;
}

#endif  // REPOS_FILL_CPP