1.please write your code in c
2. your code will be judged by loader code
3. make sure to pass the test case

Please write a gettoken function which can isolate sequential tokens in a null-terminated string. The first argument str is a pointer to char which will point to the string that we want to get tokens from. The second argument sep is a string of separator. The first time that gettoken is called, str should be specified; subsequent calls, wishing to obtain further tokens from the same string, should pass a NULL pointer instead.

strtok, strtok_r, strsep is banned in this problem

Input
The first line contains an integer N that indicates the number of lines, followed by N lines of text, each line will be less than 4000 character


Output
Multiple tokens, each separated by a newline

Loader Code
Your code will be judge using this program:

#include <stdio.h>
#include <stdlib.h>

char *strtok(char *s, const char *sep) {
  printf("strtok banned\n");
  exit(1);
}
char *strtok_r(char *str, const char *sep, char **lasts) {
  printf("strtok_r banned\n");
  exit(1);
}

char *strsep(char **stringp, const char *delim) {
  printf("strsep banned\n");
  exit(1);
}
char *gettoken(char *str, const char *sep);
int main() {
  char buffer[4096];
  char *sep = " \t\n;,.?!";
  char *word;
  int N;
  scanf("%d\n", &N);
  for (int i = 0; i < N; i++) {
    fgets(buffer, 4095, stdin);
    for (word = gettoken(buffer, sep); word != NULL;
         word = gettoken(NULL, sep)) {
      printf("%s\n", word);
    }
  }
}
Example 1

Input

1
C makes it easy to shoot yourself in the foot; C++ makes it harder, but when you do, it blows your whole leg off.

Output

C
makes
it
easy
to
shoot
yourself
in
the
foot
C++
makes
it
harder
but
when
you
do
it
blows
your
whole
leg
off

Example 2

Input

2
When I wrote this code, only God and I understood what I did. Now... only God knows.
C programmers never die. They are just cast into void.

Output

When
I
wrote
this
code
only
God
and
I
understood
what
I
did
Now
only
God
knows
C
programmers
never
die
They
are
just
cast
into
void
