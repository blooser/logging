#ifndef TYPES_H
#define TYPES_H

#include <type_traits>
#include <string>

namespace logging {

namespace types {

template <typename, typename, typename = void>
struct is_streamable : std::false_type { };

template <typename T, typename S>
struct is_streamable<T, S, std::void_t<decltype(std::declval<T&>() << std::declval<S>())>> : std::true_type {};

template <typename T>
constexpr bool is_string_like() {
    using TT = typename std::remove_const<T>::type;	

    if (std::is_array<TT>::value) {
        return std::is_same<TT, char[sizeof(TT)]>::value;
    }

    return std::is_same<TT, char*>::value or std::is_same<TT, std::string&>::value or
                 std::is_same<TT, std::string>::value;

}

}

}

#endif
