# cpp-jsonparser
A very simple JSON parser written using C++11. This parser only supports deserialization and assumes the input of valid JSON as defined by json.org.

## Example Usages

```C++
void printSimple() {
    std::cout << "-----TEST1-----\n";
    JsonObject data("{\"data\": true, \"nums\": [7.6, 3.5, 7.8, 1.0E+2]}");
    std::cout << data.getBool("data") << "\n";

    JsonArray dataArr = data.getJsonArray("nums");
    for (int i = 0; i < dataArr.length(); i++) {
        std::cout << dataArr.getFloat(i) << "\n";
    }

    JsonArray arr("[\"hello\", \"world\", \"this\", \"is\", \"cool\"]");
    for (int i = 0; i < arr.length(); i++) {
        std::cout << arr.getString(i) << "\n";
    }
}

void printTopAnime() {
    std::cout << "-----TEST2-----\n";

    // constructors for JsonObject and JsonArr can deserialize from a string or from a file.
    // Set the second parameter to true to specify that the json data is in a file.
    JsonObject anime("example2.json", true);
    JsonArray top = anime.getJsonArray("top");
    for (int i = 0; i < top.length(); i++) {
        JsonObject currentAnime = top.getJsonObject(i);
        std::cout << currentAnime.getString("title") << "\n";
    }
    std::cout << "\n";
}

void printMemeTitlesAndUrls() {
    std::cout << "-----TEST3-----\n";
    JsonArray memes = JsonObject("example1.json", true).getJsonObject("data").getJsonArray("children");
    for (int i = 0; i < memes.length(); i++) {
        JsonObject currentPost = memes.getJsonObject(i).getJsonObject("data");
        std::cout << currentPost.getString("title") << "\n";
        if(currentPost.has("preview") && currentPost.isNotNull("preview")) {
            JsonObject imageSource = currentPost.getJsonObject("preview").getJsonArray("images").getJsonObject(0);
            std::cout << imageSource.getJsonObject("source").getString("url") << "\n";
        }
    }
}
```
