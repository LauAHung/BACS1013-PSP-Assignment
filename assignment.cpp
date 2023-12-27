#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>
#include <regex>
#include <stdlib.h>
#include <random>
#define ANSI_GOLD "\033[48;5;220m"
#define ANSI_LIGHT_BLUE "\033[37m"
#pragma warning(disable : 4996)
#ifdef _WIN32
#include <Windows.h>
#endif
#define RESET   "\033[0m"
#define BG_BLUE    "\033[44m"
#define BG_CYAN    "\033[46m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BG_GREEN   "\033[42m"
#define BG_RED     "\033[41m"
#define BG_YELLOW  "\033[43m"
#define BG_GRAY  "\033[47m"
#define BOLDWHITE   "\033[1m\033[37m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

using namespace std;

int generateRandomNumber(int lowerBound, int upperBound) {
    random_device rd;  // Seed for the random number generator
    mt19937 gen(rd()); // Mersenne Twister engine
    uniform_int_distribution<int> distribution(lowerBound, upperBound); // Distribution

    return distribution(gen); // Generate a random number
}

void ticket_menu_page(const string& username, const string& password, const string& email, const string& phoneNumber);
void loginpage();
vector<pair<string, string>> bookedSeats;
const int numRows = 20;
const int numCols = 18;
const char emptySeat = ' ';
const char bookedSeat = 'X';
int seatID_p = 1;
int seatID_g = 1;
int seatID_s = 1;
char seat;

void displayDateTime() {
    // Define arrays for day names and month names
    const char* dayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    const char* monthNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    // Get the current time
    time_t currentTime = time(nullptr);

    // Use local time to extract day, date, and time components
    tm* localTime = localtime(&currentTime);

    // Display the current time, day, and date in the specified format
    cout << setfill('0') << setw(3) << left << dayNames[localTime->tm_wday] << " / "
        << setw(2) << localTime->tm_mday << " " << monthNames[localTime->tm_mon] << " "
        << setw(4) << localTime->tm_year + 1900 << " / "
        << setfill('0') << setw(2) << right << localTime->tm_hour << ":"
        << setfill('0') << setw(2) << right << localTime->tm_min << ":"
        << setfill('0') << setw(2) << right << localTime->tm_sec << endl;
}


void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setColor(int color) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#endif
}

void seat_categories_layout() {
    system("CLS");

#define RESET   "\033[0m"
#define BG_BLUE    "\033[44m"
#define BG_CYAN    "\033[46m"      
#define BOLDBLACK   "\033[1m\033[30m"
#define BG_GREEN   "\033[42m"    
#define BG_RED     "\033[41m"
#define BG_YELLOW  "\033[43m"  
#define BG_GRAY  "\033[47m"
#define BOLDWHITE   "\033[1m\033[37m" 

    cout << endl;
    cout << " Concert Seats Layout";
    cout << endl;
    cout << endl;
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                                                       " << RESET << endl;
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                         STAGE                         " << RESET << endl;
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                                                       " << RESET << endl;
    cout << endl;
    cout << setfill(' ') << setw(47) << BOLDBLACK << BG_RED << "          " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_RED << "                                                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_RED << "          " << RESET << endl;

    cout << setfill(' ') << setw(47) << BOLDBLACK << BG_RED << "          " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_RED << "                                                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_RED << "          " << RESET << endl;

    cout << setfill(' ') << setw(47) << BOLDBLACK << BG_RED << "          " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_RED << "                                                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_RED << "          " << RESET << endl;

    cout << setfill(' ') << setw(47) << BOLDWHITE << BG_RED << " PLATINUM " << RESET;
    cout << setfill(' ') << setw(11) << BOLDWHITE << BG_RED << "                        PLATINUM                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDWHITE << BG_RED << " PLATINUM " << RESET << endl;

    cout << setfill(' ') << setw(47) << BOLDBLACK << BG_RED << "          " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_RED << "                                                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_RED << "          " << RESET << endl;

    cout << setfill(' ') << setw(47) << BOLDBLACK << BG_RED << "          " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_RED << "                                                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_RED << "          " << RESET << endl;

    cout << setfill(' ') << setw(47) << BOLDBLACK << BG_RED << "          " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_RED << "                                                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_RED << "          " << RESET << endl;

    cout << endl;

    cout << setfill(' ') << setw(47) << BOLDWHITE << BG_GREEN << "          " << RESET;
    cout << setfill(' ') << setw(11) << BOLDWHITE << BG_GREEN << "                                                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDWHITE << BG_GREEN << "          " << RESET << endl;

    cout << setfill(' ') << setw(47) << BOLDBLACK << BG_GREEN << "          " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_GREEN << "                                                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_GREEN << "          " << RESET << endl;

    cout << setfill(' ') << setw(47) << BOLDBLACK << BG_GREEN << "          " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_GREEN << "                                                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_GREEN << "          " << RESET << endl;

    cout << setfill(' ') << setw(47) << BOLDWHITE << BG_GREEN << "   GOLD   " << RESET;
    cout << setfill(' ') << setw(11) << BOLDWHITE << BG_GREEN << "                        GOLD                           " << RESET;
    cout << setfill(' ') << setw(11) << BOLDWHITE << BG_GREEN << "   GOLD   " << RESET << endl;

    cout << setfill(' ') << setw(47) << BOLDBLACK << BG_GREEN << "          " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_GREEN << "                                                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_GREEN << "          " << RESET << endl;

    cout << setfill(' ') << setw(47) << BOLDBLACK << BG_GREEN << "          " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_GREEN << "                                                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_GREEN << "          " << RESET << endl;

    cout << setfill(' ') << setw(47) << BOLDBLACK << BG_GREEN << "          " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_GREEN << "                                                       " << RESET;
    cout << setfill(' ') << setw(11) << BOLDBLACK << BG_GREEN << "          " << RESET << endl;

    cout << endl;

    cout << setfill(' ') << setw(49) << BOLDBLACK << BG_YELLOW << "                                     " << RESET;
    cout << setfill(' ') << setw(10) << BOLDBLACK << BG_YELLOW << "                                     " << RESET << endl;

    cout << setfill(' ') << setw(49) << BOLDBLACK << BG_YELLOW << "                                     " << RESET;
    cout << setfill(' ') << setw(10) << BOLDBLACK << BG_YELLOW << "                                     " << RESET << endl;

    cout << setfill(' ') << setw(49) << BOLDWHITE << BG_YELLOW << "              STANDARD               " << RESET;
    cout << setfill(' ') << setw(10) << BOLDWHITE << BG_YELLOW << "              STANDARD               " << RESET << endl;

    cout << setfill(' ') << setw(49) << BOLDBLACK << BG_YELLOW << "                                     " << RESET;
    cout << setfill(' ') << setw(10) << BOLDBLACK << BG_YELLOW << "                                     " << RESET << endl;

    cout << setfill(' ') << setw(49) << BOLDBLACK << BG_YELLOW << "                                     " << RESET;
    cout << setfill(' ') << setw(10) << BOLDBLACK << BG_YELLOW << "                                     " << RESET << endl;

    cout << endl;
    cout << endl;
    cout << " Ticket Categories Price : " << endl;
    cout << endl;
    cout << setfill(' ') << setw(10) << BOLDWHITE << BG_RED << " PLATINUM ( ZONE A ) " << RESET << "  >>>> RM 799" << endl;
    cout << endl;
    cout << setfill(' ') << setw(10) << BOLDWHITE << BG_GREEN << "   GOLD ( ZONE B )   " << RESET << "  >>>> RM 599" << endl;
    cout << endl;
    cout << setfill(' ') << setw(10) << BOLDWHITE << BG_YELLOW << " STANDARD ( ZONE C ) " << RESET << "  >>>> RM 299" << endl;
    cout << endl;
}

void seating_layout() {
#define RESET   "\033[0m"
#define BG_BLUE    "\033[44m"

    cout << endl;
    cout << endl;
    cout << endl;
    cout << setw(14) << left << " " << setw(14) << right;
    cout << setw(14) << BG_BLUE << " " << RESET << setw(14) << right << endl;
    cout << endl;
    cout << endl;
}

