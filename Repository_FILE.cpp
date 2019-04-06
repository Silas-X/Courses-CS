#ifndef REPOS_FILL_CPP
#define REPOS_FILL_CPP

int ShowInfo_FILE(ofstream& reposLog, GoodsType*& target) {
  reposLog << "商品标识码\t" << target->code << "\t";
  reposLog << "商品名称\t" << target->name << "\t";
  reposLog << "商品当前剩余数量\t" << target->remainCount << "\t";
  return 0;
}

int writeOffLog(ofstream& reposLog, int opt, GoodsType*& target,
                int changes = 0) {
  reposLog.close();
  reposLog.open("repos.log", ios_base::app);
  if (target == NULL) {
    cout << "Error" << endl;
    system("PAUSE");
  }
  switch (opt) {
    case 0:
      reposLog << "删除商品记录\t";
      ShowInfo_FILE(reposLog, target);
      break;
    case 1:
      reposLog << "添加商品记录\t";
      ShowInfo_FILE(reposLog, target);
      break;
    case 2:
      reposLog << "变更商品库存\t";
      ShowInfo_FILE(reposLog, target);
      reposLog << "库存变更为\t" << target->remainCount + changes << "\t";
      break;
    case 3:

      break;
  }
  reposLog << endl;
  return 0;
}

int InitRepos(fstream& is, Repository*& repos) {
  // cout << "请输入仓库基本信息" << endl << endl;
  // cout << "请输入仓库代码" << endl;
  int code;
  is >> code;
  repos->info.series = code;
  // cout << "请输入仓库名称" << endl;
  string name;
  is.get();
  // while (getchar() == '\n')
  //;
  getline(is, name);
  repos->info.name = name;
  repos->goodsList = new GoodsType;
  InitGoods(repos->goodsList, -1, "_RESERVED", 0);
  repos->next = NULL;
  return 0;
}

int CreateRepos(fstream& is, Repository*& repos) {
  // exception here
  if (repos == NULL) {
    repos = new Repository;
    InitRepos(is, repos);  // Init Repository
    return 0;
  }
  return -1;
}

int Import(fstream& is, Repository*& repos) {
  // exceptions here;
  if (!is.is_open()) return -1;
  if (is.eof()) return -2;
  // cout << "请输入商品唯一标识符" << endl;
  int code;
  is >> code;
  GoodsType* newGoods = Find(code, repos->goodsList);
  if (newGoods->next == NULL || newGoods->next->code != code) {
    // cout << "商品不存在，新建商品" << endl;
    newGoods = new GoodsType;
    CreateGoods(is, code, newGoods);
    InsertNewItems(repos->goodsList, newGoods);

  } else {
    newGoods = newGoods->next;
    // cout << "商品已存在，信息如下" << endl;
    // ShowInfo(newGoods);
    // cout << "请输入入库数量" << endl;
    // int nums;
    // is >> nums;
    // IncreaseStorage(newGoods, nums);
  }
  // ModifyRepos(repos, newGoods, 1);  // TODO: need Update;
  return 0;
}

int CreateGoods(fstream& is, int code, GoodsType*& target) {
  // exceptions here;
  //  cout << "商品标识码:  " << code << endl;
  // cout << "请输入商品基本信息" << endl;
  // cout << "请输入商品名称" << endl;
  string name;
  is.get();
  getline(is, name);
  // cout << "商品名称为:  " << name << endl;
  // cout << "请输入入库商品数量" << endl;
  int remainNumber;
  is >> remainNumber;
  InitGoods(target, code, name, remainNumber);
  writeOffLog(reposLog, 1, target, 0);
  return 0;
}

#endif //REPOS_FILL_CPP