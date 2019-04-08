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
    cout << "�޲ֿ�" << endl;
    return -1;
  }
  Info reposInfo = repos->info;
  cout << "�ֿ����\t" << reposInfo.series << endl;
  cout << "�ֿ�����\t " << reposInfo.name << endl;
  cout << "�ֿ⵱ǰ�洢����\t" << reposInfo.totalGoods << endl;
  cout << "�ֿ��������\t" << reposInfo.maxGoods << endl;
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
  cout << "������ֿ������Ϣ" << endl << endl;
  cout << "������ֿ����" << endl;
  int code;
  readInNum(code);
  repos->info.series = code;
  cout << "������ֿ�����" << endl;
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
  cout << "��������ƷΨһ��ʶ��" << endl;
  int code;
  readInNum(code);
  GoodsType* newGoods = Find(code, repos->goodsList);
  if (newGoods->next == NULL || newGoods->next->code != code) {
    if (isFull(repos)) {
      cout << "��Ʒ���ʧ��,�ֿ�����" << endl;
      return -1;
    }
    cout << "��Ʒ�����ڣ��½���Ʒ" << endl;
    newGoods = new GoodsType;
    if (CreateGoods(code, newGoods) == -1) {
      cout << "�½���Ʒʧ��,��Ʒ��������������" << endl;
      return -1;
    }
    InsertNewItems(repos->goodsList, newGoods);
    repos->info.totalGoods++;
  } else {
    newGoods = newGoods->next;
    cout << "��Ʒ�Ѵ��ڣ���Ϣ����" << endl;
    ShowInfo(newGoods);
    cout << "�������������" << endl;
    int nums;
    is >> nums;
    IncreaseStorage(newGoods, nums);
  }
  // ModifyRepos(repos, newGoods, 1);  // TODO: need Update;
  return 0;
}

int Export(Repository*& repos) {
  cout << "��������ƷΨһ��ʶ��" << endl;
  int code;
  readInNum(code);
  GoodsType* newGoods = Find(code, repos->goodsList);
  if (newGoods->next == NULL || newGoods->next->code != code) {
    cout << "��Ʒ�����ڣ���ȷ��" << endl;
    system("Pause");
  } else {
    cout << "��Ʒ�Ѵ��ڣ���Ϣ����" << endl;
    ShowInfo(newGoods->next);
    cout << "�������������" << endl;
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
  cout << "��������Ʒ������Ϣ" << endl;
  cout << "��������Ʒ����" << endl;
  string name;
  getchar();
  getline(cin, name);
  cout << "�����������Ʒ����" << endl;
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
  cout << "ɾ������¼" << endl;
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
  cout << "�������ѯ��Ʒ����" << endl;
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
    cout << "��Ʒ���ʧ�ܣ��ֿ���ݲ���" << endl;
    return -1;
  }
  writeOffLog(reposLog, 2, target, number);
  target->remainCount += number;

  return 0;
}

inline int DecreaseStorage(GoodsType*& target, int number) {
  // TODO::need Exception, in case of positive,and NULL
  if (number > target->remainCount) {
    cout << "�������������Ч�Ĳ���" << endl;
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
  cout << "�ɹ��޸�" << endl;
  return 0;
}

inline int ChangeGoodsName(GoodsType*& target, const string name) {
  writeOffLog(reposLog, 4, target, 0, name, 0);
  target->name = name;
  cout << "�ɹ��޸�" << endl;
  return 0;
}

inline int ChangeGoodsCode(GoodsType*& goodsHead, GoodsType*& target,
                           const int code) {
  GoodsType* newGoods = Find(code, goodsHead);
  if (newGoods->next == NULL || newGoods->next->code != code) {
    writeOffLog(reposLog, 3, target, 0, "", 0);
    target->code = code;
    cout << "�ɹ��޸�" << endl;
    return 0;
  }
  cout << "�����ظ����޸�ʧ��,��Ϣ����" << endl;
  ShowInfo(newGoods->next);
  return -1;
}
inline int ChangeReposName(Repository*& target, const string name) {
  writeOffLog(reposLog, 5, NULL, 0, name, 0, target);
  target->info.name = name;
  cout << "�ɹ��޸�" << endl;
  return 0;
}

inline int ChangeReposCode(Repository*& target, const int code) {
  writeOffLog(reposLog, 5, NULL, 0, "", code, target);
  target->info.series = code;
  cout << "�ɹ��޸�" << endl;
  return 0;
}
int ShowInfo(GoodsType*& target) {
  cout << "��Ʒ��ʶ��" << target->code << endl;
  cout << "��Ʒ����  " << target->name << endl;
  cout << "��Ʒʣ������" << target->remainCount << endl;
  return 0;
}

int ShowAllGoods(Repository*& repos) {
  GoodsType* p = repos->goodsList->next;
  if (p == NULL) {
    cout << "��ǰ����Ʒ" << endl;
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
    cout << "�����������������룬����������" << endl;
    cin >> str;
    x = str2num(str);
  }
  return 0;
}
#endif