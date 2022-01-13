function solution(a, b) {
    return a.map((_, index) => a[index] * b[index])
            .reduce((sum, cur) => sum + cur);
}
