#pragma once

enum Orientation { HORIZONTAL, VERTICAL };

class Zone {
public:
    char name = 'X';
    int startX = 0;
    int endX = 0;
    int startY = 0;
    int endY = 0;
    Orientation orientation = HORIZONTAL;
};
