//
// Created by jared on 10/3/18.
//

#include "jash_core_commands.h"

int jash_cd(std::string) {

}

int jash_help(std::string) {
    std::cout << "jash: just another shell" << std::endl;
    std::cout << "Core commands include: " << std::endl;

}

int jash_exit(std::string) {
    return 0;
}