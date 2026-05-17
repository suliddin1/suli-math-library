#pragma once
#ifndef SULI_H
#define SULI_H
#include <string>    // std::string v? std::to_string üçün
#include <algorithm> // std::reverse üçün

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
#include <stdexcept>

//              RIYAZIYYAT.H - Azerbaycanca Funksiyalar

// 1. Toplama
template<typename T>
T topla(T a, T b) {
    return a + b;
}

// 2. Vurma
template<typename T>
T vur(T a, T b) {
    return a * b;
}

// 3. Bolme
template<typename T>
T bol(T a, T b) {
    if (b == 0) throw std::invalid_argument("Bolme: Sifre bolmek olmaz!");
    return a / b;
}

// 4. Ustegelme (Toplama)
template<typename T>
T ustegelme(T a, T b) {
    return a + b;
}

// 5. Cixma
template<typename T>
T cix(T a, T b) {
    return a - b;
}

// 6. Palindrom yoxlanilmasi
bool palindromMu(long long n) {
    if (n < 0) return false;
    std::string s = std::to_string(n);
    std::string r = s;
    std::reverse(r.begin(), r.end());
    return s == r;
}

// 7. Faktorialin tapilmasi (n!)
long long faktorial(int n) {
    if (n < 0) throw std::invalid_argument("Faktorial: Menfi reqem!");
    if (n == 0 || n == 1) return 1;
    long long netice = 1;
    for (int i = 2; i <= n; i++)
        netice *= i;
    return netice;
}

// 8. Sade eded yoxlanilmasi
bool sadeMi(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

// 9. EBOB 
long long ebob(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return std::abs(a);
}

// 10. EKOB 
long long ekob(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return std::abs(a / ebob(a, b) * b);
}

// 11. Fibonacchi n-ci hedd
long long fibonacchi(int n) {
    if (n < 0) throw std::invalid_argument("Fibonacchi: Menfi indeks!");
    if (n == 0) return 0;
    if (n == 1) return 1;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// 12. Ededi ters cevirmek (reqemlerin yerini deyismek)
long long terseCevir(long long n) {
    bool menfimi = (n < 0);
    if (menfimi) n = -n;
    long long ters = 0;
    while (n > 0) {
        ters = ters * 10 + n % 10;
        n /= 10;
    }
    return menfimi ? -ters : ters;
}

// 13. Armstrong ededi yoxlanilmasi
bool armstrongMu(long long n) {
    if (n < 0) return false;
    std::string s = std::to_string(n);
    int req = s.size();
    long long cem = 0;
    for (char c : s)
        cem += (long long)std::pow(c - '0', req);
    return cem == n;
}

// 14. Mukemmel eded yoxlanilmasi
bool mukemmelMi(long long n) {
    if (n <= 1) return false;
    long long cem = 1;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cem += i;
            if (i != n / i) cem += n / i;
        }
    }
    return cem == n;
}

// 15. Quvvete yukseltme 
double quvvet(double a, double b) {
    return std::pow(a, b);
}

// Tam eded versiyasi (asan istifade ucun)
long long quvvetTam(long long a, int b) {
    if (b < 0) throw std::invalid_argument("quvvetTam: Menfi us!");
    long long netice = 1;
    for (int i = 0; i < b; i++)
        netice *= a;
    return netice;
}

// 16. Kvadrat kok 
double kvadratKok(double x) {
    if (x < 0) throw std::invalid_argument("kvadratKok: Menfi reqem!");
    if (x == 0) return 0;
    double taxmin = x / 2.0;
    for (int i = 0; i < 1000; i++)
        taxmin = (taxmin + x / taxmin) / 2.0;
    return taxmin;
}

// 17. Reqemlerin cemi
long long reqemlerCemi(long long n) {
    if (n < 0) n = -n;
    long long cem = 0;
    while (n > 0) {
        cem += n % 10;
        n /= 10;
    }
    return cem;
}

// 18. Reqemlerin hasil
long long reqemlerHasili(long long n) {
    if (n < 0) n = -n;
    if (n == 0) return 0;
    long long hasil = 1;
    while (n > 0) {
        hasil *= n % 10;
        n /= 10;
    }
    return hasil;
}

// 19. Bolenlerin sayi
long long bolenlerSayi(long long n) {
    if (n <= 0) return 0;
    long long say = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            say++;
            if (i != n / i) say++;
        }
    }
    return say;
}

// 20. Bolenlerin cemi
long long bolenlerCemi(long long n) {
    if (n <= 0) return 0;
    long long cem = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cem += i;
            if (i != n / i) cem += n / i;
        }
    }
    return cem;
}

// 21. Ikilik (Binary) sistemine cevirmek
std::string ikilikSistem(long long n) {
    if (n == 0) return "0";
    bool menfimi = (n < 0);
    if (menfimi) n = -n;
    std::string netice = "";
    while (n > 0) {
        netice = char('0' + n % 2) + netice;
        n /= 2;
    }
    return menfimi ? "-" + netice : netice;
}

