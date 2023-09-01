
#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>

#include "traits.h"


/**
 * @brief Dot char.
 */
constexpr static char k_dot_char = '.';

/**
 * @brief Bit mask.
 *
 * Helps to get smallest byte from the binary number.
 */
constexpr static auto k_bit_mask = 0xFF;

/**
 * @brief Print IpV4 from parameter of integral representation.
 *
 * @param ip universal reference to IpV4 integral representation.
 *
 * @param out output stream.
 */
template <typename Integer, enable_if_integral_t<Integer> = true>
void print_ip(Integer &&ip, std::ostream &out = std::cout)
{
    size_t byte = 8; // (i << 3) TODO: check
    const size_t size = sizeof(ip);
    for (int i = size; i--;)
    {
        auto k = (i * byte);
        out << (ip >> k & k_bit_mask);
        if (i > 0) { out << k_dot_char; }
    }

    out << std::endl;
}

/**
 * @brief Print IpV4 from parameter of string representation.
 *
 * @param ip universal reference to IpV4 string representation.
 *
 * @param out output stream.
 */
template <typename String, enable_if_string_t<String> = true>
void print_ip(String &&ip, std::ostream &out = std::cout)
{
    out << ip << std::endl;
}

/**
 * @brief Print IpV4 from parameter of iterable type.
 *
 * @param ip universal reference to iterable type, that contains IpV4.
 *
 * @param out output stream.
 */
template <typename Iterable, enable_if_container_t<Iterable> = true>
void print_ip(Iterable &&ip, std::ostream &out = std::cout)
{
    auto begin = ip.begin();
    std::for_each(begin, ip.end(), [&begin, &out](auto &item)
    {
        if (item != *begin) { out << k_dot_char; }
        out << item;
    });

    out << std::endl;
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename Tuple, typename T, T ...I>
void print_sequence(const Tuple &tuple, std::index_sequence<I...> &&sequence, std::ostream &out)
{
    std::string dot_str;
    dot_str = k_dot_char;

    auto seq_size = sequence.size();
    auto last = seq_size ? seq_size - 1 : seq_size;

    ((out << std::get<I>(tuple) << (I != last ? dot_str : "")), ...);
    out << std::endl;
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/**
 * @brief Print IpV4 from intergral parameter of tuple type.
 *
 * @param ip universal reference to tuple type, that contains IpV4.
 *
 * @param out output stream.
 */
template <typename ...Args, enable_if_tuple_with_same_types_t<Args...> = true>
void print_ip(std::tuple<Args...> &&ip, std::ostream &out = std::cout)
{
    print_sequence(ip, std::make_index_sequence<std::tuple_size_v<std::tuple<Args...>>>(), out);
}

