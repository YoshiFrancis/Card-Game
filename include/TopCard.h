#include "ICard.h"
#include "UnoCard.h"

class TopCard {

public:

	TopCard() = default;

	~TopCard() = default;

	TopCard& operator=(const TopCard& other) = delete;

	TopCard(TopCard&& other) noexcept {
		m_top_card = std::move(other.m_top_card);
	}

	TopCard& operator=(TopCard&& other) noexcept 
	{
		if (this == &other) 
		{
			m_top_card = std::move(other.m_top_card);
		}
		return *this;
	}

	virtual bool replace(std::unique_ptr<ICard>& new_card);
	std::string peek();
	void reset();
protected:
	std::unique_ptr<ICard> m_top_card = nullptr;
	virtual bool isValid(std::unique_ptr<ICard>& new_card) = 0;
	

};
