#include "ICard.h"
#include <string_view>
#include <vector>
#include <sstream>

class UnoCard : public ICard {

public:
    
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
        NINE
        max_symbols
    }

    UnoCard(std::string_view name) {


    }


    std::string_view getType() override;
    std::string_view getName() override;
    
private:
    std::vector<std::string_view> m_colorStrings = { "red", "blue", "green", "yellow", "all" };
    std::vector<std::string_view> m_symbolStrings = { "skip", "reverse", "plus2", "plus4", "change", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    std::string_view m_color_str;
    std::string_view m_symbol_str;
    COLOR m_color;
    SYMBOl m_symbol;


    void splitStringName(std::string_view);
    void convertStringSymTypeToEnum();
    std::string_view convertCardToString();
};
