#ifndef ICache_hpp
#define ICache_hpp

class ICache {                                          //интерфейс
public:
    virtual int get(int key) = 0;
    virtual void put(int key, int value) = 0;
    virtual int operator[](int key) = 0;

    virtual ~ICache() = default;
};

#endif