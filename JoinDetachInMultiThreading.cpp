#include<iostream>
#include<chrono>
#include<thread>

using namespace std;

// join() : once a thread is started we wait for the thread to finish by calling join()
// double join() will result into program termination

void run()
{
	int x = 10;
	while (x-- > 0)
	{
		cout << x << " cpp\n";
	}
	std::this_thread::sleep_for(chrono::seconds(3));
}

//JOIN
//int main()
//{
//	thread T1(run);
//	cout << "Main()\n"; // since T1 is taking time it has printed main()
//	T1.join(); // the thread will wait for 3 sec for its completion. 
//	// T1.join(); //double join will not give you compilation error. but will throw system error while execution.
//	cout << "Main_out";
//	return 0;
//}

//DETACH
/* Try this code with and without 3 sec sleep time.
   Detach will suspend the thread from execution
*/
int main()
{
	thread T1(run);
	cout << "main" << endl;
	T1.detach();
	cout << "main after" << endl;
	std::this_thread::sleep_for(chrono::seconds(3));
	return 0;
}