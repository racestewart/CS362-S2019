#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// testing adventure card
int main() {
  int i = 0;
  int trash = 0;
  int garbage = 0;
  int temp[MAX_HAND];

  int j = 0;
  int m, draw;
  int seed = 1000;
  int numPlayers = 2;
  struct gameState G, G2;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

  initializeGame(numPlayers, k, seed, &G);

  printf("Card Test 2: Adventure\n");

  memcpy(&G2, &G, sizeof(struct gameState));
  G2.hand[G2.whoseTurn][0] = minion;

  adventurerFunction(&G2, 0);
  printf("Expected: %d, Actual: %d\n", G.handCount[G.whoseTurn] + 2, G2.handCount[G2.whoseTurn]);

  G.discardCount[G.whoseTurn] = 5;
  memcpy(&G2, &G, sizeof(struct gameState));
  adventurerFunction(&G2, 0);

  while(j < 2) {
    drawCard(G.whoseTurn, &G);
    draw = G.hand[G.whoseTurn][G.handCount[G.whoseTurn] - 1];
    if(draw == copper || draw == silver || draw == gold) {
      j++;
    } else {
      temp[i] = draw;
      G.handCount[G.whoseTurn]--;
      i++;
    }
  }

  printf("Expected count: %d, Actual count: %d\n", G.discardCount[G.whoseTurn] + i, G2.discardCount[G2.whoseTurn]);

  for(m = 0; m < G.handCount[G.whoseTurn]; m++) {
    if(G.hand[G.whoseTurn][m] == copper || G.hand[G.whoseTurn][m] == silver || G.hand[G.whoseTurn][m] == gold) {
      trash++;
    }
  }

  for(m = 0; m < G2.handCount[G2.whoseTurn]; m++) {
    if(G2.hand[G2.whoseTurn][m] == copper || G2.hand[G2.whoseTurn][m] == silver || G2.hand[G2.whoseTurn][m] == gold) {
      garbage++;
    }
  }

  printf("Final expected count: %d, Actual final count: %d\n", trash, garbage);
  printf("End of Card Test 2: Adventure\n");
  return 0;
}
