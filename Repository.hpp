#ifndef Repository_HEADDER_INCLUDE
#define Repository_HEADDER_INCLUDE
#include <iostream>
#include "Repository_Types.hpp"
using namespace std;

int ShowRepos(Repository*& repos);
int InitRepos(istream& is, Repository*& repos);
int CreateRepos(istream& is, Repository*& repos);
int Destroyed(Repository*& repos);
int Import(istream& is, Repository*& repos);
int Export(Repository*& repos);
int UpdateInfo();
int InitGoods(GoodsType*& target, int code, string name, int remainNumber);
int CreateGoods(int code, GoodsType*& target);
int RemoveGoods(GoodsType*& pre, GoodsType*& target);
int SearchFor(Repository*& repos, GoodsType*& target);
inline int IncreaseStorage(GoodsType*& target, int number);
inline int DecreaseStorage(GoodsType*& target, int number);
inline int ChangeStorage(GoodsType*& target, int number);
inline int ChangeGoodsName(GoodsType*& target, const string name);
inline int ChangeGoodsCode(GoodsType*& goodsHead, GoodsType*& target,
                           const int code);
int ShowInfo(GoodsType*& target);
int ShowAllGoods(Repository*& repos);
int InsertNewItems(GoodsType*& head, GoodsType*& goods);
GoodsType* Find(int target, GoodsType*& goodsHead);
int readInNum(int& x);

#endif  // Repository_HEADDER_INCLUDE
