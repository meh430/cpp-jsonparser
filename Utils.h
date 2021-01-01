#ifndef UTILS_H
#define UTILS_H
#include <iostream>

// for returning end index and json array/object
struct StringAndIndex {
    int index;
    std::string jsonItem;
};

class Utils {
    public:
        bool toBool(std::string str);

        std::string trimString(std::string str);

        //requires: str[0] == '{'
        StringAndIndex getJsonObjectEndIndex(std::string str);

        //requires: str[0] == '['
        StringAndIndex getJsonArrayEndIndex(std::string str);

        //requires: str[0] == '\"'
        StringAndIndex getStringIndex(std::string str);

        template <class T>
        T checkIfNull(std::string str);
};
#endif