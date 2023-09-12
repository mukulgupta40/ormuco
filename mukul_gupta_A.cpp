#include<iostream>
using namespace std;

int main(){
	
	 int x1, x2, x3, x4;
	 cout<<"Enter coordinates of line 1";
	 cin>>x1>>x2;
	 cout<<"Enter coordinates of line 2";
	 cin>>x3>>x4;
	 
	 
	 //checking if the lines overlap 
	 //check if max of startpoints <= min of endpoints

	 if(max(x1, x3) <= min(x2, x4)){
	 	cout<<"They Overlap\n";
	 }else{
	 	cout<<"They don't Overlap\n";
	 }
	 
	 return 0;
	
}
