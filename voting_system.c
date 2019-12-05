/*

	voting_system.c

    Task:

	https://scontent.fbeg7-1.fna.fbcdn.net/v/t1.15752-9/79090088_2557402667827007_2246587501504364544_n.png?_nc_cat=108&_nc_ohc=xZavIJ8pweYAQn3PHIaGRv8ABXRuOaKcynjHDGpEKfnjyw5JEMRdJ4RPw&_nc_ht=scontent.fbeg7-1.fna&oh=25240f9c364557059e776852ea1a58e4&oe=5E6D8BE6

	https://scontent.fbeg7-1.fna.fbcdn.net/v/t1.15752-9/79265770_727426401076495_1186445090151727104_n.jpg?_nc_cat=102&_nc_ohc=u5LhbMTsrI0AQmzd4xCRDWs-sRAjnfppZhWvfn6vJZUjcvn7VFDBbpB_w&_nc_ht=scontent.fbeg7-1.fna&oh=397d73147916bc2933a6a402c108385e&oe=5E72C34E



	You can find all my C programs at Dragan Milicev's pastebin:

	https://pastebin.com/u/dmilicev

*/

#include <stdio.h>
#include <string.h>


// fill the bank of 10 users names and their passwords
void fill_users_names_and_passwords( char users_names_arr[10][20], char users_pass_arr[10][20] )
{
	int i;

	for( i=0; i<10; i++)
	{
		sprintf( users_names_arr[i], "User%d", i );
		sprintf( users_pass_arr[i],  "pass%d", i );
	}

/*	// or
	strcpy( users_names_arr[0], "User0" );
	strcpy( users_pass_arr[0],  "pass0" );

	strcpy( users_names_arr[1], "User1" );
	strcpy( users_pass_arr[1],  "pass1" );

	strcpy( users_names_arr[2], "User2" );
	strcpy( users_pass_arr[2],  "pass2" );

	strcpy( users_names_arr[3], "User3" );
	strcpy( users_pass_arr[3],  "pass3" );

	strcpy( users_names_arr[4], "User4" );
	strcpy( users_pass_arr[4],  "pass4" );

	strcpy( users_names_arr[5], "User5" );
	strcpy( users_pass_arr[5],  "pass5" );

	strcpy( users_names_arr[6], "User6" );
	strcpy( users_pass_arr[6],  "pass6" );

	strcpy( users_names_arr[7], "User7" );
	strcpy( users_pass_arr[7],  "pass7" );

	strcpy( users_names_arr[8], "User8" );
	strcpy( users_pass_arr[8],  "pass8" );

	strcpy( users_names_arr[9], "User9" );
	strcpy( users_pass_arr[9],  "pass9" );
*/
} // fill_users_names_and_passwords()


void fill_candidates_names_arr( char Mayor_name_arr[3][20],     int Mayor_vote_arr[3],
								char V_Mayor_name_arr[3][20],   int V_Mayor_vote_arr[3],
								char Secretary_name_arr[3][20], int Secretary_vote_arr[3],
								char Treasurer_name_arr[3][20], int Treasurer_vote_arr[3] )
{
	int i;

	strcpy( Mayor_name_arr[0], "Maria" );
	strcpy( Mayor_name_arr[1], "Jose" );
	strcpy( Mayor_name_arr[2], "Xhi" );

	for( i=0; i<3; i++)			// reset votes
		Mayor_vote_arr[i] = 0;

	strcpy( V_Mayor_name_arr[0], "Estella" );
	strcpy( V_Mayor_name_arr[1], "Agnes" );
	strcpy( V_Mayor_name_arr[2], "Marley" );

	for( i=0; i<3; i++)			// reset votes
		V_Mayor_vote_arr[i] = 0;

	strcpy( Secretary_name_arr[0], "Janinen" );
	strcpy( Secretary_name_arr[1], "Ariel" );
	strcpy( Secretary_name_arr[2], "Gerard" );

	for( i=0; i<3; i++)			// reset votes
		Secretary_vote_arr[i] = 0;

	strcpy( Treasurer_name_arr[0], "Jenalyn" );
	strcpy( Treasurer_name_arr[1], "Rhea" );
	strcpy( Treasurer_name_arr[2], "Marife" );

	for( i=0; i<3; i++)			// reset votes
		Treasurer_vote_arr[i] = 0;

} // fill_candidates_names_arr()


void display_candidates_and_votes( char Mayor_name_arr[3][20],     int Mayor_vote_arr[3],
								   char V_Mayor_name_arr[3][20],   int V_Mayor_vote_arr[3],
								   char Secretary_name_arr[3][20], int Secretary_vote_arr[3],
								   char Treasurer_name_arr[3][20], int Treasurer_vote_arr[3] )
{
	int i;

	printf("\n List of all candidates and their votes: \n");

	printf("\n Mayor \n");
	for(i=0;i<3;i++)
		printf("\n %d. %s \t %d ", i+1, Mayor_name_arr[i], Mayor_vote_arr[i] );

	printf("\n\n Vice - Mayor \n");
	for(i=0;i<3;i++)
		printf("\n %d. %s \t %d ", i+1, V_Mayor_name_arr[i], V_Mayor_vote_arr[i] );

	printf("\n\n Secretary \n");
	for(i=0;i<3;i++)
		printf("\n %d. %s \t %d ", i+1, Secretary_name_arr[i], Secretary_vote_arr[i] );

	printf("\n\n Treasurer \n");
	for(i=0;i<3;i++)
		printf("\n %d. %s \t %d ", i+1, Treasurer_name_arr[i], Treasurer_vote_arr[i] );


	printf("\n");

} // display_candidates_and_votes()


