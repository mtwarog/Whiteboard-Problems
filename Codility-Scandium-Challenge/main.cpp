#include<iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

int firstOddGlobal = 0;
int lastOddGlobal = 0;

void showArray(vector<int> &table, int size) {
	for (int i = 0; i < size; i++) {
		cout << table[i];
		cout << ", ";
	}
}

bool binaryArray(vector<int> &A, int N) { // converts number array into binary even/odd array
	lastOddGlobal = N -1;
	int counter = 0;

	for (int i = 0; i < N; i++)
		if (A[i] & 1) { 
			A[i] = 1;
			counter++;
		}
		else
			A[i] = 0;

	while (!(A[firstOddGlobal] & 1))
		firstOddGlobal++;
	while (!(A[lastOddGlobal] & 1))
		lastOddGlobal--;

	if (counter & 1)
		return false;
	else
		return true;
}

int * fromRightCheck(vector<int> &A, int N) {
	static int *Ret = new int[2];
	Ret[0] = -1;
	Ret[1] = -1;

	int j = lastOddGlobal;
	int K = 0;
	int S = 0;

	for (int i=j+1; i < N; i++) // suma ciagu z prawej
		S++;

	cout << "Right S: " << S << "\n"; //DELETE

	if (S == 0) { // sytuacja np, np1 lub n
		if (N != 1) {
			Ret[0] = 0;
			Ret[1] = j-1;
		}
		return Ret;
	}
	if (2*S + 1 >= N) 
		return Ret;

	for (int i = 0; i <= S; i++) {
		K = 1;
		for (int k = j - S + i; k < j; k++) 
			if (A[k] & 1) {
				K = 0;
				break;
			}
		if (K == 1)
			for (int k = 0; k < i; k++)
				if (A[k] & 1) {
					K = 0;
					break;
				}
		if (K == 1) {
			Ret[0] = i;
			Ret[1] = j - S + i -1;
			break;
		}
	}

	return Ret;
}

int * fromLeftCheck(vector<int> &A, int N) {
	static int *Ret = new int[2];
	Ret[0] = -1;
	Ret[1] = -1;

	int j = firstOddGlobal;
	int K = 0;
	int S = 0;

	for (int i=0; i < j; i++) // suma ciagu z lewej
		S++;

	cout << "Left S: " << S << "\n"; //DELETE

	if (S == 0) { // sytuacja np, np1 lub n
		if (N != 1) {
			Ret[0] = j + 1;
			Ret[1] = N - 1;
		}
		return Ret;
	}
	if (2*S + 1 >= N) 
		return Ret;

	for (int i = 0; i <= S; i++) {
		K = 1;
		for (int k = N - S + i; k < N; k++) 
			if (A[k] & 1) {
				K = 0;
				break;
			}
		if (K == 1)
			for (int k = j + 1; k < j + 1 + i; k++)
				if (A[k] & 1) {
					K = 0;
					break;
				}
		if (K == 1) {
			Ret[0] = j + 1 + i;
			Ret[1] = N - S + i -1;
			break;
		}
	}

	return Ret;
}

string solution(vector<int> &A) { // returns first move of wining strategy 
	int *retL, *retR;
	int N = A.size();

	if (N == 0)  // obsluga bledow
		return "NO SOLUTION";
	for (int i = 0; i < N; i++)
		if (A[i] <= 0)
			return "NO SOLUTION";

	

	
	//showArray(A, N); // DELETE
	
	const clock_t begin_time1 = clock();
	if (binaryArray(A, N)) {// converts number array into binary even/odd array
		std::stringstream ss;
		ss << "0," << N-1;
		std::string s = ss.str();
		return s; // if there are even number of odd numbers the whole A array should be returned
	}
	std::cout << "\n" << "binaryArray: " << float( clock () - begin_time1 ) /  CLOCKS_PER_SEC << "\n";

	cout << "\n"; // DELETE
	//showArray(A, N); // DELETE
	cout << "\n"; // DELETE

	cout << "firstOddGlobal: " << firstOddGlobal << "\n"; // DELETE
	cout << "lastOddGlobal: " << lastOddGlobal << "\n"; // DELETE
	
	const clock_t begin_time2 = clock();
	retR = fromRightCheck(A, N);
	std::cout << "\n" << "fromRightArray: " << float( clock () - begin_time2 ) /  CLOCKS_PER_SEC << "\n";
	cout << "Passed right\n"; // DELETE
	const clock_t begin_time3 = clock();
	retL = fromLeftCheck(A, N);
	std::cout << "\n" << "fromLeftArray: " << float( clock () - begin_time3 ) /  CLOCKS_PER_SEC << "\n";
	cout << "Passed left\n"; // DELETE

	cout << "Right: " << retR[0] << ", " << retR[1]; // DELETE
	cout << "\n"; // DELETE
	cout << "Left: " << retL[0] << ", " << retL[1]; // DELETE

	std::stringstream ss;
	if ((retL[0] == -1 || retL[1] == -1) && (retR[0] == -1 || retR[1] == -1))
		ss << "NO SOLUTION";
	else {
		if ((((retL[0] < retR[0]) || (retL[0] == retR[0] && retL[1] < retR[1])) && (retL[0] != -1) && (retL[1] != -1)) || ((retR[0] == -1) && (retR[1] == -1)))
			ss << retL[0] << "," << retL[1];
		else 
			ss << retR[0] << "," << retR[1];
	}
	std::string s = ss.str();

	return s;
}
	
int main(){
	//int B[] = {2, 1, 2, 2, 2, 1, 2, 1, 2};
	//int B[] = {2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 2};
	//int N = 9;

	vector<int> myVector;
	srand((unsigned)time(NULL));
	//int a = rand() % 100000 + 1; //1 to 100,000   
	int a = 100000;
	int b = 0;
	for (int i =0; i < a; i++){
        if (i < 25000)
			b = 2*(rand() % 500000000 + 100000000);
		else 
			if (i > 75000)
				b = 2*(rand() % 500000000 + 100000000);
			else
				b = (rand() % 1000000000 + 100000000);
        myVector.push_back(b);
    }

	//std::vector<int> A(B, B + sizeof B / sizeof B[0]);
	string ret;
	//ret = solution(A);
	ret = solution(myVector);
	cout << "\n";
	cout << ret;
	cout << "\n";
	system("PAUSE");
	return 0;
}