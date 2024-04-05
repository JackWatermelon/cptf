#include <iostream>
#include <unistd.h>
using namespace std;

string January[31];
string February[28];
string March[31];
string April[30];
string May[31];
string June[30];
string July[31];
string August[31];
string September[30];
string October[31];
string November[30];
string December[31];

string inside(string month, int day, string msg, bool insert){
	if(month == "January" && day <= 30){
		if(insert){
			January[day] = msg;
		}
		return January[day];
	}
	if(month == "February" && day <= 27){
		if(insert){
			February[day] = msg;
		}
		return February[day];
	}
	if(month == "March" && day <= 30){
		if(insert){
			March[day] = msg;
		}
		return March[day];
	}
	if(month == "April" && day <= 29){
		if(insert){
			April[day] = msg;
		}
		return April[day];
	}
	if(month == "May" && day <= 30){
		if(insert){
			May[day] = msg;
		}
		return May[day];
	}
	if(month == "June" && day <= 29){
		if(insert){
			June[day] = msg;
		}
		return June[day];
	}
	if(month == "July" && day <= 30){
		if(insert){
			July[day] = msg;
		}
		return July[day];
	}
	if(month == "August" && day <= 30){
		if(insert){
			August[day] = msg;
		}
		return August[day];
	}
	if(month == "September" && day <= 29){
		if(insert){
			September[day] = msg;
		}
		return September[day];
	}
	if(month == "October" && day <= 30){
		if(insert){
			October[day] = msg;
		}
		return October[day];
	}
	if(month == "November" && day <= 29){
		if(insert){
			November[day] = msg;
		}
		return November[day];
	}
	if(month == "December" && day <= 30){
		if(insert){
			December[day] = msg;
		}
		return December[day];
	}
	else{
		return "bro";
	}
	return "inserted";
}

void nextweek(string month, int day){
    for(int i = 0; 7 > i; i++){
        if(!(inside(month, day+i, "", false) == "")){
            printf(inside(month, day,//
        }
    }
}

int main(){
	string month;
	int day;
	string input;
	int choice;
	while(true){
		printf("\n1) Look at you schedule\n"
			   "2) Put something in your schedule\n"
			   "3) Check if anything is scheduled in the following week\n"
			   "4) I'm done\n");
		cin >> choice;
		if(choice == 1){
			printf("What day would you like to look at? ");
			cin >> month >> day;
			day -= 1;

			if(inside(month, day, "", false) == "bro"){
				printf("\nThat is not a valid day.\n");
				sleep(1);
			}

			else if(inside(month, day, "", false) == ""){
				printf("There is nothing scheduled here, would you like to add something? (yes/no) ");
				cin >> input;
				if(input == "yes"){
					printf("Put your message here: ");
					cin.ignore();
					getline(cin, input);
					inside(month, day, input, true);
				}
			}

			else{
				cout << endl << '"' << inside(month, day, "", false) << '"' << endl;
				sleep(2);
			}
		}
		if(choice == 2){
			printf("\nWhat day would you like to schedule? ");
			cin >> month >> day;
			day -= 1;

			if(inside(month, day, "", false) == "bro"){
				printf("That is not a valid day.\n");
			}

			if(inside(month, day, "", false) == ""){
				printf("Put your message here: ");
				cin.ignore();
				getline(cin, input);
				inside(month, day, input, true);
			}
			else{
				int choice2;
				printf("There is already something scheduled here\n"
					   "1) Replace\n"
					   "2) View\n");
				cin >> choice2;
				if(choice2 == 1){
					printf("Put your message here: ");
					cin.ignore();
					getline(cin, input);
					inside(month, day, input, true);
				}
				else if(choice == 2){
					cout << endl << '"' << inside(month, day, "", false) << '"' << endl;
					sleep(2);
				}
				else{
					cout << "???" << endl;
				}
			}
		}
		if(choice == 3){
            printf("Which date would you like to check from?");
            cin >> month >> day;
			printf("Here are your schedueled items for that week");
            nextweek(month, day);
		}
		if(choice == 4){
			return 0;
		}
	}
	return 0;
}
