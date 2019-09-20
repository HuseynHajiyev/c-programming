#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) 
{
  assert((c.value >= 2 && c.value <= VALUE_ACE)&&(c.suit >= SPADES && c.suit < NUM_SUITS));

}

const char* ranking_to_string(hand_ranking_t r) 
{
  switch(r)
  {
    case STRAIGHT_FLUSH:
      return "straight flush";
    case FOUR_OF_A_KIND:
      return "four of a kind";
    case FULL_HOUSE:
      return "full house";
    case FLUSH:
      return "flush";
    case STRAIGHT:
      return "straight";
    case THREE_OF_A_KIND:
      return "threee of a kind";
    case TWO_PAIR:
      return "two pair";
    case PAIR:
      return "pair";
    default:
      return "nothing";
  }
}

char value_letter(card_t c) 
{
 if(c.value >= 2 && c.value <= 9)
 {
   return '0' + c.value;
 }
 switch (c.value)
 {
  case 10:
    return '0';
  case VALUE_JACK:
    return 'J';
  case VALUE_QUEEN:
    return 'Q';
  case VALUE_KING:
    return 'K';
  case VALUE_ACE:
    return 'A';
  default:
    return EXIT_FAILURE;
  }

}


char suit_letter(card_t c) 
{
  switch (c.suit)
  {
    case SPADES:
      return 's';
    case HEARTS:
      return 'h';
    case DIAMONDS:
      return 'd';
    case CLUBS:
      return 'c';   
    default:
      return EXIT_FAILURE;
  }
}

void print_card(card_t c) 
{
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) 
{
  card_t temp;

  if(value_let >= '2' && value_let <= '9')
  {
    temp.value = value_let - '0';
  } else 
  {
      switch (value_let)
    {
      case '0':
        temp.value = 10;
        break;
      case 'J':
        temp.value = VALUE_JACK;
        break;
      case 'Q':
        temp.value = VALUE_QUEEN;
        break;
      case 'K':
        temp.value = VALUE_KING;
        break;
      case 'A':
        temp.value = VALUE_ACE; 
        break;
    }
  }

  switch(suit_let)
  {
    case 's':
      temp.suit = SPADES;
      break;
    case 'h':
      temp.suit = HEARTS;
      break;
    case 'd':
      temp.suit = DIAMONDS;
      break;
    case 'c':
      temp.suit = CLUBS;
      break;
  }

  assert_card_valid(temp);

  return temp;
}

card_t card_from_num(unsigned c) 
{ 
  int modValue;
  int modSuit;
  card_t temp;

  modValue = c%13;
  modSuit =c%4;

  switch(modValue)
  {
    case 0:
      temp.value = VALUE_KING;
      break;
    case 1:
      temp.value = VALUE_ACE;
      break;
    default:
      temp.value = modValue;
      break;
  }

  switch(modSuit)
  {
    case 0:
      temp.suit = SPADES;
      break;
    case 1:
      temp.suit = HEARTS;
      break;
    case 2:
      temp.suit = DIAMONDS;
      break;
    case 3:
      temp.suit = CLUBS;
      break;
  }
  
  assert_card_valid(temp);

  return temp;
}
