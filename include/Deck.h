#include "IDeck.h"
#include "ICard.h"

class Deck : public IDeck {

public:

    ICard drawCards(int count) override;
    void createDeck() override;
    void randomizeDeck() override;
    void addCardToDeck(ICard&& card) override;
    const ICard* peek() const
	bool isEmpty() const;
	int getCount() const;
    ~IDeck() {};

private:
    std::vector<const ICard*> m_cards;
	std::vector<const ICard*> generateDeck(int count) const;
    int m_count {0};
};
