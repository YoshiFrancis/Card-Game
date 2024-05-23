#include "TopCard.h"

bool TopCard::replace(std::unique_ptr<ICard>& new_card) {
	m_top_card = std::move(new_card);
	return true;
}
		
