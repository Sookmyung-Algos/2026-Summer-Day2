unsigned int setMask;

void Init() {
    setMask = 0u;
}

void Flip() {
    setMask = ~setMask;
}

void Insert(int k) {
    setMask |= (1u << k);
}

void Erase(int k) {
    setMask &= ~(1u << k);
}

int Find(int k) {
    return (setMask >> k) & 1u;
}

void Inverse(int k) {
    setMask ^= (1u << k);
}

void Plus(int k) {
    k %= 32;

    if (k == 0) return;

    setMask = (setMask << k)
            | (setMask >> (32 - k));
}

void Minus(int k) {
    k %= 32;

    if (k == 0) return;

    setMask = (setMask >> k)
            | (setMask << (32 - k));
}

void Clear(int k) {
    unsigned int lowerMask =
        (1u << k) | ((1u << k) - 1u);

    setMask &= ~lowerMask;
}

void Fill(int k) {
    unsigned int lowerMask =
        (1u << k) | ((1u << k) - 1u);

    setMask |= lowerMask;
}
