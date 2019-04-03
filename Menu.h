#ifndef MENU_H
#define MENU_H

#include "Repository.hpp"

// Member Functions
int MainMenu();
int ReposMenu(Repository*& repos);

// Auxiliary Functions
void ShowInstruments();

void ShowReposInstruments();

#endif