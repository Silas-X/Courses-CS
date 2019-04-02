// TODO::1. Create A find fucntion to locate a goods.

#include "Repository.hpp"

int create(Repository** repos, bool enforce = false) {
  if (*repos == NULL || enforce) {
    if (*repos != NULL)
      destroy(
          repos,
          true);  // if repos is not empty and force to create, overwrite it.
    *repos = new Repository;
    (*repos)->totalGoodsInRepository = 0;
    (*repos)->goodsList = NULL;
    return 0;
  }
  return 001;  // TODO:001 for failure to create a repos;
}

int destroy(Repository** repos, bool enforce = false) {
  if (*repos == NULL) {
    return 002;  // TODO:002 for failure to delete, it is empty;
  }
  delete *repos;
  return 0;
}

int pushGoods(const int code, const string name, Repository** repos) {
  if ((*repos)->totalGoodsInRepository == 0) {
    (*repos)->goodsList = new GoodsType;
  }
  // createAGoodsType;
  GoodsType* newGoods = new GoodsType;
  newGoods->code = code;
  newGoods->Name = name;
  updateInfo(newGoods, true);  // update in and out info.

  //// Insert in the head of the list;
  newGoods->nextGoods = (*repos)->goodsList;
  (*repos)->goodsList->nextGoods = newGoods;
  return 0;
}

int popGoods(int code, Repository*& repos) {
  GoodsType*& target = find(code, repos);
  if (target == NULL) {
    return 102;  // TODO:102 for pop failure, since ther is no match item;
  }

  if (target->remainCount == 1) {
    deleteGoods(target);
  } else {
    target->remainCount--;
    updateInfo(target, false);
  }
  repos->totalGoodsInRepository--;
  return 0;
}

// Auxiliary
GoodsType*& find(int code, Repository*& repos) {
  
}