#ifndef SONG_H_
#define SONG_H_
#include <iostream>
#include <string>
using namespace std;

class Song {
private:
	string Title;
	string Artist;
	string Genre; //valid genres are ModernPop, Grunge, Classical, and American
public:
	//constructors
	Song() { //default song
		Title = "Cheetah Sisters";
		Artist = "The Cheetah Girls";
		Genre = "ModernPop";
	}
	Song(string title, string artist, string genre) { //to allow caller to set up song
		Title = title;
		Artist = artist;
		if (genre == "ModernPop" || genre == "Grunge" || genre == "Classical" || genre == "Americana")
			Genre = genre;
		else
			genre = "ModernPop"; //default
	}
	//const get fxns
	const string getTitle() { return Title; }
	const string getArtist() { return Artist; }
	const string getGenre() { return Genre; }
	//check if song is of genre
	bool isOfGenre(string genre) {
		if (genre == Genre) //checking genre of object to selected genre in ()
			return true;
		else
			return false;
	}
};

/*
UML DIAGRAM
- string Title, Artist, Genre
+ Song()
+ Song(string title, string artist, string genre)
+ string getTitle(), getArtist(), getGenre()
+ bool isOfGenre(string genre)
*/

#endif