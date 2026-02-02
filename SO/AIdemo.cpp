#include <iostream>
#include <random>
#include <limits>
#include <string>
#include <ctime>

class GuessNumberGame {
private:
    int secretNumber;      // 要猜的数字
    int attempts;          // 尝试次数
    int maxAttempts;       // 最大尝试次数
    int minRange;          // 最小范围
    int maxRange;          // 最大范围
    bool gameOver;         // 游戏是否结束
    std::mt19937 rng;      // 随机数生成器
    
public:
    // 构造函数
    GuessNumberGame(int min = 1, int max = 100) 
        : minRange(min), maxRange(max), attempts(0), gameOver(false) {
        // 使用当前时间作为随机种子
        rng.seed(static_cast<unsigned int>(time(nullptr)));
        selectDifficulty(); // 选择难度
        generateSecretNumber(); // 生成随机数
    }
    
    // 选择难度
    void selectDifficulty() {
        std::cout << "===== 猜数字游戏 =====\n";
        std::cout << "请选择难度:\n";
        std::cout << "1. 简单 (1-50, 10次机会)\n";
        std::cout << "2. 中等 (1-100, 7次机会)\n";
        std::cout << "3. 困难 (1-200, 5次机会)\n";
        std::cout << "4. 自定义\n";
        std::cout << "请输入选项 (1-4): ";
        
        int choice;
        while (!(std::cin >> choice) || choice < 1 || choice > 4) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "无效输入，请输入1-4: ";
        }
        
        switch (choice) {
            case 1: // 简单
                minRange = 1;
                maxRange = 50;
                maxAttempts = 10;
                break;
            case 2: // 中等
                minRange = 1;
                maxRange = 100;
                maxAttempts = 7;
                break;
            case 3: // 困难
                minRange = 1;
                maxRange = 200;
                maxAttempts = 5;
                break;
            case 4: // 自定义
                std::cout << "请输入最小数字: ";
                while (!(std::cin >> minRange) || minRange < 0) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "无效输入，请输入正整数: ";
                }
                
