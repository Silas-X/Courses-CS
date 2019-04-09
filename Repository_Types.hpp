#ifndef REPOS_TYPE_HPP
#define REPOS_TYPE_HPP
#include <string>
using std::string;
//��Ʒ��Ϣ
struct GoodsType {
  int code;                   // ��Ʒ���кţ��������ظ�
  string name{""};            // ��Ʒ���ƣ������ظ�
  int remainCount{0};         // ��Ʒ�����
  const int maxNumber{1000};  //��Ʒ�����������
  GoodsType* next;            //����ָ��
};

//�ֿ���Ϣ
struct Info {
  string name;                //�ֿ�����
  int series;                 //�ֿ���ţ��ڶ�ֿ�汾��ʹ��
  const int maxGoods{1000};   //�ֿ������Ʒ��Ŀ
  int totalGoods{0};          //�ֿ⵱ǰ��Ʒ��Ŀ
};

struct Repository {
  Info info;                 //�ֿ������Ϣ
  GoodsType* goodsList;      //�ֿ���Ʒ��
};

inline bool isFull(Repository*& repos) {
  return (!(repos->info.totalGoods < repos->info.maxGoods));
}
inline bool isFull(GoodsType*& goods, int nums) {
  return (!(goods->remainCount + nums < goods->maxNumber));
}
#endif