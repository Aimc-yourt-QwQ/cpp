#include <iostream>
#include <string>
class omg
{
  private:
    std::string user = "hello";
    int password = 114514;
  public:
    void login(std::string userName,int userPassword)
    {
      if (userName == user)
      {
        if (userPassword == password)
        {
          std::cout << "huan ying! " << user << std::endl;
        }
        else
        {
          std::cout << "?" << std::endl;
        }
      }
    }
};
int main()
{
  omg MyOmg;
  MyOmg.login("hello", 114514);
  return 0;
}
