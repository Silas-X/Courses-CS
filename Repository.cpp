// TODO::1. Create A find function to locate a goods.
#ifndef REPOSITORY_CPP
#define REPOSITORY_CPP
#include "Repository.hpp"
#include <iostream>
#include <string>
using namespace std;

// Repository Functions
int ShowRepos(Repository*& repos) {
  if (repos == NULL) {
    cout << "�޲ֿ�" << endl;
    return -1;
  }
  Info reposInfo = repos->info;
  cout << "�ֿ����:  " << reposInfo.series << endl;
  cout << "�ֿ�����:  " << reposInfo.name << endl;

  return 0;
}

int InitGoods(GoodsType*& target, int code, string name, int remainNumber) {
  target->code = code;
  target->name = name;
  target->next = NULL;
  target->remainCount = remainNumber;
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
  repos->goodsList = new GoodsType;
  InitGoods(repos->goodsList, -1, "_RESERVED", 0);
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
  GoodsType* newGoods = Find(code, repos->goodsList);
  if (newGoods->next == NULL || newGoods->next->code != code) {
    cout << "��Ʒ�����ڣ��½���Ʒ" << endl;
    newGoods = new GoodsType;
    CreateGoods(code, newGoods);
    InsertNewItems(repos->goodsList, newGoods);

  } else {
    newGoods = newGoods->next;
    cout << "��Ʒ�Ѵ��ڣ���Ϣ����" << endl;
    ShowInfo(newGoods);
    cout << "�������������" << endl;
    int nums;
    cin >> nums;
    IncreaseStorage(newGoods, nums);
  }
  // ModifyRepos(repos, newGoods, 1);  // TODO: need Update;
  return 0;
}

int Export(Repository*& repos) {
  cout << "��������ƷΨһ��ʶ��" << endl;
  int code;
  cin >> code;
  GoodsType* newGoods = Find(code, repos->goodsList);
  if (newGoods->next == NULL || newGoods->next->code != code) {
    cout << "��Ʒ�����ڣ���ȷ��" << endl;
    system("Pause");
  } else {
    cout << "��Ʒ�Ѵ��ڣ���Ϣ����" << endl;
    ShowInfo(newGoods->next);
    cout << "�������������" << endl;
    int nums;
    cin >> nums;
    DecreaseStorage(newGoods->next, nums);

    if (newGoods->next->remainCount == 0)
      RemoveGoods(newGoods, newGoods->next);
    else
      ShowInfo(newGoods->next);
  }
  return 0;
}
int CreateGoods(int code, GoodsType*& target) {
  // exceptions here;
  //  cout << "��Ʒ��ʶ��:  " << code << endl;
  cout << "��������Ʒ������Ϣ" << endl;
  cout << "��������Ʒ����" << endl;
  string name;
  getchar();
  getline(cin, name);
  // cout << "��Ʒ����Ϊ:  " << name << endl;
  cout << "�����������Ʒ����" << endl;
  int remainNumber;
  cin >> remainNumber;
  InitGoods(target, code, name, remainNumber);
  return 0;
}

int RemoveGoods(GoodsType*& pre, GoodsType*& target) {
  cout << "ɾ������¼" << endl;
  ShowInfo(target);
  if (target == NULL) return -1;
  pre->next = target->next;
  delete target;
  return 0;
}

int InsertNewItems(GoodsType*& head, GoodsType*& goods) {
  // Insert at the head of the single linked list;
  goods->next = head->next;
  head->next = goods;
  return 0;
}

// Goods Functions

inline int IncreaseStorage(GoodsType*& target, int number) {
  // TODO::need Exception, in case of positive,and NULL
  target->remainCount += number;
  return 0;
}

inline int DecreaseStorage(GoodsType*& target, int number) {
  // TODO::need Exception, in case of positive,and NULL
  if (number > target->remainCount) {
    cout << "�������������Ч�Ĳ���" << endl;
    return -1;
  }
  target->remainCount -= number;
  return 0;
}

inline int ChangeStorage(GoodsType*& target, int number) {
  // TODO::need Exception, in case of non-positive,and NULL
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

GoodsType* Find(int target, GoodsType*& goodsHead) {
  GoodsType *q = goodsHead, *p = q->next;
  while (p != NULL && p->code != target) {
    q = p;
    p = p->next;
  }
  return q;
}
#endif