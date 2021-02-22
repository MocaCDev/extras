#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> push(std::vector<std::string> strings, std::string new_string)
{
    strings.push_back(new_string);
    std::cout << "Vector size is now: " << strings.size() << std::endl;
    return strings;
}

std::vector<std::string> push_multiple(std::vector<std::string> to_push, std::vector<std::string> vector)
{
    for(int i = 0; i < to_push.size(); i++)
    {
        vector.push_back(to_push[i]);
    }
    return vector;
}

std::vector<int> push_length_for_all(std::vector<std::string> all, std::vector<int> lengths)
{
    for(int i = 0; i < all.size(); i++)
    {
        lengths.push_back(all[i].size());
    }
    return lengths;
}

std::vector<int> push_lenght(std::vector<std::string> strings, std::vector<int> lengths)
{
    std::cout << "Pushing length for newest element: " << strings[strings.size()-1] << std::endl;
    lengths.push_back(strings[strings.size()-1].size());
    return lengths;
}

void for_eachS(std::vector<std::string> vector)
{
    for(int i = 0; i < vector.size(); i++)
    {
        std::cout << i+1 << ". " <<vector[i] << std::endl;
    }
}

void for_eachI(std::vector<int> vector, std::vector<std::string> corel)
{
    for(int i = 0; i < vector.size(); i++)
    {
        std::cout << i+1 << ". " << corel[i] << " -> LEN = " << vector[i] << std::endl;
    }
}

int main()
{
    std::vector<std::string> names = {"bob","jeff","ted"};
    std::vector<std::string> strings;
    std::vector<int> string_lengths;
    strings = push_multiple(names,strings);
    string_lengths = push_length_for_all(strings,string_lengths);
    for_eachS(strings);
    for_eachI(string_lengths, strings);
}
