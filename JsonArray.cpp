#include "JsonItem.h"

JsonArray::JsonArray(std::string array, bool fromFile) {
    if(fromFile) {
        jsonArray = parser.tokenizeJsonArray(parser.utils.trimString(parser.utils.readFromFile(array)));
    } else {
        jsonArray = parser.tokenizeJsonArray(parser.utils.trimString(array));
    }
}

bool JsonArray::isNotNull(int index) {
    return getString(index) != tokens::null;
}

int JsonArray::length() {
    return jsonArray.size();
}

std::string JsonArray::getString(int index) {
    return jsonArray[index];
}

bool JsonArray::getBool(int index) {
    return parser.utils.toBool(jsonArray[index]);
}

int JsonArray::getInt(int index) {
    return std::stoi(jsonArray[index]);
}

double JsonArray::getDouble(int index) {
    return std::stod(jsonArray[index]);
}

float JsonArray::getFloat(int index) {
    return std::stof(jsonArray[index]);
}

JsonArray JsonArray::getJsonArray(int index) {
    return JsonArray(jsonArray[index]);
}

JsonObject JsonArray::getJsonObject(int index) {
    return JsonObject(jsonArray[index]);
}