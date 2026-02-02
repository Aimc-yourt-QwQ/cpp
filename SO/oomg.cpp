#include <iostream>
#include <string>
class omg
{
  private:
    std::string UserName;
    int UserPassword;
    int Money = 100;
  public:
    void registers(std::string RegisterUserName, int RegistersUserPassword)
    {
      UserName = RegisterUserName;
      UserPassword = RegistersUserPassword;
      std::cout << "register complete" << std::endl;
    }
    void login(std::string LoginUserName, int LoginUserPassword)
    {
      if (LoginUserName == UserName && LoginUserPassword == UserPassword)
      {
        std::cout << "Login " << UserName << std::endl;
      }
      else
      {
        std::cout << "?" << std::endl;
      }
    }
    void GetMoney()
    {
      std::cout << "Money: " << Money << std::endl;
    }
    void Deposit(int M_)
    {
      if (M_ <= 0) M_ = 0;
      Money += M_;
      std::cout << "Deposit " << M_ << ", Money = " << Money << std::endl;
    }
    void Extract(int E_)
    {
      if (E_ <= 0) E_ = 0;
      Money -= E_;
      std::cout << "Extract " << E_ << ", Money = " << Money << std::endl;
    }
};
int main()
{
  omg U1;
  std::string N_;
  int P_;
  std::cout << "Name: ";
  std::cin >> N_;
  
  std::cout << "Password: ";
  std::cin >> P_;

  U1.registers(N_, P_);
  U1.GetMoney();
  U1.Deposit(217834);
  U1.Extract(4353);
  return 0;
}
