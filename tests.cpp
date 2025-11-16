#include "gtest/gtest.h"
#include "FibonachhiCacheLRU.hpp"
#include "FibonachhiCacheLFU.hpp"

TEST(LRUCacheTest, PutGet) {
    FibonachhiCacheLRU cache(2);
    cache.put(1, 100);
    EXPECT_EQ(cache.get(1), 100);
}

TEST(LRUCacheTest, GetMissingReturnsMinusOne) {
    FibonachhiCacheLRU cache(2);
    EXPECT_EQ(cache.get(5), -1);
}

TEST(LRUCacheTest, EvictsLeastRecentlyUsed) {
    FibonachhiCacheLRU cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cache.get(1);

    cache.put(3, 30);

    EXPECT_EQ(cache.get(2), -1);
    EXPECT_EQ(cache.get(1), 10);
    EXPECT_EQ(cache.get(3), 30);
}

TEST(LRUCacheTest, UpdateValueDoesNotChangeSize) {
    FibonachhiCacheLRU cache(2);

    cache.put(1, 10);
    cache.put(1, 20);

    EXPECT_EQ(cache.get(1), 20);
}

TEST(LRUCacheTest, CapacityOne) {
    FibonachhiCacheLRU cache(1);

    cache.put(1, 10);
    EXPECT_EQ(cache.get(1), 10);

    cache.put(2, 20);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(2), 20);
}

TEST(LFUCacheTest, PutGet) {
    FibonachhiCacheLFU cache(2);
    cache.put(1, 200);
    EXPECT_EQ(cache.get(1), 200);
}

TEST(LFUCacheTest, GetMissingReturnsMinusOne) {
    FibonachhiCacheLFU cache(2);
    EXPECT_EQ(cache.get(123), -1);
}

TEST(LFUCacheTest, EvictsLeastFrequentlyUsed) {
    FibonachhiCacheLFU cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cache.get(1);
    cache.get(1);

    cache.put(3, 30);

    EXPECT_EQ(cache.get(2), -1);
    EXPECT_EQ(cache.get(1), 10);
    EXPECT_EQ(cache.get(3), 30);
}

TEST(LFUCacheTest, EvictsLRUWithinSameFrequency) {
    FibonachhiCacheLFU cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cache.get(1);

    cache.put(3, 30);
    EXPECT_EQ(cache.get(2), -1);
}

TEST(LFUCacheTest, UpdateValueDoesNotResetFrequency) {
    FibonachhiCacheLFU cache(2);

    cache.put(1, 10);
    cache.get(1);
    cache.put(1, 99);

    EXPECT_EQ(cache.get(1), 99);
}

TEST(LFUCacheTest, CapacityOne) {
    FibonachhiCacheLFU cache(1);

    cache.put(1, 10);
    EXPECT_EQ(cache.get(1), 10);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
