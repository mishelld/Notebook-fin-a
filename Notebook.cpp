#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace ariel;

 
    const int num = 100;
    const int num1 = 127;
    const int num2 = 200;

      void Notebook::write(int page,int row, int column, Direction h, string a){
         if(Map[page][row][column]=='~' || Map[page][row][column]== ' '){
              throw invalid_argument("there is already values there, write in other place\n");
          }
          if(page<0 || row<0 || column<0){
              throw invalid_argument("negetive value is not good\n");
          }
         
          if(column>num){
              throw invalid_argument("each row has only 100 chracters\n");
          }

          if(Direction::Horizontal== h){
               int f = a.size();
               int l = (int)column+f;
              if(l>num){
                   throw invalid_argument("each row has only 100 chracters\n");
              }
              int j = 0;
          for(unsigned int i = 0; i<a.length();i++,j++){
              //(Map[page][row][column+j]>0 && Map[page][row][column+j]<num1)
           if(Map[page][row][column+j]=='~' || Map[page][row][column+j]== ' '){
              throw invalid_argument("there is already values there, write in other place\n");
          }
          
          Map[page][row][column+j] = a.at(i);
          
          }
          }
          if(Direction::Vertical==h){
        int k = 0;
        for(unsigned int i = 0; i<a.length();i++,k++){
            //(Map[page][row+k][column]>0 && Map[page][row+k][column]<num1)
                    if(Map[page][row+k][column]=='~' || Map[page][row+k][column]==' '){
              throw invalid_argument("there is already values there, write in other place\n");
                    }
          Map[page][row+k][column] = a.at(i);
          
          }
          } 
      }
      string Notebook::read(int page, int row, int column, Direction v,  int length){
           if(page<0 || row<0 || column<0){
              throw invalid_argument("negetive value is not good\n");
          }
          if(column>num){
              throw invalid_argument("each row has only 100 chracters\n");
          }
           string s;
          
           if(Direction::Horizontal== v){
               if(column+length>num){
                   
                 throw invalid_argument("each row has only 100 chracters\n");
               }
          for(int i = 0; i<length;i++){
            if(Map[page][row][column+i]>0 && Map[page][row][column+i]<num1){
                   s +=Map[page][row][column+i];
                }
            else{
                   s += "_";
                  }
          }
          }
          if(Direction::Vertical==v){
              for(int i = 0; i<length;i++){
                if(Map[page][row+i][column]>0 && Map[page][row+i][column+i]<num1){
                   s += Map[page][row+i][column];
                   }
                else{
                   s += "_";
                    }
              }
      }
      return s;
      }
       void Notebook::erase(int page,int row, int column, Direction v,  int length){

            if(page<0 || row<0 || column<0){
              throw invalid_argument("negetive value is not good\n");
          }
          if(column>num){
              throw invalid_argument("each row has only 100 chracters\n");
          }
         if(Direction::Horizontal== v){
             if(column+length>num){
                 throw invalid_argument("each row has only 100 chracters\n");
          
             }

          for(int i = 0; i<=length;i++){
          Map[page][row][column+i] = '~';
          }
          }
          if(Direction::Vertical==v){
              for(int i = 0; i<=length;i++){
          Map[page][row+i][column] = '~';
          }
       }

       }
       void Notebook::show(int page){
       
           for(int i = 0;i<num2;i++){
               for(int j = 0;j<num;j++){
                   if((Map[page][i][j]>0 &&Map[page][i][j]<num1)){
                  cout<< Map[page][i][j];
                   }
                   else{
                     cout << "_";
                   }
               }
               cout<< endl;
            
           }
       }
       

       


    
