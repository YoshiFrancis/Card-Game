#include "UnoTopCard.h"
#include "../helper.h"
#include <string>
#include <tuple>

static std::tuple<std::string, std::string> _splitStringName(const std::string& name);

bool UnoTopCard::isValid(std::unique_ptr<ICard>& new_card) {
	std::string color, symbol;
	std::tie(color, symbol) = _splitStringName(new_card->getName());
  if (m_top_card == nullptr 
		|| m_color == color
		|| m_symbol == symbol 
		|| color == "all"
	) {
    return true;
  } else {
    return false;
  }
}

bool UnoTopCard::replace(std::unique_ptr<ICard>& new_card) {
  if (isValid(new_card)) {
		std::tie(m_color, m_symbol) = _splitStringName(new_card->getName());
		if (m_color == "all")
			m_color = "blue";
    m_top_card = std::move(new_card);
    return true;
  } else {
    return false;
  }
}

void UnoTopCard::setColor(const std::string& color) {
	m_color = color;
}

const std::string& UnoTopCard::getSymbol() {
	return m_symbol;
}

const std::string& UnoTopCard::getColor() {
	return m_symbol;
}

static std::tuple<std::string, std::string> _splitStringName(const std::string& name) {
	std::istringstream iss(Helper::toLower(name), std::ios_base::in);
	std::string color {};
	std::string symbol {};
	iss >> color;
	iss >> symbol;
	return std::make_tuple(color, symbol);
}


