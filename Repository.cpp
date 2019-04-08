// TODO::1. Create A find function to locate a goods.
#ifndef REPOSITORY_CPP
#define REPOSITORY_CPP
#include "Repository.hpp"
#include <fstream>
#include <iostream>
#include <string>

#include "Repository_FILE.cpp"
#include "Repository_FILE.hpp"
using namespace std;

// Repository Functions

int ShowRepos(Repository*& repos) {
  if (repos == NULL) {
    cout << "无仓库" << endl;
    return -1;
  }
  Info reposInfo = repos->info;
  cout << "仓库代码\t" << reposInfo.series << endl;
  cout << "仓库名称\t " << reposInfo.name << endl;
  cout << "仓库当前存储总量\t" << reposInfo.totalGoods << endl;
  cout << "仓库最大容量\t" << reposInfo.maxGoods << endl;
  return 0;
}

int InitGoods(GoodsType*& target, int code, string name, int remainNumber) {
  target->code = code;
  target->name = name;
  target->next = NULL;
  target->remainCount = remainNumber;
  return 0;
}

int InitRepos(istream& is, Repository*& repos) {
  cout << "请输入仓库基本信息" << endl << endl;
  cout << "请输入仓库代码" << endl;
  int code;
  readInNum(code);
  repos->info.series = code;
  cout << "请输入仓库名称" << endl;
  string name;
  getchar();
  // while (getchar() == '\n')
  //;
  getline(is, name);
  repos->info.name = name;
  repos->goodsList = new GoodsType;
  InitGoods(repos->goodsList, -1, "_RESERVED", 0);
  repos->next = NULL;
  ShowRepos(repos);
  return 0;
}

