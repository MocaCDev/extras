#include <iostream>

#define age 16
#define Name "Aidan"

class boo
{ 
    private:
        std::string password;
    public:
        int a;
        std::string name;
        
        int is_true(std::string name);
        void set_pass(std::string new_pass)
        {
            password = new_pass;
        }
        std::string print_pass()
        {
            return password;
        }
};

int boo::is_true(std::string name)
{
    if(name == "Aidan")
    {
        return 1; // true
    }
    return 0; // false
}

int main()
{
    boo a;
    a.a = age;
    a.name = Name;
    std::cout << a.a << "\n" << a.name << std::endl;
    if(a.is_true(a.name) == 1)
    {
        std::cout << "Hello, Aidan! You are admin!";
        a.set_pass("adminadmin24");
        std::cout << "Password now set.\n" << a.print_pass() << std::endl;
    }
    
}
