#include "ScanLine.hpp"
#include <queue>

namespace solution {
    void ScanLine::SetImage(const std::vector<std::vector<int>>& new_image) {
        image_ = new_image;
        height = image_.size();
        width = image_[0].size();
    }

    int ScanLine::get_bit(int i, int j, bool is_inverted) {
        return is_inverted ? image_[j][i] : image_[i][j];
    }

    std::vector<Line> ScanLine::GetLines(int x_len, int y_len, bool is_vertical) {
        std::vector<Line> thin_lines;

        for (int i = 0; i < x_len; ++i) {
            for (int j = 0; j < y_len;) {
                if (get_bit(i, j, is_vertical) == 1) {
                    int start = j;
                    int current_len = 0;
                    while (j < y_len && get_bit(i, j, is_vertical) == 1) {
                        ++current_len;
                        ++j;
                    }
                    if (current_len >= LINE_DETECT) {
                        if (is_vertical) {
                            thin_lines.emplace_back(i, start, 1, current_len, false);
                        } else {
                            thin_lines.emplace_back(start, i, 1, current_len, true);
                        }
                        break;
                    }
                } else {
                    ++j;
                }
            }
        }

        std::vector<Line> lines;
        for (int i = 0; i < thin_lines.size();) {
            Line current = thin_lines[i];
            current.width = 0;
            if (is_vertical) {
                while (i < thin_lines.size() && current.start_x + current.width == thin_lines[i].start_x) {
                    ++current.width;
                    ++i;
                }
            } else {
                while (i < thin_lines.size() && current.start_y + current.width == thin_lines[i].start_y) {
                    ++current.width;
                    ++i;
                }
            }
            lines.push_back(current);
        }

        return lines;
    }

    std::vector<Line> ScanLine::GetHorizontalLines() {
        return GetLines(height, width, false);
    }

    std::vector<Line> ScanLine::GetVerticalLines() {
        return GetLines(width, height, true);
    }


    bool ScanLine::InArea(const Point &p, const Rectangle &area) {
        return p.x >= area.A.x && p.x < area.B.x && p.y >= area.A.y && p.y < area.B.y;
    }

    void ScanLine::BFS(const Point &v, const Rectangle &area, int val) {
        int dx[] = {1, 0};
        int dy[] = {0, 1};
        std::queue<Point> points_queue;
        points_queue.push(v);
        while (!points_queue.empty()) {
            Point current = points_queue.front();
            points_queue.pop();
            for (int i = 0; i < 2; ++i) {
                Point next(current.x + dx[i], current.y + dy[i]);
                if (InArea(next, area) && image_[next.x][next.y] == 0) {
                    image_[next.x][next.y] = val;
                    points_queue.push(next);
                }
            }
        }
    }

    ScanLine::Results ScanLine::ProcessField(const Rectangle &area) {
        bool has_black = false;
        int val = 2;
        for (int i = area.A.x; i < area.B.x; ++i) {
            for (int j = area.A.y; j <= area.B.y; ++j) {
                if (image_[i][j] == 1) {
                    has_black = true;
                } else if (image_[i][j] == 0) {
                    BFS(Point(i, j), area, ++val);
                }
            }
        }
        if (has_black && val == 3) {
            return CROSS;
        } else if (!has_black && val == 3) {
            return EMPTY;
        } else {
            return ZERO;
        }
    }

    void ScanLine::SolveTask() {

        auto verticals = GetVerticalLines();
        auto horizontals = GetHorizontalLines();

        Line first_vertical(horizontals.begin()->start_x - 1, verticals.begin()->start_y, 1, verticals.begin()->height,
                            false);
        Line last_vertical(horizontals.begin()->start_x + horizontals.begin()->height + 1, verticals.begin()->start_y, 1, verticals.begin()->height,
                           false);

        Line first_horizontal(horizontals.begin()->start_x, verticals.begin()->start_y - 1, 1, horizontals.begin()->height, true);
        Line last_horizontal(horizontals.begin()->start_x, verticals.begin()->start_y + verticals.begin()->height + 1, 1, horizontals.begin()->height,
                             true);

        verticals.insert(verticals.begin(), first_vertical);
        verticals.push_back(last_vertical);

        horizontals.insert(horizontals.begin(), first_horizontal);
        horizontals.push_back(last_horizontal);

        std::vector<std::vector<Results>> game(3, std::vector<Results>(3, EMPTY));
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                /*
                Point LeftUp(horizontals[i - 1].start_x + horizontals[i - 1].height)
                game[i - 1][j - 1] = ProcessField(R)
                 */
            }
        }
    }


}