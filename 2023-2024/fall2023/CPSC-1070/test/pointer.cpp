#include <iostream>
#include <string>

using namespace std;

void edit (string* [2]);

int main(){

  string list [4] = {"sus", "baka", "pog", "ligma"};
  
  string* point [2] = {&list[0], &list[1]};
  string* l [5];
  
  cout <<"p1: " << *point[0] << " p2: " << *point[1] <<endl;

  edit(point);

  cout <<"changed p1: " << *point[0] << " changed p2: " << *point[1] <<endl;
  //cout <<"l1: " << l[0] << " l2: "<<l[1]<<endl;
  
  edit(point);

  cout <<"changed p1: " << *point[0] << " changed p2: " << *point[1] <<endl;
  //cout <<"l1: " << l[0] << " l2: "<<l[1]<<endl;

}

void edit(string* items [2]){
  static int count = 0;

  if(count == 0){
  *items[0] = "l rizz";
  *items[1] = "w rizz";
  
  } else {
    *items[0] = "fortnite";
    items[1] = items[0];
  }
  count++;
}
