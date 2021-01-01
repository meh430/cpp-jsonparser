#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>

class Parser {
    public:
        std::vector<std::string> tokenizeObject(std::string jsonObjectStr);
        std::vector<std::string> tokenizeArray(std::string jsonArrayStr);
};
#endif