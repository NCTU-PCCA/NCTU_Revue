#include <bits/stdc++.h>
#include <sys/stat.h>
#define LINE "(line " << line_cnt << ") "
#define ERROR "\033[1;31m"
#define CORRECT "\033[1;32m"
#define INFO "\033[1;34m"
#define END   "\033[0m"
using namespace std;
void throwParserError(const string &msg, int line_cnt, string &input) {
    cerr << ERROR << LINE << msg << ": " << input << '\n' << END;
    exit(0);
}
void throwTestError(const string &msg) {
    cerr << ERROR << msg << '\n' << END;
    exit(0);
}
bool isPathExist(const string &s) {
    struct stat buffer;
    return (stat (s.c_str(), &buffer) == 0);
}
void checkTestStructure(const string &s, int line_cnt, string &input) {
    if (s == "-") return ;
    if (!isPathExist(s))
        throwParserError("Config Test Folder input folder Not Found", line_cnt, input);
    if (!isPathExist(s + "/input"))
        throwParserError("Config Test Folder Structure input folder Not Found", line_cnt, input);
    if (!isPathExist(s + "/output"))
        throwParserError("Config Test Folder Structure output folder Not Found", line_cnt, input);
    if (!isPathExist(s + "/answer"))
        throwParserError("Config Test Folder Structure answer folder Not Found", line_cnt, input);
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
        if (!isPathExist(s + "/answer/" + str + ".ans"))
            break;
        ans_cnt++;
    }
    if (in_cnt == 0)
        throwParserError("Test Data Not Found", line_cnt, input);
    if (in_cnt != ans_cnt)
        throwParserError("Number of Test Data between Input and Answer not match", line_cnt, input);
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
                        throwParserError("Config Name Error", line_cnt, input);
                    push_back(S(name));
                    break;
                case 's':
                    ss >> name >> sour_path >> test_path;
                    if (name == "")
                        throwParserError("Config Name Error", line_cnt, input);
                    if (!isPathExist(sour_path))
                        throwParserError("Config Source File Not Found Error", line_cnt, input);
                    checkTestStructure(test_path, line_cnt, input);
                    back().push_back({name, sour_path, test_path});
                    break;
                default:
                    throwParserError("Config Type Error", line_cnt, input);
            }
        }
    }
};
int cmd(const string &s) {
    return system(s.c_str());
}
void testOne(s &_s) {
    if (cmd("g++ -std=c++17 " + _s.sour_path + " -o test.out"))
        throwTestError("Compile " + _s.sour_path + " Error");
    int cnt = 0;
    while (1) {
        stringstream ss; ss << cnt + 1;
        string str; ss >> str;
        if (!isPathExist(_s.test_path + "/input/" + str + ".in"))
            break;
        string input_file  = _s.test_path + "/input/" + str + ".in";
        string output_file = _s.test_path + "/output/" + str + ".out";
        string answer_file = _s.test_path + "/answer/" + str + ".ans";
        cmd("./test.out < " + input_file + " > " + output_file);
        cmd("diff " + output_file + " " + answer_file + " | wc -l > result");
        ifstream result("result");
        bool wa; result >> wa;
        cnt++;
        cout << "----testcase #" << cnt << ": ";
        if (wa) {
            cout << ERROR << "WA\n" << END;
            cmd("rm result test.out");
            throwTestError(_s.name + ": wrong answer on test " + str);
        } else cout << CORRECT << "AC\n" << END;
    }
    cmd("rm result test.out");
}
void testAll(CodeBook &codebook) {
    for (auto &_S : codebook) {
        cout << _S.name << '\n';
        for (auto &_s : _S) {
            if (_s.test_path == "-")
                continue;
            cout << "--" << _s.name << '\n';
            testOne(_s);
        }
    }
}
int main() {
    ifstream config("config");
    cout << INFO << "Config Parser\n" << END;
    CodeBook codebook(config);
    cout << CORRECT << "Config Parser Correct\n" << END;
    cout << INFO << "Test Template\n" << END;
    testAll(codebook);
    cout << CORRECT << "Test Template Correct\n" << END;
    string latex_output;
}
