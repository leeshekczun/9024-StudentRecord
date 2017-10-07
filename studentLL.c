#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "studentLL.h"
#include "studentRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
    studentRecordT data;
    struct node    *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;
   int   n;
   int   totalCredits;
   float totalWAM;
/* Add more fields if you wish */

} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity: O(1)
// Explanation: it takes constant time to initialize the struct
List newLL() {
   ListRep *s = malloc(sizeof(ListRep));
   assert(s != NULL);
   s -> head = NULL;
   s -> formerNode = NULL;
   s -> top = 0;
   return s; 
}

// Time complexity: O(n)
// Explanation: need to free every node within the linked list, so the 
// time it takes is proportional to the length
void dropLL(List listp) {
   NodeT *curr = listp->head;   
   while (curr != NULL) {
      NodeT *temp = curr->next;
      free(curr);
      curr = temp;
   }
   free(listp);
   
   return;
}

// Time complexity: O(n)
// Explanation: the zid might be located at the last node, forcing us to 
// search the whole linked list
void inLL(List listp, int zid) {
   NodeT *curr = listp->head;
   int numi = listp -> top;
   if (numi == 0) {
	  printf("No record found.\n");
   }
   while (curr != NULL) {
      if (curr->data.zID == zid) {
         printStudentData(curr->data.zID, curr->data.credits, curr->data.WAM);
         return;
      }
      NodeT *temp = curr->next;
      curr = temp;
   }
   printf("No record found.\n");
   
   return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: might need to search the whole linked list to determine 
// where the new node should be inserted
void insertLL(List listp, int zid, int cr, float wam) {
   NodeT *new = malloc(sizeof(NodeT));
   assert(new != NULL);
   
   new->data.zID = zid;
   new->data.credits = cr;
   new->data.WAM = wam;
   
   if (listp->head == NULL || listp->head->data.zID > zid) {
      new->next = listp->head;
      listp->head = new;
      listp->n++;
      listp->totalCredits += cr;
      listp->totalWAM += wam;
      printf("Student record added.\n");
      return;
   }
   else if (listp->head->data.zID == zid) {
      new->next = listp->head->next;
      listp->totalCredits = listp->totalCredits - listp->head->data.credits + cr;
      listp->totalWAM = listp->totalWAM - listp->head->data.WAM + wam;
      free(listp->head);
      listp->head = new;
      printf("Student record updated.\n");
      return;
   }
   
   NodeT *curr = listp->head;
   while (curr->next != NULL) {
      if (curr->next->data.zID > zid) {
         new->next = curr->next;
         curr->next = new;
         listp->n++;
         listp->totalCredits += cr;
         listp->totalWAM += wam;
         printf("Student record added.\n");
         return;
      }
      else if (curr->next->data.zID == zid) {
         new->next = curr->next->next;
         listp->totalCredits = listp->totalCredits - curr->next->data.credits + cr;
         listp->totalWAM = listp->totalWAM - curr->next->data.WAM + wam;
         free(curr->next);
         curr->next = new;
         printf("Student record updated.\n");
         return;
      }
      else {
         NodeT *temp = curr->next;
         curr = temp;
      }
   }
   
   new->next = NULL;
   curr->next = new;
   listp->n++;
   listp->totalCredits += cr;
   listp->totalWAM += wam;
   printf("Student record added.\n");
   
   return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: need to loop the whole linked list to calculate weighted 
// average WAM
void getStatLL(List listp, int *n, float *wam, float *w_wam) {
   float wWAM = 0;
   int numg = listp -> top;
   NodeT *curr = listp->head;
   while (curr != NULL) {
      wWAM += ((float)curr->data.credits/listp->totalCredits*curr->data.WAM);
      NodeT *temp = curr->next;
      curr = temp;
   }
   
   *n = listp->n;
   *wam = listp->totalWAM/listp->n;
   *w_wam = wWAM;
   return;
}

// Time complexity: O(n)
// Explanation: need to print the content of every node within the linked 
// list, so the time it takes is proportional to the length
void showLL(List listp) {
   NodeT *curr = listp->head;
   int nums = listp -> top;
   while (nums != 0 && curr != NULL) {
      printStudentData(curr->data.zID, curr->data.credits, curr->data.WAM);
      NodeT *temp = curr->next;
      curr = temp;
   }   
   return;
}
