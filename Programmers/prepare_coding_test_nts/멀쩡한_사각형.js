function solution(w, h) {
    return w * h - (w + h - gcd(w, h));    
}

function gcd(a, b) {
    return b ? gcd(b, a % b) : a;
}
