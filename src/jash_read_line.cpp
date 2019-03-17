//
// Created by jared on 10/3/18.
//

#include "jash_read_line.h"

std::string jash_read_line(void) {
    std::string buffer = "";

    for (;;) {
        char input;
        std::cin.get(input);

        if (input == EOF) {
            exit(EXIT_SUCCESS);
        }
        else if (input == '\n') {
            buffer += '\0';
            return buffer;
        }
        else buffer += input;
    }
}