// Function to print the seating layout
void printSeatingLayout_platinum(const vector<vector<char>>& seats, int numRows, int numCols) {
    system("CLS");
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                                                       " << RESET << endl;
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                       PLATINUM                        " << RESET << endl;
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                                                       " << RESET << endl;
    cout << endl;

    // Print each row
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (j == 0) {
                cout << setfill(' ') << setw(24) << RESET;
            }
            if (seats[i][j] == emptySeat && i <= 14) {

                if (j == 4 || j == 14) {
                    cout << "    ";
                }
                if (i >= 0 && i <= 6) {

                    if (j >= 0 && j <= numCols) {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
                        cout << "\033[32m[";
                        string category1 = "A";

                        string stringcolumn = to_string(seatID_p++);

                        string formattedColumn = "000" + stringcolumn;

                        formattedColumn = formattedColumn.substr(formattedColumn.length() - 3);

                        string combine_id_p = category1 + formattedColumn;

                        cout << combine_id_p << "]\033[0m";// Available seats
                    }
                }
                if (i >= 7 && i <= 15) {

                    if (j >= 0 && j <= numCols) {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << "[";
                        string category2 = "B";

                        string stringcolumn = to_string(seatID_g++);

                        string formattedColumn = "000" + stringcolumn;

                        formattedColumn = formattedColumn.substr(formattedColumn.length() - 3);

                        string combine_id_g = category2 + formattedColumn;

                        cout << combine_id_g << "]";// Available seats
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    }
                    if (i == 14 && j == 17) {
                        cout << endl;
                    }
                }


            }
            else if (seats[i][j] == emptySeat && i >= 15 && i <= numRows) {
                if (j == 0) {
                    seatID_p = 1;
                    seatID_s = 1;
                    seatID_g = 1;
                    cout << "          ";
                }if (j == 9) {
                    cout << "    ";
                }
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                cout << "[";
                string category3 = "C";

                string stringcolumn = to_string(seatID_s++);

                string formattedColumn = "00" + stringcolumn;

                formattedColumn = formattedColumn.substr(formattedColumn.length() - 2);

                string combine_id_s = category3 + formattedColumn;

                if (i == 16 && j == 0) {
                    seatID_s = seatID_s + 18;
                }

                if (i == 17 && j == 0) {
                    seatID_s = seatID_s + 36;
                }

                if (i == 18 && j == 0) {
                    seatID_s = seatID_s + 54;
                }

                if (i == 19 && j == 0) {
                    seatID_s = seatID_s + 72;
                }

                if (i == 20 && j == 0) {
                    seatID_s = seatID_s + 90;
                }
                cout << combine_id_s << "]";// Available seats
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            else {
                if (i <= 14 && i >= 0) {
                    if (j == 14 || j == 4) {
                        cout << "    ";
                    }
                }
                if (i >= 15 && i <= 19) {
                    ++seatID_s;
                    if (seatID_s == 2 && j == 0) {
                        cout << "    ";
                    }
                    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(consoleHandle, 0);
                    cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                }
                else if (i >= 0 && i <= 6 && j >= 0 && j <= 18) {
                    ++seatID_p;
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_INTENSITY);
                    cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                }
                else if (i >= 7 && i <= 15 && j >= 0 && j <= 18) {
                    ++seatID_g;
                    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(consoleHandle, 0);
                    cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                }
                if (i == 14 && j == 17) {
                    cout << endl;
                }
            }
        }
        cout << endl;
    }
}

void printSeatingLayout_gold(const vector<vector<char>>& seats, int numRows, int numCols) {
    system("CLS");
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                                                       " << RESET << endl;
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                         GOLD                          " << RESET << endl;
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                                                       " << RESET << endl;
    cout << endl;

    // Print each row
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (j == 0) {
                cout << setfill(' ') << setw(24) << RESET;
            }
            if (seats[i][j] == emptySeat && i <= 14) {

                if (j == 4 || j == 14) {
                    cout << "    ";
                }
                if (i >= 0 && i <= 6) {

                    if (j >= 0 && j <= numCols) {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << "[";
                        string category1 = "A";

                        string stringcolumn = to_string(seatID_p++);

                        string formattedColumn = "000" + stringcolumn;

                        formattedColumn = formattedColumn.substr(formattedColumn.length() - 3);

                        string combine_id_p = category1 + formattedColumn;

                        cout << combine_id_p << "]";// Available seats
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    }
                }
                if (i >= 7 && i <= 15) {

                    if (j >= 0 && j <= numCols) {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN);
                        cout << "\033[32m[";
                        string category2 = "B";

                        string stringcolumn = to_string(seatID_g++);

                        string formattedColumn = "000" + stringcolumn;

                        formattedColumn = formattedColumn.substr(formattedColumn.length() - 3);

                        string combine_id_g = category2 + formattedColumn;

                        cout << combine_id_g << "]\033[0m";// Available seats
                    }
                    if (i == 14 && j == 17) {
                        cout << endl;
                    }
                }


            }
            else if (seats[i][j] == emptySeat && i >= 15 && i <= numRows) {
                if (j == 0) {
                    seatID_p = 1;
                    seatID_s = 1;
                    seatID_g = 1;
                    cout << "          ";
                }if (j == 9) {
                    cout << "    ";
                }
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                cout << "[";
                string category3 = "C";

                string stringcolumn = to_string(seatID_s++);

                string formattedColumn = "00" + stringcolumn;

                formattedColumn = formattedColumn.substr(formattedColumn.length() - 2);

                string combine_id_s = category3 + formattedColumn;

                if (i == 16 && j == 0) {
                    seatID_s = seatID_s + 18;
                }

                if (i == 17 && j == 0) {
                    seatID_s = seatID_s + 36;
                }

                if (i == 18 && j == 0) {
                    seatID_s = seatID_s + 54;
                }

                if (i == 19 && j == 0) {
                    seatID_s = seatID_s + 72;
                }

                if (i == 20 && j == 0) {
                    seatID_s = seatID_s + 90;
                }
                cout << combine_id_s << "]";// Available seats
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            else {
                if (i <= 14 && i >= 0) {
                    if (j == 14 || j == 4) {
                        cout << "    ";
                    }
                }
                if (i >= 15 && i <= 19) {
                    ++seatID_s;
                    if (seatID_s == 2 && j == 0) {
                        cout << "    ";
                    }
                    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(consoleHandle, 0);
                    cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                }
                else if (i >= 0 && i <= 6 && j >= 0 && j <= 18) {
                    ++seatID_p;
                    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(consoleHandle, 0);
                    cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                }
                else if (i >= 7 && i <= 15 && j >= 0 && j <= 18) {
                    ++seatID_g;
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_INTENSITY);
                    cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                }
                if (i == 14 && j == 17) {
                    cout << endl;
                }
            }
        }
        cout << endl;
    }
}

void printSeatingLayout_standard(const vector<vector<char>>& seats, int numRows, int numCols) {
    system("CLS");
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                                                       " << RESET << endl;
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                         STANDARD                      " << RESET << endl;
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                                                       " << RESET << endl;
    cout << endl;

    // Print each row
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (j == 0) {
                cout << setfill(' ') << setw(24) << RESET;
            }
            if (seats[i][j] == emptySeat && i <= 14) {

                if (j == 4 || j == 14) {
                    cout << "    ";
                }
                if (i >= 0 && i <= 6) {

                    if (j >= 0 && j <= numCols) {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << "[";
                        string category1 = "A";

                        string stringcolumn = to_string(seatID_p++);

                        string formattedColumn = "000" + stringcolumn;

                        formattedColumn = formattedColumn.substr(formattedColumn.length() - 3);

                        string combine_id_p = category1 + formattedColumn;

                        cout << combine_id_p << "]";// Available seats
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    }
                }
                if (i >= 7 && i <= 15) {

                    if (j >= 0 && j <= numCols) {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << "[";
                        string category2 = "B";

                        string stringcolumn = to_string(seatID_g++);

                        string formattedColumn = "000" + stringcolumn;

                        formattedColumn = formattedColumn.substr(formattedColumn.length() - 3);

                        string combine_id_g = category2 + formattedColumn;

                        cout << combine_id_g << "]";// Available seats
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    }
                    if (i == 14 && j == 17) {
                        cout << endl;
                    }
                }


            }
            else if (seats[i][j] == emptySeat && i >= 15 && i <= numRows) {
                if (j == 0) {
                    seatID_p = 1;
                    seatID_s = 1;
                    seatID_g = 1;
                    cout << "          ";
                }if (j == 9) {
                    cout << "    ";
                }
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                cout << "\033[32m[";
                string category3 = "C";

                string stringcolumn = to_string(seatID_s++);

                string formattedColumn = "00" + stringcolumn;

                formattedColumn = formattedColumn.substr(formattedColumn.length() - 2);

                string combine_id_s = category3 + formattedColumn;

                if (i == 16 && j == 0) {
                    seatID_s = seatID_s + 18;
                }

                if (i == 17 && j == 0) {
                    seatID_s = seatID_s + 36;
                }

                if (i == 18 && j == 0) {
                    seatID_s = seatID_s + 54;
                }

                if (i == 19 && j == 0) {
                    seatID_s = seatID_s + 72;
                }

                if (i == 20 && j == 0) {
                    seatID_s = seatID_s + 90;
                }
                cout << combine_id_s << "]\033[0m";// Available seats
            }
            else {
                if (i <= 14 && i >= 0) {
                    if (j == 14 || j == 4) {
                        cout << "    ";
                    }
                }
                if (i >= 15 && i <= 19) {
                    if (seatID_s == 2 && j == 0) {
                        cout << "    ";
                    }
                    if (j == 0) {
                        cout << "          ";
                        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(consoleHandle, 0);
                        cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                    }
                    else {
                        ++seatID_s;
                        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(consoleHandle, 0);
                        cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                    }
                }
                else if (i >= 0 && i <= 6 && j >= 0 && j <= 18) {
                    ++seatID_p;
                    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(consoleHandle, 0);
                    cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                }
                else if (i >= 7 && i <= 15 && j >= 0 && j <= 18) {
                    ++seatID_g;
                    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(consoleHandle, 0);
                    cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                }
                if (i == 14 && j == 17) {
                    cout << endl;
                }
            }
        }
        cout << endl;
    }
}

