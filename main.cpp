#include <iostream>
#include <string>
#include <vector>


int main(int argc, char **argv) {
    std::vector<std::string> args(argv, argv + argc);
    //run_command(cmd); - decide, shell function? built-in command? normal program?
    for (int i = 0; i < args.size(); i++) std::cout << " " << args[i];
    return 0;
}

