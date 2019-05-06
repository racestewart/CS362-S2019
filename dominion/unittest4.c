#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  struct gameState G;

  printf("Unit Test 4: Smithy\n");

  G.handCount[0] = 1;
  G.hand[0][0] = smithy;

  smithyFunction(&G, 0);

  if(G.handCount[0] == 3) {
    printf("Passed: num cards correct\n");
  } else {
    printf("Failed: num cards incorrect\n");
  }
  return 0;
}
