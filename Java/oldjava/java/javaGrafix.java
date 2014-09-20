/*
Programming Project 1
CSC 15, Spring 2014, 3/19/2014
Written by: Class ID 1486(or 7426)
This program replicates the "Cafe Wall" optical illusion
as seen on Project 3G.5 of the textbook.
*/



import java.awt.*;
public class Proj5 {
   /*Draws the various rows and grids*/ 
   public static void main(String[] args) { 
      DrawingPanel panel=new DrawingPanel(650,400);
      Graphics g = panel.getGraphics();
      panel.setBackground(Color.GRAY);   
      drawRow(g,0,0,20,4);
      drawRow(g,50,70,30,5);
      drawGrid(g,10,150,25,4,4,0);
      drawGrid(g,250,200,25,3,3,10);
      drawGrid(g,425,180,20,5,5,10);
      drawGrid(g,400,20,35,2,2,35);
     
     
     
   }
   /*Draws the black and white box pair*/
   public static void drawPair(Graphics g, int x, int y, int size){
      g.setColor(Color.BLACK);
      g.fillRect(x,y,size,size);
      g.setColor(Color.BLUE);
      g.drawLine(x,y,x+(size-1),y+(size-1));
      g.drawLine(x,y+(size-1),x+(size-1),y);
      g.setColor(Color.WHITE);
      g.fillRect(x+size,y,size,size);
   }
   /*Draw the pairs in rows*/
   public static void drawRow(Graphics g, int x, int y, int size, int numPairs){
      for (int i=0;i<=numPairs-1;i++){
         drawPair(g,x+(i*2*size),y,size);
      }
   }
   /*Draws row pairs with the second x-coordinate offset 
     and sets the y coordinate through each iteration*/
   public static void drawGrid(Graphics g, int x, int y, int size, int numHPairs,int numVPair, int offset){
      for (int i=1;i<=numVPair;i++){
            drawRow(g,x,y,size,numHPairs);
            drawRow(g,x+offset,y+2+size,size,numHPairs);
            y+=2*size+4;       
      }

    }
    
}
