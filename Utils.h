#ifndef UTILS_H
#define UTILS_H
#include <iostream>
class Utils {
    public:
        bool toBool(std::string str);

        //requires: str[0] == '{'
        std::string getJsonObjectStr(std::string str);

        //requires: str[0] == '['
        std::string getJsonArrayStr(std::string str);


        template <class T>
        T checkIfNull(std::string str);
};
#endif