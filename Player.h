//
//  Hand.h
//  HandHomework
//
//  Created by Howard Stahl on 4/30/15.
//  Copyright (c) 2015 Howard Stahl. All rights reserved.
//

#ifndef __HandHomework__Hand__
#define __HandHomework__Hand__

#include <iostream>
#include "Card.h"

#define MAXCARDS 12     // in BlackJack, you can't have more than 12 cards without busting...
                        // 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3 ---> Busted!

// CS 31 Students need to complete this class.
// Please read over the assignment and the TODO comments in the accompanying
// implementation file for further instructions.
namespace cs31
{
    
class Player
{
public:
    // constructor
    Player( );
    
    // mutator
    // add another Card into the myCards array
    void acceptCard( Card c );
    
    // accessors
    // retrieve a Card from the myCards array
    Card getCard( int index ) const;
    // how many cards are being stored in the myCards array?
    int  cardCount( ) const;

    // what is the value of this Player's hand?
    int  handcount( ) const;
    // does this Player have BlackJack?
    bool hasBlackJack( ) const;
    
    // called by Game::display to print out a player's hand
    friend std::ostream& operator <<( std::ostream& outs, const Player & p );

private:    
    Card myCards[ MAXCARDS ];
    int  myNumberOfCards;
};
    
    
}

#endif /* defined(__HandHomework__Hand__) */