                std::cout << "请输入最大数字: ";
                while (!(std::cin >> maxRange) || maxRange <= minRange) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "无效输入，请输入大于 " << minRange << " 的数字: ";
                }
                
                std::cout << "请输入最大尝试次数: ";
                while (!(std::cin >> maxAttempts) || maxAttempts <= 0) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "无效输入，请输入正整数: ";
                }
                break;
        }
    }
    
    // 生成秘密数字
    void generateSecretNumber() {
        std::uniform_int_distribution<int> dist(minRange, maxRange);
        secretNumber = dist(rng);
        std::cout << "\n数字已生成！范围: " << minRange << " - " << maxRange 
                  << "，你有 " << maxAttempts << " 次机会。\n";
        std::cout << "----------------------------------------\n";
    }
    
    // 检查猜测
    bool checkGuess(int guess) {
        attempts++;
        
        if (guess == secretNumber) {
            gameOver = true;
            std::cout << "\n🎉 恭喜你！猜对了！\n";
            std::cout << "你在第 " << attempts << " 次猜中了数字 " << secretNumber << "。\n";
            return true;
        }
        
        if (attempts >= maxAttempts) {
            gameOver = true;
            std::cout << "\n😔 游戏结束！你没有猜中。\n";
            std::cout << "正确答案是: " << secretNumber << "\n";
            return false;
        }
        
        if (guess < secretNumber) {
            std::cout << "太小了！";
        } else {
            std::cout << "太大了！";
        }
        
        std::cout << " 还剩 " << (maxAttempts - attempts) << " 次机会。\n";
        
        // 给出提示
        if (attempts >= maxAttempts / 2) {
            giveHint(guess);
        }
        
        return false;
    }
    
    // 给出提示
    void giveHint(int guess) {
        int difference = abs(secretNumber - guess);
        int rangeSize = maxRange - minRange + 1;
        
        if (difference <= rangeSize * 0.1) { // 差10%以内
            std::cout << "提示：非常接近了！";
        } else if (difference <= rangeSize * 0.25) { // 差25%以内
            std::cout << "提示：比较接近了！";
        } else if (difference <= rangeSize * 0.5) { // 差50%以内
            std::cout << "提示：还有一定距离。";
        }
        
        // 奇偶提示
        if (attempts >= maxAttempts - 1) {
            if (secretNumber % 2 == 0) {
                std::cout << "（提示：数字是偶数）";
            } else {
                std::cout << "（提示：数字是奇数）";
            }
        }
        std::cout << "\n";
    }
    
    // 获取玩家输入
    int getPlayerGuess() {
        int guess;
        std::cout << "第 " << (attempts + 1) << " 次猜测: ";
        
        while (!(std::cin >> guess) || guess < minRange || guess > maxRange) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "请输入 " << minRange << " 到 " << maxRange << " 之间的整数: ";
        }
        
        return guess;
    }
    
    // 显示游戏状态
    void displayGameStatus() const {
        std::cout << "\n=== 游戏状态 ===\n";
        std::cout << "范围: " << minRange << " - " << maxRange << "\n";
        std::cout << "已尝试: " << attempts << " 次\n";
        std::cout << "剩余次数: " << (maxAttempts - attempts) << "\n";
        std::cout << "================\n\n";
    }
    
    // 显示游戏规则
    static void displayRules() {
        std::cout << "\n游戏规则:\n";
        std::cout << "1. 计算机会生成一个指定范围内的随机数\n";
        std::cout << "2. 你需要猜出这个数字是多少\n";
        std::cout << "3. 每次猜测后，计算机会告诉你猜的数字是太大还是太小\n";
        std::cout << "4. 在有限的尝试次数内猜中数字即为胜利\n";
        std::cout << "5. 游戏过程中会提供适当的提示\n";
        std::cout << "----------------------------------------\n";
    }
    
    // 主游戏循环
    void play() {
        displayRules();
        
        while (!gameOver) {
            int guess = getPlayerGuess();
            checkGuess(guess);
            
            if (!gameOver) {
                displayGameStatus();
            }
        }
        
        // 询问是否再来一局
        askForReplay();
    }
    
    // 重置游戏
    void reset() {
        attempts = 0;
        gameOver = false;
        generateSecretNumber();
    }
    
    // 询问是否重玩
    void askForReplay() {
        char choice;
        std::cout << "\n想再来一局吗？(y/n): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (choice == 'y' || choice == 'Y') {
            std::cout << "\n";
            std::cout << "========================================\n";
            std::cout << "             新的一局开始！             \n";
            std::cout << "========================================\n";
            
            // 让玩家选择是否改变难度
            std::cout << "是否改变难度？(y/n): ";
            char changeDiff;
            std::cin >> changeDiff;
            
            if (changeDiff == 'y' || changeDiff == 'Y') {
                selectDifficulty();
            }
            
            reset();
            play();
        } else {
            std::cout << "\n谢谢游玩！再见！\n";
        }
    }
    
    // 获取游戏统计信息
    void getStats() const {
        std::cout << "\n=== 本局统计 ===\n";
        std::cout << "数字范围: " << minRange << " - " << maxRange << "\n";
        std::cout << "目标数字: " << secretNumber << "\n";
        std::cout << "尝试次数: " << attempts << " / " << maxAttempts << "\n";
        
        if (attempts > 0) {
            double efficiency = (maxAttempts - attempts + 1.0) / maxAttempts * 100.0;
            std::cout << "游戏效率: " << efficiency << "%\n";
            
            // 评价
            if (attempts <= maxAttempts * 0.3) {
                std::cout << "评价: 🎯 神级玩家！\n";
            } else if (attempts <= maxAttempts * 0.6) {
                std::cout << "评价: 👍 表现不错！\n";
            } else if (attempts < maxAttempts) {
                std::cout << "评价: 😅 勉强过关\n";
            } else {
                std::cout << "评价: 💪 继续努力！\n";
            }
        }
    }
    
    // 析构函数
    ~GuessNumberGame() {
        getStats();
    }
};

// 辅助函数：显示欢迎信息
void displayWelcome() {
    std::cout << R"(
    ╔═══════════════════════════════════╗
    ║     欢迎来到猜数字游戏！          ║
    ║    Guess the Number Game          ║
    ╚═══════════════════════════════════╝
    )" << std::endl;
}

// 主函数
int main() {
    displayWelcome();
    
    try {
        GuessNumberGame game;
        game.play();
    } catch (const std::exception& e) {
        std::cerr << "游戏出错: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
