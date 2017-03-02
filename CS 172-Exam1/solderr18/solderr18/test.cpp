//CS172 EXAM 1
//SARAH OLDERR 
#include <iostream>
#include <string>
#include "Playlist.h"
#include "Song.h"
using namespace std;

int main() { //directly from test case provided on exam sheet
	//make an array of songs
	static int numsongs = 9;
	Song songs[] = {
		Song("Human", "Rag'n'Bone Man", "ModernPop"),
		Song("Closer", "The Chainsmokers", "ModernPop"),
		Song("Chained To the Rythm", "Katy Perry", "ModernPop"),
		Song("Smells Like Teen Spirit", "Nirvana", "Grunge"),
		Song("Black Hole Sun", "Soundgarden", "Grunge"),
		Song("Loser", "Beck", "Grunge"),
		Song("Elvis Presley Blues", "Gillian Welch", "Americana"),
		Song("Pirate's Gospel", "Alela Diane", "Americana"),
		Song("Come On Up To The House", "Sarah Jarosz", "Americana")
	};
	//make the playlist
	Playlist playlist("iRandomMusic");
	for (int i = 0; i < numsongs; i++) {
		playlist.addSong(songs[i]);
	}
	//test
	int errors = 0;
	//does playlist have the correct number of songs?
	if (numsongs != playlist.numberOfSongs()) {
		errors++;
		cout << "error: not counting songs correctly\n";
	}

	//check the genreof one song
	if (playlist.playSong(2) == "") { 
		errors++;
		cout << "error: title of the song is incorrect \n"; 
	}
	if (playlist.playSong(10) != "") {
		errors++;
		cout << "error: index out of range not handled correctly\n";
	}
	//check for a genre
	if (!playlist.hasGenre("Americana")) 
		errors++;
	else
		cout << "Errors: " << errors << endl;

	return errors;
}