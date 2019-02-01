#include <iostream>
#include <string>
#include <fstream>

#include <cstdlib>
#include <cxxabi.h>

using namespace std;

template <typename T>
class Params {
private:
    string chars[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    string defs[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    int dimensions;
    int size;
    string arrayName;
    string codeHeader;
    string codeBody;
    string codeFooter;
    string sealed;

    std::string typeName() {
        int status;
        std::string tname = typeid(T).name();
        char *demangled_name = abi::__cxa_demangle(tname.c_str(), NULL, NULL, &status);
        if(status == 0) {
            tname = demangled_name;
            std::free(demangled_name);
        }   
        return tname;
    }

    void seal() {
        sealed = codeHeader + codeBody + codeFooter;
    }

    void generateDefines() {
        string defines = "\n";
        for (int i = 0; i < dimensions; i++) {
            defines = defines + "#define " + defs[i] + " " + std::to_string(size) + "\n";
        }
        codeHeader = codeHeader + defines;
    }

    void generateArray() {
        string root = typeName();
        string code = root + " " + arrayName;
        for (int i = 0; i < dimensions; i++) {
            code = code + "[" + defs[i] + "]";
        }
        codeBody = codeBody + code + ";\n";
    }

    void generateLoops() {
        string loops = "";
        for (int i = 0; i < dimensions; i++) {
            string temp = chars[i];
            string spaces = "";
            for (int space = 0; space < i; space++) {
                spaces = spaces + "   ";
            }
            string loop = spaces + "for (int " + temp + " = 0; " + temp + " < " + std::to_string(size) + "; " + temp + "++) {";
            loops = loops + "\n" + loop;
        }

        string totalSpaces = "";
        for (int i = 0; i < dimensions - 1; i++) {
            totalSpaces = totalSpaces + "    ";
        }

        loops = loops + "\n" + totalSpaces + "// Enter any code that you want here!\n" + totalSpaces + "// We'll give you an example...\n";
        string example = "\n" + totalSpaces + arrayName;
        for (int i = 0; i < dimensions; i++) {
            example = example + "[" + chars[i] + "]";
        }
        example = example + " = \"hello world!!\";\n";

        // Next up, write the func to close all of the for loops.
        // Then, fix an error: make all of the defines letters capitalized.
        string closeLoops = totalSpaces;
        for (int i = 0; i < dimensions; i++) {
            closeLoops = closeLoops + "\n}";
        }

        codeBody = codeBody + loops + example + closeLoops + "\n";
    }

public:
    Params(int d, int s, string a) {
        if (size <= 26) {
            dimensions = d;
            size = s;
            arrayName = a;
            codeHeader = "#include <iostream>\n";
            codeBody = "\nint main() {\n";
            codeFooter = "\nreturn 0;\n}";
        }
        else {
            exit(-1);
        }
        
    }

    void Generate() {
        generateDefines();
        generateArray();
        generateLoops();
        seal();
    }

    void PrintCode() {
        std::cout << sealed << std::endl;
    }

    void WriteToFile(string fname) {
        ofstream f;
        f.open(fname + ".cpp");
        f << sealed;
        f.close();
    }

};


int main() {
    Params<string> *p = new Params<string>(26, 26, "arr");
    
    p -> Generate();
    p -> PrintCode();
    p -> WriteToFile("work");


    return 0;
}
