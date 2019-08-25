#include <bits/stdc++.h>
#include <sys/stat.h>
#define LINE "(line " << line_cnt << ") "
#define ERROR "\033[1;31m"
#define CORRECT "\033[1;32m"
#define INFO "\033[1;34m"
#define WARNING "\033[1;33m"
#define END   "\033[0m"
using namespace std;
int cmd(const string &s) { return system(s.c_str()); }
void throwParserError(const string &msg, int line_cnt, string &input) {
    cerr << ERROR << LINE << msg << ": " << input << '\n' << END;
    exit(1);
}
void throwTestError(const string &msg) {
    cerr << ERROR << msg << '\n' << END;
    exit(1);
}
void throwCheckLatexLabelError(const string &sour_path, int line_cnt, const string &msg) {
    cerr << ERROR << sour_path;
    if (line_cnt) cerr << LINE;
    cerr << ": " << msg << '\n' << END;
    exit(1);
}
bool isPathExist(const string &s) {
    struct stat buffer;
    return (stat (s.c_str(), &buffer) == 0);
}
void checkTestStructure(const string &test_path, const string &test_sour_path, int line_cnt, string &input) {
    if (test_path == "-") return ;
    if (!isPathExist(test_path))
        throwParserError("Config Test Folder input folder Not Found", line_cnt, input);
    if (!isPathExist(test_path + "/input"))
        throwParserError("Config Test Folder Structure input folder Not Found", line_cnt, input);
    if (!isPathExist(test_path + "/output"))
        throwParserError("Config Test Folder Structure output folder Not Found", line_cnt, input);
    if (!isPathExist(test_path + "/answer"))
        throwParserError("Config Test Folder Structure answer folder Not Found", line_cnt, input);
    if (test_sour_path != "-" && !isPathExist(test_sour_path))
        throwParserError("Config Test Source code Not Found", line_cnt, input);
    int in_cnt = 0;
    int ans_cnt = 0;
    while (1) {
        stringstream ss; ss << in_cnt + 1;
        string str; ss >> str;
        if (!isPathExist(test_path + "/input/" + str + ".in"))
            break;
        in_cnt++;
    }
    while (1) {
        stringstream ss; ss << ans_cnt + 1;
        string str; ss >> str;
        if (!isPathExist(test_path + "/answer/" + str + ".ans"))
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
    string test_sour_path;
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
            string name, sour_path, test_path, test_sour_path;
            switch (type) {
                case 'S':
                    ss >> name;
                    if (name == "")
                        throwParserError("Config Name Error", line_cnt, input);
                    push_back(S(name));
                    break;
                case 's':
                    ss >> name >> sour_path >> test_path >> test_sour_path;
                    if (test_sour_path == "-") test_sour_path = sour_path;
                    if (name == "")
                        throwParserError("Config Name Error", line_cnt, input);
                    if (!isPathExist(sour_path))
                        throwParserError("Config Source File Not Found Error", line_cnt, input);
                    checkTestStructure(test_path, test_sour_path, line_cnt, input);
                    back().push_back({name, sour_path, test_path, test_sour_path});
                    break;
                default:
                    throwParserError("Config Type Error", line_cnt, input);
            }
        }
    }
};
void testOne(s &_s) {
    if (cmd("g++ -std=c++17 " + _s.test_sour_path + " -o test.out"))
        throwTestError("Compile " + _s.test_sour_path + " Error");
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
            throwTestError(_s.name + ": wrong answer on test " + str + ".");
        } else cout << CORRECT << "AC\n" << END;
    }
    cmd("rm result test.out");
}
void testAll(CodeBook &codebook, bool gitDiffCheck = true) {
    for (auto &_S : codebook) {
        cout << _S.name << '\n';
        for (auto &_s : _S) {
            if (_s.test_path == "-")
                continue;
            cout << "--" << _s.name << '\n';
            cmd("git add -N " + _s.sour_path);
            cmd("git diff HEAD " + _s.sour_path + " | wc -l > result");
            ifstream result("result");
            bool chg; result >> chg;
            cmd("rm result");
            if (chg || !gitDiffCheck)
                testOne(_s);
            else
                cout << "----" << INFO << "No Change.\n" << END;
        }
    }
}
void checkLatexLabel(CodeBook &codebook) {
    for (auto &_S : codebook) {
        for (auto &_s : _S) {
            ifstream code(_s.sour_path);
            string str; int write = 0, line_cnt = 0;
            while (getline(code, str)) {
                line_cnt++;
                if (str == "// LatexEnd") {
                    if (write % 2 == 0)
                        throwCheckLatexLabelError(_s.sour_path, line_cnt, "Latex Label \"// LatexEnd\" must have a \"// LatexBegin\" in front of it");
                    write++;
                }
                if (str == "// LatexBegin") {
                    if (write % 2 == 1)
                        throwCheckLatexLabelError(_s.sour_path, line_cnt, "Latex Label \"// LatexBegin\" must not after another \"// LatexBegin\"");
                    write++;
                }
            }
            if (!write)
                throwCheckLatexLabelError(_s.sour_path, 0, "Latex Label Not Found");
            if (!write)
                throwCheckLatexLabelError(_s.sour_path, 0, "Number of Latex Label(// LatexBegin & // LatexEnd) not Math");
        }
    }
}
void genCodeBook(CodeBook &codebook) {
    cmd("mkdir .tmp");
    ofstream out("content.tex");
    for (auto &_S : codebook) {
        cmd("mkdir .tmp/" + _S.name);
        out << "\\section{" << _S.name << "}\n";
        for (auto &_s : _S) {
            ofstream output(".tmp/" + _s.sour_path);
            ifstream code(_s.sour_path);
            string str; bool write = false;
            while (getline(code, str)) {
                if (str == "// LatexEnd")
                    write = false;
                if (write)
                    output << str << '\n';
                if (str == "// LatexBegin")
                    write = true;
            }
            out << "\t\\subsection{" << _s.name << "}\n";
            out << "\t\t\\lstinputlisting [language=c++] { .tmp/" << _s.sour_path << " }\n";
        }
    }
}
int main(int argc, char **argv) {
    string op = (argc >= 2 ? string(argv[1]) : "genCodeBook");
    ifstream config("config");
    cout << INFO << "Config Parser.\n" << END;
    CodeBook codebook(config);
    cout << CORRECT << "Config Parser Correct.\n" << END;
    if (op == "genCodeBook" || op == "test" || op == "check") {
        cout << INFO << "Test Template.\n" << END;
        testAll(codebook, op != "test");
        cout << CORRECT << "Test Template Correct.\n" << END;
    }
    if (op == "genCodeBook" || op == "check") {
        cout << INFO << "Check Latex Label.\n" << END;
        checkLatexLabel(codebook);
        cout << CORRECT << "Check Latex Label Done.\n" << END;
    }
    if (op == "genCodeBook") {
        cout << INFO << "Generate CodeBook." << END << '\n';
        genCodeBook(codebook);
        cmd("xelatex codebook.tex");
        cmd("xelatex codebook.tex");
        cmd("rm codebook.aux codebook.log codebook.toc -f > /dev/null");
        cmd("rm -rf .tmp");
        cmd("rm content.tex");
        cout << CORRECT << "Generate CodeBook Done.\n" << END;
    }
}
