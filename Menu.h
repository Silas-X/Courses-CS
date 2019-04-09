#ifndef MENU_H
#define MENU_H

#include <fstream>
#include "Repository.hpp"
// Member Functions

int MainMenu();
int ReposManageMenu(Repository*& repos);//����ֿ�������Ϣ��struct Info
int ReposMenu(Repository*& repos);//����ֿ�����Ϣ������Ʒ�ڲֿ��еĴ洢����
int SearchMenu(Repository*& repos);//�����ֿ��ڴ��ڵ���Ʒ��Ϣ
int ModifyMenu(Repository*& repos, GoodsType*& preGoods, GoodsType*& goods);//�޸Ĳֿ��ڴ��ڵ���Ʒ��Ϣ
int GoodsInfoMenu(Repository*& repos, GoodsType*& goods);//��Ʒ������Ϣ����Ŀ¼
// Auxiliary Functions
void ShowInstruments();
void ShowReposManageInstruments();
void ShowReposInstruments();
void ShowSearchInstruments();
void ShowModifyInstruments();
void ShowGoodsInstruments();
int str2num(string str);
#endif