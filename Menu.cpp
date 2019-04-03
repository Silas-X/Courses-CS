#ifndef MENU_CPP
#define MENU_CPP
#include <iostream>

#include "Menu.h"

using namespace std;
// Driven Menu

int MainMenu() {
  cout << "��Ʒ����ϵͳ" << endl;
  int opt = 0;
  // Company* rootCorp = new Company;
  Repository* root = NULL;
  while (1) {
    ShowInstruments();
    cin >> opt;
    switch (opt) {
      case 0:
        ShowRepos(root);
        cout << "���ٲֿ�" << endl;  // TODO:������ٲֿ�
        Destroyed(root);
        system("PAUSE");
        return 0;
      case 1:
        cout << "�����ֿ�" << endl;
        CreateRepos(root);
        ShowRepos(root);
        system("PAUSE");
        break;
      case 2:
        cout << "�鿴��ǰ�ֿ���Ϣ" << endl;
        ShowRepos(root);
        system("PAUSE");
        break;
      case 3:
        cout << "ѡ��ֿ���й���" << endl;
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
  cout << "��ӭ����ǰ�ֿ�Ϊ" << endl;
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
        cout << "��ӻ���" << endl;
        Import(repos);
        system("PAUSE");
        break;
      case 2:
        cout << "����" << endl;
        cout << "TODO in progress" << endl;  // TODO: ��������
        system("PAUSE");
        break;
      case 3:
        cout << "��ʾȫ����Ʒ��Ϣ" << endl;
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
  cout << "1.  ���" << endl;
  cout << "2.  ����" << endl;
  cout << "3.  �鿴��ǰ����״̬ " << endl;
  cout << "����0���˳�" << endl;
}
#endif