#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[]) {

  printf("指定時間を入力してください：");
  int choice_time;
  scanf("%d",&choice_time );
  //choice_time = get_time();

  printf("開始時間を入力してください：");
  int start_time;
  scanf("%d",&start_time );

  printf("終了時間を入力してください：");
  int end_time;
  scanf("%d",&end_time );

  printf("choice:%d, start:%d, end:%d \n", choice_time, start_time, end_time);

  /*if (start_time > end_time)
    end_time = end_time + 24;*/
  if ((choice_time >= start_time && choice_time < end_time) || (choice_time == start_time && choice_time == end_time) || (start_time > end_time && end_time > choice_time))
    printf("指定時間は開始時間と終了時間の間にあります\n");
  /*else if (choice_time == start_time & choice_time == end_time) {
    printf("指定時間は開始時間と終了時間の間にあります\n");
  }*/
  else printf("指定時間は開始時間と終了時間の間にありません\n");
  return 0;
}

/*int get_time(){
  char num[128];
  int *test;*/
  /*if (fgets(num, 256, stdin) == NULL || num[0] == '\n') {

  }*/
  /*
  fgets(num, 256, stdin);
  if (num[strlen(num) - 1] == '\n') {
    num[strlen(num) - 1] = '\0';
  }
  strtoi(num, test, 10);
  return *test;
}*/
