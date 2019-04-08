#ifndef MENU_H
#define MENU_H

#include <fstream>
#include "Repository.hpp"
// Member Functions

int MainMenu();
int FileMenu();
int ReposMenu(Repository*& repos);
int SearchMenu(Repository*& repos);
int ModifyMenu(GoodsType*& preGoods, GoodsType*& goods);
// Auxiliary Functions
void ShowInstruments();

void ShowReposInstruments();
void ShowSearchInstruments();
void ShowModifyInstruments();

int str2num(string str);
#endif