#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

/********** Put the Card class definition between these lines **********/
class Card{
    public:
        Card();
        Card(int faceValue, const char suitName[]);
        void setCard(int newFace, const char newSuit[]);
        int getFace();
        char * getSuit();
        void displayCard();
        
    private:
        char suit[9];
        int cardFaceValue;
};

/***************************************************************************/


//Definition for a class that represents a deck of cards

class DeckOfCards
{
public:
    DeckOfCards();
    Card draw();
    void shuffle();
    bool isEmpty();

private:
    static const int MAX_CARDS = 52; //Maximum number of cards in a deck
    static const int NUM_SUITS = 4; //Number of card suits
    static const int CARDS_PER_SUIT = 13; //Number of cards of each suit
    Card deck[MAX_CARDS]; //The deck of cards
    int topCard; //The subscript of the card on the top of the deck
};


/***************************************************************************/

//int main()
//{
    //seed the random number generator
    //Note: this must be done before creating any Card class objects
//    srand(11);
//    Card myCard;  //creating an object of Student  
//    myCard.
//    
//    return 0;
//}


/********** Code the Card class methods between these lines **********/
//Constructor
Card::Card(){
    int maxVal = 13;
    int minVal = 1;
    int faceValueRandomNumber = rand()%(maxVal - minVal + 1) + minVal;
    minVal = 1;
    maxVal = 4;
    int suitValueRandomNumber = rand()%(maxVal - minVal + 1) + minVal;
    if (suitValueRandomNumber == 1){
        setCard(faceValueRandomNumber, "Clubs");
    } else if (suitValueRandomNumber == 2){
        setCard(faceValueRandomNumber, "Diamonds");
    } else if (suitValueRandomNumber == 3){
        setCard(faceValueRandomNumber, "Hearts");
    } else if (suitValueRandomNumber == 4){
        setCard(faceValueRandomNumber, "Spades");
    }
}

//Constructor with parameter
Card::Card(int newFace, const char suitName[]){
    setCard(newFace, suitName);
}

//Set the face and suit value for a card
void Card::setCard(int newFace, const char newSuit[]){
    if ((newFace < 1) || (newFace > 13)){
        newFace = 1;
    }
    cardFaceValue = newFace;
    if ((strcmp(newSuit, "Clubs") == 0) || (strcmp(newSuit, "Diamonds") == 0) || (strcmp(newSuit, "Hearts") == 0) || (strcmp(newSuit, "Spades") == 0)){
        strcpy(suit, newSuit);
    } else{
        strcpy(suit, "Hearts");
    }
}

//Get the face value of the card
int Card::getFace(){
    return cardFaceValue;
}

//Return the suit value
char * Card::getSuit(){
    return suit;
}

//displayCard diaplays the face and suit value of the card in text format 
void Card::displayCard(){
    if (getFace() == 1){
        cout << "Ace of " << getSuit();
    } else if(getFace() == 11){
        cout << "Jack of " << getSuit();
    } else if(getFace() == 12){
        cout << "Queen of " << getSuit();
    } else if(getFace() == 13){
        cout << "King of " << getSuit();
    } else{
        cout << getFace() << " of " << getSuit();
    }
}

/*************************************************************************/


/***************************************************************
Constructor

Use: This creates a DeckOfCards object and then shuffles the
cards

Arguments: none

Note: -1 is used to signal that no cards have been removed from
the deck
***************************************************************/

DeckOfCards::DeckOfCards()
{
    //An array of the 4 possible values for the card suit
    const char suitVals[NUM_SUITS][9] = { "Clubs", "Diamonds", "Hearts", "Spades" };
    
    int cardSub = 0; //subscript to process the deck of cards
    
    //Go through all 52 spots in the array of Cards and put a card
    //at the location
    
    for( int suitSub = 0; suitSub < NUM_SUITS; suitSub++ )
    {
        //For each of the suits, put in all of the cards for the suit
        for( int faceVal = 1; faceVal <= CARDS_PER_SUIT; faceVal++ )
        {
            //Put the card into the deck
            deck[ cardSub ].setCard( faceVal, suitVals[suitSub] );
            //Move to the next card in the deck
            cardSub++;
        }
    }

    //shuffle the playing cards
    shuffle();
    
    //Set the top card location to -1 to indicate the deck is brand new
    topCard = -1;
}

/***************************************************************
Method: Card draw()

Use: This method draws a card from the top of the deck

Arguments: none

Returns: a Card object (the card on the top of the deck)
***************************************************************/

