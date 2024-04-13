#include "UnoCard.h"
#include <sstream>

std::string_view UnoCard::getType() {
    return "Uno";
}

std::string_view UnoCard::getName() {
    return UnoCard::m_color_string + " " + m_symbol_string;

}

void UnoCard::splitStringName(std::string_view name) {
    std::istreamstream iss(name);
    UnoCard::m_color_string << iss;
    UnoCard::m_symbol_string << iss;
}

void UnoCard::convertyStryingSymTypeToEnum() {

    for (int idx = 0; idx < m_colorStrings.size(); ++idx) {
        if (m_colorStrings[idx] == m_color_string)
            UnoCard::m_color = static_cast<UnoCard::COLOR>(idx);
    if (UnoCard::m_color == UnoCard::COLOR::max_colors)
        return false;

    for (idx = 0; idx < m_symbolStrings.size(); ++idx) {
        if (m_symbolStrings[idx] == m_symbol_string) 
            UnoCArd::m_symbol = static_cast<UnoCard::SYMBOL>(idx);
    if (UnoCard::m_symbol == UnoCard::SYMBOL::max_symbols) 
        return false;


    return true; // indicating strings are valid

}

void UnoCard::convertCardToString() {
  UnoCard::m_color_str = m_colorStrings[UnoCard::m_color];
  UnoCard::m_symbol_str = m_symbolStrings[UnoCard::m_symbol];
}