// Function to print the seating layout
void printSeatingLayout(const vector<vector<char>>& seats, int numRows, int numCols) {
    system("CLS");
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                                                       " << RESET << endl;
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                         STAGE                         " << RESET << endl;
    cout << setfill(' ') << setw(59) << BOLDBLACK << BG_GRAY << "                                                       " << RESET << endl;
    cout << endl;

    // Print each row
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (j == 0) {
                cout << setfill(' ') << setw(24) << RESET;
            }
            if (seats[i][j] == emptySeat && i <= 14) {

                if (j == 4 || j == 14) {
                    cout << "    ";
                }
                if (i >= 0 && i <= 6) {

                    if (j >= 0 && j <= numCols) {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
                        cout << "\033[32m[";
                        string category1 = "A";

                        string stringcolumn = to_string(seatID_p++);

                        string formattedColumn = "000" + stringcolumn;

                        formattedColumn = formattedColumn.substr(formattedColumn.length() - 3);

                        string combine_id_p = category1 + formattedColumn;

                        cout << combine_id_p << "]\033[0m";// Available seats
                    }
                }
                if (i >= 7 && i <= 15) {

                    if (j >= 0 && j <= numCols) {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN);
                        cout << "\033[32m[";
                        string category2 = "B";

                        string stringcolumn = to_string(seatID_g++);

                        string formattedColumn = "000" + stringcolumn;

                        formattedColumn = formattedColumn.substr(formattedColumn.length() - 3);

                        string combine_id_g = category2 + formattedColumn;

                        cout << combine_id_g << "]\033[0m";// Available seats
                    }
                    if (i == 14 && j == 17) {
                        cout << endl;
                    }
                }


            }
            else if (seats[i][j] == emptySeat && i >= 15 && i <= numRows) {
                if (j == 0) {
                    seatID_p = 1;
                    seatID_s = 1;
                    seatID_g = 1;
                    cout << "          ";
                }if (j == 9) {
                    cout << "    ";
                }
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                cout << "\033[32m[";
                string category3 = "C";

                string stringcolumn = to_string(seatID_s++);

                string formattedColumn = "00" + stringcolumn;

                formattedColumn = formattedColumn.substr(formattedColumn.length() - 2);

                string combine_id_s = category3 + formattedColumn;

                if (i == 16 && j == 0) {
                    seatID_s = seatID_s + 18;
                }

                if (i == 17 && j == 0) {
                    seatID_s = seatID_s + 36;
                }

                if (i == 18 && j == 0) {
                    seatID_s = seatID_s + 54;
                }

                if (i == 19 && j == 0) {
                    seatID_s = seatID_s + 72;
                }

                if (i == 20 && j == 0) {
                    seatID_s = seatID_s + 90;
                }
                cout << combine_id_s << "]\033[0m";// Available seats
            }
            else {
                if (i <= 14 && i >= 0) {
                    if (j == 14 || j == 4) {
                        cout << "    ";
                    }
                }
                if (i >= 15 && i <= 19) {
                    ++seatID_s;
                    if (seatID_s == 2 && j == 0) {
                        cout << "    ";
                    }
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_INTENSITY);
                    cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                }
                else if (i >= 0 && i <= 6 && j >= 0 && j <= 18) {
                    ++seatID_p;
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_INTENSITY);
                    cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                }
                else if (i >= 7 && i <= 15 && j >= 0 && j <= 18) {
                    ++seatID_g;
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_INTENSITY);
                    cout << "\033[31m[" << bookedSeat << bookedSeat << bookedSeat << bookedSeat << "]\033[0m"; // Booked seats
                }
                if (i == 14 && j == 17) {
                    cout << endl;
                }
            }
        }
        cout << endl;
    }
}

// Function to book seats
int bookSeats(vector<vector<char>>& seats, int row, int col, int i) {
    if (seats[row][col] == emptySeat) {
        seats[row][col] = bookedSeat;
        cout << "\t\t\t\tSeat booked successfully!\n";
        this_thread::sleep_for(chrono::seconds(1)); // Pause for 1 second to display the result
        return(0);
    }
    else {
        cout << "\t\t\t\tSorry, the seat is already booked. Please select another seat.\n";
        this_thread::sleep_for(chrono::seconds(2)); // Pause for 2 seconds to display the result
        return(1);
    }
}

// Display asterisks for all digits except the last four
string hideCardNumber(const string& card_number) {
    size_t length = card_number.length();
    string hiddenPart(length - 4, '*');
    string visiblePart = card_number.substr(length - 4);
    return hiddenPart + visiblePart;
}

void generateAndDisplayTicket(const string& seatId, const string& category, const int& inv_num) {

    cout << "\t\t\t\t\t+=========================================+\n";
    cout << "\t\t\t\t\t|             COOL PLAY TICKET            |\n";
    cout << "\t\t\t\t\t+=========================================+\n";
    cout << "\t\t\t\t\t|                                         |" << endl;
    cout << "\t\t\t\t\t| Seat ID: " << setfill(' ') << setw(31) << left << seatId << "|\n";
    cout << "\t\t\t\t\t| Category: " << setfill(' ') << setw(30) << left << category << "|\n";
    cout << "\t\t\t\t\t| Receipt INV No.: " << setfill(' ') << setw(23) << left << "INV" + to_string(inv_num) << "|\n";
    cout << "\t\t\t\t\t|                                         |" << endl;
    cout << "\t\t\t\t\t| Date: 20 JAN 2024                       |" << endl;
    cout << "\t\t\t\t\t| Time: 7.30pm                            |" << endl;
    cout << "\t\t\t\t\t| Venue: Axiata Arena                     |" << endl;
    cout << "\t\t\t\t\t+=========================================+\n";
}

void invoice_other_method(const string& username, const string& password, const string& email, const string& phoneNumber, const int& num_input, const double& total_price, const int& platinum_num_input, const int& gold_num_input, const int& standard_num_input, const vector<pair<string, string>>& bookedSeats, const string& method_type);

