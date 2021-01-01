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