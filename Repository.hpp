#ifndef Repository_HEADDER_INCLUDE
#define Repository_HEADDER_INCLUDE
#include <iostream>
#include "Repository_Types.hpp"
using namespace std;

int ShowRepos(Repository*& repos);  //��ʾ�ֿ���Ϣ
int InitRepos(istream& is, Repository*& repos);
int CreateRepos(istream& is, Repository*& repos);  //�����ֿ�
int Destroyed(Repository*& repos);  //���ٲֿ⣬�����ڴ�й©
int Import(istream& is, Repository*& repos);  //��⺯��
int Export(Repository*& repos);               //���⺯��

int CreateGoods(int code, GoodsType*& target);//������Ʒ
int RemoveGoods(GoodsType*& pre, GoodsType*& target);//�Ƴ���Ʒ
int InsertNewItems(GoodsType*& head, GoodsType*& goods);  //��ֿ��в����µ���Ʒ
GoodsType* Find(int target, GoodsType*& goodsHead);  //������Ʒ����
int SearchFor(Repository*& repos, GoodsType*& target);

//�ֿ���Ϣ�޸ĺ���
inline int ChangeReposName(Repository*& target, const string name);
inline int ChangeReposCode(Repository*& target, const int code);

//��Ʒ�޸ĺ���
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
