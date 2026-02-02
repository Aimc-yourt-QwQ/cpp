//致歉
#include <iostream>
class nightCord {
  private:
    const char* knd = "宵崎奏";
    const char* mfy = "朝比奈真冬";
    const char* ena = "东云绘名";
    const char* mzk = "晓山瑞希";
  public:
    nightCord() {
      std::cout << knd << "、" << mfy 
                << "、" << ena << "、" << mzk << "。25時nightCord見" << std::endl;
    }
};
int main() {
  nightCord();
  return 0;
}
