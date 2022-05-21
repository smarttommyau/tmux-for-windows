#include <cstdlib>
#include <fstream>
#include <iostream>
#include <libloaderapi.h>
#include <filesystem>
std::string get_exe_loaction(){
    wchar_t szPath[MAX_PATH];
    std::string path;
    GetModuleFileNameW( NULL, szPath, MAX_PATH );
    return std::filesystem::path{ szPath }.parent_path().u8string() + "\\" ;   
}
int main(int argc,char *argv[]){
    std::ifstream config;
    config.open(get_exe_loaction() + "tmux.conf");
    if(!config.good()){
        std::cerr << "config file not found" << std::endl;
        return -1;
    }
    std::string distro;
    bool dis = false;
    while(!config.eof()){
        std::string input;
        config >> input;
        if(dis && distro.empty()){
            distro = input;
        }
        if(input == "distro:"){
            dis = true;
        }
    }
    if(!dis){
        std::cerr << "ERROR: distro name is not set" << std::endl;
        return -2;
    }
    std::string cmd = "wsl.exe -d " + distro + " tmux";
    for(int i = 1;i < argc;i++){
        cmd.append(" ");
        cmd.append(argv[i]);
    }
    system(cmd.c_str());
    return 0;
}