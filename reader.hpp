#include <vector>
#include <string>
#include <fstream>

std::vector<std::vector<int>> get_bits_array(std::ifstream& input) {
    std::vector<std::vector<int>> result_arr;
    std::string str;
    int kek = 0;
    while (!input.eof()) {
        input >> str;
        result_arr.emplace_back();
        for (char &c : str) {

            result_arr.back().emplace_back(c == '1' ? 1 : 0);
        }
    }
    return result_arr;
}
