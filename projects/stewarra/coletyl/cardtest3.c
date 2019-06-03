#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  struct gameState G;

  printf("Card Test 3: Outpost\n");

  cardEffect(outpost, 0, 0, 0, &G, 0, 0);

  if(G.outpostPlayed == 1){
    printf("Passed: outpost played\n");
  } else {
    printf("Failed: outpost not played\n");
  }

  printf("End of Card Test 3: Outpost\n");
  return 0;
}
