#ifndef MENU_CPP
#define MENU_CPP
#include <iostream>

#include "Menu.h"

using namespace std;
// Driven Menu

int MainMenu() {
  cout << "商品管理系统" << endl;
  int opt = 0;
  // Company* rootCorp = new Company;
  Repository* root = NULL;
  while (1) {
    ShowInstruments();
    cin >> opt;
    switch (opt) {
      case 0:
        ShowRepos(root);
        cout << "销毁仓库" << endl;  // TODO:深度销毁仓库
        Destroyed(root);
        system("PAUSE");
        return 0;
      case 1:
        cout << "创建仓库" << endl;
        CreateRepos(root);
        ShowRepos(root);
        system("PAUSE");
        break;
      case 2:
        cout << "查看当前仓库信息" << endl;
        ShowRepos(root);
        system("PAUSE");
        break;
      case 3:
        cout << "选择仓库进行管理" << endl;
        ShowRepos(root);
        ReposMenu(root);
        break;
      default:
        break;
    }
  }
  return 1;
}

int ReposMenu(Repository*& repos) {
  cout << "欢迎！当前仓库为" << endl;
  ShowRepos(repos);
  cout << "请选择将要执行的操作" << endl;
  int opt;
  while (1) {
    system("cls");
    ShowReposInstruments();
    cin >> opt;
    GoodsType* p = NULL;
    switch (opt) {
      case 0:
        ShowRepos(repos);
        cout << "退出仓库" << endl;
        system("Pause");
        return 0;
      case 1:
        cout << "添加货物" << endl;
        Import(repos);
        system("PAUSE");
        break;
      case 2:
        cout << "出货" << endl;
        cout << "TODO in progress" << endl;  // TODO: 出货函数
        system("PAUSE");
        break;
      case 3:
        cout << "显示全部商品信息" << endl;
        p = repos->goodsList;
        while (p != NULL) {
          ShowInfo(p);
          cout << endl;
          p = p->next;
        }
        system("PAUSE");
        break;
      default:
        break;
    }
  }
  return 0;
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
  cout << "1.  入货" << endl;
  cout << "2.  出货" << endl;
  cout << "3.  查看当前货物状态 " << endl;
  cout << "输入0以退出" << endl;
}
#endif