//
// Created by jared on 10/5/18.
//

#include "jash_autocomplete.h"

std::vector<std::string> get_dirs(void) {
    std::vector<std::string> found_dirs;
    DIR *dirp = opendir("./");
    struct dirent *direntp;
    while((direntp = readdir(dirp)) != nullptr) {
        found_dirs.push_back(direntp->d_name);
    }
    closedir(dirp);
}

std::string autocompleted_dir(std::vector<std::string> found_dirs, std::string current_arg){
    int largest_arg = 0;
    std::string dir_to_complete;

    for (std::string dir : found_dirs) {
        if (common_chars(dir, current_arg) > largest_arg) {
            largest_arg = common_chars(dir, current_arg);
            dir_to_complete = dir;
        }
    }
    return dir_to_complete;
}

int common_chars(std::string dir, std::string arg) {
    int map[26], map2[26];
    int common_chars = 0;

    for (char c : dir) map[c]++;
    for (char c : arg) map2[c]++;

    for (int i = 0; i <= 25; i++) {
        common_chars += std::min(map[i], map2[i]);
    }
    return common_chars;
}
