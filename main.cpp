/*
//main.cpp
//Patterns possible on a smartphone
//Author: Kuldeep Singh Sidhu

CONTACT
GitHub: github.com/singhsidhukuldeep
LinkedIn: linkedin.com/in/kuldeep-singh-sidhu-96a67170/
Facebook: facebook.com/singhsidhukuldeep
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;



void Gen(int x, vector <int> v, long long int &ctr, int *visited)
{
    //file opener for printing possible combinations
	//creating file
    ofstream ofopener;
	ofopener.open("results.txt",std::ofstream::app);
	ofopener.clear();


	int flag,l;

	visited[x]=1;
	v.push_back(x);
	l=v.size();

	//To check if the line segment connecting any two consecutive dots in the pattern passes through any other dots, then the other dots must have previously been in the pattern
	//To check the validity of the last pushed element in vector.
	flag=1;
  	if(l>1)
  	{
    	if(v[l-2]==0  && v[l-1]==2 && visited[1]==0)
        	flag=0;

        if(v[l-2]==0  && v[l-1]==6 && visited[3]==0)
         	flag=0;
        if(v[l-2]==0  && v[l-1]==8 && visited[4]==0)
         	flag=0;

        if(v[l-2]==2  && v[l-1]==0 && visited[1]==0)
         	flag=0;

        if(v[l-2]==2  && v[l-1]==6 && visited[4]==0)
         	flag=0;

        if(v[l-2]==2  && v[l-1]==8 && visited[5]==0)
         	flag=0;

        if(v[l-2]==6  && v[l-1]==0 && visited[3]==0)
        	flag=0;

        if(v[l-2]==6  && v[l-1]==2 && visited[4]==0)
        	flag=0;

        if(v[l-2]==6  && v[l-1]==8 && visited[7]==0)
        	flag=0;

        if(v[l-2]==8  && v[l-1]==2 && visited[5]==0)
        	flag=0;

        if(v[l-2]==8  && v[l-1]==0 && visited[4]==0)
        	flag=0;

        if(v[l-2]==8  && v[l-1]==6 && visited[7]==0)
        	flag=0;

        if(v[l-2]==1  && v[l-1]==7 && visited[4]==0)
        	flag=0;

        if(v[l-2]==7  && v[l-1]==1 && visited[4]==0)
        	flag=0;

        if(v[l-2]==3  && v[l-1]==5 && visited[4]==0)
        	flag=0;

        if(v[l-2]==5  && v[l-1]==3 && visited[4]==0)
        	flag=0;
    }

	if(flag==1)
    {
    	//To check If length>=4
    	if(l>3)
        {
			//Valid vector representing lock pattern sequence
        	ctr++;
			/*
			//Loop to print the valid lock patterns
        	cout<<ctr<<"		:	";
        	for(int i=0;i<l;i++)
        		cout<<v[i];
        	cout<<endl;
			*/

			//Loop to print in file results.txt
                    ofopener<<ctr<<"		:	";
                    for(int i=0;i<l;i++)
                        ofopener<<v[i];
                    ofopener<<endl;

        }

        //Recursive call to push next number in the vector
        for(int i=0;i<9;i++)
		{
			if(visited[i]==0)	//To ensure that the dots in the pattern must all be distinct.
				Gen(i,v,ctr,visited);
		}
    }

    //Backtrack
	visited[x]=0;
	v.pop_back();
	return;
}

int main()
{
	int visited[9];	//To check if a number is used in sequence
	vector <int> V;	//vector to store valid pattern sequence
	long long int ctr; //To keep count of valid lock patterns.


	//Initialization of visited array
	for(int i=0; i<9;i++)
		visited[i]=0;
	//Initialization of counter variable
	ctr=0;

	//Starting from first point as i
	for(int i=0; i<9;i++)
	{
		Gen(i,V,ctr,visited);
	}

	//output
	cout<<ctr<<endl;

  	return 0;
}
