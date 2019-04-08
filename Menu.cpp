#ifndef MENU_CPP
#define MENU_CPP
#include "Menu.h"
#include <fstream>
#include <iostream>
#include "Repository_converge.hpp"

using namespace std;
// Driven Menu

int MainMenu() {
  cout << "商品管理系统" << endl;
  int opt = 0;
  Repository* root = NULL;
  ReadIn(root);
  bool flag = true;
  while (flag) {
    system("cls");
    ShowInstruments();
    string str;
    cin >> str;
    int opt = str2num(str);
    switch (opt) {
      case 0:
        backup();
        writeOff(reposData, goodsData, root);
        ShowRepos(root);
        cout << "销毁内存仓库" << endl;  // TODO:深度销毁仓库
        Destroyed(root);
        flag = false;
        break;
      case 1:
        cout << "创建仓库" << endl;
        if (root != NULL) {
          cout << "抱歉，当前版本仅支持单仓库管理，请等待后续更新" << endl;
          break;
        }
        CreateRepos(cin, root);
        break;
      case 2:
        cout << "查看当前仓库信息" << endl;
        ShowRepos(root);
        break;
      case 3:
        cout << "选择仓库进行管理" << endl;
        ShowRepos(root);
        ReposMenu(root);
        break;
      default:
        cout << "输入错误，请重新选择" << endl;
        break;
    }
    system("PAUSE");
  }
  return 1;
}

int ReposMenu(Repository*& repos) {
  if (repos == NULL) {
    cout << "仓库不存在,请先创建仓库" << endl;
    return -1;
  }
  string str;
  int opt;
  int flag = true;
  while (flag) {
    system("cls");
    cout << "欢迎！当前操作仓库为" << endl;
    ShowRepos(repos);
    cout << "请选择将要执行的操作" << endl;
    ShowReposInstruments();
    cin >> str;
    opt = str2num(str);
    switch (opt) {
      case 0:
        ShowRepos(repos);
        cout << "退出仓库" << endl;
        flag = false;
        break;
      case 1:
        cout << "新建商品" << endl;
        Import(cin, repos);
        break;
      case 2:
        cout << "查询与修改" << endl;
        SearchMenu(repos);
        break;
      default:
        cout << "输入错误，请重新选择" << endl;
        break;
    }
    system("PAUSE");
  }
  return 0;
}
int SearchMenu(Repository*& repos) {
  bool flag = true;
  while (flag) {
    system("cls");
    ShowSearchInstruments();
    string str;
    cin >> str;
    GoodsType* preGoods = NULL;
    int opt = str2num(str);
    switch (opt) {
      case 0:
        cout << "返回上级菜单" << endl;
        flag = false;
        break;
      case 1:
        ShowAllGoods(repos);
        break;
      case 2:
        SearchFor(repos, preGoods);
        if (preGoods == NULL) {
          cout << "不存在该商品" << endl;
          break;
        }
        ModifyMenu(repos, preGoods, preGoods->next);
        break;
      default:
        cout << "输入错误，请重新选择" << endl;
        break;
    }
    system("PAUSE");
  }
  return 0;
}

int ModifyMenu(Repository*& repos, GoodsType*& preGoods, GoodsType*& goods) {
  bool flag = true;
  while (flag) {
    system("cls");
    cout << "当前选择商品" << endl;
    ShowInfo(goods);
    cout << endl;
    ShowModifyInstruments();
    string str;
    cin >> str;
    int opt = str2num(str);
    switch (opt) {
      case 0:
        cout << "返回上级目录" << endl;
        flag = false;
        break;
      case 1: {
        cout << "请输入入库数量" << endl;
        int nums;
        readInNum(nums);
        IncreaseStorage(goods, nums);
      } break;
      case 2: {
        cout << "请输入出库数量" << endl;
        int nums;
        readInNum(nums);
        DecreaseStorage(goods, nums);
        if (goods->remainCount == 0) {
          RemoveGoods(preGoods, goods);
          flag = false;
        } else
          ShowInfo(goods);
      } break;
      case 3:
        GoodsInfoMenu(repos, goods);
        if (goods != NULL && goods->remainCount == 0) {
          cout << "库存为0,删除商品记录" << endl;
          RemoveGoods(preGoods, goods);
          flag = false;
        }
        break;
      default:
        cout << "输入错误，请重新选择" << endl;
        break;
    }

    system("PAUSE");
  }
  return 0;
}

int GoodsInfoMenu(Repository*& repos, GoodsType*& goods) {
  bool flag = true;
  while (flag) {
    system("cls");
    cout << "当前选择商品" << endl;
    ShowInfo(goods);
    cout << endl;
    ShowGoodsInstruments();
    string str;
    cin >> str;
    int opt = str2num(str);
    switch (opt) {
      case 0:
        cout << "返回上级目录" << endl;
        flag = false;
        break;
      case 1: {
        cout << "请输入新的代号" << endl;
        int code;
        readInNum(code);
        ChangeGoodsCode(repos->goodsList, goods, code);
      } break;
      case 2: {
        cout << "请输入新商品名" << endl;
        string name;
        getchar();
        getline(cin, name);
        ChangeGoodsName(goods, name);
      } break;
      case 3:
        cout << "请输入新的存储量" << endl;
        int remain;
        readInNum(remain);
        ChangeStorage(goods, remain);
        break;
      default:
        cout << "输入错误，请重新选择" << endl;
        break;
    }
    system("PAUSE");
  }
  return 0;
}

int str2num(string str) {
  for (int i = 0; i < str.size(); i++) {
    if (str[i] < '0' || str[i] > '9') return -1;
  }
  return stoi(str);  // The c++11 Standard Function string to number;
}
void ShowInstruments() {
  cout << "说明" << endl;
  cout << "请输入序号选择您所需要的操作" << endl;
  cout << "1.  创建仓库" << endl;
  cout << "2.  查看当前仓库信息" << endl;
  cout << "3.  选择仓库 " << endl;
  cout << "输入0以退出" << endl;
}
void ShowReposInstruments() {
  cout << "说明" << endl;
  cout << "请输入序号选择您所需要的操作" << endl;
  cout << "1.  新建商品" << endl;
  cout << "2.  查询与修改" << endl;
  cout << "输入0以退出" << endl;
}

void ShowSearchInstruments() {
  cout << "说明" << endl;
  cout << "请输入序号选择您所需要的操作" << endl;
  cout << "1.  显示全部货物信息" << endl;
  cout << "2.  查询指定货物信息" << endl;
  cout << "输入0以返回" << endl;
}

void ShowModifyInstruments() {
  cout << "说明" << endl;
  cout << "请输入序号选择您所需要的操作" << endl;
  cout << "1.  入库" << endl;
  cout << "2.  出库" << endl;
  cout << "3. 修改该货物信息" << endl;
  cout << "输入0以退出" << endl;
}

void ShowGoodsInstruments() {
  cout << "说明" << endl;
  cout << "请输入序号选择您所需要的操作" << endl;
  cout << "1.  修改代号" << endl;
  cout << "2.  修改商品名" << endl;
  cout << "3.  修改商品存储量" << endl;
  cout << "输入0以退出" << endl;
}
#endif