#include <iostream>
#include <string>
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

void fill_functions(){
	for(int i = 0; i < 31; i++){
		January[i] = "--";
		March[i] = "--";
		May[i] = "--";
		July[i] = "--";
		August[i] = "--";
		October[i] = "--";
		December[i] = "--";
	}
	for(int i = 0; i < 30; i++){
		April[i] = "--";
		June[i] = "--";
		September[i] = "--";
		November[i] = "--";
	}
	for(int i = 0; i < 28; i++){
		February[i] = "--";
	}
}

string inside(int month, int day, string msg, bool insert){
	if(month == 1 && day <= 30){
		if(insert){
			January[day] = msg;
		}
		return January[day];
	}
	if(month == 2 && day <= 27){
		if(insert){
			February[day] = msg;
		}
		return February[day];
	}
	if(month == 3 && day <= 30){
		if(insert){
			March[day] = msg;
		}
		return March[day];
	}
	if(month == 4 && day <= 29){
		if(insert){
			April[day] = msg;
		}
		return April[day];
	}
	if(month == 5 && day <= 30){
		if(insert){
			May[day] = msg;
		}
		return May[day];
	}
	if(month == 6 && day <= 29){
		if(insert){
			June[day] = msg;
		}
		return June[day];
	}
	if(month == 7 && day <= 30){
		if(insert){
			July[day] = msg;
		}
		return July[day];
	}
	if(month == 8 && day <= 30){
		if(insert){
			August[day] = msg;
		}
		return August[day];
	}
	if(month == 9 && day <= 29){
		if(insert){
			September[day] = msg;
		}
		return September[day];
	}
	if(month == 10 && day <= 30){
		if(insert){
			October[day] = msg;
		}
		return October[day];
	}
	if(month == 11 && day <= 29){
		if(insert){
			November[day] = msg;
		}
		return November[day];
	}
	if(month == 12 && day <= 30){
		if(insert){
			December[day] = msg;
		}
		return December[day];
	}
	else{
		return "na";
	}
}

void nextweek(int month, int day){
    for(int i = 0; i < 7; i++){
		if(inside(month, day - 1, "", false) == "na"){
        	month += 1;
        	day = 1;
			if(month > 12){
				month = 1;
			}
        }
		printf("\n%d/%d ", month, day);
		if(!(inside(month, day - 1, "", false) == "--")){
			printf("\"%s\"", inside(month, day - 1, "", false).c_str());
		}
		day += 1;
    }
	cout << endl;
}

int main(){
	fill_functions();
	int month;
	char slash;
	int day;
	string input;
	int choice;
    printf("Welcome to the schedule maker!\n");
    printf("Please enter your dates in a "
            "month/day format only using numbers\n");
	while(true){
		printf("\n1) Look at your schedule\n"
			   "2) Put something in your schedule\n"
			   "3) Check if anything is scheduled in the following week\n"
			   "4) I'm done\n");
		cin >> choice;
		if(choice == 1){
			printf("\nWhat day would you like to look at? ");
			cin >> month >> slash >> day;
			day -= 1;

			if(inside(month, day, "", false) == "na"){
				printf("\nThat is not a valid day.\n");
				sleep(1);
			}

			else if(inside(month, day, "", false) == "--"){
				printf("There is nothing scheduled here, "
                       "would you like to add something? (yes/no) ");
				cin >> input;
				if(input == "yes"){
					printf("Put your message here: ");
					cin.ignore();
					getline(cin, input);
					inside(month, day, input, true);
				}
			}

			else{
				printf("\"%s\"", inside(month, day, "", false).c_str());
                cout << endl;
				sleep(2);
			}
		}
		if(choice == 2){
			printf("\nWhat day would you like to schedule? ");
			cin >> month >> slash >> day;
			day -= 1;

			if(inside(month, day, "", false) == "na"){
				printf("That is not a valid day.\n");
				sleep(1);
			}

			else if(inside(month, day, "", false) == "--"){
				printf("Put your message here: ");
				cin.ignore();
				getline(cin, input);
				inside(month, day, input, true);
			}
			else{
				int choice2 = 5;
				printf("There is already something scheduled here\n"
					   "1) Replace\n"
					   "2) View\n");
				cin >> choice2;
                cout << endl;
				if(choice2 == 1){
					printf("Put your message here: ");
					cin.ignore();
					getline(cin, input);
					inside(month, day, input, true);
				}
				else{
					printf("\"%s\"", inside(month, day, "", false).c_str());
                    cout << endl;
					sleep(2);
				}
			}
		}
		if(choice == 3){
            printf("Which date would you like to check from? ");
            cin >> month >> slash >> day;
            if(inside(month, day - 1, "", false) == "na"){
                printf("This is not a valid day.\n");
            }
			else{
                printf("Here are your schedueled items for that week:\n");
                nextweek(month, day);
            }
		}
		if(choice == 4){
			return 0;
		}
	}
	return 0;
}