Card DeckOfCards::draw()
{
    //Increment to get the subscript of the current top card
    topCard++;
    
    //return the card that is currently on the top of the deck
    return deck[topCard];
}

/***************************************************************
Method: void shuffle()

Use: This method shuffles the deck of cards

Arguments: none

Returns: nothing

Note: this method uses the random_shuffle function that is part
of the algorithm library to shuffle the 52 cards
***************************************************************/

void DeckOfCards::shuffle()
{
    //Shuffle all 52 cards that are in the deck
    
    random_shuffle(deck, deck+MAX_CARDS);
}


/***************************************************************
Method: bool isEmpty()

Use: This method determines if the deck of cards is empty( have
all of the cards been drawn)

Arguments: none

Returns: boolean value: true if all of the cards have been drawn
false if there are still cards in the deck
***************************************************************/

bool DeckOfCards::isEmpty()
{
    return topCard + 1 >= MAX_CARDS;
}

//!! TESTER PROGRAM BEFORE MOVING TO PART 2


int main()
{
//Set the seed value for the random number generator
srand(11);

//Test 1: Constructors and displayCard method

//Create the 3 Card objects

Card firstCard;
Card secondCard;
Card thirdCard = Card( 13, "Spades" );

//Display the 3 objects

cout << "Test 1: Constructors and displayCard method" << endl << endl
<< " The first card is the ";
firstCard.displayCard();

cout << "." << endl << endl << " The second card is the ";
secondCard.displayCard();

cout << "." << endl << endl << " The third card is the ";
thirdCard.displayCard();


//Test 2: setCard method on the first object

cout << endl << endl << endl << "Test 2: setCard method" << endl << endl;

//Change the first card to the Jack of Hearts

firstCard.setCard( 11, "Hearts" );

cout << " Change the first card to the Jack of Hearts. It is now the ";
firstCard.displayCard();


//Test 3: setCard method on the second object

cout << endl << endl << endl << "Test 3: setCard method with invalid values" << endl << endl;

//Try to change the second card using face of -5 and suit of ""

secondCard.setCard( -5, "" );

cout << " The second card should be the Ace of Hearts. It is now the ";
secondCard.displayCard();

//Try to change the first card using face of 16 and suit of "Candles"

firstCard.setCard( 16, "Candles" );

cout << endl << endl << " The first card should be the Ace of Hearts. It is now the ";
firstCard.displayCard();

//Test 4: getFace and getSuit methods on the third object

//Change the third card to 3 of Clubs
thirdCard.setCard( 3, "Clubs" );

cout << endl << endl << endl << "Test 4: getFace and getSuit methods" << endl << endl;

cout << " The third card should have a face value of 3. It is "
<< thirdCard.getFace() << endl
<< " The suit value should be Clubs. It is " << thirdCard.getSuit() << endl;

DeckOfCards gameDeck;
Card drawnCard;
int castCount;
int pointsWon;
int finalPointsWon;
int drawnCardFaceValue;
pointsWon = 0;
finalPointsWon = 0;

cout << "\nHow many times do you want to try to catch a fish? ";
cin >> castCount;
for (int i=0; i < castCount; i++){
    drawnCard = gameDeck.draw();
    cout << "\nDraw " << i+1 << " :";
    cout << "\nYou drew the ";
    drawnCard.displayCard();
    cout << " and caught a ";
    drawnCardFaceValue = drawnCard.getFace();
    if (drawnCardFaceValue == 1){
        pointsWon = 20;
        cout << "big fish! " << pointsWon << " points";
        finalPointsWon += pointsWon;
    } else if (drawnCardFaceValue == 13){
        pointsWon = 40;
        cout << "shark! " << pointsWon << " points";
        finalPointsWon += pointsWon;
    } else if (drawnCardFaceValue == 12){
        pointsWon = 10;
        cout << "fish! " << pointsWon << " points";
        finalPointsWon += pointsWon;
    } else if (drawnCardFaceValue == 11){
        pointsWon = -10;
        cout << "old shoe! " << pointsWon << " points";
        finalPointsWon += pointsWon;
    } else if ((drawnCardFaceValue >= 2) && (drawnCardFaceValue <= 6)) {
        pointsWon = 5;
        cout << "gold fish! " << pointsWon << " points";
        finalPointsWon += pointsWon;
    }  else if ((drawnCardFaceValue >= 7) && (drawnCardFaceValue <= 10)) {
        pointsWon = -20;
        cout << "toilet seat! " << pointsWon << " points";
        finalPointsWon += pointsWon;
    }
}
cout << "\nYour final point total is " << finalPointsWon << " points.";
return 0;
}