#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

int main() {
  srand(time(NULL));

  int i, j, l, m;
  int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, player = 0, count1 = 0, count2 = 0, passed = 0, failed = 0;
  struct gameState G, test;
  int seed = 1000;
  int numPlayers = 2;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

  printf("\n Testing Adventurer Card\n");

  for(i = 0; i < 100; i++) {
    initializeGame(numPlayers, k, seed, &G);

    memcpy(&test, %G, sizeof(struct gameState));

    adventurerFunction(&G, handpos)

    player = whoseTurn(&test);

    // hand count accuracy
    if(test.handCount[player] - 1 == G.handCount[player]) {
      passed++;
    } else {
      failed++;
    }

    // deck count accuracy
    if(test.deckCount[player] - 1 == G.deckCount[player]) {
      passed++;
    } else {
      failed++;
    }

    // check if card was added
    if(G.hand[player][test.handCount[player]] != -1) {
      passed++;
    } else {
      failed++;
    }

    // check if card was played
    if(G.playedCardCount == test.playedCardCount + 2) {
      passed++;
    } else {
      failed++;
    }

    // check the number of adventurers in each hand
    for(i = 0; i < G.handCount[0]; i++) {
      if(G.hand[0][i] = adventurer) {
        count1++;
      }
    }

    for(i = 0; i < test.handCount[0]; i++) {
      if(test.hand[0][i] = adventurer) {
        count2++;
      }
    }

    if(count1 == count2 - 1) {
      passed++;
    } else {
      failed++;
    }

    // check num of actions
    if(G.numActions == test.numActions + 2) {
      passed++;
    } else {
      failed++;
    }

    // check discard
    if(G.discardCount[player] == test.discardCount[player]) {
      passed++;
    } else {
      failed++;
    }
  }

  printf("Number of tests passed: %d\n", passed);
  printf("Number of tests failed: %d\n", failed);
  printf("End of Adventurer Card Test\n");

  return 0;
}
