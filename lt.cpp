 #include <iostream>
#include "E101.h"

using namespace std;

int main()
{
  int err;
  cout<<" Hello"<<endl;
  err = init(0);
  cout<<"After init() error="<<err<<endl;
  
  int count = 0;
  open_screen_stream();
  while(count < 500)
  {
	 set_motors(1,48);
	 set_motors(5,48);
	 hardware_exchange();
	 take_picture();
	 update_screen();
	 sleep1(510);
	 set_motors(1,55);
	 set_motors(5,55);
	 hardware_exchange();
	 take_picture();
	 update_screen();
	 sleep1(510);
 
       count++;
       cout<<count<<endl;
    }
    close_screen_stream();
    stoph();
	
	return 0;
}
