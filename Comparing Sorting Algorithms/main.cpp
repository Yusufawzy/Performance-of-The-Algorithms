#include<bits/stdc++.h>
#include "QuickSorter.h"
#include "SelectionSorter.h"
#include "ShellSorter.h"
#include "sorter.h"
#include "Testbed.h"
using namespace std;
int main()
{
    Sorter<int> *shell = new ShellSorter<int>;
    SelectionSorter<int> *select = new SelectionSorter<int>;
    QuickSorter<int> *quick = new QuickSorter<int>;

 	Testbed Test;

 	cout<<"Shell sort --  Random Generated Set "<<endl;
    Test.RunExperiment(shell, 0, 1, 1000000, 0, 10000, 100, 500);
   cout<<"Shell sort --  Reversed Ordered Set "<<endl;
    Test.RunExperiment(shell, 1, 1, 1000000, 0, 10000, 100, 500);


    cout<<"Selection sort --  Random Generated Set "<<endl;
   Test.RunExperiment(select, 0,  1, 1000000, 0, 10000, 100, 500);
    cout<<"Selection sort --  Reversed Ordered Set "<<endl;
    Test.RunExperiment(select, 1,  1, 1000000, 0, 10000, 100, 500);


   cout<<"Quick sort --  Random Generated Set "<<endl;
    Test.RunExperiment(quick, 0,  1, 1000000, 0, 10000, 100, 500);
    cout<<"Quick sort --  Reversed Ordered Set "<<endl;
    Test.RunExperiment(quick, 1, 1, 1000000, 0, 10000, 100, 500);

 	//cout<<Test.RunAndAverage(shell,true,0,100,50,10);
 	//RunExperiment(Sorter<int>* sorter, bool type, int min, int max, int min_val, int max_val, int sets_num, int step)
 	//RunAndAverage(Sorter* sorter, int type, int min, int max, int size, int sets_num) {
	cout << endl;
	return 0;
}

