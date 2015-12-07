// bin sort using methods of chain
#include "studentRecord.h"
#include "chain.h"


void binSort(chain<studentRecord>& theChain, int range)
{// Sort by score.

   // initialize the bins
   chain<studentRecord> *bin;
   bin = new chain<studentRecord> [range + 1];

   // distribute student records from theChain to bins
   int numberOfElements = theChain.size();
   for (int i = 1; i <= numberOfElements; i++)
   {
      studentRecord x = theChain.get(0);
      theChain.erase(0);
      bin[x.score].insert(0,x);
   }

   // collect elements from bins
   for (int j = range; j >= 0; j--)
      while (!bin[j].empty())
      {
         studentRecord x = bin[j].get(0);
         bin[j].erase(0);
         theChain.insert(0,x);
      }

   delete [] bin;
}

int main(void)
{
   studentRecord s;
   chain<studentRecord> c;
   /*
   for (int i = 1; i <= 20; i++)
   {
      s.score = i/2;
      s.name = new string(s.score, 'a');
      c.insert(0,s);
   }
   */

   s.score = 1;
   s.name = new string ("John");
   c.insert (0, s);

   s.score = 2;
   s.name = new string ("Harry");
   c.insert(0, s);

   s.score = 10;
   s.name = new string("Nale");
   c.insert(0, s);

   s.score = 8;
   s.name = new string("Mike");
   c.insert(0, s);
   s.score = 1;
   s.name = new string("Shawn");
   c.insert(0, s);

   s.score = 8;
   s.name = new string("Jack");
   c.insert(0, s);
   cout << "The unsorted chain is" << endl;
   cout << "  " << c << endl;
   
   binSort(c,10);
   cout << "The sorted chain is" << endl;
   cout << "  " << c << endl;
   
}
