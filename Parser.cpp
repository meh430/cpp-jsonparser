#include "Parser.h"



std::vector<std::string> Parser::tokenizeArray(std::string jsonArrayStr) {
    int stringLength = jsonArrayStr.size();

    if(stringLength <= 1 || jsonArrayStr[0] != '[' || 
        jsonArrayStr[stringLength - 1] != ']') {
        throw "Expected Array";
    }

    std::vector<std::string> arrayTokens;
    std::string arrayContents = jsonArrayStr.substr(1, stringLength-1);

    if(arrayContents == "") {
        return arrayTokens;
    }

    for (int i = 0; i < arrayContents.size(); i++) {
        
    }
}