#include <fstream>
#include "reader.hpp"
#include "ScanLine.hpp"
#include <vector>

int main() {
    std::ifstream input("./PNGReader/working_copy");
    std::vector<std::vector<int>> bits = get_bits_array(input);
    input.close();

    solution::ScanLine line;
    line.SetImage(bits);
    line.SolveTask();
    return 0;
}
