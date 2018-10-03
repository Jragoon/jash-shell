//
// Created by jared on 10/3/18.
//

#include "jash_launch.h"

pid_t pid;
int status;

int jash_launch(std::vector<std::string> args) {

    //if (args[0])

    for (int i = 0; i < core_list.size(); i++) {
        if (args[0] == core_list[i]) return jash_handler(i, args);
    }

    // Prepare args for execvp function call
    const char **exec_args = new const char* [args.size() - 1];
    for (int i = 0; i < args.size() - 1; i++) exec_args[i] = args[i].c_str();

    pid = fork();
    if (pid == 0) {
        // This would be a child process
        if (execvp(args[0].c_str(), (char **)exec_args) == -1) {
            perror("jash");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    else {
        // Fly free, process friend
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) and !WIFSIGNALED(status));
    }

    return 1;
}