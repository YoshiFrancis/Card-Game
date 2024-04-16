#include "ICard.h"
#include <string_view>
#include <string>
#include <vector>
#include <sstream>

class UnoCard : public ICard {

public:

  UnoCard(std::string name="RED ONE") {
    splitStringName(name);
    convertStringSymTypeToEnum();
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
  std::string m_color_str;
  std::string m_symbol_str;
  COLOR m_color;
  SYMBOL m_symbol;


  void splitStringName(const std::string& name);
  bool convertStringSymTypeToEnum();
  void convertCardToString();
};
