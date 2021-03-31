#include <iostream>

#define age 16
#define Name "Aidan"

class Secret
{
    private:
        std::string password_to_save;
    public:
        
        std::string set(std::string pass)
        {
            password_to_save = pass;
            return password_to_save;
        }
        std::string show_password()
        {
           return password_to_save; 
        }
};

class boo
{ 
    private:
        Secret s;
    public:
        int a;
        std::string name;
        
        int is_true(std::string name);
        std::string get_pass()
        {
            return s.show_password();
        }
        void void_it_out(std::string pass)
        {
            s.set(pass);
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
        std::cout << "Hello, Aidan! You are admin!\n";
        a.void_it_out("adminadmin24");
        std::cout << "Password now set.\n" << a.get_pass() << std::endl;
    }
    
}
