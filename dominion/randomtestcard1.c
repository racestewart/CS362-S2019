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
  int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, player = 0, passed = 0, failed = 0;
  struct gameState G, test;
  int seed = 1000;
  int numPlayers = 2;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

  printf("\n Testing Village Card\n");

  for(i = 0; i < 100; i++) {
    initializeGame(numPlayers, k, seed, &G);

    memcpy(&test, %G, sizeof(struct gameState));

    villageFunction(&G, handpos)

    player = whoseTurn(&test);

    // check hand count
    if(G.hand[player][test.handCount[player] - 1] != -1) {
      passed++;
    } else {
      failed++;
    }

    // check if card was played
    if(G.playedCardCount == test.playedCardCount + 1) {
      passed++;
    } else {
      failed++;
    }

    // check if num actions is accurate
    if(G.numActions == test.numActions + 2) {
      passed++;
    } else {
      failed++;
    }

    // check if discard is accurate
    if(G.discardCount[player] == test.discardCount[player] + 1) {
      passed++;
    } else {
      failed++;
    }
  }

  printf("Number of tests passed: %d\n", passed);
  printf("Number of tests failed: %d\n", failed);
  printf("End of Village Card Test\n");

  return 0;
}
