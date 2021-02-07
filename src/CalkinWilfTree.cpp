//A C++ program to print out number sequence in Calkin-Wilf tree to prove the contability of number set Q
#include <cstdio>
#include <cmath>

using namespace std;

#define ODD(i) ((i) % 2)
int power(int base, int exponent)
{
	int result = 1;
	for(int i = 0; i < exponent; ++i)
	{
		result *= base;
	}
	return result;
}

int main() {
	FILE *fileOutput = fopen("CalkinWilf.txt","w");
	int layer = 0;
	// Ensure valid input
	while(layer <= 0)
		scanf("%d",&layer);
	int tree_numerator[(int)power(2,layer)],tree_denominator[(int)power(2,layer)];
	// printf("%d\n",power(2,layer));

	

	// Constructing the Calkin-Wilf tree, in heap form
	int size = power(2,layer); // number of elements in the tree
	tree_numerator[1] = tree_denominator[1] = 1; // Initializing the first element in tree
	if(layer - 1)for(int i = 2; i < size; i *= 2)
	{
		for(int j = 0; j < i; ++j)
			{
				int parent = (i + j) / 2;
				printf("%d, %3d/%3d\n",parent,tree_numerator[parent],tree_denominator[parent]);
				if(!ODD(i+j)){ // all even number elements are left node
					tree_numerator[i+j] = tree_numerator[parent];
					tree_denominator[i+j] = tree_denominator[parent] + tree_numerator[parent];
				}
				else
				{ // all odd number elements are right note
					tree_numerator[i+j] = tree_numerator[parent] + tree_denominator[parent];
					tree_denominator[i+j] = tree_denominator[parent];
				}
	
			}
	}
	
	//Printing out elements in Calkin-Wilf tree
	for(int i = 1; i < size; ++i)
	{
		if(i > 1)fprintf(fileOutput, ", ");
		fprintf(fileOutput, "\\frac{%d}{%d}",tree_numerator[i],tree_denominator[i]);
		// fprintf(fileOutput, "%5d / %5d\n",tree_numerator[i],tree_denominator[i]);
	}
	fclose(fileOutput);
}
