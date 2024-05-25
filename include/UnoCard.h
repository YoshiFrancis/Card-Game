#ifndef UNOCARD_H
#define UNOCARD_H
#include "ICard.h"
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>

static const std::vector<std::string> m_colorStrings = { "red", "blue", "green", "yellow", "all" };
static const std::vector<std::string> m_symbolStrings = { "plus4", "change", "skip", "reverse", "plus2", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

class UnoCard : public ICard {

public:

  UnoCard(std::string name="RED ONE") {
    splitStringName(name); convertStringSymTypeToEnum();
  }

  ~UnoCard() = default;

	UnoCard& operator=(UnoCard& other) = delete;

	UnoCard& operator=(UnoCard&& other) {
		if (this == &other) {
			return *this;
		}
	
		m_color_str = other.m_color_str;
		m_symbol_str = other.m_symbol_str;
		m_color = other.m_color;
		m_symbol = other.m_symbol;

		return *this;
	}

	UnoCard(UnoCard&& other) {
		m_color_str = other.m_color_str;
		m_symbol_str = other.m_symbol_str;
		m_color = other.m_color;
		m_symbol = other.m_symbol;
	}
	



  enum COLOR {
    RED,
    BLUE,
    GREEN,
    YELLOW,
		ALL,
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

  std::string getType() const override;
  std::string getName() const override;
  
  static inline const std::vector<std::string>& getAllColors() { return m_colorStrings; }
  static inline const std::vector<std::string>& getAllSymbols() { return m_symbolStrings; }

private:
  std::string m_color_str;
  std::string m_symbol_str;
	COLOR m_color;
	SYMBOL m_symbol;


  void splitStringName(const std::string& name);
  bool convertStringSymTypeToEnum();
  void convertCardToString();
};

#endif
