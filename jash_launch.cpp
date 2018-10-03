//
// Created by jared on 10/3/18.
//

#include "jash_launch.h"

int status;

int jash_launch(std::vector<std::string> args) {
    for (int i = 0; i < core_list.size(); i++) {
        if (args[0] == core_list[i]) return jash_handler(i, args);
    }

    
    return 0;
}