void display_candidates( char text[], char name_arr[3][20] )
{
	int i;

	printf("%s", text);

	for(i=0;i<3;i++)
		printf("\n %d. %s ", i+1, name_arr[i] );

	printf("\n");

} // display_candidates()


void display_all_candidates( char Mayor_name_arr[3][20],
						     char V_Mayor_name_arr[3][20],
							 char Secretary_name_arr[3][20],
							 char Treasurer_name_arr[3][20] )
{
	display_candidates("\n Mayor:\n", Mayor_name_arr );

	display_candidates("\n V_Mayor:\n", V_Mayor_name_arr );

	display_candidates("\n Secretary:\n", Secretary_name_arr );

	display_candidates("\n Treasurer:\n", Treasurer_name_arr );
} // display_all_candidates()


// return 1 if in bank exist user_name and user_pass, otherwise return 0
int exist_in_bank( char users_names_arr[10][20], char users_pass_arr[10][20],
				 char user_name[20], char user_pass[20] )
{
	int i, exist=0;

	for( i=0; i<10; i++)
	{
		if( strcmp(users_names_arr[i],user_name)==0 && strcmp(users_pass_arr[i],user_pass)==0 )
			exist = 1;				// 1 if user_name and user_pass exists in bank
	}

	return exist;

} // exist_in_bank()


// returns 1 on success, otherwise returns 0 (for more than 3 attempts)
int user_login( char user_name[20], char user_pass[20],
			    char users_names_arr[10][20], char users_pass_arr[10][20] )
{
	int number_of_login_attempts = 0;
	int end = 0;

	while( !end && number_of_login_attempts<=2 )
	{
		number_of_login_attempts++;		// count user number_of_login_attempts

		// Enter user login name
		printf("\n\n Enter user login name: ");
		scanf( "%s", user_name );

		// Enter user login password
		printf("\n Enter user login password: ");
		scanf( "%s", user_pass );

		if( exist_in_bank(users_names_arr, users_pass_arr, user_name, user_pass) )
			end = 1;
		else
			printf("\n Wrong data. Try %d more times \n", 3 - number_of_login_attempts );
	}

	return end;

} // user_login()


// returns 0 if user voted for first candidate
// returns 1 if user voted for second candidate
// returns 2 if user voted for third candidate
int get_vote( void )
{
	int num = 0;

	while ( !num )
	{
		printf("\n Enter the number of candidate you are voting for :  ");
		scanf("%d", &num );

		if ( num < 1 || num > 3 )
		{
			printf("\n Vote must be 1, 2 or 3.  Try again ! \n");
			num = 0;
		}
	}

	return (num-1);

} // get_vote()


void vote( char Mayor_name_arr[3][20],     int Mayor_vote_arr[3],
		   char V_Mayor_name_arr[3][20],   int V_Mayor_vote_arr[3],
		   char Secretary_name_arr[3][20], int Secretary_vote_arr[3],
		   char Treasurer_name_arr[3][20], int Treasurer_vote_arr[3] )
{
	display_candidates("\n Mayor candidates \n", Mayor_name_arr );	// display candidates
	Mayor_vote_arr[ get_vote() ]++;				// we are increasing the number of votes

	display_candidates("\n V_Mayor candidates \n", V_Mayor_name_arr );	// display candidates
	V_Mayor_vote_arr[ get_vote() ]++;			// we are increasing the number of votes

	display_candidates("\n Secretary candidates \n",  Secretary_name_arr );	// display candidates
	Secretary_vote_arr[ get_vote() ]++;			// we are increasing the number of votes

	display_candidates("\n Treasurer candidates \n",  Treasurer_name_arr );	// display candidates
	Treasurer_vote_arr[ get_vote() ]++;			// we are increasing the number of votes

} // vote()


// return -1 if no one is elected because of equal number of votes
// return  0 if first  candidate is elected
// return  1 if second candidate is elected
// return  2 if third  candidate is elected
int elected( char name_arr[3][20], int vote_arr[3] )
{
	int i, max, index, number_of_the_same_votes=0;

	max = vote_arr[0];			// suppose the first candidate has the highest number of votes
	index = 0;					// we remember his index in array

	for( i=1; i<3; i++ )		// compare him to other two candidates
		if( max < vote_arr[i] )
		{
			max = vote_arr[i];	// then he has max votes
			index = i;			// we remember his index in array
		}

	for( i=0; i<3; i++ )		// count same votes
		if( max == vote_arr[i] )
			number_of_the_same_votes++;

	if( number_of_the_same_votes > 1 )
		return -1;				// no one is elected because of equal number of votes
	else
		return index;			// return array index of elected candidate

} // elected()


