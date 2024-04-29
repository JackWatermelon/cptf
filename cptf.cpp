#include <iostream>
#include <string>
#include <unistd.h>
#include <utility>
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

string January_t[31];
string February_t[28];
string March_t[31];
string April_t[30];
string May_t[31];
string June_t[30];
string July_t[31];
string August_t[31];
string September_t[30];
string October_t[31];
string November_t[30];
string December_t[31];


void fill_functions(){
    for(int i = 0; i < 31; i++){
        January[i] = "--";
        March[i] = "--";
        May[i] = "--";
        July[i] = "--";
        August[i] = "--";
        October[i] = "--";
        December[i] = "--";

        January_t[i] = "--";
        March_t[i] = "--";
        May_t[i] = "--";
        July_t[i] = "--";
        August_t[i] = "--";
        October_t[i] = "--";
        December_t[i] = "--";
    }
    for(int i = 0; i < 30; i++){
        April[i] = "--";
        June[i] = "--";
        September[i] = "--";
        November[i] = "--";

        April_t[i] = "--";
        June_t[i] = "--";
        September_t[i] = "--";
        November_t[i] = "--";
    }
    for(int i = 0; i < 28; i++){
        February[i] = "--";
        February_t[i] = "--";
    }
}

pair<string, string> inside(int month, int day, string msg, string time, bool insert){
    if(month == 1 && day <= 30){
        if(insert){
            January[day] = msg;
            January_t[day] = time;
        }
        return make_pair(January[day], January_t[day]);
    }
    if(month == 2 && day <= 27){
        if(insert){
            February[day] = msg;
            February_t[day] = time;
        }
        return make_pair(February[day], February_t[day]);
    }
    if(month == 3 && day <= 30){
        if(insert){
            March[day] = msg;
            March_t[day] = time;
        }
        return make_pair(March[day], March_t[day]);
    }
    if(month == 4 && day <= 29){
        if(insert){
            April[day] = msg;
            April_t[day] = time;
        }
        return make_pair(April[day], April_t[day]);
    }
    if(month == 5 && day <= 30){
        if(insert){
            May[day] = msg;
            May_t[day] = time;
        }
        return make_pair(May[day], May_t[day]);
    }
    if(month == 6 && day <= 29){
        if(insert){
            June[day] = msg;
            June_t[day] = time;
        }
        return make_pair(June[day], June_t[day]);
    }
    if(month == 7 && day <= 30){
        if(insert){
            July[day] = msg;
            July_t[day] = time;
        }
        return make_pair(July[day], July_t[day]);
    }
    if(month == 8 && day <= 30){
        if(insert){
            August[day] = msg;
            August_t[day] = time;
        }
        return make_pair(August[day], August_t[day]);
    }
    if(month == 9 && day <= 29){
        if(insert){
            September[day] = msg;
            September_t[day] = time;
        }
        return make_pair(September[day], September_t[day]);
    }
    if(month == 10 && day <= 30){
        if(insert){
            October[day] = msg;
            October_t[day] = time;
        }
        return make_pair(October[day], October_t[day]);
    }
    if(month == 11 && day <= 29){
        if(insert){
            November[day] = msg;
            November_t[day] = time;
        }
        return make_pair(November[day], November_t[day]);
    }
    if(month == 12 && day <= 30){
        if(insert){
            December[day] = msg;
            December_t[day] = time;
        }
        return make_pair(December[day], December_t[day]);
    }
    else{
        return make_pair("na","na");
    }
}

int nextweek(int month, int day, pair<string,string> result){
    int time = 0;
    for(int i = 0; i < 7; i++){
        result = inside(month, day, "", "", false);
        if(result.first == "na" || result.second == "na"){
            month += 1;
            day = 1;
            if(month > 12){
                month = 1;
            }
        }
        printf("\n%d/%d ", month, day);
    pair<string, string> result = inside(month, day - 1, "", "", false);
    if(!(result.first == "--" || result.second == "--")){
            printf("\"%s\"", result.first.c_str());
            time += 1;
        }
        day += 1;
    }
    cout << endl;
    return time;
}


bool validtime(int time){

    int hours = time/100;
    int minutes = time%100;

    if(hours > 0 && hours <= 12 && minutes >= 0 && minutes <= 59){
        return true;
    }
    else{
        return false;
    }
    return false;
}

