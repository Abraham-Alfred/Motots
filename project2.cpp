#include <iostream> 
#include <stdlib.h>
#include "E101.h"

using namespace std;

bool is_Red(double r,double g,double b){
	if( 7/3*b < r && 
		7/3*g < r && 
		   90 < r   )
	{
		return true;
	}
	return false;
}

int main(){
	int err;
    err = init(0);
    open_screen_stream();
    
	int w = 320;
	int h = 240;
	int a_horiz = 48;
	int a_verti = 48;
	int col_hist [320];
	int row_hist [240];
    int count = 0;
	
	while(count<1000){ //till goes off screen
    int row_max = 0;
	int row_max_index = -1;
	int col_max = 0;
	int col_max_index = -1;
	
	take_picture();
	
	
	for(int col = 0; col < w; col++){
		col_hist[col] = 0;
	}	
	
	for(int row = 0; row < h; row++){
			row_hist[row] = 0;
	}	
	
	for(int row = 0; row < h; row++ ){
		for(int col = 0; col < w; col++) {
			double r = get_pixel(row, col, 0);
			double g = get_pixel(row, col, 1);
			double b = get_pixel(row, col, 2);
			
			if(is_Red(r,g,b)){
				col_hist[col]++;
				row_hist[row]++;
				set_pixel(row,col,0,0,0);
			} else{
				set_pixel(row,col,255,255,255);
			}
		}
	}
    update_screen();
     
	for(int row = 0; row < h; row++){
		if(row_hist[row] > row_max){
			row_max = row_hist[row];
			row_max_index = row;	
		}
	}
	
	for(int col = 0; col < w; col++){
		if(col_hist[col] > col_max){
			col_max = col_hist[col];
			col_max_index = col;	
		}
	}

	int error_verti = (row_max_index - 120);
	int error_horiz = (col_max_index - 160);
		
	if(error_horiz > 5){
		a_horiz = a_horiz + 1;	
	}
	
	if(error_horiz < -5){
		a_horiz = a_horiz - 1;	
	}
	
	if(error_verti > 5){
		a_verti = a_verti + 1;	
	}
	
	if(error_verti < -5){
		a_verti = a_verti - 1;	
	}
	
	cout<<a_verti<<" "<<a_horiz<<endl;
	cout<<error_verti<<" "<<error_horiz<<endl;
	set_motors(5,a_verti);
	set_motors(1,a_horiz);
	hardware_exchange();
	sleep1(500);
	count++;
 }
}
