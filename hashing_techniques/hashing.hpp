#pragma once

class QString;

struct HashParameters {
    long long max;
};

struct GammaParameters {
    long long a;
    long long b;
    long long c;
    long long t;
};

long long hashSum(const QString &text, HashParameters params);
long long gammaSum(const QString &text, GammaParameters params);