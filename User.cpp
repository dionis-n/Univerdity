#include <iostream>
#include <string>
#include "User.h"

User::User(): name(""), password(""), warnings(0), accessLevel(0) {}
User::User(std::string name, std::string password, int warnings): name(name), password(password), warnings(warnings), accessLevel(0) {}

bool User::isBlocked()
{
    if (accessLevel == 0 && warnings > 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void User::printInfo()
{
    std::cout << "User: " << name << " Access Level: " << accessLevel << std::endl;
}

void User::addWarning() {
    warnings++;
}

void User::changePassword(const std::string& newPassword) {
    password = newPassword;
}

Moderator::Moderator()
{
    accessLevel = 1;
}

void Moderator::warnUser(User& user)
{
    user.addWarning();
}

void Moderator::printInfo()
{
    std::cout << "Moderator: " << name << " Access Level: " << accessLevel << std::endl;
}

Admin::Admin()
{
    accessLevel = 2;
}

void Admin::setPassword(User& user, const std::string& newPassword) {
    user.changePassword(newPassword);
}

void Admin::printInfo()
{
    std::cout << "Admin: " << name << "Access Level: " << accessLevel << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Admin& admin)
{
    os << "Admin: " << admin.name << " (Access Level: " << admin.accessLevel << ")";
    return os;
}


int main()
{
    User u1;


    return 0;
}
