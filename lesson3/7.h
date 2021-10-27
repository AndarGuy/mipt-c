struct Complex {
    float a;
    float b;
};

struct Complex sum(struct Complex, struct Complex);

struct Complex sub(struct Complex, struct Complex);

void mul(struct Complex, struct Complex, struct Complex *z);

void div(struct Complex, struct Complex, struct Complex *z);
