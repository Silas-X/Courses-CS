#ifndef MENU_CPP
#define MENU_CPP
#include "Menu.h"
#include <fstream>
#include <iostream>
#include "FileMenu.cpp"
using namespace std;
// Driven Menu

// reposData.close();
// ifstream reposData("Data_repos.txt");

int MainMenu() {
  cout << "商品管理系统" << endl;
  int opt = 0;
  // Company* rootCorp = new Company;
  Repository* root = NULL;
  if (!reposData.is_open()) cout << "OpenFailed" << endl;
  CreateRepos(reposData, root);
  // reposData.close();
  if (goodsData.is_open()) {
    cout << "读取存档" << endl;
    system("PAUSE");
    while (Import(goodsData, root) == 0)
      ;
  } else {
    cout << "Not Open" << endl;
    system("PAUSE");
  }
  while (1) {
    ShowInstruments();
    cin >> opt;
    switch (opt) {
      case 0:
        writeOff(reposData, goodsData, root);
        ShowRepos(root);
        cout << "销毁仓库" << endl;  // TODO:深度销毁仓库
        Destroyed(root);
        system("PAUSE");
        return 0;
      case 1:
        cout << "创建仓库" << endl;
        CreateRepos(cin, root);
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
  if (repos == NULL) {
    cout << "仓库不存在" << endl;
    return -1;
  }
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
        Import(cin, repos);
        system("PAUSE");
        break;
      case 2:
        cout << "出货" << endl;
        // cout << "TODO in progress" << endl;  // TODO: 出货函数
        Export(repos);
        system("PAUSE");
        break;
      case 3:
        cout << "显示全部商品信息" << endl;
        p = repos->goodsList->next;
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