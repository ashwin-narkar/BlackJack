//
//  Dealer.cpp
//  HandHomework
//
//  Created by Howard Stahl on 4/30/15.
//  Copyright (c) 2015 Howard Stahl. All rights reserved.
//

#include "Deck.h"
#include "RandomNumber.h"
#include <iostream>

// This class has been provided to CS 31 students.
// No changes need to be made to this class.
namespace cs31
{
    
    Deck::Deck()
    {
        myCards[ 0 ]  =  Card( ACE, HEARTS );
        myCards[ 1 ]  =  Card( ACE, CLUBS );
        myCards[ 2 ]  =  Card( ACE, DIAMONDS );
        myCards[ 3 ]  =  Card( ACE, SPADES );
        myCards[ 4 ]  =  Card( DEUCE, HEARTS );
        myCards[ 5 ]  =  Card( DEUCE, CLUBS );
        myCards[ 6 ]  =  Card( DEUCE, DIAMONDS );
        myCards[ 7 ]  =  Card( DEUCE, SPADES );
        myCards[ 8 ]  =  Card( THREE, HEARTS );
        myCards[ 9 ]  =  Card( THREE, CLUBS );
        myCards[ 10 ] =  Card( THREE, DIAMONDS );
        myCards[ 11 ] =  Card( THREE, SPADES );
        myCards[ 12 ] =  Card( FOUR, HEARTS );
        myCards[ 13 ] =  Card( FOUR, CLUBS );
        myCards[ 14 ] =  Card( FOUR, DIAMONDS );
        myCards[ 15 ] =  Card( FOUR, SPADES );
        myCards[ 16 ] =  Card( FIVE, HEARTS );
        myCards[ 17 ] =  Card( FIVE, CLUBS );
        myCards[ 18 ] =  Card( FIVE, DIAMONDS );
        myCards[ 19 ] =  Card( FIVE, SPADES );
        myCards[ 20 ] =  Card( SIX, HEARTS );
        myCards[ 21 ] =  Card( SIX, CLUBS );
        myCards[ 22 ] =  Card( SIX, DIAMONDS );
        myCards[ 23 ] =  Card( SIX, SPADES );
        myCards[ 24 ] =  Card( SEVEN, HEARTS );
        myCards[ 25 ] =  Card( SEVEN, CLUBS );
        myCards[ 26 ] =  Card( SEVEN, DIAMONDS );
        myCards[ 27 ] =  Card( SEVEN, SPADES );
        myCards[ 28 ] =  Card( EIGHT, HEARTS );
        myCards[ 29 ] =  Card( EIGHT, CLUBS );
        myCards[ 30 ] =  Card( EIGHT, DIAMONDS );
        myCards[ 31 ] =  Card( EIGHT, SPADES );
        myCards[ 32 ] =  Card( NINE, HEARTS );
        myCards[ 33 ] =  Card( NINE, CLUBS );
        myCards[ 34 ] =  Card( NINE, DIAMONDS );
        myCards[ 35 ] =  Card( NINE, SPADES );
        myCards[ 36 ] =  Card( TEN, HEARTS );
        myCards[ 37 ] =  Card( TEN, CLUBS );
        myCards[ 38 ] =  Card( TEN, DIAMONDS );
        myCards[ 39 ] =  Card( TEN, SPADES );
        myCards[ 40 ] =  Card( JACK, HEARTS );
        myCards[ 41 ] =  Card( JACK, CLUBS );
        myCards[ 42 ] =  Card( JACK, DIAMONDS );
        myCards[ 43 ] =  Card( JACK, SPADES );
        myCards[ 44 ] =  Card( QUEEN, HEARTS );
        myCards[ 45 ] =  Card( QUEEN, CLUBS );
        myCards[ 46 ] =  Card( QUEEN, DIAMONDS );
        myCards[ 47 ] =  Card( QUEEN, SPADES );
        myCards[ 48 ] =  Card( KING, HEARTS );
        myCards[ 49 ] =  Card( KING, CLUBS );
        myCards[ 50 ] =  Card( KING, DIAMONDS );
        myCards[ 51 ] =  Card( KING, SPADES );
        
        myTotalUsed = 0;
    }
    
    
    Card Deck::dealCard( )
    {
        Card c;
        if (myTotalUsed >= DECKSIZE)
        {
            // no cards left...
            throw std::logic_error( "out of cards" );
        }
        else
        {
            int index = -1;
            RandomNumber random( 0, 51 );

            do {
                index = random.random();
            } while (myCards[ index ].isInPlay() || myCards[ index ].isDiscarded());
            /// we want the index of something not yet used...
            c = myCards[ index ];
            myCards[ index ].inplay();
            myTotalUsed++;
        }
        
        return( c );
    }
    
    void Deck::shuffleDeck( )
    {
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (myCards[i].isDiscarded())
            {
                myCards[i].recycle();
            }
        }
        myTotalUsed = 0;
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (myCards[i].isInPlay())
            {
                myTotalUsed = myTotalUsed + 1;
            }
        }
    }
    
    std::ostream& operator<<( std::ostream& outs, const Deck& d )
    {
        int totalInPlay = 0, totalDiscarded = 0, totalNotPlayed = 0;
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (d.myCards[i].isInPlay())
            {
                totalInPlay++;
            }
        }
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (d.myCards[i].isDiscarded())
            {
                totalDiscarded++;
            }
        }
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (d.myCards[i].isNotPlayed())
            {
                totalNotPlayed++;
            }
        }
        outs << "in play: " << totalInPlay << " discarded: " << totalDiscarded << " notplayed: " << totalNotPlayed << std::endl;
        return( outs );
    }
}