#include <iostream>

class User
{
    protected:
        std::string name;
};

static int id = 0;

typedef struct UserInfo
{
    std::string users[0xAAAF];
    int id;
} UserInfo;

class SetupUser : public User
{
    public:
        UserInfo user_info;
        void set(std::string username)
        {
            name = username;
            user_info.id = ++id;
            user_info.users[user_info.id-1] = name;
        };
        std::string return_user()
        {
            return name;
        }
        int find_user(std::string username)
        {
            for(std::string i : user_info.users)
            {
                if(i == username) return 0;
            }
            return 1;
        }
};

namespace USER
{
    SetupUser user;
    void setup_user(std::string username)
    {
        user.set(username);
    }
    std::string current_user()
    {
        return user.return_user();
    }
    int findUser(std::string username)
    {
        return user.find_user(username);
    }
};


int main()
{
    
    USER::setup_user("Aidan");
    std::cout << USER::current_user() << std::endl;
    
    if(USER::findUser("Aidan")==0)
    {
        std::cout << "Aidan has been added!" << std::endl;
    }
    
}
