/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Student record manager

     COMP9024 17s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "studentRecord.h"
#include "studentLL.h"

void printHelp();
void StudentLinkedListProcessing();

int main(int argc, char *argv[]) {
   if (argc == 2) {
      int i, n = atoi(argv[1]), totalCredits = 0;
      float totalWAM = 0, wWAM = 0;      
      studentRecordT *s = malloc(n * sizeof(studentRecordT));
      assert(s != NULL);      
      for (i = 0; i < n; i++) {
         printf("Enter student ID: ");
         s[i].ID = readValidID();
         printf("Enter Credit points: ");
         s[i].Credits = readValidCredits();
         totalCredits += s[i].Credits;
         printf("Enter WAM: ");
         s[i].WAM = readValidWAM();
         totalWAM += s[i].WAM;
      }
      
      for (i = 0; i < n; i++) {
         printStudentData(s[i].ID, s[i].Credits, s[i].WAM);
      }
      printf("Average WAM: %.3f\n", totalWAM/n);
      for (i = 0; i < n; i++) {
         wWAM += ((float)s[i].Credits/totalCredits*s[i].WAM);
      }
      printf("Weighted average WAM: %.3f\n", wWAM);      
   } else {
      StudentLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void StudentLinkedListProcessing() {
   int op, ch;
   int ID, Credits, n;
   float WAM, averageWAM, wWAM;
   
   List list = newLL();   // create a new linked list
   
   while (1) {
      printf("Enter command (a,f,g,p,q, h for Help)> ");

      do {
         ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
         ch = getchar();
      }

      switch (op) {

         case 'a':
         case 'A':
            printf("Enter student ID: ");
	        int zid = readValidID();
		    printf("Enter credit points: ");
		    int cr = readValidCredits();
			printf("Enter WAM: ");
		    float wam = readValidWAM();
			insertLL(list, zid, cr, wam);
        break;

         case 'f':
         case 'F':
            int ID = readValidID();
            inLL(list, ID);
            /*** Insert your code for finding a student record ***/

        break;
        
         case 'g':
         case 'G':
            getStatLL(list, &n, &averageWAM, &wWAM);
            printf("Number of records: %d\n", n);
            printf("Average WAM: %.3f\n", averageWAM);
            printf("Average weighted WAM: %.3f\n", wWAM);
            /*** Insert your code for getting statistical information ***/

        break;
        
         case 'h':
         case 'H':
            printHelp();
        break;
        
         case 'p':
         case 'P':
            showLL(list);
            /*** Insert your code for printing all student records ***/

        break;

     case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
        printf("Bye.\n");
        return;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" A - Add student record\n" );
   printf(" F - Find student record\n" );
   printf(" G - Get statistics\n" );
   printf(" H - Help\n");
   printf(" P - Print all records\n" );
   printf(" Q - Quit\n");
   printf("\n");
}
