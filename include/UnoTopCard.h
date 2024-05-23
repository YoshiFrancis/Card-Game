#include "TopCard.h"
#include "UnoCard.h"
#include <string>

class UnoTopCard : public TopCard
{

public:
	UnoTopCard& operator=(UnoTopCard&& other) noexcept
	{
		m_top_card = std::move(other.m_top_card);
		m_color = other.m_color;
		return *this;
	}

	bool replace(std::unique_ptr<ICard>& new_card) override;

private:
	bool isValid(std::unique_ptr<ICard>& new_card) override;
	std::string m_color;
	std::string m_symbol;
};	
