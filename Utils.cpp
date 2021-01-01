#include "Utils.h"

bool Utils::toBool(std::string str) {
    return (str == "true");
}

template <class T>
T Utils::checkIfNull(std::string str) {
    if(str == "null") {
        return nullptr;
    }
}

std::string Utils::trimString(std::string str) {
    int start = 0;
    int end = str.size() - 1;

    for (int i = 0; i < str.size(); i++) {
        if(str[i] != ' ') {
            start = i;
            break;
        }
    }

    for (int i = str.size() - 1; i >= 0; i--) {
        if(str[i] != ' ') {
            end = i;
            break;
        }
    }

    if(start > end) {
        return "";
    } else {
        return str.substr(start, end + 1);
    }
}