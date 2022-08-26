# rand_util.hpp: a simplified and abbreviated interface to std::random. 

## `rand_int(lo, hi)`
```
template<class Generator = std::mt19937, class IntType>
IntType rand_int(IntType lo, IntType hi);
```

## rand_real(lo, hi)
```
template<class Generator = std::mt19937, class RealType>
RealType rand_real(RealType lo, RealType hi);

template<class Generator = std::mt19937, class IntType>
double rand_real(IntType lo, IntType hi);
```

## rand_normal(mean, std_dev)
```
template<class Generator = std::mt19937, class RealType>
RealType rand_normal(RealType mean, RealType std_dev);

template<class Generator = std::mt19937, class IntType>
double rand_normal(IntType mean, IntType std_dev);
```

## rand_seed(seedvalue)
```
template<class Generator = std::mt19937>
void rand_seed(int seedval0, int seedval1 = 0);
```

## rand_seed_all(seedvalue) 
```
void rand_seed_all(int seedval0, int seedval1 = 0);
```
