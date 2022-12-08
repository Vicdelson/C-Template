#include <stdio.h>
#include <string.h>

#define MAX_CAND_CNT 20
#define MAX_NAME_LEN 32
struct ballot_counter_s {
  int count;
  char name[MAX_NAME_LEN];
} counter[MAX_CAND_CNT];
int cand_cnt;

void count(const char *name);
const char *winner();

int main() {
  scanf("%d", &cand_cnt);
  for (int i = 0; i < cand_cnt; i++) {
    scanf("%s", counter[i].name);
    counter[i].count = 0;
  }

  char name[MAX_NAME_LEN];
  while (scanf("%s", name) != EOF)
    count(name);

  for (int i = 0; i < cand_cnt; i++)
    printf("%s %d\n", counter[i].name, counter[i].count);

  printf("%s\n", winner());

  return 0;
}

/* count(name) function increment the count of voted of candidate named name by
 * 1*/
void count(const char *name) {
  int i;
  // iterate over the number of candidates
  for (i = 0; i < cand_cnt; i++) {
    // if candidate[i] name is same as name increment his count
    if (strcmp(counter[i].name, name) == 0)
      counter[i].count++;
  }
}

/* winner() funtion returns the name of winner*/
const char *winner() {
  // winner_index stores the index of winning candidate
  int i, winner_index = 0;
  // iterate over the number of candidates
  for (i = 0; i < cand_cnt; i++) {
    // if candidate[i] count is greater than candidate[winner_index] set
    // winner_index to i
    if (counter[i].count > counter[winner_index].count)
      winner_index = i;
  }
  // return winner candidate name
  return counter[winner_index].name;
}