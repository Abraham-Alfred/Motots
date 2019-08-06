#include <iostream>
#include <stdlib.h>
#include "E101.h"

using namespace std;

int main()
{
  int err;
  cout<<" Hello"<<endl;
  err = init(0);
  cout<<"After init() error="<<err<<endl;
  char fn[5] = {'b','a','t', '0','0'};
  open_screen_stream();
  int i =0;
  int k = 48;
  int k1 =48;
  while( i < 99){
	 take_picture();
	 fn[3]  = static_cast<char>(k1);
	 fn[4] =  static_cast<char>(k);
	 printf(" %d  %d  %s\n",k,k1, fn);
	 save_picture(fn);

	 k = k+1;
	 if(k > 57){
		 k=48;
		 k1 = k1 + 1;
	 }
	 //save_picture(fn);
	 update_screen();
	 sleep1(50);
	 i++;
 }

    close_screen_stream();
    stoph();
	
	return 0;
}
