#ifndef MENU_CPP
#define MENU_CPP
#include "Menu.h"
#include <fstream>
#include <iostream>
#include "Repository_converge.hpp"

using namespace std;
// Driven Menu

int MainMenu() {
  cout << "��Ʒ����ϵͳ" << endl;
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
        cout << "�����ڴ�ֿ�" << endl;  // TODO:������ٲֿ�
        Destroyed(root);
        flag = false;
        break;
      case 1:
        cout << "�����ֿ�" << endl;
        if (root != NULL) {
          cout << "��Ǹ����ǰ�汾��֧�ֵ��ֿ������ȴ���������" << endl;
          break;
        }
        CreateRepos(cin, root);
        break;
      case 2:
        cout << "�鿴��ǰ�ֿ���Ϣ" << endl;
        ShowRepos(root);
        break;
      case 3:
        cout << "ѡ��ֿ���й���" << endl;
        ShowRepos(root);
        ReposMenu(root);
        break;
      default:
        cout << "�������������ѡ��" << endl;
        break;
    }
    system("PAUSE");
  }
  return 1;
}
/*
int ReposMenu(Repository*& repos) {
  if (repos == NULL) {
    cout << "�ֿⲻ����" << endl;
    return -1;
  }
  cout << "��ӭ����ǰ�����ֿ�Ϊ" << endl;
  ShowRepos(repos);
  cout << "��ѡ��Ҫִ�еĲ���" << endl;
  int opt;
  while (1) {
    system("cls");
    ShowReposInstruments();
    cin >> opt;
    GoodsType* p = NULL;
    switch (opt) {
      case 0:
        ShowRepos(repos);
        cout << "�˳��ֿ�" << endl;
        system("Pause");
        return 0;
      case 1:
        cout << "���" << endl;
        Import(cin, repos);
        system("PAUSE");
        break;
      case 2:
        cout << "����" << endl;
        // cout << "TODO in progress" << endl;  // TODO: ��������
        Export(repos);
        system("PAUSE");
        break;
      case 3:
        cout << "��ʾȫ����Ʒ��Ϣ" << endl;
        ShowAllGoods(repos);
        system("PAUSE");
        break;
      case 4:
        cout << "��ѯ���޸���Ϣ" << endl;
        SearchMenu(repos);
        system("PAUSE");
      default:
        break;
    }
  }
  return 0;
}
*/
int ReposMenu(Repository*& repos) {
  if (repos == NULL) {
    cout << "�ֿⲻ����,���ȴ����ֿ�" << endl;
    return -1;
  }
  string str;
  int opt;
  int flag = true;
  while (flag) {
    system("cls");
    cout << "��ӭ����ǰ�����ֿ�Ϊ" << endl;
    ShowRepos(repos);
    cout << "��ѡ��Ҫִ�еĲ���" << endl;
    ShowReposInstruments();
    cin >> str;
    opt = str2num(str);
    switch (opt) {
      case 0:
        ShowRepos(repos);
        cout << "�˳��ֿ�" << endl;
        flag = false;
        break;
      case 1:
        cout << "�½���Ʒ" << endl;
        Import(cin, repos);
        break;
      case 2:
        cout << "��ѯ���޸�" << endl;
        SearchMenu(repos);
        break;
      default:
        cout << "�������������ѡ��" << endl;
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
    int opt = str2num(str);
    switch (opt) {
      case 0:
        cout << "�����ϼ��˵�" << endl;
        flag = false;
        break;
      case 1:
        ShowAllGoods(repos);
        break;
      case 2:
        // SearchFor(repos);
      default:
        cout << "�������������ѡ��" << endl;
        break;
    }
    system("PAUSE");
  }
  return -1;
}

int str2num(string str) {
  for (int i = 0; i < str.size(); i++) {
    if (str[i] < '0' || str[i] > '9') return -1;
  }
  return stoi(str);  // The c++11 Standard Function string to number;
}
void ShowInstruments() {
  cout << "˵��" << endl;
  cout << "���������ѡ��������Ҫ�Ĳ���" << endl;
  cout << "1.  �����ֿ�" << endl;
  cout << "2.  �鿴��ǰ�ֿ���Ϣ" << endl;
  cout << "3.  ѡ��ֿ� " << endl;
  cout << "����0���˳�" << endl;
}
void ShowReposInstruments() {
  cout << "˵��" << endl;
  cout << "���������ѡ��������Ҫ�Ĳ���" << endl;
  cout << "1.  �½���Ʒ" << endl;
  cout << "2.  ��ѯ���޸�" << endl;
  cout << "����0���˳�" << endl;
}

void ShowSearchInstruments() {
  cout << "˵��" << endl;
  cout << "���������ѡ��������Ҫ�Ĳ���" << endl;
  cout << "1.  ��ʾȫ��������Ϣ" << endl;
  cout << "2.  ��ѯָ��������Ϣ" << endl;
  cout << "����0�Է���" << endl;
}

void ShowModifyInstruments() {
  cout << "˵��" << endl;
  cout << "���������ѡ��������Ҫ�Ĳ���" << endl;
  cout << "1.  ���" << endl;
  cout << "2.  ����" << endl;
  cout << "3. �޸ĸû�����Ϣ" << endl;
  cout << "����0���˳�" << endl;
}

#endif