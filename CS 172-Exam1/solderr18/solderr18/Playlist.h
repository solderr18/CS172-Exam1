#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include "Song.h"
#include <iostream>
#include <string>
using namespace std;

class Playlist {
private:
	string Name;
	int numSongs;
//	const int MAX_SONGS = 100;
	Song song[100];
public:
	//constructor
	Playlist(string name) {
		Name = name;
		numSongs = 0;
	}
	//getFxns
	string getName() { return Name; }
	
	int numberOfSongs() { return numSongs; }

	//bool check fxns
	//returns true when at least one song of this genre is present
	bool hasGenre(string genre) {
		bool check = false;
		for (int i = 0; i < numberOfSongs(); i++) { //????????INFINITE LOOP ????
			if (song[i].isOfGenre(genre) == true)
				check = true;
		}
		return check;
	}

	//add a new song
	void addSong(Song newSong) { 
		if (numSongs < 100) { //INFINITE LOOP >>>???????
			song[numSongs] = newSong;
			numSongs++;
		}
	}


	//Play a song. return an empty string if no such song.
	string playSong(int songNumber) {
		if (songNumber > numberOfSongs())
			return "";
		else
			return song[songNumber].getTitle();
	}

};

/*
UML DIAGRAM
- string Name
- int numSongs
- Song songs[100]
+ Playlist (string name)
+ string getName()
+ int numberOfSongs()
+ bool hasGenre(string genre)
+ void addSong(Song newSong)
+ string playSong(int songNumber)
*/

#endif
