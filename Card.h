//
//  Card.h
//  HandHomework
//
//  Created by Howard Stahl on 4/30/15.
//  Copyright (c) 2015 Howard Stahl. All rights reserved.
//

#ifndef __HandHomework__Card__
#define __HandHomework__Card__

#include <iostream>

// This class has been provided to CS 31 students.
// No changes need to be made to this class.
namespace cs31
{
  
    enum Cycle {
                 INPLAY,     // a dealt card that is held by a player and in use in a game
                 DISCARDED,  // a played card that can be recycled
                 NOTPLAYED   // a fresh card that has not yet been played
                };
    enum Suit  { HEARTS=100, DIAMONDS=200, CLUBS=300, SPADES=400 };
    enum Face  { ACE=1, DEUCE=2, THREE=3, FOUR=4, FIVE=5, SIX=6, SEVEN=7, EIGHT=8, NINE=9, TEN=10, JACK=11, QUEEN=12, KING=13 };
    
    class Card
    {
    public:
        // ACE of HEARTS by default....
        Card( Face f=ACE, Suit s=HEARTS );
    
        Face getFace( ) const;
        Suit getSuit( ) const;
        bool isInPlay( ) const;
        void inplay( );
        bool isDiscarded( ) const;
        void discard( );
        bool isNotPlayed( ) const;
        void recycle( );
        
        int  count( ) const;
    
        friend std::ostream& operator<<( std::ostream& outs, const Card& c );
        friend bool operator==( const Card& c1, const Card& c2 );
        friend bool operator<( const Card& c1, const Card& c2 );
    private:
        Suit  mySuit;
        Face  myFace;
        Cycle myCycle;
    };

}

#endif /* defined(__HandHomework__Card__) */
