#ifndef REPOS_TYPE_HPP
#define REPOS_TYPE_HPP
#include <string>
using std::string;
//商品信息
struct GoodsType {
  int code;                   // 商品序列号，不允许重复
  string name{""};            // 商品名称，允许重复
  int remainCount{0};         // 商品库存量
  const int maxNumber{1000};  //商品最大允许库存量
  GoodsType* next;            //链表指针
};

//仓库信息
struct Info {
  string name;                //仓库名称
  int series;                 //仓库序号，在多仓库版本中使用
  const int maxGoods{1000};   //仓库最大商品条目
  int totalGoods{0};          //仓库当前商品条目
};

struct Repository {
  Info info;                 //仓库基本信息
  GoodsType* goodsList;      //仓库商品表
};

inline bool isFull(Repository*& repos) {
  return (!(repos->info.totalGoods < repos->info.maxGoods));
}
inline bool isFull(GoodsType*& goods, int nums) {
  return (!(goods->remainCount + nums < goods->maxNumber));
}
#endif