# pd2-sudoku

give_question.cpp
  #include"Sudoku.h"
  int main(){
    Sudoku ss;
    ss.GiveQuestion();
    return 0;
  }

solve.cpp
  #include"Sudoku.h"
  int main(){
    Sudoku ss;
    ss.ReadIn();
    ss.Solve();
    return 0;
  }
  
Compile with makefile and excute by ./give_question and ./solve
