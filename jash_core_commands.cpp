//
// Created by jared on 10/3/18.
//

#include "jash_core_commands.h"

int jash_cd(std::vector<std::string> args) {
    if (args[1].empty()) {
        std::cerr << "\njash: expected argument to \"cd\"" << std::endl;
    }
    else {
        if (chdir(args[1].c_str()) not_eq 0) perror("jash");
    }
    return 1;
}

int jash_help(std::vector<std::string> args) {
    std::cout << "jash: Just Another Shell\n" << std::endl;
    std::cout << "core commands include: " << std::endl;

    for (std::string i : core_list) {
        std::cout << "- " << i << std::endl;
    }

    std::cout << "\nwritten by Jared Taylor" << std::endl;
    std::cout << "see more: https://github.com/Jragoon/jash-shell" << std::endl;
    return 1;
}

int jash_exit(std::vector<std::string> args) {
    return 0;
}

int jash_clear(std::vector<std::string> args) {
    std::cout << "\\033[2J" << "\0333" << std::endl;
    return 1;
}

int jash_handler(int function_code, std::vector<std::string> args) {
    switch(function_code) {
        case 0: return jash_cd(args);
        case 1: return jash_help(args);
        case 2: return jash_exit(args);
        case 3: return jash_clear(args);
        // Something went wrong
        default: return 0;
    }
}