void display_result_of_voting( char Mayor_name_arr[3][20],     int Mayor_vote_arr[3],
							   char V_Mayor_name_arr[3][20],   int V_Mayor_vote_arr[3],
							   char Secretary_name_arr[3][20], int Secretary_vote_arr[3],
							   char Treasurer_name_arr[3][20], int Treasurer_vote_arr[3]  )
{
	int index;
	//char elected_candidate[20];

	printf("\n ______________________________________________________ \n\n");
	printf("\n \t\t\t List of Nominated Candidates \n\n");

	index = elected( Mayor_name_arr, Mayor_vote_arr );
	if ( index == -1 )
		printf("\n Mayor          :  %2d \t %s \n", index, "No one is elected because of same number of votes." );
	else
		printf("\n Mayor          :  %2d \t %s \n", Mayor_vote_arr[index], Mayor_name_arr[index] );

	index = elected( V_Mayor_name_arr, V_Mayor_vote_arr );
	if ( index == -1 )
		printf("\n Vice - Mayor   :  %2d \t %s \n", index, "No one is elected because of same number of votes." );
	else
		printf("\n Vice - Mayor   :  %2d \t %s \n", V_Mayor_vote_arr[index], V_Mayor_name_arr[index] );


	index = elected( Secretary_name_arr, Secretary_vote_arr );
	if ( index == -1 )
		printf("\n Secretary      :  %2d \t %s \n", index, "No one is elected because of same number of votes." );
	else
		printf("\n Secretary      :  %2d \t %s \n", Secretary_vote_arr[index], Secretary_name_arr[index] );


	index = elected( Treasurer_name_arr, Treasurer_vote_arr );
	if ( index == -1 )
		printf("\n Treasurer      :  %2d \t %s \n", index, "No one is elected because of same number of votes." );
	else
		printf("\n Treasurer      :  %2d \t %s \n", Treasurer_vote_arr[index], Treasurer_name_arr[index] );


	printf("\n\n Thank you for Voting !!! \n\n");

} // display_result_of_voting()



int main()
{
	char user_name[20];					// name of user who will vote
	char user_pass[20];					// pass of user who will vote

	char users_names_arr[10][20];		// bank of 10 users with their names long max 20 characters
	char users_pass_arr[10][20];		// bank of 10 passwords each long max 20 characters

	char Mayor_name_arr[3][20]; 		// 3 candidates names long max 20 characters
	char V_Mayor_name_arr[3][20];
	char Secretary_name_arr[3][20];
	char Treasurer_name_arr[3][20];

	int Mayor_vote_arr[3];				// 3 candidates and their int number of votes
	int V_Mayor_vote_arr[3];
	int Secretary_vote_arr[3];
	int Treasurer_vote_arr[3];

	int number_of_login_attempts = 0;
	int end = 0;						// flag 0-1
	int i;
	char ch;							// char for answer (Y / N)


	// initialize user names and passwords for 10 users
	fill_users_names_and_passwords( users_names_arr, users_pass_arr );

	// display users names and their passwords
	// (put in comment if you don't want to display this)
	for(i=0;i<10;i++)
		printf("\n users_names_arr[%d] = %s \t users_pass_arr[%d] = %s \n",
				i, users_names_arr[i], i, users_pass_arr[i] );

	// Initialize all candidates
	fill_candidates_names_arr( Mayor_name_arr,     Mayor_vote_arr,
							   V_Mayor_name_arr,   V_Mayor_vote_arr,
							   Secretary_name_arr, Secretary_vote_arr,
							   Treasurer_name_arr, Treasurer_vote_arr );
	while( !end )
	{
		if( user_login(user_name, user_pass, users_names_arr, users_pass_arr ) == 1 )
		{
			printf("\n ______________________________________________________ \n\n");
			printf("\n Welcome %s to Voting System: \n", user_name );

			vote( Mayor_name_arr,     Mayor_vote_arr,
				  V_Mayor_name_arr,   V_Mayor_vote_arr,
				  Secretary_name_arr, Secretary_vote_arr,
				  Treasurer_name_arr, Treasurer_vote_arr );

			printf("\n Next user (Y or N) :  ");

			ch = getch();

			if ( ch=='n' || ch=='N' )
				end = 1;
		}
		else
		{
			printf("\n Voting is interrupted by a total of three failed logins ! \n");
			end = 1;
		}
	}

	// display result of voting
	display_result_of_voting( Mayor_name_arr,     Mayor_vote_arr,
							  V_Mayor_name_arr,   V_Mayor_vote_arr,
							  Secretary_name_arr, Secretary_vote_arr,
							  Treasurer_name_arr, Treasurer_vote_arr  );

	// display all candidates names and their votes
	// (put in comment if you don't want to display this)
	display_candidates_and_votes( Mayor_name_arr,     Mayor_vote_arr,
							      V_Mayor_name_arr,   V_Mayor_vote_arr,
							      Secretary_name_arr, Secretary_vote_arr,
							      Treasurer_name_arr, Treasurer_vote_arr  );

    return 0;

} // main()
