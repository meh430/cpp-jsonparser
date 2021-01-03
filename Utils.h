#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include <vector>
#include <stack>

namespace tokens {
    const char openingSquare = '[';
    const char closingSquare = ']';
    const char openingCurly = '{';
    const char closingCurly = '}';
    const char quote = '\"';
    const char comma = ',';
    const char colon = ':';
    const char space = ' ';
    const std::string null = "null";
}

// for returning end index and json array/object
struct StringAndIndex {
    int index;
    std::string jsonItem;
};

class Utils {
    public:
        bool toBool(const std::string &str);

        std::string trimString(const std::string &str, bool newLine = false);

        //requires: str[startIndex] == '{'
        StringAndIndex getJsonObjectEndIndex(const std::string &str, int startIndex);

        //requires: str[startIndex] == '['
        StringAndIndex getJsonArrayEndIndex(const std::string &str, int startIndex);

        //requires: str[startIndex] == '\"'
        StringAndIndex getStringEndIndex(const std::string &str, int startIndex);

        //requires: str[startIndex] == opening
        StringAndIndex getJsonItemEndIndex(const std::string &str, int startIndex, char opening, char closing);

        void printVector(const std::vector<std::string> &vec);

        std::string readFromFile(const std::string &filename);

};
#endif