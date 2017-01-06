//
//  Game.cpp
//  HandHomework
//
//  Created by Howard Stahl on 12/6/15.
//  Copyright © 2015 Howard Stahl. All rights reserved.
//

#include "Game.h"
#include <iostream>

// CS 31 Students need to complete this class.
// Please read over the assignment and the TODO comments in the accompanying
// implementation file for further instructions.
namespace cs31
{

Game::Game()
{
    // TODO : set the outcome of the game initially
    //        set the player's turn is not yet over
	mOutcome = NOOUTCOME;
	mPlayerStood = false;
}
 
Game::Game( Player player, Player dealer )
{
    mPlayer = player;
    mDealer = dealer;
	// TODO : set the outcome of the game initially
    //        set the player's turn is not yet over
	mOutcome = NOOUTCOME;
	mPlayerStood = false;
}

// did the Player win?
bool Game::playerWon()
{
    return( mOutcome == PLAYERWON );
}
    
// did the Player lose?
bool Game::playerLost()
{
    return( mOutcome == PLAYERLOST );
}
    
// did the Player and the Dealer tie?
bool Game::playerTied( )
{
    return( mOutcome == TIED );
}
    
void Game::deal()
{
    // TODO : shuffle deck
    //        deal two cards to the player and two to the dealer
	mDeck.shuffleDeck();
	mPlayer.acceptCard(mDeck.dealCard());
	mPlayer.acceptCard(mDeck.dealCard());
	mDealer.acceptCard(mDeck.dealCard());
	mDealer.acceptCard(mDeck.dealCard());
	if (playerHasBlackJack()||dealerHasBlackJack()) {   //if either of them has blackjack end the game
		dealerStands();
	}
	
}
    
void Game::playerHits( )
{
    // TODO : deal another card to the player
	mPlayer.acceptCard(mDeck.dealCard());
}
    
// let the Game know that the Player's turn is over
void Game::playerStands()
{
    mPlayerStood = true;
}
 
// has the Player's turn ended?
bool Game::playerStood() const
{
    return( mPlayerStood );
}

void Game::dealerHits( )
{
    // TODO : deal another card to the dealer
	mDealer.acceptCard(mDeck.dealCard());
}
    
void Game::dealerStands( )
{
    // TODO : since the game is now over, determine the outcome
    //        store the outcome in the member mOutcome
	if (playerBusted() && dealerBusted()) {   //if both bust player loses. technically thhis cannot happen, but as a failsafe
		mOutcome = PLAYERLOST;
		return;
	}
	else {
		if (mPlayer.handcount() == mDealer.handcount()) {
			mOutcome = TIED;
			return;
		}
	}
	if (dealerBusted()) { //we already know that both of them did not bust. so if dealer busted the player did not.
		mOutcome = PLAYERWON;
		return;
	}
	
	if (playerBusted()) {
		mOutcome = PLAYERLOST;
		return;
	}
	if (playerHasBlackJack() && dealerHasBlackJack()) {  //if both have blackjack, they tie
		mOutcome = TIED;
		return;
	}
	if (playerHasBlackJack()) {
		mOutcome = PLAYERWON;
		return;
	}
	if (dealerHasBlackJack()) {
		mOutcome = PLAYERLOST;
		return;
	}
	if (mPlayer.handcount() > mDealer.handcount()) {  //if no blackjack, the player with a greater handcount wins
		mOutcome = PLAYERWON;
		return;
	}
	if (mPlayer.handcount() < mDealer.handcount()) {
		mOutcome = PLAYERLOST;
		return;
	}

}
    
bool Game::dealerBusted( ) const
{
    // TODO : did the dealer go over 21?
    bool result = false;
	if (mDealer.handcount() > 21) {
		result = true;
	}
    return( result );
}
    
bool Game::playerBusted( ) const
{
    // TODO : did the player go over 21?
    bool result = false;
	
	if (mPlayer.handcount() > 21) {
		result = true;
		
	}
	return( result );
}
    
void Game::dealerPlays()
{
    // TODO : if the player hasn't busted,
    //        play the dealer's hand by taking cards until the
    //        dealer's cards total 17 or more or the dealer busts

    // let the Game know that play has ended
	if (!playerBusted()) {   //as long as the player hasnt busted
		while (mDealer.handcount() < 17) {     
			mDealer.acceptCard(mDeck.dealCard()); //keep getting cards while handcount is less than 17
			if (dealerBusted()) {  //if dealer busts end the function
				dealerStands();
				return;
			}
		}
	}
    dealerStands(); //end dealers turn
}
    
bool Game::playerHasBlackJack( ) const
{
    // TODO : does the player have blackjack?h
    bool result = false;
	if (mPlayer.hasBlackJack()) {
		result = true;
	}
    return( result );
}
    
bool Game::dealerHasBlackJack( ) const
{
    // TODO : does the dealer have blackjack?
    bool result = false;
	if (mDealer.hasBlackJack()) {
		result = true;
	}
    return( result );
}
    
//
// ALL THE CODE BELOW THIS POINT SHOULD NOT BE CHANGED!
//
void Game::display( std::string s , bool allCards )
{
    // when allCards is true  --> show all dealer cards
    // otherwise just show the one turned up dealer card
    // and then display the passed message at the bottom of the screen, if supplied
    using namespace std;
    int dealerCount = mDealer.handcount();
    int playerCount = mPlayer.handcount();
    cout << "DEALER'S HAND:" << endl;
    if (allCards)
    {
        cout << mDealer << endl;
    }
    else
    {
        cout << mDealer.getCard(0) << endl;
    }
    if (dealerBusted())
    {
        cout << "          --->dealer busted!" << endl;
    }
    else if (allCards)
    {
        cout << "          --->" << dealerCount << endl;
    }
    cout << endl;
    cout << "PLAYER'S HAND:" << endl;
    cout << mPlayer << endl;
    if (playerBusted())
    {
        cout << "          --->player busted!" << endl;
    }
    else if (allCards)
    {
        cout << "          --->" << playerCount << endl;
    }

    if (s != "")
        cout << s << endl;
}
    


    
}