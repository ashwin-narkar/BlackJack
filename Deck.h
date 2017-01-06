//
//  Dealer.h
//  HandHomework
//
//  Created by Howard Stahl on 4/30/15.
//  Copyright (c) 2015 Howard Stahl. All rights reserved.
//

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Card.h"

#define DECKSIZE 52

// This class has been provided to CS 31 students.
// No changes need to be made to this class.
namespace cs31
{
    
class Deck
{
public:
    Deck();
    
    Card  dealCard( );
    void  shuffleDeck( );
    friend std::ostream& operator<<( std::ostream& outs, const Deck& d );
private:
    Card  myCards[ DECKSIZE ];
    int   myTotalUsed;
};
    
    
}

#endif /* defined(__HandHomework__Dealer__) */
