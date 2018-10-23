/*九州工業大学 大学院 修士1年 丸山 剛尚*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int get_time(long *time);// 入力された時間取得用関数。成功で0、失敗で1を返す。

int main(int argc, char const *argv[]) {

  long choice_time;// ある時刻
  long start_time;// 開始時刻
  long end_time;// 終了時刻
  int get_time_flag = 1;// 入力時間取得フラグ

  printf("半角数字のみを用い、0から23までの整数を入力しEnterで値を確定してください。\n" );

  while(get_time_flag == 1) {
    printf("指定時間を入力してください：");
    get_time_flag = get_time(&choice_time);// フラグの更新
  }

  get_time_flag = 1;// 入力時間取得フラグの初期化
  while(get_time_flag == 1) {
    printf("開始時間を入力してください：");
    get_time_flag = get_time(&start_time);// フラグの更新
  }

  get_time_flag = 1;// 入力時間取得フラグの初期化
  while(get_time_flag == 1) {
    printf("終了時間を入力してください：");
    get_time_flag = get_time(&end_time);// フラグの更新
  }

  // printf("choice:%d, start:%d, end:%d \n", choice_time, start_time, end_time);// デバッグ用

  if ( choice_time == start_time || (start_time - end_time)*(choice_time - start_time)*(choice_time - end_time) > 0 )
    printf("指定時間は開始時間と終了時間の間にあります。\n");

  else
    printf("指定時間は開始時間と終了時間の間にありません。\n");

  return 0;
}

int get_time(long *time){
  int len = 4;// 入力文字数2桁+'\n'+'\0'の4文字
  char num[len];
  long time_num;

  if ( fgets(num, len, stdin) == NULL ) {
    // 取得失敗時エラー処理
    printf("\nエラー：予期せぬエラーが発生しました。もう一度やり直してください。\n");
    return 1;
  }

  else if( num[strlen(num) - 1] != '\n' ){
    // 入力文字サイズが2バイト以上の時のエラー処理
    while(getchar() != '\n');
    printf("\nエラー：0から23までの整数を半角数字で入力してください。\n");
    return 1;
  }

  else if ( (num[0] < '0' || num[0] > '9') || ((num[1] < '0' || num[1] > '9') && num[1] != '\n') ) {
    // 入力文字が半角数字以外の時のエラー処理
    printf("\nエラー：0から23までの整数を半角数字で入力してください。\n");
    return 1;
  }

  else{
    // 入力をlong型へ変換
    num[strlen(num) - 1] = '\n';
    time_num = strtol(num, NULL, 10);
  }

  // printf("%d\n", strlen(num));// デバッグ用

  if ( time_num > 23 ) {
    // 入力文字が24以上の時のエラー処理
    printf("\nエラー：0から23までの整数で入力してください。\n");
    return 1;
  }

  else
    *time = time_num;
  return 0;
}
