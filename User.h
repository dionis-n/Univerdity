#pragma once

class User
{
    protected:
        std::string name;
        std::string password;
        int warnings;
        int accessLevel;
    public:

        User();
        User(std::string name, std::string password, int warnings);
        void addWarning();
        void changePassword(const std::string& newPassword);
        bool isBlocked();
        virtual void printInfo();
};

class Moderator: public User
{
    public:
        Moderator();

        void warnUser(User& user);
        virtual void printInfo() override;
};

class Admin: public Moderator
{
    public:
        Admin();
        void setPassword(User& user,const std::string& newPassword);
        friend std::ostream& operator<<(std::ostream& os, const Admin& admin);
        void printInfo();
};

