#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  struct gameState G;
  int garden;

  printf("Card Test 4: Gardens\n");

  G.hand[0][0] = gardens;
  G.phase = 0;
  G.numActions = 1;
  garden = playCard(0, -1, -1, -1, &G);

  if(G.numActions == 1) {
    printf("Passed: num actions correct\n");
  } else {
    printf("Passed: num actions incorrect\n");
  }
  if(gardens == -1) {
    printf("Passed\n");
  } else {
    printf("Failed\n");
  }

  printf("End of Card Test 4\n");
  return 0;
}
