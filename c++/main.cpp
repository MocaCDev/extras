#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> push(std::vector<int> s_l, std::vector<std::string> strings, std::string new_string)
{
    s_l.push_back(new_string.size());
    strings.push_back(new_string);
    return strings;
}

void for_eachS(std::vector<std::string> vector)
{
    for(int i = 0; i < vector.size(); i++)
    {
        std::cout << i << ". " <<vector[i] << std::endl;
    }
}

int main()
{
    std::vector<std::string> strings;
    std::vector<int> string_lengths;
    strings = push(string_lengths,strings,"Aidan");
    for_eachS(strings);
}
