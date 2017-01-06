//
//  Hand.cpp
//  HandHomework
//
//  Created by Howard Stahl on 4/30/15.
//  Copyright (c) 2015 Howard Stahl. All rights reserved.
//

#include "Player.h"
#include <stdexcept>

// CS 31 Students need to complete this class.
// Please read over the assignment and the TODO comments in the accompanying
// implementation file for further instructions.
namespace cs31
{

Player::Player( )
{
    // The Player has no Cards in his hand
	myNumberOfCards = 0;
	
}
    
std::ostream& operator <<( std::ostream& outs, const Player & p )
{
    // TODO : print out all the actual cards in the array myCards
	for (int i = 0; i < p.myNumberOfCards; i++) {
		std::cout << p.myCards[i] << std::endl;
	}
    return( outs );
}
    
void Player::acceptCard(Card c)
{
    // TODO : as long as there is space in the array myCards, place Card c into myCards
    //        if there is not enough space for another card, throw an exception
	if (myNumberOfCards < 12) { //as long as there is space
		myCards[myNumberOfCards] = c;
		myNumberOfCards++;     //increase the counter for how many cards are in my hand
		
	}
	
	else {
		throw std::logic_error("Not enough space for another card");
	}
	
}
    
Card Player::getCard( int index ) const
{
    // TODO : return the requested card
    //        if the index is bad, throw an exception
	if (index < 0 || index > 11) { //if its outside the array throw an exception
		throw std::logic_error("Bad Index");
	}
	if (index > (myNumberOfCards - 1)) {
		throw std::logic_error("Player does not have that many cards");
	}
    Card c = myCards[index];
    return( c );
}
    
int  Player::handcount( ) const
{
    // TODO : total up the points in this player's hand
    //        you will need to figure out how to handle Ace's that might be worth 1 or 11
    int total = 0;
	int numAces = 0;
	for (int i = 0; i < myNumberOfCards; i++) {
		if (myCards[i].getFace()==ACE){
			numAces++;
		}
		else {
			total += myCards[i].count();
		}
	}
	if (numAces == 0) {
		return total; //if there are no aces just end the function and return total 
	}
	//only one ace can count as 11.
	//default one as 11 and the rest as 1
	//if doing this makes it more than 21, all aces count as 1
	//if there is more than one ace, only one can count as 11. all the other ones count as 1.
	total += numAces - 1; //if there is only one ace this does nothing.
	if ((total + 11) <= 21) { //For the last ace, if counting as 11 keeps the total under 21, count it as 11
		total += 11;
	}
	else { //otherwise treat it as 1
		total++;
	}
	
	return( total );
}
    
int Player::cardCount() const {
	return myNumberOfCards; //returns how many cards are in play
}

bool Player::hasBlackJack( ) const
{
    bool result = false;
    if (myNumberOfCards == 2 && handcount() == 21)
    {
        result = true;
    }
    return( result );
}
    
}