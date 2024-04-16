#include "IDeck.h"
#include "ICard.h"

class Deck : public IDeck {

public:

	Deck(std::string type = "Uno") 
	{
		createDeck(type);
	}

    std::vector<const ICard*> drawCards(int count) override;
    void createDeck(const std::string& type) override;
    void randomizeDeck() override;
    void addCardToDeck(const ICard* card) override;
    const ICard* peek() const;
	bool isEmpty() const;
	int getCount() const;
    ~Deck() override {};

private:
    std::vector<const ICard*> m_cards;
	std::vector<const ICard*> generateDeck(int count, const std::string type) const;
    int m_count {0};
};
