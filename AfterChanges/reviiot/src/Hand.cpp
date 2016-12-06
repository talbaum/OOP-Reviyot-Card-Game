#include "../include/Hand.h"
#include <cstdlib>

using namespace std;
Hand::Hand():HandCards(),count(0),deck() {} //empty constructor


Hand:: Hand(Deck &deck2) :HandCards(), count(0){
	deck=deck2;
	for(unsigned int i=0;i<7&&deck.getNumberOfCards()!=0;i++)
            addCard(*deck.fetchCard());

	sortMyHand();
}



Hand::Hand(Hand &other): HandCards() ,count (other.count), deck(other.deck) {
string word=other.toString();
cout<< "test" <<endl;
makeHandVec(word,other.deck.N);
};
//copy constructor


Hand& Hand::operator =(Hand &other){
	if(this==&other)
		return *this;


	HandCards = other.HandCards;
	count= other.count;
	deck= other.deck;
	return *this;
}


void Hand::sortMyHand(){
	vector <Card*> tmp;
	for(unsigned int i=0;i<HandCards.size();i++){
		for(unsigned int j=i;j<HandCards.size();j++){
			if(HandCards[i][0]->getValue()>HandCards[j][0]->getValue()){
				tmp=HandCards[i];
				HandCards[i]=HandCards[j];
				HandCards[j]=tmp;
			}
		}
	}
}

Hand::~Hand(){
    
    cout<< "hand destructor" <<endl;

while (!HandCards.empty()){
    while (!HandCards.back().empty()){
    delete (HandCards.back().back());
    HandCards.back().pop_back();
    }
    HandCards.pop_back();
    }
}

vector<vector<Card*> > Hand:: getHand(){
	return this->HandCards;
}

int Hand:: whereToInsert(Card &card){   // made for the addCard method.
	unsigned int mid=0, left = 0 ;
	unsigned int right = (HandCards.size()==0)?0:HandCards.size()-1;
	while (left < right) {
		mid = (left + right)/2;
		if (card.getValue() > HandCards[mid][0]->getValue()){
			left = mid+1;
		}
		else if (card.getValue() < HandCards[mid][0]->getValue()){
			right = mid;
		}
		else {
			return mid;
		}
	}
	return mid; //for making sure its inserted before the closer bigger value. need to check it.
}

bool Hand:: addCard(Card &card){
	int myCardPos=searchCard(card);

	if(myCardPos==-1){
		std::vector<vector<Card*> >::iterator it;
		vector<Card*> insideVec;
		insideVec.push_back(&card);
		int pos=whereToInsert(card);
		it=HandCards.begin();
		HandCards.insert(it+pos,insideVec);
		sortMyHand();
	}
	else{
		HandCards.at(myCardPos).push_back(&card);
		if(HandCards.at(myCardPos).size()==4){   //if player got revia.
				removeCardReviia(*HandCards[myCardPos][0]);
                }
		else if(HandCards.at(myCardPos).size()>=2)
			HandCards[myCardPos]=sortByShape(HandCards[myCardPos]);
	}
	count++;
	return true;
}

vector<Card*> Hand:: sortByShape(vector<Card*> sortMe) {
	//insertion sort.
	Card* tmp;
	for (unsigned int i = 1; i < sortMe.size(); i++)  {
		for (unsigned int j = i; j >= 1; j--) {
			if (sortMe[j]->getShape() < sortMe[j-1]->getShape()) {
				tmp = sortMe[j];
				sortMe[j] = sortMe[j-1];
				sortMe[j-1] = tmp;
			}
		}
	}
	return sortMe;
}

bool  Hand:: removeCard(Card &card) {
	//vector<Card*> insideVec;
	int pos = searchCard(card);
	if (pos < 0)
		return false; //no such card at the hand.
	else {
		HandCards[pos].pop_back();
                count--;
		if(HandCards[pos].empty()) //my if of empty vec
			HandCards.erase(HandCards.begin()+pos);

		return true;
	}
}

bool  Hand:: removeCardReviia(Card &card) {
	//vector<Card*> insideVec;
	int pos = searchCard(card);
	if (pos < 0)
		return false; //no such card at the hand.
	else {
            while (!HandCards[pos].empty()){
		delete(HandCards[pos].back());
		HandCards[pos].pop_back();
                count--;
            }
            HandCards.erase(HandCards.begin()+pos);

		
		return true;
	}
}

int Hand:: searchCard(Card &card){  //made for remove card method. (had to make 2 diffrenet ones).

	int left = 0;
	int right = HandCards.size() - 1;
	int middle;
	while (left <= right) {
		middle = left + (right - left)/2;
		if (HandCards[middle][0]->getValue() > card.getValue())
			right = middle - 1;
		else
			if (HandCards[middle][0]->getValue() < card.getValue())
				left = middle + 1;
			else
				return middle;
	}
	return -1;
}

int Hand:: getNumberOfCards(){
	return this->count;
}
void Hand::makeHandVec(string word,int N){
	char shape;
	char fig;
	int value;
	unsigned int index=0;
	string s;
	while (index<word.length()){
		s="";
		while ((index<word.length())&&(word.at(index)!=(char)32)){
			s=s+word.at(index);
			index++;
		}
		if (s.at(0)<='9'){ //numericCard
			shape=s.at(s.length()-1);
			s.resize(s.length()-1);
			//value = atoi(s);
			value=atoi(s.c_str());
			NumericCard * c=new NumericCard(shape,value); // new!
			this->addCard(*c);
		}
		else{ //figureCard
			fig=s.at(0);
			switch (fig){
			case 'J':
				value=N+1;
				break;
			case 'Q':
				value=N+2;
				break;
			case 'K':
				value=N+3;
				break;
			case 'A':
				value=N+4;
				break;
			}
			shape=s.at(1);
			FigureCard * f=new FigureCard(shape,fig,value);
			this->addCard(*f);
		}
		index++;
	}
	this->sortMyHand();
}


string Hand:: toString(){
	string ans="";
        //sortMyHand();
	vector<Card*> insideVec;
	for(unsigned int i=0; i<HandCards.size();i++){
		insideVec=HandCards[i];
		for(unsigned int j=0; j<insideVec.size();j++)
			ans+=insideVec[j]->toString() + " ";
	}
	return ans;
}
