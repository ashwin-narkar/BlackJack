//
//  Card.cpp
//  HandHomework
//
//  Created by Howard Stahl on 4/30/15.
//  Copyright (c) 2015 Howard Stahl. All rights reserved.
//

#include "Card.h"

// This class has been provided to CS 31 students.
// No changes need to be made to this class.
namespace cs31
{
    
    Card::Card( Face f, Suit s ) : myFace( f ), mySuit( s ), myCycle( NOTPLAYED )
    {

    }

    cs31::Face Card::getFace( ) const
    {
        return( myFace );
    }
    
    cs31::Suit Card::getSuit( ) const
    {
        return( mySuit );
    }
    
    bool Card::isInPlay( ) const
    {
        return( myCycle == INPLAY );
    }
    
    bool Card::isDiscarded( ) const
    {
        return( myCycle == DISCARDED );
    }
    
    bool Card::isNotPlayed( ) const
    {
        return( myCycle == NOTPLAYED );
    }
    
    void Card::discard( )
    {
        myCycle = DISCARDED;
    }
    
    void Card::recycle()
    {
        myCycle = NOTPLAYED;
    }
    
    void Card::inplay()
    {
        myCycle = INPLAY;
    }

    bool operator==( const Card& c1, const Card& c2 )
    {
        return( c1.getFace() == c2.getFace() && c1.getSuit() == c2.getSuit() );
    }

    bool operator<( const Card& c1, const Card& c2 )
    {
        return( c1.getFace() < c2.getFace() );
    }
    
    std::ostream& operator<<( std::ostream& outs, const Card& c )
    {
        switch (c.getFace())
        {
            case ACE:
                outs << "Ace of ";
                break;
            case DEUCE:
                outs << "Two of ";
                break;
            case THREE:
                outs << "Three of ";
                break;
            case FOUR:
                outs << "Four of ";
                break;
            case FIVE:
                outs << "Five of ";
                break;
            case SIX:
                outs << "Six of ";
                break;
            case SEVEN:
                outs << "Seven of ";
                break;
            case EIGHT:
                outs << "Eight of ";
                break;
            case NINE:
                outs << "Nine of ";
                break;
            case TEN:
                outs << "Ten of ";
                break;
            case JACK:
                outs << "Jack of ";
                break;
            case QUEEN:
                outs << "Queen of ";
                break;
            case KING:
                outs << "King of ";
                break;
        }
        switch (c.getSuit())
        {
            case SPADES:
                outs << "Spades";
                break;
            case CLUBS:
                outs << "Clubs";
                break;
            case HEARTS:
                outs << "Hearts";
                break;
            case DIAMONDS:
                outs << "Diamonds";
                break;
        }
        return( outs );
    }

    int  Card::count( ) const
    {
        int result = 0;
        switch (getFace())
        {
            case ACE:
                result = 1;
                break;
            case DEUCE:
                result = 2;
                break;
            case THREE:
                result = 3;
                break;
            case FOUR:
                result = 4;
                break;
            case FIVE:
                result = 5;
                break;
            case SIX:
                result = 6;
                break;
            case SEVEN:
                result = 7;
                break;
            case EIGHT:
                result = 8;
                break;
            case NINE:
                result = 9;
                break;
            case TEN:
                result = 10;
                break;
            case JACK:
                result = 10;
                break;
            case QUEEN:
                result = 10;
                break;
            case KING:
                result = 10;
                break;
        }
        return( result );
    }
}