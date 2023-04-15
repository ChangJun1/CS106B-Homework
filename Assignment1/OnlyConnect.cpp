#include <gtest/gtest.h>
#include <string>

bool isConsonant(char c) {
    if (std::isalpha(c) && std::toupper(c) != 'A' && std::toupper(c) != 'E' && std::toupper(c) != 'I' && std::toupper(c) != 'O' && std::toupper(c) != 'U') {
        return true;
    }
    return false;
}

std::string onlyConnectize(std::string phrase) {
    if (phrase.empty()) {
        return "";
    }

    std::string prefix;
    if (isConsonant(phrase[0])) {
        prefix += (char) std::toupper(phrase[0]);
    }
    return prefix + onlyConnectize(phrase.substr(1));
}

//Non-Recursive
//#include <algorithm>
//#include <cctype>
//#include <regex>
//#include <string>
//std::string onlyConnectize(std::string str) {
//    // 定义正则表达式规则，匹配元音字母、标点符号、空格和数字
//    std::regex re("[aeiouAEIOU\\W\\d\\s]");
//    // 使用正则表达式规则替换字符串中匹配到的字符为空字符
//    str = std::regex_replace(str, re, "");
//    // 使用 transform 算法将字符串中所有字符转为大写
//    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });
//    return str;
//}

TEST(TEST, MyTEST) {
    ASSERT_EQ(onlyConnectize("Elena Kagan"), "LNKGN");
    ASSERT_EQ(onlyConnectize("Antonin Scalia"), "NTNNSCL");
    ASSERT_EQ(onlyConnectize("EE 364A"), "");
    ASSERT_EQ(onlyConnectize("For sale: baby shoes, never worn."), "FRSLBBYSHSNVRWRN");
    ASSERT_EQ(onlyConnectize("For sale: baby shoes, never worn."), "FRSLBBYSHSNVRWRN");
    ASSERT_EQ(onlyConnectize("Annie Mae, My Sea Anemone Enemy!"), "NNMMYSNMNNMY");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}