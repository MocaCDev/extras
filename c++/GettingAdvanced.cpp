#include <iostream>
#include <vector>

static int total_users = 0;

class AllUsers
{
    public:
        std::string username;
};

typedef struct User
{
    std::string user_name;
    int user_id; // will be total_users + 1
    AllUsers next[0xAAAF]; // append each struct
} USER;

class UserInformation
{
    public:
        std::vector<std::string> public_usernames;
        USER user_;
        
        void add_user(std::string username)
        {
            public_usernames.push_back(username);
            user_.user_name = public_usernames[public_usernames.size()-1];
            user_.user_id = ++total_users;
            user_.next[total_users-1].username = user_.user_name;
        }
        void show_all()
        {
            for(int i = 0; i < user_.user_id; i++)
            {
                std::cout << user_.next[i].username << std::endl;
            }
        }
};

int main()
{
    UserInformation user;
    user.add_user("Aidan");
    user.show_all();
}
