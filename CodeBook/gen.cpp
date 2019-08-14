#include <bits/stdc++.h>
#include <sys/stat.h>
#define LINE "(line " << line_cnt << ") "
#define ERROR "\033[1;31m"
#define CORRECT "\033[1;32m"
#define INFO "\033[1;34m"
#define END   "\033[0m"
using namespace std;
void throwError(const string &msg, int line_cnt, string &input) {
    cerr << ERROR << LINE << msg << ": " << input << '\n' << END;
    exit(0);
}
bool isPathExist(const string &s) {
    struct stat buffer;
    return (stat (s.c_str(), &buffer) == 0);
}
void checkTestStructure(const string &s, int line_cnt, string &input) {
    if (s == "-") return ;
    if (!isPathExist(s))
        throwError("Config Test Folder input folder Not Found", line_cnt, input);
    if (!isPathExist(s + "/input"))
        throwError("Config Test Folder Structure input folder Not Found", line_cnt, input);
    if (!isPathExist(s + "/output"))
        throwError("Config Test Folder Structure output folder Not Found", line_cnt, input);
    if (!isPathExist(s + "/answer"))
        throwError("Config Test Folder Structure answer folder Not Found", line_cnt, input);
    int in_cnt = 0;
    int ans_cnt = 0;
    while (1) {
        stringstream ss; ss << in_cnt + 1;
        string str; ss >> str;
        if (!isPathExist(s + "/input/" + str + ".in"))
            break;
        in_cnt++;
    }
    while (1) {
        stringstream ss; ss << ans_cnt + 1;
        string str; ss >> str;
        if (!isPathExist(s + "/answer/" + str + ".in"))
            break;
        ans_cnt++;
    }
    if (in_cnt == 0)
        throwError("Test Data Not Found", line_cnt, input);
    if (in_cnt != ans_cnt)
        throwError("Number of Test Data between Input and Answer not match", line_cnt, input);
}
struct s {
    string name;
    string sour_path;
    string test_path;
};
struct S : vector<s> {
    string name;
    S (string name) : name(name) { }
};
struct CodeBook : vector<S> {
    CodeBook(ifstream &config) {
        int line_cnt = 0;
        string input; while (getline(config, input)) {
            line_cnt++; stringstream ss; ss << input;
            char type; ss >> type;
            string name, sour_path, test_path;
            switch (type) {
                case 'S':
                    ss >> name;
                    if (name == "")
                        throwError("Config Name Error", line_cnt, input);
                    push_back(S(name));
                    break;
                case 's':
                    ss >> name >> sour_path >> test_path;
                    if (name == "")
                        throwError("Config Name Error", line_cnt, input);
                    if (!isPathExist(sour_path))
                        throwError("Config Source File Not Found Error", line_cnt, input);
                    checkTestStructure(test_path, line_cnt, input);
                    back().push_back({name, sour_path, test_path});
                    break;
                default:
                    throwError("Config Type Error", line_cnt, input);
            }
        }
    }
};
void testAll(CodeBook &codebook) {
    for (auto &_S : codebook) {
        cerr << _S.name << '\n';
        for (auto &_s : _S) {
            if (_s.test_path == "-")
                continue;
            cout << "\t" << _s.name << '\n';
            
        }
    }
}
int main() {
    ifstream config("config");
    cerr << INFO << "Config Parser\n" << END;
    CodeBook codebook(config);
    cerr << CORRECT << "Config Parser Correct\n" << END;
    // cerr << INFO << "Test Template\n" << END;
    // testAll(codebook);
    // cerr << CORRECT << "Test Template Correct\n" << END;
    // string latex_output;
}