string add_time(int time, string choice3, bool validtime){

    if(validtime == true){
            if (time <= 959){
                if(choice3 == "AM" || choice3 == "am"){
                    string time_str = to_string(time);
                    time_str.insert(1, ":");
                    time_str.insert(4, "AM");
                    return time_str;
                }
                else if(choice3 == "PM" || choice3 == "pm"){
                    string time_str = to_string(time);
                    time_str.insert(1, ":");
                    time_str.insert(4, "PM");
                    return time_str;
                }
                else{
                    return "INVALID TIME OF DAY";
                }
            }
            else if(time <= 1259){
                if(choice3 == "AM" || choice3 == "am"){
                    string time_str = to_string(time);
                    time_str.insert(2, ":");
                    time_str.insert(5,"AM");
                    return time_str;
                }
                else if(choice3 == "PM" || choice3 == "pm"){
                    string time_str = to_string(time);
                    time_str.insert(2,":");
                    time_str.insert(5,"PM");
                    return time_str;
                }
                else{
                    return"INVALID TIME OF DAY";
                }
            }
            else{
                return "INVAILD TIME";
            }

        }
    else if(validtime == false){
        return "NONREAL TIME";
    }

return "SOMETHING WENT WRONG WRONG";
}

int main(){
    fill_functions();
    int time;
    int month;
    char slash;
    int day;
    string input;
    int choice;
    bool bool_time;
    string schedule_t;
    string choice3;
    pair<string, string> result;
    printf("Welcome to the schedule maker!\n");
    printf("Please enter your dates in a "
            "month/day format only using numbers. Ex: 12/25\n");
    printf("Also please enter your time as a whole number."
           "Ex: 200 == 2:00 ");
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

            result = inside(month, day, "", "", false);
            if(result.first == "na" || result.second == "na"){
                printf("\nThat is not a valid day.\n");
                sleep(1);
            }
            result = inside(month, day, "", "", false);
            if(result.first == "--" || result.second == "--"){
                printf("There is nothing scheduled here, " 
                "would you like to add something? (yes/no) ");
                cin >> input;
            }
                if(input == "yes"){

                    printf("Put your message here: ");
                    cin.ignore();
                    getline(cin, input);

                    printf("Put a time here: ");
                    printf("AM or PM: ");
                    cin >> choice3;
                    printf("Add a time: ");
                    cin >> time;
                    bool_time = validtime(time);
                    schedule_t = add_time(time, choice3, bool_time);
                    result = inside(month, day, input, schedule_t, true);

                }
                if(input == "no"){
                    cout << "ok :(";
                }
                else{
                    cout << " \" " <<  result.first << " \" " << endl;
                    sleep(1);
                    cout << "Time that was set " <<  result.second << "." << endl;
                    sleep(2);
                }
            }

        if(choice == 2){
            printf("\nWhat day would you like to schedule? ");
            cin >> month >> slash >> day;
            day -= 1;

            result = inside(month, day, "", "", false);
            if(result.first == "na" || result.second == "na"){
                printf("\nThat is not a valid day.\n");
                sleep(1);
            }
            result = inside(month, day, "", "", false);
            if(result.first == "--" || result.second == "--"){
                printf("There is nothing scheduled here, "
                "would you like to add something? (yes/no) ");
                cin >> input;
            }

            if(result.first == input || result.second == schedule_t){
                int choice2 = 0;
                printf("There is already something scheduled here\n"
                "1) Replace\n"
                "2) View\n");
                cin >> choice2;
                cout << endl;
                if(choice2 == 1){
                    printf("Put your message here: ");
                    cin.ignore();
                    getline(cin, input);

                    printf("Put a time here: ");
                    printf("AM or PM: ");
                    cin >> choice3;
                    printf("Add a time: ");
                    cin >> time;

                    bool_time = validtime(time);
                    schedule_t = add_time(time, choice3, bool_time);

                    result = inside(month, day, input, schedule_t, true);
                }
                else{
                    cout <<  " \" " << result.first << " \" " << endl;
                    sleep(1);
                    cout << "Time that was set " <<  result.second << "." << endl;
                    sleep(2);
                }
            }


            if(input == "yes"){

                printf("Put your message here: ");
                cin.ignore();
                getline(cin, input);

                printf("Put a time here: ");
                printf("AM or PM: ");
                cin >> choice3;
                printf("Add a time: ");
                cin >> time;

                bool_time = validtime(time);
                schedule_t = add_time(time, choice3, bool_time);
                    
                result = inside(month, day, input, schedule_t, true);
                }

            if(input == "no"){
                cout << ":(";
            }


        }
        if(choice == 3){
            printf("Which date would you like to check from? ");
            cin >> month >> slash >> day;
            result = inside(month, day, "", "", false);
            if(result.first == "na" || result.second == "na"){
                printf("\nThat is not a valid day.\n");
            }
            else{
                printf("Here are your schedueled items for that week:\n");
                sleep(nextweek(month, day, result));
            }
        }
        if(choice == 4){
            break;
       }
    }
return 0;
}






