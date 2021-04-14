#pragma once

#include <vector>
#include "Geometry.hpp"

namespace solution {

    class ScanLine {
    public:
        ScanLine() = default;

        void SetImage(const std::vector<std::vector<int>> &new_image);

        void SolveTask();

        std::vector<std::vector<int>> GetResult();

        private:
        enum Results {
            CROSS,
            ZERO,
            EMPTY
        };

        int get_bit(int i, int j, bool is_inverted);

        Results ProcessField(const Rectangle& area);
        void BFS(const Point& bit, const Rectangle& area, int val);
        bool InArea(const Point& p, const Rectangle& area);

        std::vector<Line> GetLines(int x_len, int y_len, bool is_horizontal);
        std::vector<Line> GetVerticalLines();
        std::vector<Line> GetHorizontalLines();
        std::vector<std::vector<int>> image_{};

        int width{-1};
        int height{-1};

        const int LINE_DETECT = 200;
    };
}