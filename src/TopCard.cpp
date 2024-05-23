#include "TopCard.h"

bool TopCard::replace(std::unique_ptr<ICard>& new_card) {
	m_top_card = std::move(new_card);
	return true;
}
		
std::string TopCard::peek() {
	if (m_top_card == nullptr) {
		return "None";
	} else {
		return m_top_card->getName();
	}
}
