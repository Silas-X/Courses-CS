#ifndef Repository_HEADDER_INCLUDE
#define Repository_HEADDER_INCLUDE
#include <iostream>
#include "Repository_Types.hpp"
using namespace std;

int ShowRepos(Repository*& repos);  //显示仓库信息
int InitRepos(istream& is, Repository*& repos);
int CreateRepos(istream& is, Repository*& repos);  //创建仓库
int Destroyed(Repository*& repos);  //销毁仓库，避免内存泄漏
int Import(istream& is, Repository*& repos);  //入库函数
int Export(Repository*& repos);               //出库函数

int CreateGoods(int code, GoodsType*& target);//创建商品
int RemoveGoods(GoodsType*& pre, GoodsType*& target);//移除商品
int InsertNewItems(GoodsType*& head, GoodsType*& goods);  //向仓库中插入新的商品
GoodsType* Find(int target, GoodsType*& goodsHead);  //查找商品函数
int SearchFor(Repository*& repos, GoodsType*& target);

//仓库信息修改函数
inline int ChangeReposName(Repository*& target, const string name);
inline int ChangeReposCode(Repository*& target, const int code);

//商品修改函数
int InitGoods(GoodsType*& target, int code, string name, int remainNumber);

inline int IncreaseStorage(GoodsType*& target, int number);
inline int DecreaseStorage(GoodsType*& target, int number);
inline int ChangeStorage(GoodsType*& target, int number);
inline int ChangeGoodsName(GoodsType*& target, const string name);
inline int ChangeGoodsCode(GoodsType*& goodsHead, GoodsType*& target,
                           const int code);

int ShowInfo(GoodsType*& target);
int ShowAllGoods(Repository*& repos);

int readInNum(int& x);

#endif  // Repository_HEADDER_INCLUDE
