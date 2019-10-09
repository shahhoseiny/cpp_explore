/*
 * Using Lambda for special sort to consider even numbers less than odd numbers
 * in generall
 */

#include <iostream>
#include <algorithm>
#include <array>

int main()
{
    std::array<int, 20> my_int_array{56, 32, 43, 23, 12, 93, 132, 154, 2, 3, 33, 44, 106, 32, 13, 7};

    auto printArrray = [](const auto &arr, const std::string msg)
    {
        std::cout << " --------------> " << msg << std::endl;
        for (const auto &elem : arr)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl
                  << std::endl
                  << std::flush;
    };

    printArrray(my_int_array, "Original Array before sort : ");

    std::sort(my_int_array.begin(), my_int_array.end());
    printArrray(my_int_array, "After normal sort :");

    std::sort(my_int_array.begin(), my_int_array.end(), [](const int i, const int j)
              {
        if (i % 2 == 0 && j % 2 != 0)
        {
            return true;
        }
        else
        {
            return i < j;
        } });
    printArrray(my_int_array, "After special sort :");

    std::cout << "====================> END" << std::endl;

    return 0;
}
