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
  cout << "�ֿ����:  " << reposInfo.series << endl;
  cout << "�ֿ�����:  " << reposInfo.name << endl;

  return 0;
}

int InitRepos(Repository*& repos) {
  cout << "������ֿ������Ϣ" << endl << endl;
  cout << "������ֿ����" << endl;
  int code;
  cin >> code;
  repos->info.series = code;
  cout << "������ֿ�����" << endl;
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
  cout << "��������ƷΨһ��ʶ��" << endl;
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
  //  cout << "��Ʒ��ʶ��:  " << code << endl;
  cout << "��������Ʒ������Ϣ" << endl;
  target->code = code;
  cout << "��������Ʒ����" << endl;
  string name;
  getchar();
  getline(cin, name);
  target->name = name;
  // cout << "��Ʒ����Ϊ:  " << name << endl;
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
  cout << "��Ʒ��ʶ��" << target->code << endl;
  cout << "��Ʒ����  " << target->name << endl;
  cout << "��Ʒʣ������" << target->remainCount << endl;
  return 0;
}


#endif