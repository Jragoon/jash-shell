std::vector<std::string> parse_line(int arg_length, std::vector<std::string> cmdline) {
    if (arg_length < 1) return std::vector<std::string>();
    
    std::vector<std::string> arguments_vec = {};
    std::string current_arg = "";
    for (int i = 0; i < cmdline.size(); i++) {
        for(int j = 0; j < cmdline[i].length(); j++)
        if (cmdline[i] == ' ') {
            arguments_vec.push_back(" ");
        }
    }
    return arguments_vec;
} 
 
