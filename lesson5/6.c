#include <stdio.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

struct Rect {
    struct Point lt;
    struct Point rb;
};

struct Rect rotate(struct Rect rect) {
    struct Rect nRect;
    nRect.rb.x = -rect.lt.x;
    nRect.rb.y = -rect.lt.y;
    nRect.lt.x = -rect.rb.x;
    nRect.lt.y = -rect.rb.y;
}

struct Rect mirrorY(struct Rect rect) {
    struct Rect nRect;
    nRect.lt.x = -rect.rb.x;
    nRect.rb.x = -rect.lt.x;
    nRect.lt.y = rect.lt.y;
    nRect.rb.y = rect.rb.y;
    return nRect;
}

struct Rect mirrorX(struct Rect rect) {
    struct Rect nRect;
    nRect.rb.y = -rect.lt.y;
    nRect.lt.y = -rect.rb.y;
    nRect.rb.x = rect.rb.x;
    nRect.lt.x = rect.lt.x;
    return nRect;
}

int main() {
    struct Rect rect;
    scanf("%d %d %d %d", &rect.lt.x, &rect.lt.y, &rect.rb.x, &rect.rb.y);
    struct Rect mY = mirrorY(rect);
    printf("Mirrored by Y: %d %d %d %d\n", mY.lt.x, mY.lt.y, mY.rb.x, mY.rb.y);
    struct Rect mX = mirrorX(rect);
    printf("Mirrored by X: %d %d %d %d\n", mX.lt.x, mX.lt.y, mX.rb.x, mX.rb.y);
    struct Rect mR = mirrorX(mirrorY(rect));
    printf("Rotated: %d %d %d %d\n", mR.lt.x, mR.lt.y, mR.rb.x, mR.rb.y);
    
    return 0;
}