// 22. Onluq (Decimal) sistemine cevirmek (ikili stringden)
long long onluqSistem(const std::string& ikili) {
    long long netice = 0;
    for (char c : ikili) {
        if (c != '0' && c != '1')
            throw std::invalid_argument("onluqSistem: Yalniz 0 ve 1 ola biler!");
        netice = netice * 2 + (c - '0');
    }
    return netice;
}

// 23. Sekkizlik (Octal) sistemine cevirmek
std::string sekkizlikSistem(long long n) {
    if (n == 0) return "0";
    bool menfimi = (n < 0);
    if (menfimi) n = -n;
    std::string netice = "";
    while (n > 0) {
        netice = char('0' + n % 8) + netice;
        n /= 8;
    }
    return menfimi ? "-" + netice : netice;
}

// 24. Onaltilik (Hexadecimal) sistemine cevirmek
std::string onaltilikSistem(long long n) {
    if (n == 0) return "0";
    bool menfimi = (n < 0);
    if (menfimi) n = -n;
    const std::string simvollar = "0123456789ABCDEF";
    std::string netice = "";
    while (n > 0) {
        netice = simvollar[n % 16] + netice;
        n /= 16;
    }
    return menfimi ? "-" + netice : netice;
}

// 25. Eded orta 
double ededOrta(const std::vector<double>& v) {
    if (v.empty()) throw std::invalid_argument("ededOrta: Bos vektor!");
    double cem = 0;
    for (double x : v) cem += x;
    return cem / v.size();
}

// 26. Hendesi orta
double hendesiOrta(const std::vector<double>& v) {
    if (v.empty()) throw std::invalid_argument("hendesiOrta: Bos vektor!");
    double hasil = 1.0;
    for (double x : v) {
        if (x <= 0) throw std::invalid_argument("hendesiOrta: Musb?? deyerler lazimdir!");
        hasil *= x;
    }
    return std::pow(hasil, 1.0 / v.size());
}

// 27. Harmonik orta
double harmonikOrta(const std::vector<double>& v) {
    if (v.empty()) throw std::invalid_argument("harmonikOrta: Bos vektor!");
    double tersCem = 0;
    for (double x : v) {
        if (x == 0) throw std::invalid_argument("harmonikOrta: Sifir element ola bilmez!");
        tersCem += 1.0 / x;
    }
    return v.size() / tersCem;
}

// 28. Modul (Mutleq qiymet)
template<typename T>
T mutleq(T x) {
    return (x < 0) ? -x : x;
}

// 29. Kombinezyon C(n, k)
long long kombinezyon(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k;
    long long netice = 1;
    for (int i = 0; i < k; i++) {
        netice = netice * (n - i) / (i + 1);
    }
    return netice;
}

// 30. Permutasiya P(n, k)
long long permutasiya(int n, int k) {
    if (k < 0 || k > n) return 0;
    long long netice = 1;
    for (int i = n; i > n - k; i--)
        netice *= i;
    return netice;
}

// 31. Guclu eded yoxlanilmasi (Strong number)
bool gucluMu(long long n) {
    long long orijinal = n;
    long long cem = 0;
    while (n > 0) {
        cem += faktorial(n % 10);
        n /= 10;
    }
    return cem == orijinal;
}

// 32. Xosbext eded yoxlanilmasi (Happy number)
bool xosbextMi(long long n) {
    long long yavash = n, tez = n;
    do {
        auto adim = [](long long x) -> long long {
            long long s = 0;
            while (x > 0) {
                long long r = x % 10;
                s += r * r;
                x /= 10;
            }
            return s;
        };
        yavash = adim(yavash);
        tez = adim(adim(tez));
    } while (yavash != tez);
    return yavash == 1;
}

// 33. Artiq eded yoxlanilmasi (Abundant number)
bool artiqMi(long long n) {
    if (n <= 1) return false;
    return (bolenlerCemi(n) - n) > n;
}

// 34. Disarium ededi yoxlanilmasi
bool disariumMu(long long n) {
    std::string s = std::to_string(n);
    long long cem = 0;
    for (int i = 0; i < (int)s.size(); i++)
        cem += (long long)std::pow(s[i] - '0', i + 1);
    return cem == n;
}

// 35. Paskal ucbucagi n-ci setri
std::vector<long long> paskalSetri(int n) {
    if (n < 0) throw std::invalid_argument("paskalSetri: Menfi indeks!");
    std::vector<long long> setr(n + 1, 0);
    setr[0] = 1;
    for (int i = 1; i <= n; i++)
        setr[i] = setr[i - 1] * (n - i + 1) / i;
    return setr;
}

#endif // SULI_H
