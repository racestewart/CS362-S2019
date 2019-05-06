#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  struct gameState G;

  printf("Unit Test 1: Village\n");

  G.numActions = 0;
  G.handCount[0] = 1;
  G.hand[0][0] = village;

  villageFunction(&G, 0);

  if(G.numActions == 2) {
    printf("Passed: num actions correct\n");
  } else {
    printf("Failed: num actions incorrect\n");
  }
  if(G.handCount[0] == 1) {
    printf("Passed: num cards correct\n");
  } else {
    printf("Failed: num cards incorrect\n");
  }
  return 0;
}
