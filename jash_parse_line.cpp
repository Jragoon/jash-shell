//
// Created by jared on 10/3/18.
//

#include "jash_parse_line.h"

std::vector<std::string> jash_parse_line(std::string input_line) {
    std::vector<std::string> args = {};
    std::string current_arg = "";

    for(int i = 0; i < input_line.length(); i++) {
        if (input_line[i] == ' ' or input_line[i] == '\0') {
            args.push_back(current_arg);
            current_arg = "";
        }
        else current_arg += input_line[i];
    }
    args.push_back(current_arg);
    return args;
}
