#include <stdio.h>
#include <string.h>
/*
* 给出一个字符串，按照单词顺序进行反转
* 例如： "the sky is blue" -> "blue is sky the"
* 过程：
* 1.  先反转整个字符串："the sky is blue" -> "eulb si yks eht"
* 2. 反转单个单词："eulb si yks eht" -> "blue is sky the"
*/

void swap_chars(char *chars, int start, int end) {
  char tmp = chars[start];
  printf("s: %d, end: %d, tmp: %c\n", start, end, tmp);
  chars[start] = chars[end];
  chars[end] = tmp;
}

void _reverse_chars(char *chars, int start, int end) {
  while(start < end){
    swap_chars(chars, start, end);
    start++;
    end--;
  }
  
}

void reverse_words(char *words) {
  if (words == NULL) {
    return;
  }

  int start = 0;
  int length = strlen(words);
  swap_chars(words, start, length - 1);

  for(int i = 0; i < length; i++)
  {
    if (i == length - 1 || words[i+1] == ' ') {
      _reverse_chars(words, start, i);
      start = i + 2;
    }
  }
}

int main() {
  char *s = "the sky is blue";
  // _reverse_chars(s, 0, strlen(s) - 1);
  reverse_words(s);
  printf("result: %s\n", s);

  return 0;
}