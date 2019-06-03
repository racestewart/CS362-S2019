#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  struct gameState G;

  printf("Unit Test 2: Great Hall\n");

  G.numActions = 0;
  G.handCount[0] = 1;
  G.hand[0][0] = great_hall;

  ghFunction(&G, 0);

  if(G.numActions == 1) {
    printf("Passed: actions correct\n");
  } else {
    printf("Failed: actions incorrect\n");
  }
  if(G.handCount[0] == 1) {
    printf("Passed: num cards correct\n");
  } else {
    printf("Failed: num cards incorrect\n");
  }
  return 0;
}
