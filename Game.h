//
//  Game.h
//  HandHomework
//
//  Created by Howard Stahl on 12/6/15.
//  Copyright © 2015 Howard Stahl. All rights reserved.
//

#ifndef Game_h
#define Game_h
#include "Player.h"
#include "Deck.h"
#include <string>

// CS 31 Students need to complete this class.
// Please read over the assignment and the TODO comments in the accompanying
// implementation file for further instructions.
namespace cs31
{

// possible game outcomes
// NOOUTCOME means the game hasn't ended or started yet
// PLAYERWON means the dealer lost
// PLAYERLOST means the dealer won
// TIED means the dealer and the player wound up with the same card count value
enum OUTCOME { NOOUTCOME, PLAYERWON, PLAYERLOST, TIED };
    
class Game
{
public:
    // constructor
    Game( );
    // to support testing of the public methods of this class
    // by supplying the Player's and Dealer's hand
    Game( Player player, Player dealer );
    
    // begin a new game by shuffling the deck
    // and dealing four cards, two to the player and two to the dealer
    void deal( );
    
    // player wants another card
    void playerHits( );
    // player doesn't not want any more cards
    // after calling this method, the player's turn is over
    void playerStands( );
    // an accessor that helps us remember that the player's turn is over
    bool playerStood( ) const;
    
    // play the dealer's hand
    // the dealer stops on 17 and higher
    void dealerPlays();
    // the dealer must take another card
    void dealerHits( );
    // the dealer doesn't want any more cards
    // after calling this method, the dealer's turn is over
    // at this point, you can determine the outcome of the game
    void dealerStands( );
    
    // did the player or the dealer bust?
    bool playerBusted( ) const;
    bool dealerBusted( ) const;
    
    // these methods report on the outcome of the game
    bool playerWon( );
    bool playerLost( );
    bool playerTied( );
    
    // did the player or the dealer get BlackJack?
    bool playerHasBlackJack( ) const;
    bool dealerHasBlackJack( ) const;
    
    // prints out the current game state along with an ending message
    // if allCards is true, all the dealer cards are shown
    // otherwise, only the Dealer's single upcard is shown
    void display( std::string message="", bool allCards = false );
private:
    OUTCOME mOutcome;   // what is the game's outcome?
    bool mPlayerStood;  // has the player's turn ended?
    
    Deck   mDeck;     // the deck of cards used by this game
    Player mPlayer;
    Player mDealer;   // the dealer is just another kind of player...
};
    
}

#endif