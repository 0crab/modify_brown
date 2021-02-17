#ifndef MODIFY_BROWN_RANDOM_GEN_H
#define MODIFY_BROWN_RANDOM_GEN_H

#include "generator.h"
#include <random>
#include <sys/types.h>
#include <sys/stat.h>

#define FUZZY_BOUND 0

template<typename R>
class RandomGenerator {
public:
    static inline void generate(R *array, size_t range, size_t count, double skew = 0.0) {
        struct stat buffer;
        if (skew < zipf_distribution<R>::epsilon) {
            std::default_random_engine engine(
                    static_cast<R>(std::chrono::steady_clock::now().time_since_epoch().count()));
            std::uniform_int_distribution<size_t> dis(0, range + FUZZY_BOUND);
            for (size_t i = 0; i < count; i++) {
                array[i] = static_cast<R>(dis(engine));
            }
        } else {
            zipf_distribution<R> engine(range, skew);
            std::mt19937 mt;
            for (size_t i = 0; i < count; i++) {
                array[i] = engine(mt);
            }
        }
    }
};

#endif //MODIFY_BROWN_RANDOM_GEN_H
