/*
* hash table test file
* lindsey siegfried & emma steinman
* 6 november 2017
*/

#include <iostream>
#include <string>
#include <math.h>
#include <stdint.h>
#include <fstream>
using namespace std;


int hasher ( string s, int m )
{



  float lword = 0;
  float hval = 0;
  for ( int i = 0; i < s.length(); i++)
  {
    int code = ((int)s[i]);
    if (fmod(code, 3)==0)
      hval += fmod(pow(code, 3), 20);
    else if (fmod(code, 7) == 0)
    {
      code += 39;
      hval += fmod((pow(code, 4)*7), 27);
    }
    else if (fmod(code, 5) == 0)
      hval += floor(sqrt(pow(code, 3)));
    else
    {
      code += 29;
      hval += floor(pow((code*8), 2)*code);
    }
    lword += 1;
  }
  float conversions = hval;
  float A = (sqrt(5)-1)/2;
  float q = fmod((hval * A), 1);
  hval = floor(m * q);

  float divmeth = fmod(conversions, 983);
  float divmeth2 = fmod(conversions, 1109);
  float dmult = floor(divmeth * divmeth2);
  float what = dmult / lword;
  int pos = fmod((hval + what), m);
  if (pos == 0)
  {
    if ((fmod(conversions, 2)==0))
    {
      pos = fmod((pos + conversions) * 7, m);

    }
    else
    {
      pos = fmod(fmod(pos, conversions) *3, m);

    }

  }
  else if (pos < 0)
  {
    cout << pos << endl;
    pos = fmod(fabs(pos), m);
    cout << pos << endl;
  }
  return pos;

}


int main ( void )
{
  int m = 1000;
  ifstream ifile("words.txt");
  ofstream ofile("slots.csv");
  string line;
  while (getline(ifile, line))
  {
    int slt = hasher(line, m);
    ofile << line << "," << slt << "," << "\n";
  }

  ifile.close();
  ofile.close();

  return 0;
}
