#include "ICard.h"
#include <string_view>
#include <string>
#include <vector>
#include <sstream>

class UnoCard : public ICard {

public:

    UnoCard(std::string_view name="RED ONE") {
        m_color_str = "red";
        m_symbol_str = "one";
    }

    ~UnoCard() = default;
    
    enum COLOR {
        RED,
        BLUE,
        GREEN,
        YELLOW,
        max_colors
    };

    enum SYMBOL {
        SKIP,
        REVERSE,
        PLUS2,
        PLUS4,
        CHANGE,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        max_symbols
    };

    std::string_view getType() const override;
    std::string getName() const override;
    
private:
    std::vector<std::string_view> m_colorStrings = { "red", "blue", "green", "yellow", "all" };
    std::vector<std::string_view> m_symbolStrings = { "skip", "reverse", "plus2", "plus4", "change", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    std::string_view m_color_str;
    std::string_view m_symbol_str;
    COLOR m_color;
    SYMBOL m_symbol;


    void splitStringName(std::string_view);
    bool convertStringSymTypeToEnum();
    void convertCardToString();
};
