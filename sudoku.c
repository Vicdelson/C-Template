#include <stdio.h>
#include <stdbool.h>
#define SUDOKU_SIZE 81
int ques[SUDOKU_SIZE];
int ans[SUDOKU_SIZE];
int main()
{ // read in map
for(int i=0; i<SUDOKU_SIZE; ++i)
scanf("%d", &ques[i]);
if(solve(ques) == true)
{
printf("Solvable!\n");
printMap(ans);
}
else
printf("Unsolvable!!\n");
return 0;
}
bool checkUnique(int arr[])
{
int arr_unity[9]; // counters
for(int i=0; i<9; ++i)
arr_unity[i] = 0; // initialize
for(int i=0; i<9; ++i)
++arr_unity[arr[i]-1]; // count
for(int i=0; i<9; ++i)
if(arr_unity[i] != 1) // all element
return false; // must be 1
return true;
}
int getFirstZeroIndex(int map[])
{
for(int i=0; i<SUDOKU_SIZE; ++i)
if(map[i] == 0)
return i;
return -1;
}
void printMap(int map[])
{
for(int j=0; j<SUDOKU_SIZE; j++)
{
printf("%d ", map[j]);
if(j%9 == 8)
printf("\n");
}
}
bool isCorrect(int map[])
{
bool check_result;
int check_arr[9];
int location;
for(int i=0; i<81; i+=9){
// check rows
for(int j=0; j<9; ++j)
check_arr[j] = map[i+j];
check_result =
checkUnique(check_arr);
if(check_result == false)
return false;
}
for(int i=0; i<9; ++i){
// check columns
for(int j=0; j<9; ++j)
check_arr[j] = map[i+9*j];
check_result =
checkUnique(check_arr);
if(check_result == false)
return false;
}
for(int i=0; i<9; ++i){
// check cells
for(int j=0; j<9; ++j) {
location = 27*(i/3) +
3*(i%3) +9*(j/3) + (j%3);
check_arr[j] = map[location];
}
check_result ==
checkUnique(check_arr);
if(check_result == false)
return false;
}
return true;
}
bool solve(int question[])
{
int firstZero;
int map[SUDOKU_SIZE];
firstZero = getFirstZeroIndex(question);
if(firstZero == -1) {
// end condition
if(isCorrect(question))
{
//answer = question;
for(int i=0; i<SUDOKU_SIZE; i++)
ans[i] = question[i];
return true;
}
else
return false;
}
else {
// copy question[] to map[]
for(int i=0; i<SUDOKU_SIZE; i++)
map[i] = question[i];
for(int num=1; num<=9; ++num)
{
map[firstZero] = num;
if(solve(map))
return true;
}
return false;
}
}