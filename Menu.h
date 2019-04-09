#ifndef MENU_H
#define MENU_H

#include <fstream>
#include "Repository.hpp"
// Member Functions

int MainMenu();
int ReposManageMenu(Repository*& repos);//管理仓库自身信息即struct Info
int ReposMenu(Repository*& repos);//管理仓库内信息，即商品在仓库中的存储管理
int SearchMenu(Repository*& repos);//搜索仓库内存在的商品信息
int ModifyMenu(Repository*& repos, GoodsType*& preGoods, GoodsType*& goods);//修改仓库内存在的商品信息
int GoodsInfoMenu(Repository*& repos, GoodsType*& goods);//商品自身信息管理目录
// Auxiliary Functions
void ShowInstruments();
void ShowReposManageInstruments();
void ShowReposInstruments();
void ShowSearchInstruments();
void ShowModifyInstruments();
void ShowGoodsInstruments();
int str2num(string str);
#endif