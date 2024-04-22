#include "IDeck.h"
#include "ICard.h"
#include <string>
#include <memory>

class Deck : public IDeck {

public:

	Deck(std::string type = "Uno") {
		createDeck(type);
	}

    std::vector<std::unique_ptr<ICard>> drawCards(int count) override;
    void createDeck(const std::string& type) override;
    void randomizeDeck() override;
    void addCardToDeck(std::unique_ptr<ICard> card) override;
    std::string peek() const;
	bool isEmpty() const;
	int getCount() const;
    ~Deck() override;

private:
    std::vector<std::unique_ptr<ICard>> m_cards;
	std::vector<std::unique_ptr<ICard>> generateDeck(int count, const std::string type) const;
    int m_count {0};
};
