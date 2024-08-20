compile:
	g++ Card.cpp AnalyzeHand.cpp BlackjackRules.cpp PokerRules.cpp -c -Wall -std=c++98
	g++ Dealer.cpp Card.o AnalyzeHand.o BlackjackRules.o PokerRules.o -o deal.out -Wall -std=c++98
run:
	./deal.out
clean:
	rm *.out *.o

