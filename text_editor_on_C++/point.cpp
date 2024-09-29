struct point {
    point(int x = 0, int y = 0) : x(x), y(y) {}
    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }

    void change_x(int number) {
        x = number;
    }

    void change_y(int number) {
        y = number;
    }

    private:
        int x;
        int y;
};
