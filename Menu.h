#ifndef MENU_H
#define MENU_H

#include <fstream>
#include "Repository.hpp"
// Member Functions

fstream reposData("Data_repos.txt");
fstream goodsData("Data_goods.txt");
ofstream errLog("error.log");
ofstream reposLog("repos.log");

int MainMenu();
int FileMenu();
int ReposMenu(Repository*& repos);

// Auxiliary Functions
void ShowInstruments();

void ShowReposInstruments();

#endif