void displayPaymentPage(const string& username, const string& password, const string& email, const string& phoneNumber, const int& num_input, const double& total_price, const int& platinum_num_input, const int& gold_num_input, const int& standard_num_input, const vector<pair<string, string>>& bookedSeats) {
#define RESET         "\033[0m"
#define RED           "\033[31m"
#define GREEN         "\033[32m"
#define BLINK         "\033[5m"

    system("CLS");

    int payment_method;
    int ticket_quantity;
    string method_type;
    string card_number;
    string exp_date;
    string cvv;
    int inv_num;
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomNum = rand() % 9000 + 1000;

    cout << endl;
    cout << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t   +===============================+\n";
    cout << "\t\t\t\t\t   |          Payment Page         |\n";
    cout << "\t\t\t\t\t   +===============================+\n";
    cout << endl;
    cout << "\t\t\t\t\t    Ticket(s) categories \n";
    cout << "\t\t\t\t\t    --------------------- \n";
    cout << "\t\t\t\t\t    Platinum (Zone A)    : " << platinum_num_input << endl;
    cout << "\t\t\t\t\t    Gold (Zone B)        : " << gold_num_input << endl;
    cout << "\t\t\t\t\t    Standard (Zone C)    : " << standard_num_input << endl;
    ticket_quantity = platinum_num_input + gold_num_input + standard_num_input;
    cout << "\t\t\t\t\t    Ticket(s) Quantity   : " << ticket_quantity << endl;
    cout << endl;
    cout << "\t\t\t\t\t    Total Amount         : RM" << fixed << setprecision(2) << total_price << endl;
    cout << endl;
    cout << "\t\t\t\t\t    Payment method :\n";
    cout << "\t\t\t\t\t     [1] Credit Card/ Debit Card\n";
    cout << "\t\t\t\t\t     [2] Touch And Go Ewallet\n";
    cout << "\t\t\t\t\t     [3] Shopee Pay\n";
    cout << "\t\t\t\t\t     [4] Paypal\n";
    cout << "\t\t\t\t\t     [5] Ali pay\n";
    cout << endl;
    cout << "\t\t\t\t\t     Enter Your payment method: ";
    cin >> payment_method;
    cin.ignore();

    switch (payment_method) {
    case 1: {
        system("CLS");
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t+=====================================================+" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t+=====================================================+" << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t   +===============================+\n";
        cout << "\t\t\t\t\t   |          Payment Page         |\n";
        cout << "\t\t\t\t\t   +===============================+\n";
        cout << endl;
        cout << "\t\t\t\t\t    Ticket(s) categories \n";
        cout << "\t\t\t\t\t    --------------------- \n";
        cout << "\t\t\t\t\t    Platinum (Zone A)    : " << platinum_num_input << endl;
        cout << "\t\t\t\t\t    Gold (Zone B)        : " << gold_num_input << endl;
        cout << "\t\t\t\t\t    Standard (Zone C)    : " << standard_num_input << endl;
        ticket_quantity = platinum_num_input + gold_num_input + standard_num_input;
        cout << "\t\t\t\t\t    Ticket(s) Quantity   : " << ticket_quantity << endl;
        cout << endl;
        cout << "\t\t\t\t\t    Total Amount         : RM" << fixed << setprecision(2) << total_price << endl;
        cout << endl;

        bool isValidCard = false;
        do {
            cout << "\t\t\t\t\t     Enter Card No.: ";
            cin >> card_number;
            regex cardPattern("\\d{16}");

            if (regex_match(card_number, cardPattern)) {
                isValidCard = true;

                bool isValidExp = false;
                do {
                    cout << "\t\t\t\t\t     Enter Expire date: ";
                    cin >> exp_date;
                    regex exp_datePattern(R"(\d{2}/\d{2})");

                    if (regex_match(exp_date, exp_datePattern)) {
                        isValidExp = true;

                        bool isValidCVV = false;
                        do {
                            cout << "\t\t\t\t\t     Enter CVV (Card Verification Value): ";
                            cin >> cvv;
                            regex cvvPattern(R"(\d{3})");

                            if (regex_match(cvv, cvvPattern)) {
                                isValidCVV = true;

                            }
                            else {
                                cout << BLINK << RED << "\t\t\t\t\t     Invalid CVV format. Please enter a 3-digit CVV. " << RESET << flush << endl;
                            }
                        } while (!isValidCVV);
                    }
                    else {
                        cout << BLINK << RED << "\t\t\t\t\t     Invalid expiration date format. Please use the format MM/YY. " << RESET << flush << endl;
                    }

                } while (!isValidExp);

            }
            else {
                cout << BLINK << RED << "\t\t\t\t\t     Invalid card number. Please enter a 16 digtis card number. " << RESET << flush << endl;
            }
        } while (!isValidCard);

        system("CLS");

        cout << endl;
        cout << endl;
        cout << "\t\t\t\t+=====================================================+" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t+=====================================================+" << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t   +===============================+\n";
        cout << "\t\t\t\t\t   |             Invoice           |\n";
        cout << "\t\t\t\t\t   +===============================+\n";
        cout << endl;
        cout << "\t\t\t\t\t    Payment Method  : Credit/Debit Card" << endl;
        cout << "\t\t\t\t\t    Card No.        : " << hideCardNumber(card_number) << endl;
        cout << "\t\t\t\t\t    Date/Time       : "; displayDateTime();
        cout << "\t\t\t\t\t    Phone No.       : " << phoneNumber << endl;
        cout << "\t\t\t\t\t    Email Address   : " << email << endl;
        cout << "\t\t\t\t\t    Reciept INV No. :" << "INV " << randomNum << endl;
        inv_num = randomNum;
        cout << endl;
        cout << "\t\t\t\t\t    Ticket(s) categories \n";
        cout << "\t\t\t\t\t    --------------------- \n";
        cout << "\t\t\t\t\t    Platinum (Zone A)    : " << platinum_num_input << endl;
        cout << "\t\t\t\t\t    Gold (Zone B)        : " << gold_num_input << endl;
        cout << "\t\t\t\t\t    Standard (Zone C)    : " << standard_num_input << endl;
        cout << endl;
        ticket_quantity = platinum_num_input + gold_num_input + standard_num_input;
        cout << "\t\t\t\t\t    Ticket(s) Quantity   : " << num_input << endl;
        cout << endl;
        cout << endl;
        cout << left << setfill(' ') << setw(60) << " " << setfill('-') << setw(15) << " " << right << endl;
        cout << "\t\t\t\t\t    TOTAL: " << left << setfill(' ') << setw(15) << " " << fixed << setprecision(2) << "RM " << total_price << endl;
        cout << left << setfill(' ') << setw(60) << " " << setfill('-') << setw(15) << " " << right << endl;
        cout << endl;
        cout << "\t\t\t\t\t     NO SIGNATURE REQUIRED " << endl;

        cout << BLINK << GREEN << "\t\t\t\t\t     Press Enter to generate your ticket..." << RESET << flush;
        cin.ignore();
        cin.get();

        system("CLS");

        cout << endl;
        cout << endl;
        cout << "\t\t\t\t+=====================================================+" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t+=====================================================+" << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t   +===============================+\n";
        cout << "\t\t\t\t\t   |             TICKET            |\n";
        cout << "\t\t\t\t\t   +===============================+\n";
        cout << endl;
        cout << "\t\t\t\t\t   Dear " << username << " , Here is your ticket(s) : " << endl;
        cout << endl;
        cout << endl;

        // Generate and display tickets for each booked seat
        for (const auto& seat : bookedSeats) {
            generateAndDisplayTicket(seat.first, seat.second, inv_num);
        }
    }
          break;
    case 2:
        method_type = "Touch And Go Ewallet";
        invoice_other_method(username, password, email, phoneNumber, num_input, total_price, platinum_num_input, gold_num_input, standard_num_input, bookedSeats, method_type);
        break;

    case 3:
        method_type = "Shopee Pay";
        invoice_other_method(username, password, email, phoneNumber, num_input, total_price, platinum_num_input, gold_num_input, standard_num_input, bookedSeats, method_type);
        break;

    case 4:
        method_type = "Paypal";
        invoice_other_method(username, password, email, phoneNumber, num_input, total_price, platinum_num_input, gold_num_input, standard_num_input, bookedSeats, method_type);
        break;

    case 5:
        method_type = "Ali Pay";
        invoice_other_method(username, password, email, phoneNumber, num_input, total_price, platinum_num_input, gold_num_input, standard_num_input, bookedSeats, method_type);
        break;

    default:
        cout << "Invalid payment type";
        break;
    }


}

void invoice_other_method(const string& username, const string& password, const string& email, const string& phoneNumber, const int& num_input, const double& total_price, const int& platinum_num_input, const int& gold_num_input, const int& standard_num_input, const vector<pair<string, string>>& bookedSeats, const string& method_type) {
    int payment_method;
    int ticket_quantity;
    string card_number;
    string exp_date;
    string cvv;
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomNum = rand() % 9000 + 1000;
    int inv_num;

    system("CLS");
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t   +===============================+\n";
    cout << "\t\t\t\t\t   |             Invoice           |\n";
    cout << "\t\t\t\t\t   +===============================+\n";
    cout << endl;
    cout << "\t\t\t\t\t    Payment Method  : " << method_type << endl;
    cout << "\t\t\t\t\t    Date/Time       : "; displayDateTime();
    cout << "\t\t\t\t\t    Phone No.       : " << phoneNumber << endl;
    cout << "\t\t\t\t\t    Email Address   : " << email << endl;
    cout << "\t\t\t\t\t    Reciept INV No. : " << "INV" << randomNum << endl;
    inv_num = randomNum;
    cout << endl;
    cout << "\t\t\t\t\t    Ticket(s) categories \n";
    cout << "\t\t\t\t\t    --------------------- \n";
    cout << "\t\t\t\t\t    Platinum (Zone A)    : " << platinum_num_input << endl;
    cout << "\t\t\t\t\t    Gold (Zone B)        : " << gold_num_input << endl;
    cout << "\t\t\t\t\t    Standard (Zone C)    : " << standard_num_input << endl;
    cout << endl;
    ticket_quantity = platinum_num_input + gold_num_input + standard_num_input;
    cout << "\t\t\t\t\t    Ticket(s) Quantity   : " << ticket_quantity << endl;
    cout << endl;
    cout << left << setfill(' ') << setw(60) << " " << setfill('-') << setw(15) << " " << right << endl;
    cout << "\t\t\t\t\t    TOTAL: " << left << setfill(' ') << setw(15) << " " << fixed << setprecision(2) << "RM " << total_price << endl;
    cout << left << setfill(' ') << setw(60) << " " << setfill('-') << setw(15) << " " << right << endl;
    cout << endl;
    cout << "\t\t\t\t\t     NO SIGNATURE REQUIRED " << endl;

    cout << endl;
    cout << BLINK << GREEN << "\t\t\t\t\t     Press Enter to generate your ticket..." << RESET << flush;
    cin.ignore();
    cin.get();
    system("CLS");

    cout << endl;
    cout << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << "\t\t\t\t|                        TICKET                       |\n";
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << endl;
    cout << "\t\t\t\tDear " << username << " , Here is your ticket(s) : " << endl;
    cout << endl;
    cout << endl;

    // Generate and display tickets for each booked seat
    for (const auto& seat : bookedSeats) {
        generateAndDisplayTicket(seat.first, seat.second, inv_num);
    }
}

bool isInteger(const string& str) {
    // Check if all characters in the string are digits
    return all_of(str.begin(), str.end(), ::isdigit);
}

