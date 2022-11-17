package Arrays;

import java.util.*;

// import java.util.ArrayList;
// import java.util.Set;


/*
 * 
 * . . .    . . .    . . . 
 * . . .    . . .    . . . 
 * . . .    . . .    . . .  
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */





class Solution {

  public boolean isValidSudoku(char[][] board) {
    ArrayList<HashSet<Integer>> rows = new ArrayList<HashSet<Integer>>(); 
    ArrayList<HashSet<Integer>> cols = new ArrayList<HashSet<Integer>>(); 
    ArrayList<HashSet<Integer>> boxes = new ArrayList<HashSet<Integer>>(); 


    for(int i =0 ;i < 9; i++)
    {
      rows.add(new HashSet<Integer>());
      cols.add(new HashSet<Integer>());
      boxes.add(new HashSet<Integer>());
    }


    for (int i =0 ; i< board.length; i++)
    {
      for ( int j=0; j< board[0].length; j++)
      {
        if(board[i][j] == '.')
          continue;

        int num = board[i][j] - '0';
        int box_posn = (i/3)*3 + j/3;
        
        if(rows.get(i).contains(num) || cols.get(j).contains(num) || boxes.get(box_posn).contains(num))
          return false;
        
          rows.get(i).add(num); 
          cols.get(j).add(num);
          boxes.get(box_posn).add(num);
      }
    }

    return true;    
  }
}


// 00 01 02 30
// 10 11 12
// 20 21 22 23


// 0/3