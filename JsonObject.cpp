#include "JsonItem.h"

JsonObject::JsonObject(const std::string &object, bool fromFile) {
    if(fromFile) {
        jsonObject = parser.jsonObjectToMap(parser.tokenizeJsonObject(parser.utils.trimString(parser.utils.readFromFile(object))));
    } else {
        jsonObject = parser.jsonObjectToMap(parser.tokenizeJsonObject(parser.utils.trimString(object)));
    }
}

bool JsonObject::has(const std::string &key) {
    return jsonObject.find(key) != jsonObject.end();
}

bool JsonObject::isNotNull(const std::string &key) {
    return getString(key) != tokens::null;
}

std::string JsonObject::getString(const std::string &key) {
    return jsonObject[key];
}

bool JsonObject::getBool(const std::string &key) {
    return parser.utils.toBool(jsonObject[key]);
}

int JsonObject::getInt(const std::string &key) {
    return std::stoi(jsonObject[key]);
}

double JsonObject::getDouble(const std::string &key) {
    return std::stod(jsonObject[key]);
}

float JsonObject::getFloat(const std::string &key) {
    return std::stof(jsonObject[key]);
}

JsonArray JsonObject::getJsonArray(const std::string &key) {
    return JsonArray(jsonObject[key]);
}

JsonObject JsonObject::getJsonObject(const std::string &key) {
    return JsonObject(jsonObject[key]);
}