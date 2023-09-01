/*********************************************************************
 * @file  traits.h
 *
 * @brief Implementation for specific type traits.
 *********************************************************************/

#pragma once

#include <list>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

/**
 * @brief Check type is an integral type.
*/
template <typename T>
using enable_if_integral_t = std::enable_if_t<std::is_integral_v<T>, bool>;

/**
 * @brief Check type is a string.
*/
template <typename T, typename = void>
struct is_string : std::false_type {};

/**
 * @brief Check type is a string.
*/
template <typename T>
struct is_string<T, std::void_t<
        typename std::enable_if<std::is_same_v<T, std::string>>::type,
        decltype(std::declval<T>().c_str())>> : std::true_type {};

template <typename T>
inline constexpr bool is_string_v = is_string<T>::value;

template <typename T>
using is_string_t = typename is_string<T>::type;

template <typename T>
using enable_if_string_t = std::enable_if_t<is_string_v<T>, bool>;

/**
 * @brief Check type is not a string.
*/
template <typename T>
inline constexpr bool is_not_string = !is_string_v<T>;

/**
 * @brief Check type is an iterable container.
*/
template <typename T, typename = void>
struct is_container : std::false_type {};

/**
 * @brief Check type is an iterable container.
*/
template <typename T>
struct is_container<T, std::void_t<
        typename std::enable_if<is_not_string<T>>::type,
        decltype(std::declval<T>().begin()),
        decltype(std::declval<T>().end()),
        typename T::value_type>> : std::true_type {};

template <typename T>
inline constexpr bool is_container_v = is_container<T>::value;

template <typename T>
using is_container_t = typename is_container<T>::type;

template <typename T>
using enable_if_container_t = std::enable_if_t<is_container_v<T>, bool>;


/**
 * @brief Check whether tuple has same types.
*/
template <typename ...Args>
struct is_same_tuple_types : std::true_type {};

/**
 * @brief Check whether tuple has same types.
*/
template <typename T>
struct is_same_tuple_types<T> : std::true_type {};

/**
 * @brief Check whether tuple has same types.
*/
template <typename T, typename U, typename ...Args>
struct is_same_tuple_types<T, U, Args...>
{
    static constexpr bool value = std::is_same_v<T, U> && is_same_tuple_types<U, Args...>::value;
};

template <typename ...Args>
inline constexpr bool is_same_tuple_types_v = is_same_tuple_types<Args...>::value;

template <typename ...Args>
using enable_if_tuple_with_same_types_t = std::enable_if_t<is_same_tuple_types_v<Args...>, bool>;
/* ======= */