int CreateRepos(istream& is, Repository*& repos) {
  // exception here
  if (repos == NULL) {
    repos = new Repository;
    InitRepos(is, repos);  // Init Repository
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

int Import(istream& is, Repository*& repos) {
  // exceptions here;
  cout << "请输入商品唯一标识符" << endl;
  int code;
  readInNum(code);
  GoodsType* newGoods = Find(code, repos->goodsList);
  if (newGoods->next == NULL || newGoods->next->code != code) {
    if (isFull(repos)) {
      cout << "商品入库失败,仓库已满" << endl;
      return -1;
    }
    cout << "商品不存在，新建商品" << endl;
    newGoods = new GoodsType;
    if (CreateGoods(code, newGoods) == -1) {
      cout << "新建商品失败,商品数超出库容限制" << endl;
      return -1;
    }
    InsertNewItems(repos->goodsList, newGoods);
    repos->info.totalGoods++;
  } else {
    newGoods = newGoods->next;
    cout << "商品已存在，信息如下" << endl;
    ShowInfo(newGoods);
    cout << "请输入入库数量" << endl;
    int nums;
    is >> nums;
    IncreaseStorage(newGoods, nums);
  }
  // ModifyRepos(repos, newGoods, 1);  // TODO: need Update;
  return 0;
}

int Export(Repository*& repos) {
  cout << "请输入商品唯一标识符" << endl;
  int code;
  readInNum(code);
  GoodsType* newGoods = Find(code, repos->goodsList);
  if (newGoods->next == NULL || newGoods->next->code != code) {
    cout << "商品不存在，请确认" << endl;
    system("Pause");
  } else {
    cout << "商品已存在，信息如下" << endl;
    ShowInfo(newGoods->next);
    cout << "请输入出库数量" << endl;
    int nums;
    readInNum(nums);
    DecreaseStorage(newGoods->next, nums);

    if (newGoods->next->remainCount == 0) {
      RemoveGoods(newGoods, newGoods->next);
      repos->info.totalGoods--;
    } else
      ShowInfo(newGoods->next);
  }
  return 0;
}

int CreateGoods(int code, GoodsType*& target) {
  // exceptions here;
  cout << "请输入商品基本信息" << endl;
  cout << "请输入商品名称" << endl;
  string name;
  getchar();
  getline(cin, name);
  cout << "请输入入库商品数量" << endl;
  InitGoods(target, code, name, 0);
  int remainNumber;
  readInNum(remainNumber);
  if (IncreaseStorage(target, remainNumber) == -1) {
    return -1;
  };
  writeOffLog(reposLog, 1, target, 0);
  return 0;
}

int RemoveGoods(GoodsType*& pre, GoodsType*& target) {
  writeOffLog(reposLog, 0, target);
  cout << "删除库存记录" << endl;
  ShowInfo(target);
  if (target == NULL) return -1;
  GoodsType* p = target;
  target = target->next;
  delete p;
  return 0;
}

int InsertNewItems(GoodsType*& head, GoodsType*& goods) {
  // Insert at the head of the single linked list;
  goods->next = head->next;
  head->next = goods;
  return 0;
}

int SearchFor(Repository*& repos, GoodsType*& target) {
  cout << "请输入查询商品代号" << endl;
  int code;
  readInNum(code);
  GoodsType* newGoods = Find(code, repos->goodsList);
  if (newGoods->next == NULL || newGoods->next->code != code)
    target = NULL;
  else
    target = newGoods;
  return 0;
}
// Goods Functions

inline int IncreaseStorage(GoodsType*& target, int number) {
  // TODO::need Exception, in case of positive,and NULL
  if (isFull(target, number)) {
    cout << "商品入库失败，仓库库容不足" << endl;
    return -1;
  }
  writeOffLog(reposLog, 2, target, number);
  target->remainCount += number;

  return 0;
}

inline int DecreaseStorage(GoodsType*& target, int number) {
  // TODO::need Exception, in case of positive,and NULL
  if (number > target->remainCount) {
    cout << "超过库存量，无效的操作" << endl;
    return -1;
  }
  writeOffLog(reposLog, 2, target, -number);
  target->remainCount -= number;
  return 0;
}

inline int ChangeStorage(GoodsType*& target, int number) {
  // TODO::need Exception, in case of non-positive,and NULL
  writeOffLog(reposLog, 2, target, target->remainCount - number);
  target->remainCount = number;
  cout << "成功修改" << endl;
  return 0;
}

inline int ChangeGoodsName(GoodsType*& target, const string name) {
  writeOffLog(reposLog, 4, target, 0, name, 0);
  target->name = name;
  cout << "成功修改" << endl;
  return 0;
}

inline int ChangeGoodsCode(GoodsType*& goodsHead, GoodsType*& target,
                           const int code) {
  GoodsType* newGoods = Find(code, goodsHead);
  if (newGoods->next == NULL || newGoods->next->code != code) {
    writeOffLog(reposLog, 3, target, 0, "", 0);
    target->code = code;
    cout << "成功修改" << endl;
    return 0;
  }
  cout << "存在重复，修改失败,信息如下" << endl;
  ShowInfo(newGoods->next);
  return -1;
}
inline int ChangeReposName(Repository*& target, const string name) {
  writeOffLog(reposLog, 5, NULL, 0, name, 0, target);
  target->info.name = name;
  cout << "成功修改" << endl;
  return 0;
}

inline int ChangeReposCode(Repository*& target, const int code) {
  writeOffLog(reposLog, 5, NULL, 0, "", code, target);
  target->info.series = code;
  cout << "成功修改" << endl;
  return 0;
}
int ShowInfo(GoodsType*& target) {
  cout << "商品标识码" << target->code << endl;
  cout << "商品名称  " << target->name << endl;
  cout << "商品剩余数量" << target->remainCount << endl;
  return 0;
}

int ShowAllGoods(Repository*& repos) {
  GoodsType* p = repos->goodsList->next;
  if (p == NULL) {
    cout << "当前无商品" << endl;
  }
  while (p != NULL) {
    ShowInfo(p);
    cout << endl;
    p = p->next;
  }
  return 0;
}

GoodsType* Find(int target, GoodsType*& goodsHead) {
  GoodsType *q = goodsHead, *p = q->next;
  while (p != NULL && p->code != target) {
    q = p;
    p = p->next;
  }
  return q;
}

int readInNum(int& x) {
  string str;
  cin >> str;
  x = str2num(str);
  while (x == -1) {
    cout << "输入有误，请重新输入，仅接受数字" << endl;
    cin >> str;
    x = str2num(str);
  }
  return 0;
}
#endif