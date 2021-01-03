#include "Parser.h"

class JsonArray;

class JsonObject {
    public:
        JsonObject(const std::string &object, bool fromFile = false);

        bool has(const std::string &key);
        bool isNotNull(const std::string &key);

        std::string getString(const std::string &key);
        bool getBool(const std::string &key);
        int getInt(const std::string &key);
        double getDouble(const std::string &key);
        float getFloat(const std::string &key);
        JsonArray getJsonArray(const std::string &key);
        JsonObject getJsonObject(const std::string &key);

    private:
        std::map<std::string, std::string> jsonObject;
        Parser parser;
};

class JsonArray {
    public:
        JsonArray(std::string array, bool fromFile = false);

        int length();
        bool isNotNull(int index);

        std::string getString(int index);
        bool getBool(int index);
        int getInt(int index);
        double getDouble(int index);
        float getFloat(int index);
        JsonArray getJsonArray(int index);
        JsonObject getJsonObject(int index); 

    private:
        std::vector<std::string> jsonArray;
        Parser parser;
};