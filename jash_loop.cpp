//
// Created by jared on 10/3/18.
//

#include "jash_loop.h"
#include "jash_read_line.h"
#include "jash_parse_line.h"
#include "jash_launch.h"

void jash_loop(void) {

    std::string line;
    std::vector<std::string> args;
    char buffer[256];
    int status;

    std::cout << "Welcome to jash - Just Another Shell" << std::endl;

    do {
        std::cout << getcwd(buffer, 256) << "> ";
        line = jash_read_line();
        args = jash_parse_line(line);
        for (auto i: args)
            std::cout << i << ' ';
            std::cout << '\n';
        status = jash_launch(args);
    } while (status);
}
