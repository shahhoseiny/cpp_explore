
#include <iostream>
#include <tuple>
#include <chrono>

using namespace std::chrono;
using fibo_pair = std::pair<size_t, size_t>;

namespace sasha
{
const uint8_t MAX_FIBONATCHI_INPUT = 90;
const uint8_t MAX_FIBONATCHI_INPUT_NAIVE = 50;

class Fibonatchi
{
public:
    fibo_pair operator()(const uint8_t i) const
    {
        if (i > MAX_FIBONATCHI_INPUT)
        {
            throw std::out_of_range("This will cause overflow");
        }

        if (i == 1)
        {
            return std::make_pair(0, 1);
        }
        else
        {
            auto last_fibo = (*this)(i - 1);
            return std::make_pair(last_fibo.second, last_fibo.first + last_fibo.second);
        }
    }
} fibonatchi;

size_t fibo_naive(const uint8_t i)
{
    if (i > MAX_FIBONATCHI_INPUT_NAIVE)
    {
        throw std::out_of_range("This will take forever");
    }

    if (i == 1 || i == 0)
        return i;
    else
        return fibo_naive(i - 1) + fibo_naive(i - 2);
}
} // namespace sasha

int main()
{
    const uint8_t FIBONATCHI_INPUT1 = 41;
    std::cout << std::endl << "======>  fibo_naive result for " << static_cast<int>(FIBONATCHI_INPUT1) << " is : ";

    try
    {
        auto start_time = high_resolution_clock::now();
        auto result_naive = sasha::fibo_naive(FIBONATCHI_INPUT1);
        auto end_time = high_resolution_clock::now();
        std::cout << result_naive << "   calculation took : " << duration_cast<milliseconds>(end_time - start_time).count() << " ms" << std::endl;
    }
    catch (std::out_of_range const& ex)
    {
        std::cout << " Exception: " << ex.what() << std::endl;
    }

    const uint8_t FIBONATCHI_INPUT2 = 90;
    std::cout << std::endl << "======>  fibo_tuple result for " << static_cast<int>(FIBONATCHI_INPUT2) << " is : ";

    try
    {
        auto start_time = high_resolution_clock::now();
        auto result = sasha::fibonatchi(FIBONATCHI_INPUT2);
        auto end_time = high_resolution_clock::now();
        std::cout << result.second << "   calculation took : " << duration_cast<microseconds>(end_time - start_time).count() << " us" << std::endl;
    }
    catch (std::out_of_range const& ex)
    {
        std::cout << " Exception: " << ex.what() << std::endl;
    }

    return 0;
}

