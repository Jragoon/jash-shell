//
// Created by jared on 10/3/18.
//

#ifndef JASH_JASH_CORE_COMMANDS_H
#define JASH_JASH_CORE_COMMANDS_H

#include <string>
#include <iostream>
#include <vector>
#include <unistd.h>

static std::vector<std::string> core_list = {
        "cd",
        "help",
        "exit"
};

int jash_cd(std::vector<std::string> args);
int jash_help(std::vector<std::string> args);
int jash_exit(std::vector<std::string> args);
int jash_handler(int , std::vector<std::string> args);

#endif
