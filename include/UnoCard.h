#include "ICard.h"
#include <string_view>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

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
		DRAW,
    max_symbols
  };

  std::string_view getType() const override;
  std::string getName() const override;
  
  inline std::vector<std::string>& getAllColors() { return m_colorStrings; }
  inline std::vector<std::string>& getAllSymbols() { return m_symbolStrings; }

private:
  std::vector<std::string> m_colorStrings = { "red", "blue", "green", "yellow", "all" };
  std::vector<std::string> m_symbolStrings = { "plus4", "change", "skip", "reverse", "plus2", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "draw" };
  std::string m_color_str;
  std::string m_symbol_str;
  COLOR m_color;
  SYMBOL m_symbol;


  void splitStringName(const std::string& name);
  bool convertStringSymTypeToEnum();
  void convertCardToString();
};
