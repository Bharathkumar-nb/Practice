#include <iostream> 
#include <cstdio>
#include <cmath> 

using namespace std; 

int count_duplicates(int inputArr[], int arrSize, int key)
{
	int low, high, mid;
  	int firstPtr = 0 , lastPtr = -1, tempFirstPtr, tempLastPtr;
  	bool foundKey = false;
  	low = 0;
  	high = arrSize -1;
  	
  	while(low <= high)
    {
      	mid = low + (high - low)/2;
        //cout << "\nmid = " << mid << " low : " << low << " high :" << high << endl;
      	if(key < inputArr[mid])
        {
        	high = mid-1;
        }
      	else if(key > inputArr[mid])
        {
        	low = mid + 1;
        }
      	else
        {

          	if(!foundKey)
            {
              	lastPtr = mid;
                tempFirstPtr = mid;
              	tempLastPtr = high;
              	foundKey = true;
            }
            //cout << foundKey << endl;
          	firstPtr = mid;
          	high = mid - 1;
      	}
    }
    
  	while(tempFirstPtr <= tempLastPtr)
    {
      	mid = tempFirstPtr + ceil((tempLastPtr - tempFirstPtr)/2);
      	if(key < inputArr[mid])
        {
        	tempLastPtr = mid-1;
        }
      	else if(key > inputArr[mid])
        {
        	tempFirstPtr = mid + 1;
        }
      	else
        {
          	lastPtr = mid;
          	tempFirstPtr = mid + 1;
      	}
    }
  	cout << "\nlow : " << firstPtr << " high :" << lastPtr << endl;
  return lastPtr - firstPtr + 1;
}

int main()
{   
    int testcases;
  	int inputArr[100];
  	int arrSize, key;
  	int i, j;
  
  	cin >> testcases;
  	for(i=0; i<testcases; ++i)
    {
    	cin >> arrSize >> key;
      	j = 0;
      	for(j=0; j<arrSize; ++j)
        {
        	cin >> inputArr[j];
        }
      	cout << count_duplicates(inputArr, arrSize, key) << endl;
    }
} 
