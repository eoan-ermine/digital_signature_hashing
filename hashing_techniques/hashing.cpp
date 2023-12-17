#include "hashing.hpp"

#include <QString>

long long controlSum(const QString &text, HashParameters params) {
    long long K{};
    for (const auto c : text) {
        K += c.unicode();
    }
    return (K <= params.max ? K : K % (params.max + 1));
}

long long gammaSum(const QString &text, GammaParameters params) {
    // В исходном алгоритме: пусть каждому символу соответствует восьмибитное двоичное слово X_{i}
    // Наш алгоритм использует модификацию: шестнадцатибитное двоичное слово. Это не меняет сути.

    // В исходном алгоритме: Каждое T получается по рекуррентной формуле: T_{i + 1} = (a * t_i + b) % c
    // Наш алгоритм вычисляет его без модификаций.

    // В исходном алгоритме: Y_{i} = X_{i} ^ T_{i}
    // Наш алгоритм вычисляет его без модификаций.

    // В исходном алгоритме: Происходит суммирование полученных значений по модулю MaxVal + 1 (c)
    // Наш алгоритм выполняет это суммирование без изменений.

    long long R = 0;
    long long previousT = params.t;
    for (const auto c: text) {
        auto X = c.unicode();
        auto T = (params.a * previousT + params.b) % params.c;
        auto Y = (X ^ T);
        R =  (R + Y) % params.c;
        previousT = T;
    }
    return R;
}