void ticket_seat_selection(const string& username, const string& password, const string& email, const string& phoneNumber) {

    // Declaration of bookedSeats
    vector<pair<string, string>> bookedSeats;

    double price_platinum = 0;
    double total_price_platinum = 0;
    double price_gold = 0;
    double total_price_gold = 0;
    double price_standard = 0;
    double total_price_standard = 0;
    double total_price = 0;
    int platinum_num_input = 0;
    int gold_num_input = 0;
    int standard_num_input = 0;
    string seatId;
    char continue_option;
    bool isValidInput = false;

#define RESET         "\033[0m"
#define RED           "\033[31m"
#define GREEN         "\033[32m"
#define BLINK         "\033[5m"

    vector<vector<char>> seats(numRows, vector<char>(numCols, emptySeat));
    char choice;
    char option;
    int selectedRow, selectedCol;
    string user_input;
    int num_input = 0;
    int i = 0;
    int seatconform;

    do {
        seat_categories_layout();
        bool isValidInput = false;

        cout << "\t\t\t\t\tPlease choose the category you prefer to book: " << endl;
        cout << "\t\t\t\t\t [1] Platinum (ZONE A)" << endl;
        cout << "\t\t\t\t\t [2] Gold (ZONE B)" << endl;
        cout << "\t\t\t\t\t [3] Standatd (ZONE C)" << endl;
        cout << endl;
        cout << "\t\t\t\t\t Enter your choice: ";
        cin >> option;

        while (option < '1' || option > '3') {
            cout << "Invalid option! Please enter the option within 1 - 3 : ";
            cin >> option;
        }

        cout << endl;
        cout << endl;

        switch (option) {
        case '1':
            price_platinum = 799;
            printSeatingLayout_platinum(seats, numRows, numCols);
            while (!isValidInput) {
                cout << endl;
                cout << "\t\t\t\tHow many tickets you want to book? (maximum 10): ";
                cin >> user_input;
                cout << endl;
                cout << endl;

                if (isInteger(user_input)) {
                    // Convert string to integer
                    num_input = stoi(user_input);

                    // Check if the integer is in the desired range
                    if (num_input >= 1 && num_input <= 10) {
                        isValidInput = true;  // Set to true to exit the loop
                    }
                }

                if (!isValidInput) {
                    cout << "\t\t\t\tError! Invalid input. Please enter an integer between 1 and 10.\n";
                }
            }

            while (num_input > 10 || num_input < 0) {
                cout << "\t\t\t\tInvalid number, please enter again.";
                cin >> num_input;
            }

            platinum_num_input = num_input;
            total_price_platinum = price_platinum * num_input;

            for (i = 1; i <= num_input; i++) {
                cout << "\n\t\t\t\tEnter a seat ID (e.g., A1, A20): ";
                string userInput;
                cin >> userInput;

                // Extract row and column from the user input
                char idPrefix;
                int seatNumber;
                if (sscanf(userInput.c_str(), "%c%d", &idPrefix, &seatNumber) == 2 && idPrefix == 'A') {
                    int row = (seatNumber - 1) / numCols;
                    int col = (seatNumber - 1) % numCols;
                    if (seatNumber > 127 || seatNumber < 0) {
                        cout << "\t\t\t\tInvalid seat ID, please try again." << endl;
                        i--;
                    }
                    else {
                        seatconform = bookSeats(seats, row, col, i);
                        if (seatconform == 1) {
                            i--;
                        }
                        seatId = userInput;
                        bookedSeats.push_back(make_pair(seatId, "Platinum"));
                    }

                }
                else {
                    cout << "\t\t\t\tInvalid format. Try again.\n";
                    i--;
                }
            }
            break;

        case '2':
            price_gold = 599;
            printSeatingLayout_gold(seats, numRows, numCols);
            while (!isValidInput) {
                cout << endl;
                cout << "\t\t\t\tHow many tickets you want to book? (maximum 10): ";
                cin >> user_input;
                cout << endl;
                cout << endl;

                if (isInteger(user_input)) {
                    // Convert string to integer
                    num_input = stoi(user_input);

                    // Check if the integer is in the desired range
                    if (num_input >= 1 && num_input <= 10) {
                        isValidInput = true;  // Set to true to exit the loop
                    }
                }

                if (!isValidInput) {
                    cout << "\t\t\t\tError! Invalid input. Please enter an integer between 1 and 10.\n";
                }
            }
            while (num_input > 10 || num_input < 0) {
                cout << "\t\t\t\tInvalid number, please enter again.";
                cin >> num_input;
            }

            gold_num_input = num_input;
            total_price_gold = price_gold * num_input;

            for (i = 1; i <= num_input; i++) {
                cout << "\n\t\t\t\tEnter a seat ID (e.g., B1, B20): ";
                string userInput;
                cin >> userInput;

                // Extract row and column from the user input
                char idPrefix;
                int seatNumber;
                if (sscanf(userInput.c_str(), "%c%d", &idPrefix, &seatNumber) == 2 && idPrefix == 'B') {
                    int row = (seatNumber - 1) / numCols;
                    int col = (seatNumber - 1) % numCols;
                    if (seatNumber > 144 || seatNumber < 0) {
                        cout << "\t\t\t\tInvalid seat ID, please try again." << endl;
                        i--;
                    }
                    else {
                        row = row + 7;
                        seatconform = bookSeats(seats, row, col, i);
                        if (seatconform == 1) {
                            i--;
                        }
                        seatId = userInput;
                        bookedSeats.push_back(make_pair(seatId, "Gold"));
                    }
                }
                else {
                    cout << "\t\t\t\tInvalid format. Try again.\n";
                    i--;
                }

            }
            break;
        case '3':
            price_standard = 299;

            printSeatingLayout_standard(seats, numRows, numCols);
            while (!isValidInput) {
                cout << endl;
                cout << "\t\t\t\tHow many tickets you want to book? (maximum 10): ";
                cin >> user_input;
                cout << endl;
                cout << endl;

                if (isInteger(user_input)) {
                    // Convert string to integer
                    num_input = stoi(user_input);

                    // Check if the integer is in the desired range
                    if (num_input >= 1 && num_input <= 10) {
                        isValidInput = true;  // Set to true to exit the loop
                    }
                }

                if (!isValidInput) {
                    cout << "\t\t\t\tError! Invalid input. Please enter an integer between 1 and 10.\n";
                }
            }

            standard_num_input = num_input;
            total_price_standard = price_standard * num_input;

            for (i = 1; i <= num_input; i++) {
                cout << "\n\t\t\t\tEnter a seat ID (e.g., C1, C20): ";
                string userInput;
                cin >> userInput;

                // Extract row and column from the user input
                char idPrefix;
                int seatNumber;
                if (sscanf(userInput.c_str(), "%c%d", &idPrefix, &seatNumber) == 2 && idPrefix == 'C') {
                    int row = (seatNumber - 1) / numCols;
                    int col = (seatNumber - 1) % numCols;
                    if (seatNumber > 90 || seatNumber < 0) {
                        cout << "\t\t\t\tInvalid seat ID, please try again." << endl;
                        i--;
                    }
                    else {
                        row = row + 15;
                        seatconform = bookSeats(seats, row, col, i);
                        if (seatconform == 1) {
                            i--;
                        }
                        seatId = userInput;
                        bookedSeats.push_back(make_pair(seatId, "Standard"));
                    }

                }
                else {
                    cout << "\t\t\t\tInvalid format. Try again.\n";
                    i--;
                }
            }
            break;
        default:
            cout << "\t\t\t\tInvalid choice, please enter again.";
            seat_categories_layout();
        }
        cout << endl;
        cout << "\t\t\t\tDo you like to book other tickets? (Y/N) : ";
        cin >> continue_option;
        continue_option = toupper(continue_option);
        system("CLS");
    } while (continue_option == 'Y');

    total_price = total_price_platinum + total_price_gold + total_price_standard;
    displayPaymentPage(username, password, email, phoneNumber, num_input, total_price, platinum_num_input, gold_num_input, standard_num_input, bookedSeats);
    this_thread::sleep_for(chrono::seconds(2));
}

void concert_detial(const string& username, const string& password, const string& email, const string& phoneNumber);

void ticket_booking_page(const string& username, const string& password, const string& email, const string& phoneNumber) {
    double price_platinum = 0;
    double total_price_platinum = 0;
    double price_gold = 0;
    double total_price_gold = 0;
    double price_standard = 0;
    double total_price_standard = 0;
    double total_price = 0;
    int platinum_num_input = 0;
    int gold_num_input = 0;
    int standard_num_input = 0;
    string seatId;
    char continue_option;

#define RESET         "\033[0m"
#define RED           "\033[31m"
#define GREEN         "\033[32m"
#define BLINK         "\033[5m"

    vector<vector<char>> seats(numRows, vector<char>(numCols, emptySeat));
    char choice;
    char option;
    int selectedRow, selectedCol;
    int num_input = 0;
    int i = 0;
    int seatconform;


    do {
        system("CLS");
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t+=====================================================+" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t+=====================================================+" << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t   +===============================+\n";
        cout << "\t\t\t\t\t   |            MENU PAGE          |\n";
        cout << "\t\t\t\t\t   +===============================+\n";
        cout << "\t\t\t\t\t    [1] Book Seat\n";
        cout << "\t\t\t\t\t    [2] View Seating Layout\n";
        cout << "\t\t\t\t\t    [3] Back to Main page\n";
        cout << "\t\t\t\t\t    [4] Log Out\n";
        cout << endl;
        cout << "\t\t\t\t\t    Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            ticket_seat_selection(username, password, email, phoneNumber);
            this_thread::sleep_for(chrono::seconds(2));
            break;

        case '2':
            seat_categories_layout();
            this_thread::sleep_for(chrono::seconds(2));
            cout << BLINK << GREEN << "\t\t\t\tPress Enter to continue..." << RESET << flush;
            cin.ignore();
            cin.get();
            break;

        case '3':
            ticket_menu_page(username, password, email, phoneNumber);
            this_thread::sleep_for(chrono::seconds(2));
            break;

        case '4':
            system("CLS");
            loginpage();
            break;

        default:
            cout << "\t\t\t\tInvalid choice. Please enter a valid option.\n";
            this_thread::sleep_for(chrono::seconds(2));
        }

        cin.get();
        cout << BLINK << GREEN << "\t\t\t\tPress Enter to continue..." << RESET << flush;
        cin.ignore();
        cin.get();

        system("CLS");

    } while (choice != '4');
}

