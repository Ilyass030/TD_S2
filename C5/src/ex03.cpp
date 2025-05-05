#include <iostream>
#include <vector>
#include <unordered_map>


enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    // bool operator==(Card const& a ,Card const& b) const {
    //     if(a.value == b.value && (((a.kind == kind.CardKiind.Heart || a.kind == CardKind.Diamond) && (b.kind == CardKind.Heart || b.kind == CardKind.Diamond)) || ((a.kind == CardKind.Club || a.kind == CardKind.Spare) && (b.kind == CardKind.Club || b.kind == CardKind.Spare)) )) {
    //         return true;
    //     }
    //     return false;
    // }


    bool operator==(Card const& other) const {
        if (value == other.value && 
            (((kind == CardKind::Heart || kind == CardKind::Diamond) && 
              (other.kind == CardKind::Heart || other.kind == CardKind::Diamond)) || 
             ((kind == CardKind::Club || kind == CardKind::Spade) && 
              (other.kind == CardKind::Club || other.kind == CardKind::Spade)))) {
            return true;
        }
        return false;
    }

    int hash(Card const& card) {
    return static_cast<int>(card.kind) * 13 + static_cast<int>(card.value);
}
};

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

int main(){
    std::vector<Card> cards {get_cards(100)};
    std::unordered_map<Card, int> result {};

    std::string card_name(Card const& card) {
        std::string name {};
    
        unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};
    
        if (card_value < 10) {
            name += '0' + std::to_string(card_value);
        }else if (card_value == 10) {
            name += "10";
        }else if (card_value == 11) {
            name += 'J';
        }else if (card_value == 12) {
            name += 'Q';
        }else if (card_value == 13) {
            name += 'K';
        }
    
        name += " of ";
    
        if (card.kind == CardKind::Heart) {
            name += "Heart";
        }else if (card.kind == CardKind::Diamond) {
            name += "Diamond";
        }else if (card.kind == CardKind::Club) {
            name += "Club";
        }else if (card.kind == CardKind::Spade) {
            name += "Spade";
        }
        return name;
    }
}