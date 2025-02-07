// Atharva and Mano
// 1/29/25
// Playlist
// Extra: Searching/Save to File
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iomanip>
#include <fstream>
#include <unistd.h>

using namespace std;

int convertTime(string songLength) {
    int colonPos = songLength.find(':');                    // this function finds the colon
    int minutes = stoi(songLength.substr(0, colonPos));     // goes from the beggining of the string until the colon and converts it to an int so it works with either x:xx or xx:xx time formats
    int seconds = stoi(songLength.substr(colonPos + 1));    // same thing but does after the semicolon for the seconds
    return minutes * 60 + seconds;  
}

int main() {
    srand(time(0));
    vector<vector<string>> songs = {
        {"Travis Scott", "FE!N", "3:06"},
        {"Travis Scott", "4X$", "3:06"},
        {"Travis Scott", "HIGHEST IN THE ROOM", "2:55"},
        {"Travis Scott", "SICKO MODE", "5:12"},
        {"Travis Scott", "STARGAZING", "4:30"},
        {"Travis Scott", "90210", "5:45"},
        {"Travis Scott", "GOOSEBUMPS", "4:04"},
        {"Travis Scott", "MELTDOWN", "4:00"},
        {"Travis Scott", "MY EYES", "4:11"},
        {"Travis Scott", "TOPIA TWINS", "3:35"},

        {"Playboi Carti", "Magnolia", "3:01"},
        {"Playboi Carti", "Sky", "3:14"},
        {"Playboi Carti", "Over", "2:45"},
        {"Playboi Carti", "Location", "2:55"},
        {"Playboi Carti", "Vamp Anthem", "2:04"},
        {"Playboi Carti", "RIP", "3:12"},
        {"Playboi Carti", "New Tank", "2:20"},
        {"Playboi Carti", "Long Time", "3:31"},
        {"Playboi Carti", "Lean 4 Real", "3:05"},
        {"Playboi Carti", "Shoota", "2:33"},

        {"Kanye West", "Power", "3:40"},
        {"Kanye West", "Flashing Lights", "3:57"},
        {"Kanye West", "Heartless", "3:30"},
        {"Kanye West", "Stronger", "5:11"},
        {"Kanye West", "All of the Lights", "4:59"},
        {"Kanye West", "Runaway", "9:08"},
        {"Kanye West", "Gold Digger", "3:28"},
        {"Kanye West", "Can't Tell Me Nothing", "4:32"},
        {"Kanye West", "Ultralight Beam", "5:20"},
        {"Kanye West", "Touch the Sky", "3:56"},
        {"Kanye West", "Praise God", "3:48"},

        {"Kendrick Lamar", "Money Trees", "6:26"},
        {"Kendrick Lamar", "HUMBLE.", "2:57"},
        {"Kendrick Lamar", "Alright", "3:39"},
        {"Kendrick Lamar", "Backseat Freestyle", "3:32"},
        {"Kendrick Lamar", "DNA.", "3:06"},
        {"Kendrick Lamar", "Swimming Pools (Drank)", "3:40"},
        {"Kendrick Lamar", "ELEMENT.", "3:55"},
        {"Kendrick Lamar", "LOVE.", "3:33"},
        {"Kendrick Lamar", "LOYALTY.", "3:47"},
        {"Kendrick Lamar", "The Blacker the Berry", "5:29"},
        {"Kendrick Lamar", "Sing About Me, I'm Dying of Thirst", "12:03"}
    };
        for (vector<string> curSong : songs) {
            cout << left << setw(20) << curSong[0]          // this is a thing in the iomanip library that gives the thing a set width
                << setw(50) << curSong[1]
                << setw(10) << curSong[2] << endl;
        }
        


        int userChoice; 
while(true){
    cout<<"Would you like to do?\n1. Add Songs \n2. Play \n3. Shuffle \n4. Print Playlist \n5. Search \n6. Save to file\n7. Exit" << endl;
    cin >> userChoice;
    cin.ignore();
    switch(userChoice){
        case 1: {
            cout << "What is the name of the artist: ";
            string artistName;
            getline(cin, artistName);
    
            cout << "What is the name of the song: ";
            string songName;
            getline(cin, songName);
    
            cout << "What is the length of the song (x:xx): ";
            string songLength;
            getline(cin, songLength);
    
    songs.push_back({artistName, songName, songLength});
    
    cout<<"SONG ADDED"<<endl;
    break;
            }
        case 2: {
    string songChoice;
    string songLength;
    int time;
    bool found = false;
    cout << "What Song? (Enter full name spelled correctly)" << endl;
    getline(cin, songChoice);
    for (vector<string> song : songs) {
        if (song[1] == songChoice) {
            songLength = song[2];
            found = true;
            break;  // Exit loop once the song is found
        }
    }
    if (!found)
        cout << "Invalid Song" << endl;
    else {
        time = convertTime(songLength);
        cout << "Playing " << songChoice << " for " << time << " seconds..." << endl;

        for (int i = time; i > 0; --i) {
            cout << "Time left: " << i << " seconds" << endl;
            sleep(1); // Sleep for 1 second
        }

        cout << "Finished playing " << songChoice << endl;
    }
    break;
}
        case 3:{
            shuffle(songs.begin(), songs.end(), default_random_engine{});
            cout << "Songs Shuffled!" << endl;
            break;
        }
        case 4:{
            // print playlist
             for (vector<string> curSong : songs) {
            cout << left << setw(20) << curSong[0]          // this is a thing in the iomanip library that gives the thing a set width
                << setw(50) << curSong[1]
                << setw(10) << curSong[2] << endl;   
            }
            break;
        }
        case 5:{
            cout << "What is the name of the song: ";
            string searchSong;
            getline(cin, searchSong);
            for (vector<string> curSong : songs) {
            if (curSong[1] == searchSong) {
                 cout << "Artist: " << curSong[0] << endl;
                cout << "Song: " << curSong[1] << endl;
                cout << "Length: " << curSong[2] << endl;
                
                
                }
            }
             break;
        }
        case 6: {
            ofstream WriteFile("playlist.txt");
            for (vector<string> song : songs) {
                WriteFile << song[0] << ", " << song[1] << ", " << song[2] << endl;
            }
            cout << "File Made" << endl;
            break;
        }
        case 7: {
            return 1;
        }
        default:{
            cout<<"Oh nah"<<endl;
        }
    }
    }

    return 0;
}
