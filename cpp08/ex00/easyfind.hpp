#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

//yalnızca .begin() ve .end() metodlarını içeren containerlarda çalışır
template <typename T>//easyfind type'a göre bir iterator döndürüyor. 
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Element not found in container");
    return it;
}

#endif