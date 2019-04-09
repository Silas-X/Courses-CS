#ifndef REPOSITORY_FILE_HPP
#define REPOSITORY_FILE_HPP
#include <fstream>
#include "Repository_Types.hpp"
using namespace std;

fstream reposData;
fstream goodsData;
ofstream errLog;
ofstream reposLog;

int backup();//���ݵ�ǰ���ݿ⺯��(Ŀǰ����һ������)
int ReadIn(Repository*& root);  //�ļ����뺯��
int writeOff(fstream& reposData, fstream& goodsData,
             Repository*& repos);  //д�����ļ�����
             /*
int writeOffLog(ofstream& reposLog, const int opt, GoodsType* target = NULL,
                int changes = 0, string name = "", int code = -1,
                Repository* repos = NULL);  //д��������־����
*/
//�����ֿ⼰����ֿ���Ʒ��Ϣ����
int InitRepos(fstream& is, Repository*& repos);
int CreateRepos(fstream& is, Repository*& repos);
int Import(fstream& is, Repository*& repos);
int CreateGoods(fstream& is, int code, GoodsType*& target);

// auxilary functions;
int ShowInfo_FILE(ofstream& reposLog, GoodsType*& target);
int ShowInfo_FILE(ofstream& reposLog, Repository*& target);
#endif