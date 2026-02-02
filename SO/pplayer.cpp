#include <iostream>
#include <string>
#include <vector>
class item
{
  private:
    std::string NAME;
    int ID;
  public:
    item(std::string name, int id)
    {
      NAME = name;
      ID = id;
    }
};
int main()
{
  item("x", 1);
  return 0;
}
