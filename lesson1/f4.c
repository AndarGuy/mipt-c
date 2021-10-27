void div(float a, float b, float c, float d, float *e, float *f) {
    *e = (a*c + b*d) / (c * c + d * d);
    *f = (b*c - a*d) / (c*c + d*d);
    return;
}
