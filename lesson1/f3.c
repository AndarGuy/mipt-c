void mul(float a1, float b1, float a2, float b2, float *a3, float *b3) {
    *a3 = a1 * a2 - b1 * b2;
    *b3 = a1 * b2 + b1 * a2;
    return;
}
