#ifndef PARSER_H
#define PARSER_H
#include "Utils.h"
#include <vector>

class Parser {
    public:
        std::vector<std::string> tokenizeObject(std::string jsonObjectStr);
        std::vector<std::string> tokenizeArray(std::string jsonArrayStr);

    private:
        Utils utils;
};
#endif