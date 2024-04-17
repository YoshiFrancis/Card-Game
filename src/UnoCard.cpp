#include "UnoCard.h"
#include "../helper.h"
#include <sstream>
#include <string>
#include <iostream>

std::string_view UnoCard::getType() const {
    return "Uno";
}

std::string UnoCard::getName() const {
    return std::string(UnoCard::m_color_str) + " " + std::string(UnoCard::m_symbol_str);
}

void UnoCard::splitStringName(const std::string& name) {
    std::istringstream iss(Helper::toLower(name), std::ios_base::in);
    std::string color {};
    std::string symbol {};
    iss >> color;
    iss >> symbol;
    UnoCard::m_color_str = color;
    UnoCard::m_symbol_str = symbol;
}

bool UnoCard::convertStringSymTypeToEnum() {
    int idx = 0;
    for (idx = 0; idx < m_colorStrings.size(); ++idx) {
        if (m_colorStrings[idx] == m_color_str)
            UnoCard::m_color = static_cast<UnoCard::COLOR>(idx);
    }
    if (UnoCard::m_color == UnoCard::COLOR::max_colors)
        return false;

    for (idx = 0; idx < m_symbolStrings.size(); ++idx) {
        if (m_symbolStrings[idx] == m_symbol_str) 
            UnoCard::m_symbol = static_cast<UnoCard::SYMBOL>(idx);
    if (UnoCard::m_symbol == UnoCard::SYMBOL::max_symbols) 
        return false;
    }


    return true; // indicating strings are valid

}

void UnoCard::convertCardToString() {
  UnoCard::m_color_str = m_colorStrings[UnoCard::m_color];
  UnoCard::m_symbol_str = m_symbolStrings[UnoCard::m_symbol];
}
