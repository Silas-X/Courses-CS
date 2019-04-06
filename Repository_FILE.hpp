#ifndef REPOSITORY_FILE_HPP
#define REPOSITORY_FILE_HPP
#include <fstream>

int writeOff(fstream& reposData, fstream& goodsData, Repository*& repos);
int InitRepos(fstream& is, Repository*& repos);
int CreateRepos(fstream& is, Repository*& repos);
int Import(fstream& is, Repository*& repos);
int CreateGoods(fstream& is, int code, GoodsType*& target);
#endif