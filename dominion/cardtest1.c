#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  int seed = 1000;
  int numPlayers = 2;
  struct gameState G, G2;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

  initializeGame(numPlayers, k, seed, &G);

  printf("Card Test 1: Smithy\n");

  memcpy(&G2, &G, sizeof(struct gameState));
  smithyFunction(&G2, 0);

  if((G2.handCount[G2.whoseTurn] - 1) == G.handCount[G2.whoseTurn]) {
    printf("Passed: hand count correct\n");
  } else {
    printf("Failed: hand count incorrect\n");
  }

  if(G.hand[G2.whoseTurn][G2.handCount[G2.whoseTurn]] != -1) {
    printf("Passed: smithy card added\n");
  } else {
    printf("Failed: smithy card not added\n");
  }

  if((G2.playedCardCount + 2) == G.playedCardCount) {
    printf("Passed: smithy card played\n");
  } else {
    printf("Failed: smithy card not played\n");
  }

  printf("End of Card Test 1: Smithy\n");
  return 0;
}