struct Feedback {
    string username;
    string feedbackText;
};

// Function to collect user feedback and store it in a file
void collectFeedback(const string& username, const string& password, const string& email, const string& phoneNumber) {
#define RESET         "\033[0m"
#define BLINK         "\033[5m"
#define YELLOW  "\033[33m"      /* Yellow */

    Feedback feedback;
    system("CLS");

    cout << endl;
    cout << endl;

    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;

    cout << endl;

    cout << "\t\t\t\t\t   +===============================+\n";
    cout << "\t\t\t\t\t   |         Feedback Review       |\n";
    cout << "\t\t\t\t\t   +===============================+\n";

    cout << endl;

    cout << "\t\t\t\t\t     Enter your username: ";
    cin >> feedback.username;

    cout << "\t\t\t\t\t     Enter your feedback (press Enter to finish):\n";
    cout << endl;
    cout << "*_*_*_*_*_*_*_*_*| Enter Your Feedback Below |*_*_*_*_*_*_*_*_*" << endl;
    cin.ignore();  // Ignore newline left in buffer from previous input
    getline(cin, feedback.feedbackText);  // Use getline to capture the entire line of feedback

    // Append the feedback to the file
    ofstream feedbackFile("feedback.txt", ios::app);
    if (feedbackFile.is_open()) {
        feedbackFile << feedback.username << ": " << feedback.feedbackText << '\n';
        feedbackFile.close();
        cout << "\t\t\t\t\t     Feedback submitted successfully!\n";

        cout << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << BLINK << YELLOW << "\t\t\t\t\t     Press Any Key to continue..." << RESET << flush;
        cin.ignore();
        cin.get();

        ticket_menu_page(username, password, email, phoneNumber);

    }

    else {
        cerr << "\t\t\t\t\t     Error: Unable to open feedback file for writing.\n";
    }
}

// Function to display all feedback from the file
void displayAllFeedback(const string& username, const string& password, const string& email, const string& phoneNumber) {
#define RESET         "\033[0m"
#define BLINK         "\033[5m"
#define YELLOW  "\033[33m"      /* Yellow */

    ifstream feedbackFile("feedback.txt");
    if (feedbackFile.is_open()) {
        string line;
        system("CLS");

        cout << "\t\t\t\t+=====================================================+" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t+=====================================================+" << endl;

        cout << endl;

        cout << "\t\t\t\t\t   +===============================+\n";
        cout << "\t\t\t\t\t   |        Feedback Review        |\n";
        cout << "\t\t\t\t\t   +===============================+\n";

        cout << endl;

        cout << "\n\t\t\t\t\tAll Feedback:\n";
        cout << "\t\t\t\t\t------------- ";
        cout << endl;
        cout << endl;
        cout << endl;

        while (getline(feedbackFile, line)) {
            cout << "\t\t\t\t\t" << line << '\n';
        }
        feedbackFile.close();

        cout << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << BLINK << YELLOW << "\t\t\t\t\tPress Any Key to continue..." << RESET << flush;
        cin.ignore();
        cin.get();

        ticket_menu_page(username, password, email, phoneNumber);

    }
    else {
        cerr << "\t\t\t\t\t     Error: Unable to open feedback file for reading.\n";
    }
}

void ticket_menu_page(const string& username, const string& password, const string& email, const string& phoneNumber) {
#define RESET         "\033[0m"
#define RED           "\033[31m"
#define BLINK         "\033[5m"

    int option;
    system("CLS");
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t   +===============================+\n";
    cout << "\t\t\t\t\t   |     TICKET BOOKING SYSTEM     |\n";
    cout << "\t\t\t\t\t   +===============================+\n";
    cout << "\t\t\t\t\t     [1] Ticket booking menu page\n";
    cout << "\t\t\t\t\t     [2] Concert detail\n";
    cout << "\t\t\t\t\t     [3] Give us Some Feedback\n";
    cout << "\t\t\t\t\t     [4] Review Feedback\n";
    cout << "\t\t\t\t\t     [5] Log Out\n";

    cout << "\n\t\t\t\t\t   Enter your choice: ";
    cin >> option;

    while (option < 1 || option > 5) {
        cout << BLINK << RED << "\t\t\t\t\t     Invalid choice, please enter in range ( 1 - 5 )  " << RESET << flush << endl;
        cout << endl;
        cout << "\t\t\t\t\t     Enter your choice: ";
        cin >> option;
    }

    switch (option) {
    case 1:
        ticket_booking_page(username, password, email, phoneNumber);
        break;

    case 2:
        concert_detial(username, password, email, phoneNumber);
        break;

    case 3:
        collectFeedback(username, password, email, phoneNumber);
        break;

    case 4:
        displayAllFeedback(username, password, email, phoneNumber);
        break;
    case 5:
        system("CLS");
        loginpage();
        break;
    }
}

void concert_detial(const string& username, const string& password, const string& email, const string& phoneNumber) {
    vector<vector<char>> seats(numRows, vector<char>(numCols, emptySeat));
    char choice;
    char option;
    int selectedRow, selectedCol;
    int num_input = 0;
    int i = 0;
    string combine_id;
    int seatconform;
    string combine_id_s;
    string combine_id_g;
    string combine_id_p;

#define RESET   "\033[0m"
#define BG_BLUE    "\033[44m"
#define BG_CYAN    "\033[46m"      
#define BOLDBLACK   "\033[1m\033[30m"
#define BG_GREEN   "\033[42m"    
#define BG_RED     "\033[41m"
#define BG_YELLOW  "\033[43m"  
#define BG_GRAY  "\033[47m"
#define BOLDWHITE   "\033[1m\033[37m" 
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */

    system("CLS");
    cout << " Cool Play Concert " << endl;
    cout << endl;
    cout << endl;
    cout << GREEN << "\t *--------------------------------------------------------*" << RESET << endl;
    cout << GREEN << "\t |                                                        |" << RESET << endl;
    cout << GREEN << "\t |                COOL PLAY CONCERT DETIAL                |" << RESET << endl;
    cout << GREEN << "\t |                                                        |" << RESET << endl;
    cout << GREEN << "\t *--------------------------------------------------------*" << RESET << endl;
    cout << endl;
    cout << endl;
    cout << YELLOW << "\t *----------------------*" << RESET << MAGENTA << "\t *-----------------------*" << RESET << endl;
    cout << YELLOW << "\t |                      |" << RESET << MAGENTA << "\t |                       |" << RESET << endl;
    cout << YELLOW << "\t |  ------*    *******  |" << RESET << MAGENTA << "\t |                       |" << RESET << endl;
    cout << YELLOW << "\t |        |    *     *  |" << RESET << MAGENTA << "\t |    _*-* TIME: *-*_    |" << RESET << endl;
    cout << YELLOW << "\t |  *-----*    *     *  |" << RESET << MAGENTA << "\t |         19.30         |" << RESET << endl;
    cout << YELLOW << "\t |  |          *     *  |" << RESET << MAGENTA << "\t |                       |" << RESET << endl;
    cout << YELLOW << "\t |  *------    *******  |" << RESET << MAGENTA << "\t |  _*-* LOCATION: *-*_  |" << RESET << endl;
    cout << YELLOW << "\t |                      |" << RESET << MAGENTA << "\t |     Axiata Arena,     |" << RESET << endl;
    cout << YELLOW << "\t |       JAN 2024       |" << RESET << MAGENTA << "\t |      Bukit Jalil      |" << RESET << endl;
    cout << YELLOW << "\t |       ________       |" << RESET << MAGENTA << "\t |                       |" << RESET << endl;
    cout << YELLOW << "\t |       SATURDAY       |" << RESET << MAGENTA << "\t |                       |" << RESET << endl;
    cout << YELLOW << "\t |                      |" << RESET << MAGENTA << "\t |                       |" << RESET << endl;
    cout << YELLOW << "\t *----------------------*" << RESET << MAGENTA << "\t *-----------------------*" << RESET << endl;
    cout << endl;
    cout << endl;
    cout << "\tCOOL PLAY CONCERT" << endl;
    cout << "\tDATE : 20 JANUARY 2024" << endl;
    cout << "\tTIME : 7.30PM" << endl;
    cout << "\tLOCATION : AXIATA ARENA, Bukit Jalil" << endl;
    cout << endl;
    cout << endl;

    cout << "\t [1] Book your ticket NOW" << endl;
    cout << "\t [2] Back to Menu page" << endl;
    cout << endl;
    cout << "\t Enter your choice :";
    cin >> choice;

    while (choice < 1 && choice > 2) {
        cout << "\tInvalid choice, please enter again: ";
        cin >> choice;
    }

    switch (choice) {
    case '1':
        ticket_seat_selection(username, password, email, phoneNumber);
        break;

    case '2':
        ticket_menu_page(username, password, email, phoneNumber);
        break;

    default:
        cout << "Invalid choice. Please enter a valid option ( 1 - 2 ).\n";
        this_thread::sleep_for(chrono::seconds(2));
    }

}


