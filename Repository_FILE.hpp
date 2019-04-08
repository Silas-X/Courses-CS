#ifndef REPOSITORY_FILE_HPP
#define REPOSITORY_FILE_HPP
#include <fstream>
#include "Repository_Types.hpp"
using namespace std;

fstream reposData;
fstream goodsData;
ofstream errLog;
ofstream reposLog;

int backup();
int ReadIn(Repository*& root);
int writeOff(fstream& reposData, fstream& goodsData, Repository*& repos);
int InitRepos(fstream& is, Repository*& repos);
int CreateRepos(fstream& is, Repository*& repos);
int Import(fstream& is, Repository*& repos);
int CreateGoods(fstream& is, int code, GoodsType*& target);

// auxilary functions;
int ShowInfo_FILE(ofstream& reposLog, GoodsType*& target);
int ShowInfo_FILE(ofstream& reposLog, Repository*& target);
#endif