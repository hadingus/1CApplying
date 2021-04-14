
namespace solution {

    struct Line {
        Line() {}

        Line(int x_begin, int y_begin, int width, int height, bool is_hor);

        Line& operator=(const Line& other);

        int start_x;
        int start_y;
        int width;
        int height;
        bool is_horizontal;
    };


    struct Point {
        Point() = default;

        Point(int x, int y);
        Point& operator=(const Point& other);

        int x;
        int y;
    };

    struct Rectangle {
        Rectangle() = default;

        Rectangle(const Point& A, const Point& B);

        Rectangle& operator=(const Rectangle& other);

        Point A, B;
    };

}
