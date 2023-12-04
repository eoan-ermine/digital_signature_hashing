#include "hashing.hpp"

#include <QString>

long long hashSum(const QString &text, HashParameters params) {
    long long K{};
    for (const auto c : text) {
        K += c.digitValue();
    }
    return (K <= params.max ? K : K % (params.max + 1));
}

long long gammaSum(const QString &text, GammaParameters params) {
    long long K = params.t;
    long long previousT = params.t;
    for (const auto c: text) {
        auto X = c.digitValue();
        auto T = (params.a * previousT + params.b) % params.c;
        auto Y = (X ^ T);
        K = (K + Y) % params.c;
    }
    return K;
}
