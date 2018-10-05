//
// Created by jared on 10/5/18.
//

#ifndef JASH_JASH_AUTOCOMPLETE_H
#define JASH_JASH_AUTOCOMPLETE_H

#include <vector>
#include <string>
#include <dirent.h>

std::vector<std::string> get_dirs();
std::string autocompleted_dir(std::vector<std::string> found_dirs, std::string current_arg);
int common_chars(std::string dir, std::string arg);

#endif
