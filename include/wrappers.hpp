#ifndef DYNSYS_WRAPPERS_HPP_
#define DYNSYS_WRAPPERS_HPP_

// Macro for MatLab users that prefer external functions
template<typename T>
inline auto GetLength(const T& v) {
    return v.length();
}

// Macro for MatLab users that prefer external functions
template<typename T>
inline auto GetDimension(const T& g) {
    return g.length();
}

#endif // DYNSYS_WRAPPERS_HPP_

