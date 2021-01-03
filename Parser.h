#ifndef PARSER_H
#define PARSER_H
#include "Utils.h"
#include <map>

class Parser {
    public:
        std::vector<std::string> tokenizeJsonItem(const std::string &jsonItemStr, char opening, char closing);
        std::vector<std::string> tokenizeJsonObject(const std::string &jsonObjectStr);
        std::vector<std::string> tokenizeJsonArray(const std::string &jsonArrayStr);
        std::map<std::string, std::string> jsonObjectToMap(const std::vector<std::string> &jsonObjectTokens);
        Utils utils;
};
#endif