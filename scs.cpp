/* Student name:- Aparna Bhat
   University :- University of Texas at Arlington
   This program has been coded in c++ 
   Execution command:- g++ scs.cpp -o scs.o
   ./scs.o
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;


int flag = 0;


int calcOverlappingPair(string s1, string s2, string& str)
{

	int max = INT_MIN;
	int m = s1.length();
	int n = s2.length();

	// check suffix of s1 matches with prefix of s2
	for (int i = 1; i <= min(m, n); i++)
	{

		if (s1.compare(m - i, i, s2, 0, i) == 0)
		{
			if (max < i)
			{

				max = i;
				str = s1 + s2.substr(i);
				//cout << s1 << endl;
				//cout << s2 << endl;
			}
		}
	}

	// check prefix of s1 matches with suffix of s2
	for (int i = 1; i <= min(m, n); i++)
	{

		if (s1.compare(0, i, s2, n - i, i) == 0)
		{
			if (max < i)
			{

				max = i;
				str = s2 + s1.substr(i);
			}
		}
	}

	return max;
}


string calculateShortestSuperstring(vector<string> arr)	// no const, no-ref
{
	int n = arr.size();

	std::vector<string> temp = arr;
	std::vector<string> result;

	int maxArray[temp.size() - 1];
	int m = 0;

	int indexes[temp.size()];
	int k = 0;



	// run n-1 times to consider every pair
	while (n != 1)
	{
		// to store  maximum overlap
		int max = INT_MIN;

		// to store array index of strings involved in maximum overlap
		int p, q;

		// to store resultant string after maximum overlap
		string res_str;

		for (int i = 0; i < n; i++)
		{


			for (int j = i + 1; j < n; j++)
			{
				string str;

				// r will store maximum length of the matching prefix and
				// suffix. str is passed by reference and store the result
				// string after maximum overlap of arr[i] and arr[j], if any
				int r = calcOverlappingPair(arr[i], arr[j], str);

				// check for maximum overlap
				if (max < r)
				{
					max = r;
					res_str.assign(str);
					p = i, q = j;
					//cout << arr[i] << endl;
				}




			}


		}

		maxArray[m] = max;
		m++;

		flag = 1;

		//cout << arr[p] << endl;
		//cout << arr[q] << endl;

		indexes[k] = p;
		indexes[k + 1] = q;
		k = k + 2;

		//result.push_back(temp[p]);
		//result.push_back(temp[q]);

		//cout << arr[0] << endl ;




		// ignore last element in next cycle
		n--;

		// if no overlap, append arr[n] to arr[0]
		if (max == INT_MIN)
		{
			arr[0] += arr[n];
			//cout << arr[0] << endl ;
		}
		else
		{
			// copy resultant string to index p
			//cout << arr[p] << endl ;
			//cout << arr[q] << endl ;
			arr[p] = res_str;

			// copy string at last index to index q
			arr[q] = arr[n];
			//cout << arr[p] << endl ;
			//cout << arr[q] << endl ;
		}

		//cout << arr[0] << endl;


	}

	/*for(int i = 0 ; i < sizeof(indexes)/sizeof(indexes[0]) ; i++)
	{
		cout << indexes[i] << endl ;
	}*/

	for (int i = 0; i < sizeof(indexes) / sizeof(indexes[0]); i++)
	{
		int count = maxArray[i];
		int spaceCount = temp[indexes[i]].size() - count;
		for (int k = 0; k < spaceCount; k++)
		{
			cout << " ";
		}
		cout << temp[indexes[i]] << endl;
	}

	/*for (int i = 0 ; i < result.size() ; i++)
		{
			if(temp[i] == temp[p])
			{
				cout << temp[i] << endl;
				for ( int j = i+1 ; j < arr.size() ; j ++)
				{
					if (temp[j] == temp[q])
					{
						cout << temp[j] << endl;
					}
				}
			}
		}*/

		/*for (int i = 0 ; i < result.size() ; i++)
		{
			cout << result[i] << endl;
		}*/

		//cout << arr[p] << endl;
		//cout << arr[q] << endl;

	return arr[0];
}

// Shortest Superstring Problem
int main()
{
	int n;
	int i;
	string str;

	//vector<string> arr = { "1001001", "100102", "0010010", "110010" };
	vector<string> input;
	cout << "Please enter number of lines (not more than 100)" << endl;
	cin >> n;
	while (n > 100)
	{

		cout << "input lines cannot be greater than 100 . Please re-enter" << endl;
		cin >> n;

	}
	cout << "Please enter the strings one per line " << endl;
	for (i = 0; i < n; i++)
	{
		cin >> str;
		while (str.length() > 50)
		{
			cout << "String length should not exceed 50 . please reenter this string " << endl;
			cin >> str;
		}
		input.push_back(str);
	}

	/*for(i = 0 ; i < n ; i++)
	{
		cout << input[i] << endl;
	}*/



	string scs = calculateShortestSuperstring(input);

	cout << "The Shortest Superstring is " << scs << endl;
	cout << "Length is : " << scs.length() << endl;

	return 0;
}
