#include <stdexcept>
#include <iostream>
#include <string>

class ConfigLoader {
    public:
        void load(std::string filename);
};

void ConfigLoader::load(std::string filename){
    try{
        if(filename.empty())
        {
            throw std::invalid_argument("empty file name");
        };
        if(filename.length() <= 4 || filename.substr(filename.length() - 4) != ".cfg")
        {
            throw std::invalid_argument("missing \".cfg\"");
        };
        if(filename == "missing.cfg")
        {
            throw std::runtime_error("file could not be opened");
        };
        if(filename == "invalid.cfg")
        {
            throw std::runtime_error("faulty systemspecifically configuration");
        };
    }
    catch(const std::exception& error)
    {
        std::cout << "Error: " << error.what() << std::endl;
    }
    return;
}

int main()
{
    ConfigLoader cl1;

    cl1.load("");
    cl1.load("test");
    cl1.load("missing.cfg");
    cl1.load("invalid.cfg");
    cl1.load("correct_file.cfg");

    return 0;
}