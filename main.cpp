#include <iostream>
#include <fstream>

using namespace std;

struct bothRegions
{
    string name;
    string surname;
    int pin;

    bothRegions *next;
};
typedef bothRegions *REG;

 REG findPrev(REG first, bothRegions Reg);
 void addNode(REG &first, REG &last, bothRegions Reg);


int main()
{
    ifstream fin("input.txt");

    int n,m,k;

    REG first=NULL, last=NULL;
    bothRegions Reg;


    fin>>m>>n;


   for(int i=0;i<m;i++)
    {
        fin>>Reg.name>>Reg.surname>>Reg.pin;
addNode(first, last, Reg);
    }
fin>>k;
    for(int z=0; z<k; z++)
    {
        fin>>Reg.name>>Reg.surname>>Reg.pin;
addNode(first, last, Reg);
    }

    cout<<"Third: ";


   REG t=first;
    for(int s=0; s<=n+4; s++)
      t=t->next;

  cout<<t->name<<" "<<t ->surname<<" "<<t ->pin<<endl;


    return 0;
}
REG findPrev(REG first, bothRegions Reg)
{

    while(first->next->pin > Reg.pin)
    {
        first= first->next;
    }

    return first;
}

void addNode(REG &first, REG &last, bothRegions Reg)
{
    REG node;
    node= new(bothRegions);
    node->name=Reg.name;
    node->surname = Reg.surname;


    node ->pin = Reg.pin;

    if(first==NULL)
    {
        first=node;
        last=node;
    }
    else if( node->pin>=first->pin)
    {
        node->next=first;
        first=node;
    }
    else if(node->pin < last->pin)
    {
        last->next= node;
        last=node;
    }
    else{

        REG prev;
        prev=findPrev(first, Reg);
        node->next=prev->next;
        prev->next= node;
    }

}