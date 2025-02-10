#include <stdio.h>
#include <string.h>

#define INDEX(i) ((i) > 96 ? (i) - 70 : (i) - 65)

char *minWindow(char *s, char *t) {
  size_t l_s = strlen(s);
  size_t l_t = strlen(t);

  int t_map[52] = {0};
  for (int i = 0; i < l_t; i++) {
    t_map[INDEX((int)t[i])]++;
  }

  int s_map[52] = {0};
  for (int i = 0; i < l_s; i++) {
    printf("%d\n", (int)s[i]);
  }

  return NULL;
}

int main(int argc, char *argv[]) {
  char *s = "ADOBECODEBANC";
  char *t = "ABC";

  minWindow(s, t);

  return 0;
}
