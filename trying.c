#include <stdio.h>
#include <string.h>

#define NUM_PLAYERS 4
#define NUM_CARDS 5

// Structure to represent a card
typedef struct {
  char rank;
  char suit;
} Card;

// Structure to represent a hand of cards
typedef struct {
  Card cards[NUM_CARDS];
  char category;
  int top_rank;
  int second_rank;
  int third_rank;
  char top_suit;
} Hand;

// Function to compare two hands and return -1, 0, or 1 depending on
// which hand is better
int compare_hands(Hand a, Hand b) {
  // Compare by category
  if (a.category > b.category) return -1;
  if (a.category < b.category) return 1;

  // If category is the same, compare by top rank
  if (a.top_rank > b.top_rank) return -1;
  if (a.top_rank < b.top_rank) return 1;

  // If top rank is the same, compare by second rank
  if (a.second_rank > b.second_rank) return -1;
  if (a.second_rank < b.second_rank) return 1;

  // If second rank is the same, compare by third rank
  if (a.third_rank > b.third_rank) return -1;
  if (a.third_rank < b.third_rank) return 1;

  // If third rank is the same, compare by top suit
  if (a.top_suit > b.top_suit) return -1;
  if (a.top_suit < b.top_suit) return 1;

  // If all other values are the same, the hands are equal
  return 0;
}

// Function to determine the category and rankings of a hand
void determine_hand(Hand *hand) {
  // Determine the category of the hand
  char ranks[NUM_CARDS + 1];
  char suits[NUM_CARDS + 1];
  int rank_counts[13] = {0};
  int suit_counts[4] = {0};
  for (int i = 0; i < NUM_CARDS; i++) {
    ranks[i] = hand->cards[i].rank;
    suits[i] = hand->cards[i].suit;
    rank_counts[hand->cards[i].rank - '2']++;
    suit_counts[hand->cards[i].suit - 'c']++;
  }
  ranks[NUM_CARDS] = '\0';
  suits[NUM_CARDS] = '\0';

  // Check for straight and flush
  int straight = 1;
  int flush = 1;
  for (int i = 1; i < NUM_CARDS; i++) {
    if (ranks[i] != ranks[i - 1] + 1) straight = 0;
    if (suits[i] != suits[i - 1]) flush = 0;
  }
  if (straight && flush) {
    hand->category = '1';
    return;
  }

  // Check for four-of
