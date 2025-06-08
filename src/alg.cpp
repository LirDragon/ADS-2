// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
  return 0.0;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
  return 0.0;
}
enum class FunctionType { EXP, SIN, COS };
double calcItem(double x, uint16_t n) {
   switch (type) {
        case FunctionType::EXP:
            return pown(x, n) / fact(n);
        
        case FunctionType::SIN: {
            int sign = (n % 2 == 0) ? 1 : -1;
            return sign * pown(x, 2 * n + 1) / fact(2 * n + 1);
        }
        
        case FunctionType::COS: {
            int sign = (n % 2 == 0) ? 1 : -1;
            return sign * pown(x, 2 * n) / fact(2 * n);
        }
        
        default:
            return 0.0;
    }
  return 0.0;
}
double expn(double x, uint16_t count) {
   double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, n, FunctionType::EXP);
    }
    return sum;
  return 0.0;
}
double sinn(double x, uint16_t count) {
  double sinn(double x, uint16_t count) {
    const double PI = 3.14159265358979323846;
    while (x > PI) x -= 2 * PI;
    while (x < -PI) x += 2 * PI;

    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, n, FunctionType::SIN);
    }
    return sum;
  return 0.0;
}

double cosn(double x, uint16_t count) {
  const double PI = 3.14159265358979323846;
    while (x > PI) x -= 2 * PI;
    while (x < -PI) x += 2 * PI;
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, n, FunctionType::COS);
    }
    return sum;
  return 0.0;
}
