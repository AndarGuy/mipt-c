// Упорядочить матрицу по спирали.

#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Bound {
    int left;
    int right;
    int top;
    int bottom;
};

enum Direction {
    RIGHT = 0,
    BOTTOM = 1,
    LEFT = 2,
    TOP = 3,
};

void display(int matrix[10][10], int height, int width) {
    printf("Результат:\n");
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void input(int matrix[10][10], int height, int width) {
    int i, j;
    for (i = 0; i < height; i++) 
        for (j = 0; j < width; j++) 
            scanf("%d", &matrix[i][j]);
}

int rotate(enum Direction direction) {
    switch (direction) {
    case RIGHT:
        return BOTTOM;
    case BOTTOM:
        return LEFT;
    case LEFT:
        return TOP;
    case TOP:
        return RIGHT;
    }
}

struct Point next(struct Point point, struct Bound *bound, enum Direction *direction) {
    switch (*direction) {
        case RIGHT:
            if (point.y < (bound -> right)) {
                point.y++;
                return point;
            } else bound -> top++;
            break;
        case BOTTOM:
            if (point.x < bound -> bottom) {
                point.x++;
                return point;
            } else bound -> right--;
            break;
        case LEFT:
            if (point.y > bound -> left) {
                point.y--;
                return point;
            } else {
                bound -> bottom--;
            }
            break;
        case TOP:
            if (point.x > bound -> top) {
                point.x--;
                return point;
            } else bound -> left++;
            break;
    }
    *direction = rotate(*direction);
    return next(point, bound, direction);
}

void sort(int matrix[10][10], int columns, int rows) {
    enum Direction direction;
    struct Bound bound;
    struct Point point;

    int sorted = 0;

    while (!sorted) {
        sorted = 1;
        point.x = 0;
        point.y = 0;
        bound.bottom = rows - 1;
        bound.left = 0;
        bound.right = columns - 1;
        bound.top = 0;
        direction = RIGHT;
        while ((bound.bottom - bound.top) + (bound.right - bound.left) > 0) {
            struct Point nextPoint = next(point, &bound, &direction);
            if (matrix[point.x][point.y] > matrix[nextPoint.x][nextPoint.y]) {
                swap(&matrix[point.x][point.y], &matrix[nextPoint.x][nextPoint.y]);
                sorted = 0;
            }
            point = nextPoint;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int matrix[10][10];
    input(matrix, n, n);

    sort(matrix, n, n);

    display(matrix, n, n);

    return 0;
}