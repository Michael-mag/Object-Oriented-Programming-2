/*
    CH08-320143
    a4_p2.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de

    Loto
*/

  #include<bits/stdc++.h>

  using namespace std;

  int main(int argc, char const *argv[]) {
    int draw;

    srand(time(0)); //seed rand with currrent time

    //set<> imported from #include<set>
    //set inhibits duplication
    set<int> winner;
    set<int>::const_iterator next;

    //Actual Draw
    do{
      draw = rand() % 49+1;
      winner.insert(draw);
    }while(winner.size()!=6);

    //printing in ascending order
    cout<<endl<<endl<<"Draws in ascending order : "<<endl;
    for(next = winner.begin(); next != winner.end(); next++){
      cout<<*next<<" ";//using insert sorts the data in ascending order by default
    }
    cout<<endl<<endl;

    return 0;
  }
