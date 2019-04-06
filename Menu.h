#ifndef MENU_H
#define MENU_H

#include <fstream>
#include "Repository.hpp"
// Member Functions



int MainMenu();
int FileMenu();
int ReposMenu(Repository*& repos);

// Auxiliary Functions
void ShowInstruments();

void ShowReposInstruments();

#endif