#include "Parser.h"

std::vector<std::string> Parser::tokenizeJsonItem(const std::string &jsonItemStr, char opening, char closing) {
    int stringLength = jsonItemStr.size();

    if(stringLength <= 1 || jsonItemStr[0] != opening || 
        jsonItemStr[stringLength - 1] != closing) {
        std::cout << "Incorrect string format" << "\n";

        throw "Incorrect string format";
    }

    std::vector<std::string> tokens;
    std::string itemContents = jsonItemStr.substr(1, stringLength-2);

    if(itemContents == "") {
        return tokens;
    }

    std::string currentItem = "";
    // split by ,. Stop on every { and [ and \"
    for (int i = 0; i < itemContents.size(); i++) {
        if(itemContents[i] == tokens::colon) {
            tokens.push_back(currentItem);
            tokens.push_back(":");
            currentItem.clear();
        } else if(itemContents[i] == tokens::comma) {
            tokens.push_back(currentItem);
            currentItem.clear();
        } else if(itemContents[i] == tokens::openingCurly) {
            StringAndIndex objectEnd = utils.getJsonObjectEndIndex(itemContents, i);
            i = objectEnd.index;
            currentItem = objectEnd.jsonItem;
        } else if(itemContents[i] == tokens::openingSquare) {
            StringAndIndex arrayEnd = utils.getJsonArrayEndIndex(itemContents, i);
            i = arrayEnd.index;
            currentItem = arrayEnd.jsonItem;
        } else if(itemContents[i] == tokens::quote) {
            StringAndIndex stringEnd = utils.getStringEndIndex(itemContents, i);
            i = stringEnd.index;
            currentItem = stringEnd.jsonItem;
        } else if(itemContents[i] == tokens::space) {
            continue;
        } else {
            currentItem += itemContents[i];
        }
    }

    tokens.push_back(currentItem);

    return tokens;
}

std::vector<std::string> Parser::tokenizeJsonObject(const std::string &jsonObjectStr) {
    return tokenizeJsonItem(jsonObjectStr, tokens::openingCurly, tokens::closingCurly);
}

std::vector<std::string> Parser::tokenizeJsonArray(const std::string &jsonArrayStr) {
    return tokenizeJsonItem(jsonArrayStr, tokens::openingSquare, tokens::closingSquare);
}

std::map<std::string, std::string> Parser::jsonObjectToMap(const std::vector<std::string> &jsonObjectTokens) {
    std::map<std::string, std::string> jsonObject;
    for (int i = 0; i < jsonObjectTokens.size(); i++) {
        if(jsonObjectTokens[i] == ":") {
            jsonObject.insert({jsonObjectTokens[i - 1], jsonObjectTokens[i + 1]});
        }
    }

    return jsonObject;
}