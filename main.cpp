//
//  main.cpp
//  HandHomework
//
//  Created by Howard Stahl on 4/30/15.
//  Copyright (c) 2015 Howard Stahl. All rights reserved.
//

#include <iostream>
#include <string>
#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include <cassert>
void clearScreen();

int main(int argc, const char * argv[])
{
	try {
	using namespace cs31;
	using namespace std;
	string action;


	// test code
	Player p;

	Card c(Face::ACE, Suit::DIAMONDS);
	Card d(Face::TEN, Suit::CLUBS);
	Card e(Face::THREE, Suit::SPADES);
	Card f(Face::EIGHT, Suit::HEARTS);
	Card x(Face::ACE, Suit::CLUBS);
	Card a(Face::DEUCE, Suit::CLUBS);
	Card b(Face::FIVE, Suit::SPADES);
	Card h(Face::SEVEN, Suit::DIAMONDS);
	Card i(Face::NINE, Suit::HEARTS);
	Card j(Face::EIGHT, Suit::CLUBS);
	Card k(Face::QUEEN, Suit::CLUBS);
	Card l(Face::KING, Suit::HEARTS);
	Card m(Face::KING, Suit::CLUBS);
	Card n(Face::QUEEN, Suit::HEARTS);

	assert(p.handcount() == 0);
	assert(p.hasBlackJack() == false);
	assert(p.cardCount() == 0);
	p.acceptCard(c);
	assert(p.handcount() == 11);
	assert(p.hasBlackJack() == false);
	assert(p.cardCount() == 1);
	assert(p.getCard(0) == c);
	p.acceptCard(d);
	assert(p.handcount() == 21);
	assert(p.hasBlackJack() == true);

	Player z;                           //This block tests the handling of aces. 
	z.acceptCard(c);                    //Deal an ace
	assert(z.handcount() == 11);		//Handcount should be 11 now
	z.acceptCard(f);					//Take an eight
	assert(z.handcount() == 19);		//Handcount should be 19 now
	z.acceptCard(x);					//Take another ace
	assert(z.handcount() == 20);		//Handcount should be 20 now
	z.acceptCard(e);					//Take a three
	assert(z.handcount() == 13);		//Both aces should be treated as 1



	p = Player();
	Player dealer;
	Game g(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	//assert(g.playerBusted() == false);
	assert(g.playerTied() == true);
	assert(g.playerWon() == false);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);


	p = Player();
	p.acceptCard(c);
	p.acceptCard(d);

	dealer = Player();
	dealer.acceptCard(e);
	dealer.acceptCard(f);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == true);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == true);
	assert(g.dealerHasBlackJack() == false);



	p.acceptCard(c);
	p.acceptCard(d);
	p.acceptCard(e);
	p.acceptCard(l);



	dealer.acceptCard(e);
	dealer.acceptCard(f);
	dealer.acceptCard(m);
	dealer.acceptCard(l);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();

	assert(g.playerBusted() == true);
	assert(g.playerStood() == true);
	assert(g.playerLost() == true);
	assert(g.dealerBusted() == true);




		//this chunk of code tests exception handling
		p = Player();
		p.acceptCard(a);
		p.acceptCard(b);
		p.acceptCard(c);
		p.acceptCard(d);
		p.acceptCard(e);
		p.acceptCard(f);
		p.acceptCard(x);
		p.acceptCard(h);
		p.acceptCard(i);
		p.acceptCard(j);
		p.acceptCard(k);
		p.acceptCard(l);
		//p.acceptCard(m); //This line should throw an exception because there are more than 12 cards in the players hand
		//Card o = p.getCard(-1);     //This lline should throw an exception for bad index
		Card q = p.getCard(2);
		assert(q.getFace() == Face::ACE && q.getSuit() == Suit::DIAMONDS);
		//Card r = p.getCard(12);     //This line should throw an exception for bad index.
									//By commenting out various lines we can test the excetion handling. 
	



	g = Game();
	g.deal();
	// clearScreen();
	if (g.playerHasBlackJack() || g.dealerHasBlackJack())
	{
		g.playerStands();
		g.dealerStands();
	}
	else
	{
		do
		{
			g.display("(h)it (s)tand or (q)uit:");
			getline(cin, action);
			if (action.size() == 0)
			{
				g.playerStands();
			}
			else
			{
				switch (action[0])
				{
				default:   // if bad move, nobody moves
					cout << '\a' << endl;  // beep
					continue;
				case 'Q':
				case 'q':
					return 0;
				case 'h':
				case 'H':
					g.playerHits();
					clearScreen();
					break;
				case 's':
				case 'S':
					g.playerStands();
					break;
				}
			}
		} while (!g.playerBusted() && !g.playerStood());

		clearScreen();
		g.dealerPlays();
	}

	if (g.playerWon())
	{
		g.display("WON!", true);
	}
	else if (g.playerLost())
	{
		g.display("LOST!", true);
	}
	else
	{
		g.display("TIED!", true);
	}
	}
	catch (std::logic_error e) {
		std::cerr << e.what() << std::endl;  //We catch the exception which is a logic_error and print its message to cerr using .what()
	}
    
    return 0;
}



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

