#ifndef REPOSITORY_FILE_HPP
#define REPOSITORY_FILE_HPP
#include <fstream>
#include "Repository_Types.hpp"
using namespace std;

fstream reposData;
fstream goodsData;
ofstream errLog;
ofstream reposLog;

int backup();//备份当前数据库函数(目前存在一定问题)
int ReadIn(Repository*& root);  //文件读入函数
int writeOff(fstream& reposData, fstream& goodsData,
             Repository*& repos);  //写出到文件函数
             /*
int writeOffLog(ofstream& reposLog, const int opt, GoodsType* target = NULL,
                int changes = 0, string name = "", int code = -1,
                Repository* repos = NULL);  //写出操作日志函数
*/
//创建仓库及读入仓库商品信息函数
int InitRepos(fstream& is, Repository*& repos);
int CreateRepos(fstream& is, Repository*& repos);
int Import(fstream& is, Repository*& repos);
int CreateGoods(fstream& is, int code, GoodsType*& target);

// auxilary functions;
int ShowInfo_FILE(ofstream& reposLog, GoodsType*& target);
int ShowInfo_FILE(ofstream& reposLog, Repository*& target);
#endif