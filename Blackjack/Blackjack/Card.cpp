#include "Card.h"
#include<Windows.h>




void Card::Flip()
{
    this->card_pos = !(this->card_pos);
}

int Card::GetValue() 
{
    if ((card_value > 10) && (card_value < 14)) return 10;
    else if (card_value == ace) return 11;
    else return card_value;
}

Card::Card(Suit a, Value b, open_closed c): card_value(b) , card_pos(c)
{
    switch (a)
    {
    case diamonds: card_suit = u8"diamonds";
        break;
    case hearts: card_suit = u8"hearts";
        break;
    case  clubs: card_suit = u8"clubs";
        break;
    case spades: card_suit = u8"spades";
        break;
    default:
        break;
    }
}

Card::Card(int a, int b, bool c) : card_pos(c)
{
    switch (a)
    {
    case diamonds: card_suit = u8"diamonds";
        break;
    case hearts: card_suit = u8"hearts";
        break;
    case  clubs: card_suit = u8"clubs";
        break;
    case spades: card_suit = u8"spades";
        break;

    default: card_suit = u8"eror";
        break;
    }
    if ((b > 1) && (b < 15)) card_value = b;
}

Card::Card(std::string a, int b , bool c) : card_pos(c)
{

    if (a == u8"diamonds") card_suit = a;
    else if (a == u8"hearts")card_suit = a;
    else if (a == u8"clubs")card_suit = a;
    else if (a == u8"spades")card_suit = a;

    if ((b > 1) && (b < 15)) card_value = b;
}

std::ostream& operator<<(std::ostream& a, Card card)
{
    using namespace std;

    if (card.card_pos == open) 
    {
        string value;
        if (card.GetValue() < 11) value = to_string(card.GetValue());
        switch (card.GetValue())
        {
        case jack: value = u8"jack";
            break;
        case queen: value = u8"queen";
            break;
        case king: value = u8"king";
            break;
        case ace: value = u8"ace";
            break;
        default: value = to_string(card.GetValue());
            break;
        }


        cout << value << u8" ";

        cout.flush();
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

        if (card.card_suit == u8"diamonds") 
        {
            SetConsoleTextAttribute(handle, RED);
            cout << u8"♦";
        }
        else if(card.card_suit == u8"hearts")
        {
            SetConsoleTextAttribute(handle, DARKMAGENTA);
            cout << u8"♥";
        }
        else if (card.card_suit == u8"clubs")
        {
            SetConsoleTextAttribute(handle, GREEN);
            cout << u8"♣";
        }
        else if (card.card_suit == u8"spades")
        {
            SetConsoleTextAttribute(handle, YELLOW);
            cout << u8"♠";
        }  
       cout.flush();
       SetConsoleTextAttribute(handle, WHITE);
    }
    else cout << u8"XX";
    return a;

}

