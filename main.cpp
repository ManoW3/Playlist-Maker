// Atharva and Mano
// 1/29/25
// Playlist
// Extra:
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    
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
    while(true) {
        for (vector<string> curSong : songs) {
            cout << left << setw(20) << curSong[0]          // this is a thing in the iomanip library that gives the thing a set width
                << setw(50) << curSong[1]
                << setw(10) << curSong[2] << endl;
        }
        
    }

    return 0;
}