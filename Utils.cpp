#include "Utils.h"

std::string Utils::readFromFile(const std::string &filename) {
    std::ifstream fileReader(filename.c_str());
    std::string fileText = "";
    std::string currLine;
    while (getline(fileReader, currLine)) fileText += currLine;
    fileReader.close();
    return fileText;
}

std::string Utils::trimString(const std::string &str) {
    int start = 0;
    int end = str.size() - 1;
    
    for (int i = 0; i < str.size(); i++) {
        if(!isspace(str[i])) {
            start = i;
            break;
        }
    }

    for (int i = str.size() - 1; i >= 0; i--) {
        if(!isspace(str[i])) {
            end = i;
            break;
        }
    }

    if(start > end) {
        return "";
    } else {
        return str.substr(start, (end+1) - start);
    }
}

StringAndIndex Utils::getStringEndIndex(const std::string &str, int startIndex) {
    std::string returnString = "";
    int endIndex = startIndex;
    for (int i = startIndex+1; i < str.size(); i++) {
        if(str[i] == '\"' && str[i-1] != '\\') {
            endIndex = i;
            break;
        } else {
            returnString += str[i];
        }
    }

    StringAndIndex si{endIndex, returnString};
    return si;
}

StringAndIndex Utils::getJsonItemEndIndex(const std::string &str, int startIndex, char opening, char closing) {
    std::string returnString = "";
    int endIndex = startIndex;
    std::stack<char> openings;
    returnString += opening;
    openings.push(opening);

    for (int i = startIndex+1; i < str.size(); i++) {
        bool lastIndex = i == (str.size() - 1);
        if(str[i] == opening) {
            openings.push(opening);
            returnString += str[i];
        } else if(str[i] == closing) {
            openings.pop();
            returnString += str[i];
            if(openings.empty()) {
                endIndex = i;
                break;
            }
        } else {
            returnString += str[i];
        }
    }

    StringAndIndex si{endIndex, returnString};
    return si;
}

void Utils::printVector(const std::vector<std::string> &vec) {
    for(const std::string &val : vec) {
        std::cout << val << "!*!";
    }
    std::cout << "\n";
}

StringAndIndex Utils::getJsonObjectEndIndex(const std::string &str, int startIndex) {
    return getJsonItemEndIndex(str, startIndex, tokens::openingCurly, tokens::closingCurly);
}

StringAndIndex Utils::getJsonArrayEndIndex(const std::string &str, int startIndex) {
    return getJsonItemEndIndex(str, startIndex, tokens::openingSquare, tokens::closingSquare);
}

bool Utils::toBool(const std::string &str) {
    return (str == "true");
}