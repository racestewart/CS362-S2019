#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  struct gameState G;

  printf("Unit Test 3: Embargo\n");

  G.coins = 0;
  G.hand[0][0] = embargo;

  embargoFunction(&G, 0, 0);

  if(G.coins == 2) {
    printf("Passed: coins correct\n");
  } else {
    printf("Failed: coins incorrect\n");
  }
  
  return 0;
}