void welcome_message() {
#define RESET         "\033[0m"
#define GREEN         "\033[32m"
#define BLINK         "\033[5m"

    this_thread::sleep_for(chrono::seconds(2));

    cout << endl;
    cout << endl;
    const string welcomeText[] = {
        "\t\t\t\t+=====================================================+",
        "\t\t\t\t|                                                     |",
        "\t\t\t\t|                                                     |",
        "\t\t\t\t|                     WELCOME TO                      |",
        "\t\t\t\t|                                                     |",
        "\t\t\t\t|                 COOL PLAY CONCENT                   |",
        "\t\t\t\t|                                                     |",
        "\t\t\t\t|               TICKET BOOKING SYSTEM                 |",
        "\t\t\t\t|                                                     |",
        "\t\t\t\t|                                                     |",
        "\t\t\t\t+=====================================================+"
    };

    for (const string& line : welcomeText) {
        cout << line << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    cout << endl;
    cout << endl;

    cout << BLINK << GREEN << "\t\t\t\tPress Enter to continue..." << RESET << flush;
    cin.get();

    system("CLS");
}

void updateProgressBar(int progress, int total) {
#define GREEN_BACKGROUND "\033[42m"
#define RESET_FORMAT "\033[0m"

    const int barWidth = 50;

    float percent = static_cast<float>(progress) / total;
    int progressBarWidth = static_cast<int>(barWidth * percent);

    cout << "\t\t\t\t [";

    for (int i = 0; i < barWidth; ++i) {
        if (i < progressBarWidth) {
            cout << GREEN_BACKGROUND << "=" << RESET_FORMAT; // Set background color to green for the progress part
        }
        else {
            cout << " ";
        }
    }

    cout << "] " << static_cast<int>(percent * 100) << "%\r";
    cout.flush();
}

void loginpage();
void admin_login_page();

void user_page_select() {
    int option;

    cout << endl;
    cout << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t   +=============================+\n";
    cout << "\t\t\t\t\t   | [1] Enter as 'Customers'    | \n";
    cout << "\t\t\t\t\t   | [2] Enter as 'Admin'        | \n";
    cout << "\t\t\t\t\t   | [3] Exit                    | \n";
    cout << "\t\t\t\t\t   +=============================+\n";
    cout << endl;
    cout << "\t\t\t\t\t\tEnter your choice: ";
    cin >> option;

    while (option < 1 || option > 3) {
        cout << endl;
        cout << BLINK << RED << "\t\t\t\t\t\tInvalid choice! Please select the option within 1 - 3 : " << RESET << flush;
        cin >> option;
    }

    switch (option) {
    case 1:
        system("CLS");
        loginpage();
        break;

    case 2:
        system("CLS");
        admin_login_page();
        break;

    case 3:
        exit(0);
    }
}

void admin_menu();

void admin_login_page() {
    string admin_username;
    string admin_pass;
    string admin_id;

    cout << endl;
    cout << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t   +=============================+\n";
    cout << "\t\t\t\t\t   |       ADMIN LOGIN PAGE      | \n";
    cout << "\t\t\t\t\t   +=============================+\n";
    cout << endl;
    cout << "\t\t\t\t\t\tEnter your name: ";
    cin >> admin_username;
    cout << "\t\t\t\t\t\tEnter your Admin ID: ";
    cin >> admin_id;

    cin.ignore();

    cout << "\t\t\t\t\t\tEnter your password: ";
    getline(cin, admin_pass);

    // Read the adminuser.txt file and check if the entered credentials match
    ifstream file("adminuser.txt");

    if (file.is_open()) {
        string line;
        bool loginSuccessful = false;

        while (getline(file, line)) {
            istringstream iss(line);
            string stored_username, stored_id, stored_pass;

            if (iss >> stored_username >> stored_id >> stored_pass) {
                // Check if entered credentials match
                if (admin_username == stored_username && admin_id == stored_id && admin_pass == stored_pass) {
                    cout << "\n\t\t\t\t\t\tLogin successful!\n";
                    loginSuccessful = true;
                    cout << endl;
                    cout << BLINK << GREEN << "\t\t\t\tLogin sucessful! \n" << RESET << flush;

                    cout << BLINK << YELLOW << "\t\t\t\tPress Enter to continue..." << RESET << flush;
                    cin.ignore();
                    cin.get();

                    system("CLS");
                    admin_menu();

                }
            }
        }

        if (!loginSuccessful) {
            cout << endl;
            cout << BLINK << RED << "\t\t\t\tLogin unsucessful! Invalid Username or ID or Password \n" << RESET << flush;
            cout << endl;

            cout << BLINK << YELLOW << "\t\t\t\tPress Enter to continue..." << RESET << flush;
            cin.ignore();
            cin.get();

            system("CLS");
            admin_login_page();
        }

        file.close();
    }
    else {
        cerr << "Error: Unable to open adminuser.txt\n";
    }
}


void sales_report() {
    int platinum = generateRandomNumber(1, 5);
    int gold = generateRandomNumber(1, 5);
    int standard = generateRandomNumber(1, 5);
    double p_platinum = 799;
    double p_gold = 599;
    double p_standard = 299;
    int total = p_standard * standard + p_gold * gold + p_platinum * platinum;
    int platinum_remained = 126 - platinum;
    int gold_remained = 144 - gold;
    int standard_remained = 90 - standard;

    system("CLS");
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t   +=============================+\n";
    cout << "\t\t\t\t\t   |         SALES REPORT        | \n";
    cout << "\t\t\t\t\t   +=============================+\n";
    cout << endl;
    cout << "\t\t\t\t\t   Sales of Each Zone " << endl;
    cout << "\t\t\t\t\t   ------------------- " << endl;
    cout << "\t\t\t\t\t   Platinum (Zone A) :  " << platinum << setw(6) << "[RM " << p_platinum << "]" << endl;
    cout << "\t\t\t\t\t   Gold (Zone B)     :  " << gold << setw(6) << "[RM " << p_gold << "]" << endl;
    cout << "\t\t\t\t\t   Standard (Zone C) :  " << standard << setw(6) << "[RM " << p_standard << "]" << endl;
    cout << "\t\t\t\t\t   TOTAL SALES       :  RM" << total << endl;
    cout << endl;
    cout << "\t\t\t\t\t   Seats avaibility " << endl;
    cout << "\t\t\t\t\t   ------------------- " << endl;
    cout << "\t\t\t\t\t   Platinum (Zone A) :  (126) " << setw(5) << right << platinum_remained << endl;
    cout << "\t\t\t\t\t   Gold (Zone B)     :  (144) " << setw(5) << right << gold_remained << endl;
    cout << "\t\t\t\t\t   Standard (Zone C) :  (90) " << setw(6) << right << standard_remained << endl;

}

void seats_avaibility(const vector<vector<char>>& seats, int numRows, int numCols) {
    printSeatingLayout_standard(seats, numRows, numCols);
}

void admin_menu() {
    int option;

    cout << endl;
    cout << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t+=====================================================+" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t   +=============================+\n";
    cout << "\t\t\t\t\t   |        ADMIN MENU PAGE      | \n";
    cout << "\t\t\t\t\t   +=============================+\n";
    cout << endl;
    cout << "\t\t\t\t\t    [1] Sales Report\n";
    cout << "\t\t\t\t\t    [2] Log Out\n";

    cout << endl;
    cout << "\t\t\t\t\t\tEnter your choice: ";
    cin >> option;

    while (option < 1 && option > 2) {
        cout << "Invalid choice! Please select the option within 1 - 2 : ";
        cin >> option;
    }

    switch (option) {
    case 1:
        system("CLS");
        sales_report();
        break;

    case 2:
        system("CLS");
        user_page_select();
        break;
        break;
    }
    cout << endl;
    cout << BLINK << YELLOW << "\t\t\t\tPress Enter to continue..." << RESET << flush;
    cin.ignore();
    cin.get();
    system("CLS");
    admin_menu();
}

const int MAX_USERS = 1000;

struct User {
    string username;
    string password;
    string email;
    string phoneNumber;
};

enum RegistrationStatus {
    RegistrationSuccess,
    UserAlreadyExists,
    RegistrationFailed
};

enum LoginStatus {
    LoginSuccess,
    LoginFailed
};

RegistrationStatus registerUser(User users[], int& userCount, const string& username, const string& password, const string& email, const string& phoneNumber) {
    for (int i = 0; i < userCount; ++i) {
        if (users[i].username == username) {
            return UserAlreadyExists;
        }
    }

    User newUser;
    newUser.username = username;
    newUser.password = password;
    newUser.email = email;
    newUser.phoneNumber = phoneNumber;
    users[userCount++] = newUser;

    return RegistrationSuccess;
}

LoginStatus loginUser(const User users[], int userCount, const string& username, const string& password) {
    for (int i = 0; i < userCount; ++i) {
        if (users[i].username == username && users[i].password == password) {
            return LoginSuccess;
        }
    }

    return LoginFailed;
}


void saveUserData(const User users[], int userCount) {
    ofstream file("userdata.txt", ios::out);
    if (file.is_open()) {
        for (int i = 0; i < userCount; ++i) {
            file << users[i].username << ' ' << users[i].password << ' ' << users[i].email << ' ' << users[i].phoneNumber << '\n';
        }
        file.flush();
        file.close();
    }
    else {
        cerr << "Error: Unable to save user data.\n";
    }
}

int loadUserData(User users[], int& userCount) {
    ifstream file("userdata.txt");
    if (file.is_open()) {
        User user;
        while (file >> user.username >> user.password >> user.email >> user.phoneNumber) {
            if (userCount < MAX_USERS) {
                users[userCount++] = user;
            }
            else {
                cerr << "Error: Maximum number of users reached.\n";
                break;
            }
        }
        file.close();
    }
    return userCount;
}

void loginpage() {
#define RESET         "\033[0m"
#define RED           "\033[31m"
#define GREEN         "\033[32m"
#define BLINK         "\033[5m"
#define YELLOW        "\033[33m"

    User users[MAX_USERS];
    int userCount = 0;

    userCount = loadUserData(users, userCount);

    string email;
    string phoneNumber;;

    char choice;
    do {

        cout << endl;
        cout << endl;
        cout << "\t\t\t\t+=====================================================+" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t+=====================================================+" << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t   +=============================+\n";
        cout << "\t\t\t\t\t   |        Login/Register       |\n";
        cout << "\t\t\t\t\t   +=============================+\n";
        cout << "\t\t\t\t\t    [1] Register\n";
        cout << "\t\t\t\t\t    [2] Login\n";
        cout << "\t\t\t\t\t    [3] Exit\n";
        cout << endl;
        cout << "\t\t\t\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            system("CLS");
            bool isValidEmail = false;
            bool isValidPhoneNumber = false;
            bool isValidPassword = false;
            bool isValidUsername = false;

            string username, password;
            cout << endl;
            cout << endl;
            cout << "\t\t\t\t+=====================================================+" << endl;
            cout << "\t\t\t\t|                                                     |" << endl;
            cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
            cout << "\t\t\t\t|                                                     |" << endl;
            cout << "\t\t\t\t+=====================================================+" << endl;
            cout << endl;
            cout << endl;

            do {
                cout << "\t\t\t\tEnter username: ";
                cin >> username;
                regex usernamePattern(R"([a-zA-Z ]{3,})");
                if (regex_match(username, usernamePattern)) {
                    isValidUsername = true;
                }
                else {
                    cout << endl;
                    cout << BLINK << RED << "\t\t\t\tInvalid username format. Please enter at least 3 alphabetical characters." << RESET << flush << endl;
                    cout << endl;
                }
            } while (!isValidUsername);

            do {
                cout << "\t\t\t\tEnter password: ";
                cin >> password;
                regex passwordPattern(R"((?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[~`!@#$%^&*()-_+=\[\]{}|;:'",.<>?/]).{8,})");
                if (regex_match(password, passwordPattern)) {
                    isValidPassword = true;
                }
                else {
                    cout << endl;
                    cout << BLINK << RED << "\t\t\t\tInvalid password format. Please follow the specified requirements : " << RESET << flush << endl;
                    cout << BLINK << RED << "\t\t\t\tAt least one lowercase letter." << RESET << flush << endl;
                    cout << BLINK << RED << "\t\t\t\tAt least one uppercase letter." << RESET << flush << endl;
                    cout << BLINK << RED << "\t\t\t\tAt least one numeric character." << RESET << flush << endl;
                    cout << BLINK << RED << "\t\t\t\tAt least one special character" << RESET << flush << endl;
                    cout << BLINK << RED << "\t\t\t\tMinimum length of 8 characters." << RESET << flush << endl;
                    cout << endl;
                }
            } while (!isValidPassword);

            do {

                cout << "\t\t\t\tEnter your email address: ";
                cin >> email;
                regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
                if (regex_match(email, emailPattern)) {
                    isValidEmail = true;
                }
                else {
                    cout << endl;
                    cout << BLINK << RED << "\t\t\t\tInvalid email address." << RESET << flush << endl;
                    cout << endl;
                }
            } while (!isValidEmail);


            do {
                cout << "\t\t\t\tEnter your phone number : ";
                cin >> phoneNumber;
                regex phonePattern(R"(\d{10,11})");

                if (regex_match(phoneNumber, phonePattern)) {
                    isValidPhoneNumber = true;
                }
                else {
                    cout << endl;
                    cout << BLINK << RED << "\t\t\t\tInvalid phone number. Please enter 10-11 digists phone number" << RESET << flush << endl;
                    cout << endl;
                }
            } while (!isValidPhoneNumber);



            RegistrationStatus status = registerUser(users, userCount, username, password, email, phoneNumber);

            if (status == RegistrationSuccess) {
                cout << endl;
                cout << endl;
                cout << endl;
                cout << BLINK << GREEN << "\t\t\t\tRegistration successful!\n" << RESET << flush << endl;
                cout << endl;
                cout << BLINK << YELLOW << "\t\t\t\tPress Enter to continue..." << RESET << flush;
                cin.ignore();
                cin.get();

                system("CLS");
            }

            else if (status == UserAlreadyExists) {
                cout << endl;
                cout << BLINK << RED << "\t\t\t\tRegistration failed. User already exists.\n" << RESET << flush;
                cout << endl;

                cout << BLINK << YELLOW << "\t\t\t\tPress Enter to continue..." << RESET << flush;
                cin.ignore();
                cin.get();

                system("CLS");

            }

            else {
                cout << endl;
                cout << BLINK << RED << "\t\t\t\tRegistration failed.\n" << RESET << flush;
                cout << endl;

                cout << BLINK << YELLOW << "\t\t\t\tPress Enter to continue..." << RESET << flush;
                cin.ignore();
                cin.get();
            }

            system("CLS");

            saveUserData(users, userCount); // Save user data after registration
            break;

        }

        case '2': {
            system("CLS");

            string username, password;
            cout << endl;
            cout << endl;
            cout << "\t\t\t\t+=====================================================+" << endl;
            cout << "\t\t\t\t|                                                     |" << endl;
            cout << "\t\t\t\t|      COOL PLAY CONCERT TICKETS BOOKING SYSTEM       |" << endl;
            cout << "\t\t\t\t|                                                     |" << endl;
            cout << "\t\t\t\t+=====================================================+" << endl;
            cout << endl;
            cout << endl;
            cout << "\t\t\t\tEnter username: ";
            cin >> username;
            cout << "\t\t\t\tEnter password: ";
            cin >> password;

            LoginStatus status = loginUser(users, userCount, username, password);

            if (status == LoginSuccess) {
                cout << endl;
                cout << endl;
                cout << BLINK << GREEN << "\t\t\t\tLogin successful!\n" << RESET << flush << endl;
                this_thread::sleep_for(chrono::milliseconds(10));
                cout << "\r" << flush;
                this_thread::sleep_for(chrono::milliseconds(10));
                cout << endl;
                cout << endl;
                cout << BLINK << YELLOW << "\t\t\t\tPress Enter to continue..." << RESET << flush;
                cin.ignore();
                cin.get();

                ticket_menu_page(username, password, email, phoneNumber);
            }
            else {
                cout << endl;
                cout << endl;
                cout << BLINK << RED << "\t\t\t\tLogin failed. Incorrect username or password.\n" << RESET << flush;

                cout << BLINK << YELLOW << "\t\t\t\tPress Enter to continue..." << RESET << flush;
                cin.ignore();
                cin.get();

                system("CLS");

            }
            break;
        }

        case '3':
            system("CLS");
            user_page_select();
            break;

        default:
            cout << BLINK << RED << "\t\t\t\tInvalid choice. Please try again.\n" << RESET << flush;

            cout << BLINK << YELLOW << "\t\t\t\tPress Enter to continue..." << RESET << flush;
            cin.ignore();
            cin.get();

            system("CLS");

        }

    } while (choice != '3');
}
int main() {

    const int total = 100; // total number of iterations
    for (int i = 0; i <= total; ++i) {
        updateProgressBar(i, total);
        this_thread::sleep_for(chrono::milliseconds(20)); // simulate some work
    }

    cout << endl;
    cout << endl;
    cout << "\t\t\t\t \nCompleted!\n";
    this_thread::sleep_for(chrono::seconds(2));

    system("CLS");

    welcome_message();

    user_page_select();


    return 0;
}






