#include <iostream>
#include <string>
using namespace std;
class Movie {
private:
    string movieName;
    string MPAArating;
    int ratingCount[5] = {0, 0, 0, 0, 0};
public:
    Movie(string name, string rating) {
        movieName = name;
        MPAArating = rating;
    }


    void setMovieName(string name) {
        movieName = name;
    }
    void setMPAArating(string rating) {
        MPAArating = rating;
    }


    string getMovieName() {
        return movieName;
    }
    string getMPAArating() {
        return MPAArating;
    }


    void addRating(int rating) {
        if (rating >= 1 && rating <= 5) {
            ratingCount[rating - 1]++;
        } else {
            cout << "Invalid rating. Please enter a number between 1 and 5." << endl;
        }
    }

    double getAverage() {
        double sum = 0;
        double totalRatings = 0;

        for (int i = 0; i < 5; i++) {
            sum += (i + 1) * ratingCount[i];
            totalRatings += ratingCount[i];
        }

        if (totalRatings == 0) {
            return 0;
        }

        return sum / totalRatings;
    }
};

int main() {

    Movie movie1("Mission Impossible", "PG-13");
    Movie movie2("It", "R");

    movie1.addRating(4);
    movie1.addRating(5);
    movie1.addRating(3);
    movie1.addRating(4);
    movie1.addRating(5);

    movie2.addRating(4);
    movie2.addRating(1);
    movie2.addRating(4);
    movie2.addRating(2);
    movie2.addRating(5);

    cout << "Movie 1 Info:\nName: " << movie1.getMovieName() << "\nMPAA Rating: " << movie1.getMPAArating() << "\nAverage Rating: " << movie1.getAverage() << endl;
    cout << "=============================" << endl;
    cout << "Movie 2 Info:\nName: " << movie2.getMovieName() << "\nMPAA Rating: " << movie2.getMPAArating() << "\nAverage Rating: " << movie2.getAverage() << endl;
          return 0;
      }
