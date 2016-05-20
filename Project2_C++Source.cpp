#include<iostream>
#include<cmath> 

using namespace std;

// UDF to get the four scores and calculates average and standard deviation
// Returns all 6 parameters
void calculate_scores(double& S1, double& S2, double& S3, double& S4, double& Avg, double& Std_Deviation); 

// UDF to get user input for the four scores
// Returns all 4 parameters
void get_input(double& Score1, double& Score2, double& Score3, double& Score4); 

// UDF to find minimum and maximum using four scores from the function that called it
// Returns only the minimum and maximum
void get_min_max(double S1, double S2, double S3, double S4, double& Min, double& Max); 

// UDF to order the scores from the function that called it 
// Display only. Nothing is returned
void order_scores(double S1, double S2, double S3, double S4);  

// UDF to swap values
// The new values are returned
void swap_values(double& value1, double& value2);  

// UDF to format the results for highest and lowest score, the average, and the standard deviation
// Display only.  Nothing is returned
void show_results(double Min, double Max, double Avg, double Std_Dev);

int main ()
{ 
	// Declare variables
	char ans; //  used for do while loop	 
	double score1, score2, score3, score4, min, max, average, std_deviation; 


	do 
	{ 

		// Retrieves user input and calculates the average and standard deviation
		calculate_scores(score1, score2, score3, score4, average, std_deviation);

		

		// Find the lowest and highest numbers
		get_min_max(score1, score2, score3, score4, min, max); 
		
		
		// Sets the precision to tenths 
		cout.setf(ios::fixed); 
		cout.setf(ios::showpoint); 
		cout.precision(1);

		// Display the scores in the order they were entered
		cout  << "\n For the scores " << score1 << ", " << score2 << ", " << score3 
			<< ", and " << score4 << ": "<<endl << endl;

		// Display the scores in order
		order_scores(score1, score2, score3, score4); 

		// Displays the lowest score, highest score, the average and standard deviation
		show_results(min, max, average, std_deviation); 
		
		cout << "Would you like to run the program again? \n"
			<< " (Type Y for yes): "; 

		// User lets the program know if they would like to run again
		cin >> ans; 

		// Formats a new line between runs
		cout << endl; 
	} while (ans == 'Y' or  ans == 'y'); 
	// end do while loop if ans does not equal Y or y 
	// Program will terminate if any other character or integer is entered

	// return 0 to main
	return 0; 
} 

//  Function definitions for the UDF declared above main
void calculate_scores(double& S1, double& S2, double& S3, double& S4, double& Avg, double& Std_Deviation)
{
	// call UDF get input and return 4 scores
	get_input (S1, S2, S3, S4); 

	// calculates the average
	Avg = (S1 + S2 + S3 + S4)/4; 

	// calculates the standard deviation
	Std_Deviation = sqrt((pow((S1-Avg), 2)+ pow((S2-Avg), 2)+ pow((S3-Avg), 2) + 
                              pow((S4-Avg), 2))/4);  
} 

void get_input(double& Score1, double& Score2, double& Score3, double& Score4)
{
	// request input from user
	cout <<"\nEnter four scores. Please round to the nearest tenth.\n"
		<<"Don't forget to put a space between the scores: "; 

	// user input for the four scores
	cin >> Score1 >> Score2 >> Score3 >> Score4;  
	
	// all four scores are returned 
	return; 
} 

void get_min_max(double S1, double S2, double S3, double S4, double& Min, double& Max)
{ 

	// If S1 is the lowest number then Min is assigned the value of S1
	if(S1 <= S2 and S1 <= S3 and S1 <= S4)
		Min = S1; 

	// If S2 is the lowest number then Min is assigned the value of S2
	else if (S2 <= S1 and S2 <= S3 and S2 <= S4)
		Min = S2; 

	// If S3 is the lowest number then Min is assigned the value of S3
	else if (S3 <= S1 and S3 <= S2 and S3 <= S4)
		Min = S3; 
	
	// If all above Booleans are false then S4 must be the lowest number
	// Min is assigned the value of S4
	else 
		Min = S4; 


	// If S1 is the highest number then Max is assigned the value of S1
	if (S1 >= S2 and S1 >= S3 and S1 >= S4)
		Max = S1; 
	
	// If S2 is the highest number then Max is assigned the value of S2
	else if (S2 >= S1 and S2 >= S3 and S2 >= S4)
		Max = S2; 

	// If S3 is the highest number then Max is assigned the value of S3
	else if (S3 >= S1 and S3 >= S2 and S3 >= S4)
		Max = S3; 
	
	// If all above Booleans are false then S4 must be the highest number
	// Max is assigned the value of S4
	else 
		Max = S4;

} 

void order_scores(double S1, double S2, double S3, double S4)
{
	
	//Check to see if S1 is greater than S2, S3 and then S4
	//If S1 is greater than any of these then swap the values
	if(S1 > S2) 
		swap_values(S1, S2); 

	if(S1 > S3) 
		swap_values(S1, S3); 

	if(S1 > S4) 
		swap_values(S1, S4);

	//Check to see if S2 is greater than S3 and then S4
	//If S1 is greater than any of these then swap the values
	//Do not need to check S1.  S1 is already the lowest number
	if(S2 > S3) 
		swap_values(S2, S3); 

	if(S2 > S4) 
		swap_values(S2, S4); 

	//Check to see if S3 is greater than S4 
	//If S3 is greater than S4 then swap the values
	//Do not need to check S1 and S2 they are already in order
	if(S3 > S4) 
		swap_values(S3, S4); 

		//The values have been switched and the scores are now in order
		cout.setf(ios::fixed); 
		cout.setf(ios::showpoint); 
		cout.precision(2);

	    //shows the scores in order
		cout << "The Scores in order are " << S1
			 << ", " << S2 << ", " << S3 << ", " << S4 << endl;

		return; 
} 

void swap_values(double& value1, double& value2)
{ 
	// Declare a temporary place holder
	double temp; 

	// swap the values
	temp = value1;    // temp = value1
	value1 = value2; // value1 now equals value2
	value2 = temp;    // value2 now equals temp (which was holding value1) 
}

void show_results(double Min, double Max, double Avg, double Std_Dev)
{ 
	// Sets the precision to hundreths 
	cout .setf(ios::fixed); 
	cout .setf(ios::showpoint); 
	cout .precision(2);

	// displays the lowest score, highest score, average and standard deviation
	cout << "Your highest score was " << Max << " and your lowest score was " << min << endl  
		<< "The mean is " << Avg  << " and the standard deviation is " << Std_Dev
		<<endl <<endl; 

	// Display only nothing is returned
}
