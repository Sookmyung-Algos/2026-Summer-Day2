/// === user.cpp ===

static unsigned int S; // 32개의 원소를 비트로 표현 (i번째 비트 = i가 집합에 있는지)

void Init(){
    S = 0;
}

void Flip(){
    S = ~S;
}

void Insert(int k){
    S |= (1u << k);
}

void Erase(int k){
    S &= ~(1u << k);
}

int Find(int k){
    return (S >> k) & 1;
}

void Inverse(int k){
    S ^= (1u << k);
}

// 모든 원소에 k를 더함 = 비트를 왼쪽으로 k만큼 회전(rotate)
void Plus(int k){
    S = (S << k) | (S >> (32 - k));
}

// 모든 원소에서 k를 뺌 = 비트를 오른쪽으로 k만큼 회전(rotate)
void Minus(int k){
    S = (S >> k) | (S << (32 - k));
}

// k 이하 원소들 삭제 = 0~k번 비트를 0으로 만듦
void Clear(int k){
    S &= ~((k == 31) ? 0xFFFFFFFFu : ((1u << (k+1)) - 1));
}

// k 이하 원소들 채움 = 0~k번 비트를 1로 만듦
void Fill(int k){
    S |= (k == 31) ? 0xFFFFFFFFu : ((1u << (k+1)) - 1);
}